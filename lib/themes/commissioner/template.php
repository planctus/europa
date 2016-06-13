<?php

/**
 * @file
 * template.php
 */

/**
 * Implements template_preprocess_page().
 */
function commissioner_preprocess_page(&$variables) {

  // Prepare the url for the "external" homepage.
  global $language;
  $delimiter = variable_get('language_suffix_delimiter', '_');
  $suffix = $delimiter . $language->prefix;
  // Set a variable containing the external url to point to.
  $variables['front_page'] = 'http://ec.europa.eu/index' . $suffix . '.htm';

  // Adding string 'Tag: ' to Taxonomy tag pages.
  // Check if it's a taxonomy term page and object is loaded in $term.
  if (menu_get_object('taxonomy_term', 2)) {
    // Get taxonomy machine name.
    $taxonomy = $variables['page']['content']['system_main']['term_heading']['term']['#term']->vocabulary_machine_name;
    // Get term name.
    $term = $variables['page']['content']['system_main']['term_heading']['term']['#term']->name;
    if ($taxonomy == 'tags') {
      $variables['title'] = drupal_set_title(t('Tag') . ': ' . $term);
    }
  }

}

/**
 * Returns an array with singular and plural form of a bundle.
 *
 * @param string $bundle
 *   Machine name of a bundle.
 *
 * @return array
 *   Containing $forms['singular'] and $forms['plural'].
 */
function _commissioner_bundle_forms($bundle) {
  // Forming plurals for existing content types.
  $plurals = array(
    'activities' => t("calendar items"),
    'aggregated_news' => t("announcements"),
    'biography' => t("commissioners"),
    'commisioner_blog_post' => t("blog posts"),
    'highlight' => t("highlights"),
    'page' => t("pages"),
  );

  $singular = node_type_get_name($bundle);
  // If user preference for plural form - use it, otherwise use the label.
  if (isset($plurals[$bundle])) {
    $plural = $plurals[$bundle];
  }
  else {
    $plural = drupal_strtolower(t("@bundles", array('@bundle' => $singular)));
  }

  $forms = array(
    'singular' => ucfirst(drupal_strtolower($singular)),
    'plural' => $plural,
  );

  return $forms;
}

/**
 * Implements hook_preprocess_views_view().
 */
function commissioner_preprocess_views_view(&$variables) {
  $view = $variables['view'];

  if (!empty($view->feed_link)) {
    $variables['feed_link'] = $view->feed_link;
  }

  if (isset($view->filter['type']) && ($view->display_handler->plugin_name == 'page')) {
    $variables['items_count'] = '';

    $content_type = array_shift($view->filter['type']->value);

    // Checking if .listing exists in classes_array so that result count can be
    // displayed.
    if ($view->plugin_name == 'nexteuropa_bem_listing' || $view->current_display == 'print_list') {
      // Calculate the number of items displayed in a view listing.
      $total_rows = !$view->total_rows ? count($view->result) : $view->total_rows;

      $content_type_forms = _commissioner_bundle_forms($content_type);

      if ($total_rows == 0) {
        $items_count = t("No @items", array('@items' => $content_type_forms['plural']));
      }
      else {
        $items_count = $total_rows . ' ' .
          format_plural($total_rows, $content_type_forms['singular'], $content_type_forms['plural']);
      }

      // If there is a suffix add it here.
      if (isset($view->items_count['#suffix'])) {
        $items_count .= ' ' . $view->items_count['#suffix'];
      }

      $variables['items_count'] = $items_count;
    }
  }
}

/**
 * Implements template_preprocess_views_view_unformatted().
 */
function commissioner_preprocess_views_view_unformatted(&$variables) {
  $view = $variables['view'];

  // Add custom class for current events.
  if ($view->name == 'activities' && $view->current_display == 'block') {
    $today = date('Y-m-d h:i:s');
    foreach ($view->result as $id => $row) {
      $start = $row->field_field_start_end_date[0]['raw']['value'];
      $end = $row->field_field_start_end_date[0]['raw']['value2'];

      // Add a class if the event is occuring at a current date.
      // In case of single day event the $start and $end dates will be the same
      // while for multiple day events the $end date will be different.
      // The view is only showing events in the future and all events start at
      // midnight so we only have to check whether the current date is bigger
      // than the $start date.
      $is_current = $today >= $start && ($start == $end || $today <= $end);
      if ($is_current) {
        $variables['classes_array'][$id] .= ' today';
      }
    }
  }
}

/**
 * Implements template_preprocess_html().
 */
function commissioner_preprocess_html(&$variables) {
  if (($key = array_search('front', $variables['classes_array'])) !== FALSE) {
    unset($variables['classes_array'][$key]);
  }
}

/**
 * Implements template_preprocess_node().
 */
function commissioner_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'team_cabinet_member') {
    $variables['content']['body']['#title'] = t('Responsibilities');
  }

  unset($variables['content']['links']['comment']['#links']['comment-add']);
}

/**
 * Implements template_preprocess_comment_wrapper().
 */
function commissioner_preprocess_comment_wrapper(&$variables) {
  $variables['comment_count'] = '';
  if ($variables['node']->comment_count > 0) {
    $variables['comment_count'] = $variables['node']->comment_count;
  }
}

/**
 * Implements template_preprocess_comment().
 */
function commissioner_preprocess_comment(&$variables) {
  $comment = $variables['elements']['#comment'];
  $variables['created'] = format_date($comment->created, 'ec_date');
  $variables['submitted'] = t('!username', array('!username' => $variables['author'])) . '<span class="submitted-date">' . $variables['created'] . '</span>';
  $variables['title']     = check_plain($comment->subject);
  $variables['permalink'] = t('Permalink');
  $variables['title_attributes_array']['class'] = 'comment__title';
}

/**
 * Theme function to output tablinks for classic Quicktabs style tabs.
 *
 * Adding bootstrap tab styles to quicktabs.
 *
 * @ingroup themeable
 *
 * @see theme_qt_quicktabs_tabset()
 */
function commissioner_qt_quicktabs_tabset($variables) {
  $variables = array(
    'attributes' => array(
      'class' => 'nav nav-tabs quicktabs-tabs quicktabs-style-' . $variables['tabset']['#options']['style'],
      'role' => 'tablist',
    ),
    'items' => array(),
  );
  foreach (element_children($variables['tabset']['tablinks']) as $key) {
    $item = array();
    if (is_array($variables['tabset']['tablinks'][$key])) {
      $tab = $variables['tabset']['tablinks'][$key];
      if ($key == $variables['tabset']['#options']['active']) {
        $item['class'] = array('active');
      }
      $item['data'] = drupal_render($tab);
      $variables['items'][] = $item;
    }
  }
  return '<div class="nav-tabs-wrapper">' . theme('item_list', $variables) . '</div>';
}

/**
 * Implements theme_pager_link().
 */
function commissioner_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  // Fix pager for rewritten URLs.
  // @see commissioners_url_inbound_alter().
  $original_path_cached = &drupal_static('cwt_core_orignal_path');
  $path = isset($original_path_cached['original_path']) ? $original_path_cached['original_path'] : $_GET['q'];
  $attributes['href'] = url($path, array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . $text . '</a>';
}

/**
 * Implements theme_textarea().
 *
 * @link https://www.drupal.org/node/1189584
 */
function commissioner_textarea($variables) {
  $element = $variables['element'];
  $element['#value'] = isset($element['#value']) ? $element['#value'] : '';
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Implements template_preprocess_block().
 */
function commissioner_preprocess_block(&$variables) {
  if ($variables['block']->delta == 'page_contents') {
    $variables['classes_array'][] = 'affix-top';
  }

  $exposed_blocks_delta = array('-exp-agenda-list', '-exp-biography_news-list');

  if (in_array($variables['block']->delta, $exposed_blocks_delta)) {
    $variables['classes_array'][] = 'block-filters';
    $variables['block']->subject = t('Refine');
  }
}

/**
 * Implements template_preprocess_field().
 */
function commissioner_preprocess_field(&$variables) {
  if ($variables['element']['#field_name'] == 'social_media') {
    switch ($variables['element']['#bundle']) {
      case 'aggregated_news':
        $variables['items'][0]['#prefix'] = '<span class="social-media-links__label">' . t('Share this article post on:') . '</span>';
        break;

      case 'commisioner_blog_post':
        $variables['items'][0]['#prefix'] = '<span class="social-media-links__label">' . t('Share this blog post:') . '</span>';
        break;
    }
  }
}

/**
 * Implements theme_form_element().
 */
function commissioner_form_element(&$variables) {
  if (isset($variables['element']['#name']) && $variables['element']['#name'] == 'QueryText') {
    $element = &$variables['element'];
    $prefix = isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
    $suffix = isset($element['#field_suffix']) ? $element['#field_suffix'] : '';
    $output = $prefix . $element['#children'] . $suffix . "\n";
    return $output;
  }
  else {
    return bootstrap_form_element($variables);
  }
}

/**
 * Implements hook_preprocess_file_entity().
 *
 * Because we use a different structure for the commissioners website we need to
 * avoid double .file classes on file entity's.
 */
function commissioner_preprocess_file_entity(&$variables) {
  if ($variables['view_mode'] == 'default') {
    if (($key = array_search('file', $variables['classes_array'])) !== FALSE) {
      unset($variables['classes_array'][$key]);
    }
  }
}

/**
 * Override theme_file_link().
 */
function commissioner_file_link($variables) {
  $file = $variables['file'];
  $url['path'] = file_create_url($file->uri);
  $url['options'] = array();

  // Apply the modifier if needed. Currently it's only on the front page. If on
  // a later stage, we need this everywhere, we should make this modifier the
  // default.
  $modifier = drupal_is_front_page() ? 'file--widebar' : FALSE;

  return _europa_file_markup($file, $url, $modifier);

}

/**
 * Implements hook_preprocess_bootstrap_tabs().
 */
function commissioner_preprocess_bootstrap_fieldgroup_nav(&$variables) {
  $group = &$variables['group'];

  $variables['nav_classes'] = '';

  switch ($group->format_settings['instance_settings']['bootstrap_nav_type']) {
    case 'tabs':
      $variables['nav_classes'] .= ' nav-tabs nav-tabs-right nav-tabs--with-content';
      break;

    case 'pills':
      $variables['nav_classes'] .= ' nav-pills';
      break;

    default:
  }

  if ($group->format_settings['instance_settings']['bootstrap_stacked']) {
    $variables['nav_classes'] .= ' nav-stacked';
  }

  $i = 0;
  foreach ($variables['items'] as $key => $item) {
    // Check if item is not empty and we have access to it.
    if ($item && (!isset($item['#access']) || $item['#access'])) {
      $variables['panes'][$i]['title'] = check_plain($item['#title']);
      $i++;
    }
  }
}

/**
 * Implements hook_js_alter().
 */
function commissioner_js_alter(&$js) {
  if (drupal_is_front_page()) {
    $europa_path = drupal_get_path('theme', 'europa');
    $commis_path = drupal_get_path('theme', 'commissioner');
    unset($js[$europa_path . '/js/europa_tabs.js']);
    drupal_add_js($commis_path . '/js/commissioner_tabs.js', 'file');
  }
}
