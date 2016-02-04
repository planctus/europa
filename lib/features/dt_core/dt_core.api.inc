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
function _dt_core_menu_link($link, $lang = FALSE) {
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
 * Get taxonomy term ID by term name.
 *
 * @param string $term
 *   Term name.
 * @param int $vid
 *   Vocabulary vid.
 */
function _dt_core_term_by_name($term, $vid) {
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
function _dt_core_menu_item($menu, $link, $plid, $title, $module, $weight, $lang = 'en', $tsid = NULL, $nolink = FALSE, $logs = FALSE) {
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
function _dt_core_create_node($type, $title, $path = 'node', $lang = LANGUAGE_NONE, $menu = NULL) {
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
 * Helper function to get the mlid basing on the link name.
 */
function _dt_core_menu_item_name_get($name, $menu) {
  $mlid = db_select('menu_links', 'ml')
    ->fields('ml', array('mlid'))
    ->condition('link_title', $name)
    ->condition('menu_name', $menu)
    ->execute()
    ->fetchField();

  if (is_numeric($mlid)) {
    return $mlid;
  }
  else {
    return FALSE;
  }
}
