<?php

/**
 * @file
 * template.php
 */

/**
 * Implements template_preprocess_html().
 */
function commissioner_preprocess_html(&$vars) {
  drupal_add_css(path_to_theme() . '/css/ie8.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'IE 8', '!IE' => FALSE),
    'preprocess' => FALSE,
  ));
  $vars['head_title'] = _commissioner_meta_title();
}

/**
 * Implements hook_js_alter().
 */
function commissioner_js_alter(&$javascript) {
  $path_fancybox = libraries_get_path('fancybox');
  unset(
    $javascript[$path_fancybox . '/jquery.fancybox.pack.js'],
    $javascript[$path_fancybox . '/helpers/jquery.fancybox-thumbs.js'],
    $javascript[$path_fancybox . '/helpers/jquery.fancybox-buttons.js'],
    $javascript[$path_fancybox . '/helpers/jquery.fancybox-media.js']
  );
}

/**
 * Implements hook_css_alter().
 */
function commissioner_css_alter(&$css) {
  $path_fancybox = libraries_get_path('fancybox');
  unset(
    $css[drupal_get_path('module', 'cce_basic_config') . '/cce_basic_config.css'],
    $css[drupal_get_path('module', 'date') . '/date_api/date.css'],
    $css[$path_fancybox . '/helpers/jquery.fancybox-buttons.css'],
    $css[$path_fancybox . '/helpers/jquery.fancybox-thumbs.css'],
    $css[$path_fancybox . '/jquery.fancybox.css']
  );
}

/**
 * Implements template_preprocess_views_view_unformatted().
 */
function commissioner_preprocess_views_view_unformatted(&$vars) {
  $view = $vars['view'];

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
        $vars['classes_array'][$id] .= ' today';
      }
    }
  }
}

/**
 * Implements template_preprocess_page().
 */
function commissioner_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_left']) && !empty($variables['page']['sidebar_right'])) {
    $variables['content_column_class'] = 'col-md-6';
  }
  elseif (!empty($variables['page']['sidebar_left']) || !empty($variables['page']['sidebar_right'])) {
    $variables['content_column_class'] = 'col-md-9';
  }
  else {
    $variables['content_column_class'] = 'col-md-12';
  }

  $variables['home_page_link_title'] = t('Go to the homepage');
  $variables['logo_alt'] = t('European Commission homepage');
  $variables['logo'] = commissioner_logo_path();
}

/**
 * Returns the path to the language specific logo.
 *
 * @param string $langcode
 *   Optional language code for the logo. Defaults to the current language.
 *
 * @return string
 *   The path to the logo in the given language.
 */
function commissioner_logo_path($langcode = NULL) {
  if (!$langcode) {
    global $language;
    $langcode = $language->language;
  }

  $logo_folder = path_to_theme() . '/images/logo/';
  $language_logo_filename = 'logo_' . $langcode . '.gif';
  $default_logo_filename = 'logo.gif';

  if (file_exists($logo_folder . $language_logo_filename)) {
    return base_path() . $logo_folder . $language_logo_filename;
  }
  else {
    return base_path() . $logo_folder . $default_logo_filename;
  }
}

/**
 * Implements template_preprocess_node().
 */
function commissioner_preprocess_node(&$vars) {
  unset($vars['content']['links']['comment']['#links']['comment-add']);
}


/**
 * Implements template_preprocess_region().
 */
function commissioner_preprocess_region(&$vars) {
  if ($vars['region'] == 'content_top') {
    $vars['classes_array'][] = 'clearfix';
  }
}

/**
 * Implements template_preprocess_comment().
 */
function commissioner_preprocess_comment(&$vars) {
  $comment = $vars['elements']['#comment'];
  $vars['created'] = format_date($comment->created, 'ec_date');
  $vars['submitted'] = t('!username', array('!username' => $vars['author'])) . '<span class="submitted-date">' . $vars['created'] . '</span>';
  $vars['title']     = check_plain($comment->subject);
  $vars['permalink'] = t('Permalink');
}

/**
 * Theme function to output tablinks for classic Quicktabs style tabs.
 *
 * Adding bootstrap tab styles to quicktabs.
 *
 * @ingroup themeable
 * @see theme_qt_quicktabs_tabset()
 */
function commissioner_qt_quicktabs_tabset($vars) {
  $variables = array(
    'attributes' => array(
      'class' => 'nav nav-tabs quicktabs-tabs quicktabs-style-' . $vars['tabset']['#options']['style'],
      'role' => 'tablist',
    ),
    'items' => array(),
  );
  foreach (element_children($vars['tabset']['tablinks']) as $key) {
    $item = array();
    if (is_array($vars['tabset']['tablinks'][$key])) {
      $tab = $vars['tabset']['tablinks'][$key];
      if ($key == $vars['tabset']['#options']['active']) {
        $item['class'] = array('active');
      }
      $item['data'] = drupal_render($tab);
      $variables['items'][] = $item;
    }
  }
  return '<div class="nav-tabs-wrapper">' . theme('item_list', $variables) . '</div>';
}

/**
 * Implements theme_file_link().
 */
function commissioner_file_link($variables) {
  $file = $variables['file'];

  $url = file_create_url($file->uri);

  $file_size = '<span class="file-size">' . format_size($file->filesize) . '</span>';

  $file_name = $file->uri;
  $file_extension = pathinfo($file_name, PATHINFO_EXTENSION);

  $file_metadata = '<span class="file-metadata">' . $file_size . ' - ' . $file_extension . '</span>';

  $file_class = '';
  switch ($file->type) {
    case 'image':
      $file_class = 'file-image';
      break;

    case 'audio':
      $file_class = 'file-audio';
      break;

    case 'video':
      $file_class = 'file-video';
      break;

    default:
      $file_class = 'file-document';
      break;
  }

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
      'class' => array('file', $file_class),
    ),
    'html' => TRUE,
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = '<span class="file-text">' . $file->filename . '</span>' . $file_metadata;
  }
  else {
    $link_text = '<span class="file-text">' . $file->description . '</span>' . $file_metadata;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return l($link_text, $url, $options);
}

/**
 * Implements theme_file_entity_download_link().
 */
function commissioner_file_entity_download_link($variables) {
  $file = $variables['file'];

  $uri = file_entity_download_uri($file);

  $file_size = '<span class="file-size">' . format_size($file->filesize) . '</span>';

  $file_name = $file->uri;
  $file_extension = pathinfo($file_name, PATHINFO_EXTENSION);

  $file_metadata = '<span class="file-metadata">' . $file_size . ' - ' . $file_extension . '</span>';

  $file_class = '';

  switch ($file->type) {
    case 'image':
      $file_class = 'file-image';
      break;

    case 'audio':
      $file_class = 'file-audio';
      break;

    case 'video':
      $file_class = 'file-video';
      break;

    default:
      $file_class = 'file-document';
      break;
  }

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
      'class' => array('file', $file_class),
      'title' => t('Download: [file:name]'),
    ),
    'html' => TRUE,
  );
  $options['attributes']['title'] = token_replace($options['attributes']['title'], array('file' => $file), array('clear' => TRUE, 'sanitize' => FALSE));
  $uri['options'] = array_merge($uri['options'], $options);

  // Provide the default link text.
  if (!isset($variables['text'])) {
    $variables['text'] = t('[file:name]');
  }

  // Peform unsanitized token replacement if $uri['options']['html'] is empty
  // since then l() will escape the link text.
  $variables['text'] = token_replace($variables['text'], array('file' => $file), array('clear' => TRUE, 'sanitize' => empty($uri['options']['html'])));
  $link_text = '<span class="file-text">' . $variables['text'] . '</span>' . $file_metadata;

  $output = l($link_text, $uri['path'], $uri['options']);

  return $output;
}

/**
 * Implements theme_pager().
 */
function commissioner_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // $pager_middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // $pager_current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // $pager_first is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // $pager_last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // $pager_max is the maximum page number.
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array(
    'text' => t('first'),
    'element' => $element,
    'parameters' => $parameters,
  ));
  $li_previous = theme('pager_previous', array(
    'text' => '<span class="element-invisible">' . t('previous') . '</span>',
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
    'attributes' => array('class' => 'btn btn-pager'),
  ));
  $li_next = theme('pager_next', array(
    'text' => '<span>' . t('next') . '</span><span class="subtext">' . t('page %page', array(
      '%page' => $pager_current + 1,
    )) . '</span>',
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
    'attributes' => array('class' => 'btn btn-pager'),
  ));
  $li_last = theme('pager_last', array(
    'text' => t('last'),
    'element' => $element,
    'parameters' => $parameters,
    'attributes' => array('class' => 'btn btn-pager'),
  ));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }
    $items[] = array(
      'class' => array('pager-current-combo'),
      'data' => '<span class="pager-current-combo-current">' . t('page %page', array('%page' => $pager_current)) . '</span> <span class="pager-current-combo-total subtext">' . t('of %total', array('%total' => $pager_max)) . '</span>',
    );
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      $select = array();
      if ($li_first && $i > 1) {
        $items[] = array(
          'class' => array('pager-first select'),
          'data' => $li_first,
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item select'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current select'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item select'),
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }
      }
    }
    if ($li_last && $i < $pager_max) {
      $items[] = array(
        'class' => array('pager-last select'),
        'data' => $li_last,
      );
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }

    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
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
 * Implements theme_pager_first().
 */
function commissioner_pager_first($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page.
  if ($pager_page_array[$element] > 0) {
    $output = theme('pager_link', array(
      'text' => $text,
      'page_new' => pager_load_array(0, $element, $pager_page_array),
      'element' => $element,
      'parameters' => $parameters,
      'attributes' => $attributes,
    ));
  }

  return $output;
}

/**
 * Implements theme_pager_previous().
 */
function commissioner_pager_previous($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page.
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);

    // If the previous page is the first page, mark the link as such.
    if ($page_new[$element] == 0) {
      $output = theme('pager_first', array(
        'text' => $text,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
    // The previous page is not the first page.
    else {
      $output = theme('pager_link', array(
        'text' => $text,
        'page_new' => $page_new,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
  }

  return $output;
}

/**
 * Implements theme_pager_next().
 */
function commissioner_pager_next($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page.
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    // If the next page is the last page, mark the link as such.
    if ($page_new[$element] == ($pager_total[$element] - 1)) {
      $output = theme('pager_last', array(
        'text' => $text,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
    // The next page is not the last page.
    else {
      $output = theme('pager_link', array(
        'text' => $text,
        'page_new' => $page_new,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
  }

  return $output;
}

/**
 * Implements theme_pager_last().
 */
function commissioner_pager_last($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page.
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $output = theme('pager_link', array(
      'text' => $text,
      'page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array),
      'element' => $element,
      'parameters' => $parameters,
      'attributes' => $attributes,
    ));
  }

  return $output;
}

/**
 * Implements theme_easy_breadcrumb().
 */
function commissioner_easy_breadcrumb($variables) {

  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $html = '';
  if ($segments_quantity > 0) {
    $html .= '<nav class="breadcrumb" role="navigation" aria-label="breadcrumbs"><span class="element-invisible">' . t('You are here') . ':</span> <ol>';
    for ($i = 0, $s = $segments_quantity - 1; $i < $segments_quantity; ++$i) {
      $it = $breadcrumb[$i];
      $classes = $it['class'];
      $classes[] = 'breadcrumb-segment-' . ($i + 1);
      if ($i == 0) {
        $classes[] = 'breadcrumb-segment-first';
        $attributes = array('class' => $classes, 'rel' => 'home');
      }
      else {
        // Add last class to penultimate item since last item is hidden.
        if ($i == ($s - 1)) {
          $classes[] = 'breadcrumb-segment-last';
        }
        $attributes = array('class' => $classes);
      }

      $content = check_plain(decode_entities($it['content']));
      if (isset($it['url'])) {
        $item = l($content, $it['url'], array('attributes' => $attributes));
      }
      else {
        $class = implode(' ', $classes);
        $item = '<span class="' . $class . '">'  . $content . '</span>';
      }
      $html .= '<li' . (in_array('active', $classes) ? ' class="element-invisible"' : '') . '>' . $item . '</li>';
    }

    $html .= '</ol></nav>';
  }
  return $html;
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
