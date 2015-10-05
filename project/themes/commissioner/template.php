<?php

/**
 * @file
 * template.php
 */

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
    'activities' => t("agenda items"),
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
    $plural = strtolower(t("@bundles", array('@bundle' => $singular)));
  }

  $forms = array(
    'singular' => strtolower($singular),
    'plural' => $plural,
  );

  return $forms;
}

/**
 * Implements hook_preprocess_views_view().
 */
function commissioner_preprocess_views_view(&$variables) {
  $view = $variables['view'];

  if (isset($view->filter['type']) && ($view->current_display != 'block')) {
    $variables['items_count'] = '';

    $content_type = array_shift($view->filter['type']->value);

    // Checking if .listing exists in classes_array so that result count can be
    // displayed.
    if ($view->plugin_name == 'nexteuropa_bem_listing' && isset($view->exposed_data)) {
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
  unset($variables['content']['links']['comment']['#links']['comment-add']);
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
}

/**
 * Theme function to output tablinks for classic Quicktabs style tabs.
 *
 * Adding bootstrap tab styles to quicktabs.
 *
 * @ingroup themeable
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
 * Implements hook_page_alter().
 */
function commissioner_page_alter(&$page) {
  global $language;
  if (arg(0) == 'node') {
    $node = node_load(arg(1));
    if (isset($node->title)) {
      $node_title = filter_xss($node->title);
    }
  }

  $keywords = '';
  $description = variable_get('site_slogan');
  if (empty($description)) {
    $description = filter_xss(variable_get('site_name'));
  }
  if (!empty($node)) {
    $description = $node_title . ' - ' . $description;
    $keywords = $node_title . ', ';
    $title = _commissioner_meta_title($node);
  }
  else {
    $title = _commissioner_meta_title();
  }

  if (!empty($node) && !empty($node->field_tags)) {
    $tags = field_view_field('node', $node, 'field_tags');
    if (isset($tags['#items'])) {
      foreach ($tags['#items'] as $key => $value) {
        $keywords .= $value['taxonomy_term']->name . ', ';
      }
    }
  }
  $keywords .= filter_xss(variable_get('site_name')) . ', ';
  $keywords .= 'European Commission, European Union, EU';

  $type = 'website';
  if (!empty($node)) {
    $type = $node->type;
  }

  // Content-Language.
  $meta_content_language = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'Content-Language',
      'content' => $language->language,
    ),
  );
  drupal_add_html_head($meta_content_language, 'meta_content_language');

  // Description.
  $meta_description = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'description',
      'content' => $description,
    ),
  );
  drupal_add_html_head($meta_description, 'meta_description');

  // Reference.
  $meta_reference = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'reference',
      'content' => filter_xss(variable_get('site_name')),
    ),
  );
  drupal_add_html_head($meta_reference, 'meta_reference');

  // Creator.
  $meta_creator = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'creator',
      'content' => 'COMM/DG/UNIT',
    ),
  );
  drupal_add_html_head($meta_creator, 'meta_creator');

  // IPG classification.
  $classification = variable_get('meta_configuration', 'none');
  if ($classification != 'none') {
    $meta_classification = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'classification',
        'content' => variable_get('meta_configuration', 'none'),
      ),
    );
    drupal_add_html_head($meta_classification, 'meta_classification');
  }
  else {
    if (user_access('administer site configuration')) {
      drupal_set_message(t('Please select the IPG classification of your site') . ' ' . l(t('here.'), 'admin/config/system/site-information'), 'warning');
    }
  }

  // Keywords.
  $meta_keywords = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'keywords',
      'content' => $keywords,
    ),
  );
  drupal_add_html_head($meta_keywords, 'meta_keywords');

  // Date.
  $meta_date = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'date',
      'content' => date('d/m/Y'),
    ),
  );
  drupal_add_html_head($meta_date, 'meta_date');

  // Og title.
  $meta_og_title = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:title',
      'content' => $title,
    ),
  );
  drupal_add_html_head($meta_og_title, 'meta_og_title');

  // Og type.
  $meta_og_type = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:type',
      'content' => $type,
    ),
  );
  drupal_add_html_head($meta_og_type, 'meta_og_type');

  // Og site name.
  $meta_og_site_name = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:site_name',
      'content' => filter_xss(variable_get('site_name')),
    ),
  );

  drupal_add_html_head($meta_og_site_name, 'meta_og_site_name');

  // Og description.
  $meta_og_description = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:description',
      'content' => $description,
    ),
  );
  drupal_add_html_head($meta_og_description, 'meta_og_description');

  // Fb admins.
  $meta_fb_admins = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'fb:admins',
      'content' => 'USER_ID',
    ),
  );
  drupal_add_html_head($meta_fb_admins, 'meta_fb_admins');

  // Robots.
  $meta_robots = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'robots',
      'content' => 'follow,index',
    ),
  );
  drupal_add_html_head($meta_robots, 'meta_robots');

  // Revisit after.
  $revisit_after = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'revisit-after',
      'content' => '15 Days',
    ),
  );
  drupal_add_html_head($revisit_after, 'revisit-after');

  // Viewport.
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );
  drupal_add_html_head($viewport, 'viewport');
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
 * Returns the meta title for the current page.
 *
 * The title will be derived from the given node if provided. Alternatively it
 * will be derived from the 'List Header' view for pages of types 'activities',
 * 'blog' or 'announcement'.
 * The text ' - European Commission' will always be appended to the title.
 *
 * @param object $node
 *   Optional node for which to generate the meta title.
 * @param string $title
 *   Optional fallback title to use if the title could not be derived from the
 *   node or 'List Header' view.
 *
 * @return string
 *   The meta title.
 */
function _commissioner_meta_title($node = NULL, $title = NULL) {
  if (!$node && arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
  }
  elseif (in_array(arg(0), array('announcements', 'blog', 'activities')) && arg(1) && arg(1) !== 'tag') {
    $display = arg(0) . '_header';
    $custom_title = views_embed_view('list_header', $display, arg(1));
    $doc = new DOMDocument();
    $doc->loadHTML('<meta http-equiv="content-type" content="text/html; charset=utf-8">' . $custom_title);
    if ($doc) {
      $title = strip_tags($doc->getElementsByTagName('h1')->item(0)->nodeValue);
    }
  }

  if ($node) {
    return check_plain($node->title) . ' - ' . t('European Commission');
  }
  else {
    $title = !$title ? '' : ($title . ' - ');
    return check_plain($title) . t('European Commission');
  }
}
