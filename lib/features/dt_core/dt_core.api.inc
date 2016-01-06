<?php
/**
 * @file
 * Api for the dt core feature.
 */

/**
 * Helper function to get the system path of aliased links.
 *
 * @param string $link
 *   The link to be handled.
 *
 * @return string
 *   The link, revisited.
 */
function dt_core_menu_link($link, $lang = FALSE) {
  global $base_url;
  $lang = $lang ? $lang : LANGUAGE_NONE;
  if ($link != '<front>' &&  $link != '<nolink>') {
    $source = drupal_lookup_path('source', $link, $lang);
    if (!$source) {
      $view = drupal_valid_path($link);
      if ($view) {
        return $link;
      }
      else {
        $link = url($link, array('absolute' => TRUE));
      }
    }
    else {
      $link = $source;
    }
  }

  return $link;
}

/**
 * Create a taxonomy term for a given vocabulary.
 *
 * @param string $vocabulary
 *   Vocabulary machine name.
 * @param string $name
 *   Name of the term to be created.
 * @param string $parent
 *   Name of the parent term, already existing
 *   in the specified vocabulary.
 *
 * @return string
 *   Return value from Drupal's entity_save() API call,
 *   or FALSE if no vocabulary has been found.
 */
function dt_core_create_term($vocabulary, $name, $lang = 'en', $weight = 0, $tsid = FALSE, $parent = FALSE) {

  if ($vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary)) {
    // Exit if term already exists for that vocabulary.
    $tid = dt_core_term_by_name($name, $vocabulary->vid);
    if (is_numeric($tid)) {
      return FALSE;
    }

    $values = array();
    $values['vocabulary_machine_name'] = $vocabulary->machine_name;
    $values['vid'] = $vocabulary->vid;
    $values['name'] = $name;
    $values['weight'] = $weight;
    $values['language'] = $lang;
    if ($parent) {
      $values['parent'] = $parent;
    }

    $entity = entity_create('taxonomy_term', $values);
    entity_save('taxonomy_term', $entity);

    if (!$tsid) {
      $ts = i18n_translation_set_create('taxonomy_term');
      $ts->add_item($entity, $lang);
      $ts->save(TRUE);
    }
    else {
      $ts = i18n_translation_set_load($tsid);
      $ts->add_item($entity, $lang);
      $ts->save(TRUE);
    }
    $ret = array(
      'tid' => $entity->tid,
      'tsid' => $ts->tsid,
    );
    return $ret;
  }
}

/**
 * Get taxonomy term ID by term name.
 *
 * @param string $term
 *   Term name.
 * @param int $vid
 *   Vocabulary vid.
 */
function dt_core_term_by_name($term, $vid) {
  $query = db_select('taxonomy_term_data', 't');
  $tid = $query
    ->fields('t', array('tid'))
    ->condition('t.name', $term)
    ->condition('t.vid', $vid)
    ->execute()
    ->fetchField();

  return $tid;
}

/**
 * Create menu links.
 *
 * @param string $menu
 *   Menu name.
 * @param string $link
 *   The raw link.
 * @param string $plid
 *   The parent item mlid.
 * @param string $title
 *   The link title.
 * @param string $module
 *   Module machine name.
 * @param string $weight
 *   Weight of the menu item.
 * @param string $lang
 *   Lang code sanitized.
 * @param string $tsid
 *   Translations set id.
 * @param string $nolink
 *   Items without links.
 * @param string $logs
 *   The logs directory path.
 *
 * @return int
 *   The mlid of the created menu item.
 */
function dt_core_menu_item($menu, $link, $plid, $title, $module, $weight, $lang = 'en', $tsid = NULL, $nolink = FALSE, $logs = FALSE) {
  $link = dt_core_menu_link($link, $lang);
  $plid = ($plid > 0) ? $plid : 0;

  $item = array(
    'menu_name' => $menu,
    'module' => $module,
    'customized' => 1,
    'language' => $lang,
    'plid' => $plid,
    'enabled' => 1,
    'expanded' => 1,
    'link_path' => $link,
    'locked' => TRUE,
    'link_title' => $title,
    'hidden' => 0,
    'weight' => $weight,
    'i18n_menu' => 1,
    'options' => array('title' => $link),
  );

  menu_link_save($item);

  return $item['mlid'];

}

/**
 * Create a node placeholder of a given type.
 *
 * @param string $type
 *   Content type machine name.
 * @param string $title
 *   Node title.
 * @param string $menu
 *   Menu machine name, if specified the node will receive
 *   a menu item attached to the specified menu having
 *   with the node's title as label.
 *
 * @return string
 *   Return nid.
 */
function dt_core_create_node($type, $title, $path = 'node', $lang = LANGUAGE_NONE, $menu = NULL) {
  $node = new stdClass();
  $node->type = $type;
  node_object_prepare($node);
  $node->uid = 1;
  $node->title = $title;
  $node->language = $lang;
  $node->path['alias'] = $path;
  $node->path['pathauto'] = 0;

  if ($menu) {
    $node->menu['plid'] = 0;
    $node->menu['menu_name'] = $menu;
    $node->menu['enabled'] = 1;
    $node->menu['link_title'] = $title;
    $node->menu['description'] = '';
  }
  node_save($node);

  return $node->nid;
}

/**
 * Helper function to delete menu, menu links, taxonomies.
 */
function dt_core_delete($name, $type = 'menu', $op = 'items') {
  switch ($type) {
    case 'menu':
      if ($op == 'items') {
        menu_delete_links($name);
      }
      else {
        menu_delete(array('menu_name' => $name));
      }
      break;

    case 'vocabulary':
      if ($op == 'items') {
        $voc = taxonomy_vocabulary_machine_name_load($name);
        if (!empty($voc)) {
          $terms = taxonomy_get_tree($voc->vid);
          foreach ($terms as $term) {
            taxonomy_term_delete($term->tid);
          }
        }
      }
      else {
        $voc = taxonomy_vocabulary_machine_name_load($name);
        if (!empty($voc)) {
          taxonomy_vocabulary_delete($voc->vid);
        }
      }
      break;

    case 'node':
      $node_type = array($name);
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('type', $node_type, 'IN');
      $result = $query->execute();
      foreach ($result['node'] as $node) {
        node_delete($node->nid);
      }
      break;
  }
}

/**
 * Helper function to get the mlid basing on the link name.
 */
function dt_core_menu_item_name_get($name, $voc) {
  $mlid = db_select('menu_links', 'ml')
    ->fields('ml', array('mlid'))
    ->condition('link_title', $name)
    ->condition('menu_name', $voc)
    ->execute()
    ->fetchField();

  if (is_numeric($mlid)) {
    return $mlid;
  }
  else {
    return FALSE;
  }
}
