<?php
/**
 * @file
 * template.php
 */

 /**
  * Implements hook_js_alter().
  */
function europa_js_alter(&$js) {
  $base_theme_path = drupal_get_path('theme', 'bootstrap');

  unset(
    $js[$base_theme_path . '/js/misc/ajax.js']
  );
}

 /**
  * Implements template_preprocess_field().
  */
function europa_preprocess_field(&$vars) {
  // Changing label for the field to display stripped out values.
  if ($vars['element']['#field_name'] == 'field_core_ecorganisation') {
    $field_value = $vars['element']['#items'][0]['value'];
    $field_value_stripped = substr($field_value, 0, strpos($field_value, " ("));

    $vars['items'][0]['#markup'] = $field_value_stripped;
  }
}

/**
 * Implements template_preprocess_block().
 */
function europa_preprocess_block(&$vars) {
  $block = $vars['block'];

  if ($block->delta == 'nexteuropa_feedback') {
    $vars['classes_array'][] = 'block--full-width';
  }

  if ($block->delta == 'inline_navigation') {
    $vars['classes_array'][] = 'inpage-nav__wrapper';
    $vars['title_attributes_array']['class'][] = 'inpage-nav__block-title';
  }
}

/**
 * Implements template_preprocess_views_view().
 */
function europa_preprocess_views_view(&$vars) {
  $view = $vars['view'];

  if ($view->style_plugin->definition['theme'] == 'views_view_unformatted') {
    $vars['classes_array'][] = 'listing';
  }
}

/**
 * Implements template_preprocess_views_view().
 */
function europa_preprocess_views_view_unformatted(&$vars) {
  $view = $vars['view'];

  $vars['additional_classes'][] = 'listing__item';
  $vars['additional_classes_array'] = implode(' ', $vars['additional_classes']);
}


/**
 * Implements hook_theme().
 */
function europa_theme() {
  return array(
    'node_form' => array(
      'render element' => 'form',
      'template' => 'node-form',
      'path' => drupal_get_path('module', 'europa') . '/theme',
    ),
  );
}

/**
 * Overrides theme_form_required_marker().
 */
function europa_form_required_marker($variables) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = array(
    'class' => 'form-required text-danger glyphicon glyphicon-asterisk',
    'title' => $t('This field is required.'),
  );
  return '<span' . drupal_attributes($attributes) . '></span>';
}

/**
 * Implements template_preprocess_page().
 */
function europa_preprocess_page(&$vars) {
  $node = &$vars['node'];
  $vars['ds_node'] = FALSE;

  // Nodes excluded that are not using DS.
  $node_type_list = array('class');

  if (isset($node) && !in_array($node->type, $node_type_list)) {
    // This disables message-printing on ALL page displays.
    $vars['show_messages'] = FALSE;

    // Add ds_node true to the node object.
    $vars['ds_node'] = TRUE;
  }
}

/**
 * Implements template_preprocess_node().
 */
function europa_preprocess_node(&$vars) {
  $vars['submitted'] = '';
  if (theme_get_setting('display_submitted')) {
    $vars['submitted'] = t('Submitted by !username on !datetime', array(
      '!username' => $vars['name'],
      '!datetime' => $vars['date'],
    ));
  }
  $vars['messages'] = theme('status_messages');
}


/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function europa_menu_tree__secondary(&$variables) {
  return '<ul class="menu nav navbar-nav secondary">' . $variables['tree'] . '</ul>';
}

/**
 * Implements preprocess for theme('easy_breadcrumb').
 */
function europa_preprocess_easy_breadcrumb(&$variables) {
  $variables['separator'] = '&raquo;';
}

/**
 * Overrides theme('easy_breadcrumb').
 */
function europa_easy_breadcrumb($variables) {

  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $separator = $variables['separator'];

  $html = '';

  // We don't print out "Home" if it's the only breadcrumb component.
  if ($segments_quantity > 1) {

    $html .= '<ol class="breadcrumb">';

    for ($i = 0, $s = $segments_quantity - 1; $i < $segments_quantity; ++$i) {
      $it = $breadcrumb[$i];
      $content = decode_entities($it['content']);
      if (isset($it['url'])) {
        $html .= '<li>' . l($content, $it['url'], array('attributes' => array('class' => $it['class'])))  . '</li>';
      }
      else {
        $class = implode(' ', $it['class']);
        $html .= '<li class="active ' . $class . '">' . $content . '</li>';
      }
      if ($i < $s) {
        $html .= '<span class="active breadcrumb-separator"> ' . $separator . ' </span>';
      }
    }

    $html .= '</ol>';
  }

  return $html;
}

/**
 * Implements hook_preprocess_image().
 */
function europa_preprocess_image(&$variables) {
  // Fix issue between print module and bootstrap theme, print module put a
  // string instead of an array in $variables['attributes']['class'].
  if ($shape = theme_get_setting('bootstrap_image_responsive')) {
    if (isset($variables['attributes']['class'])) {
      if (is_array($variables['attributes']['class'])) {
        $variables['attributes']['class'][] = 'img-responsive';
      }
      else {
        $variables['attributes']['class'] = array($variables['attributes']['class'], 'img-responsive');
      }
    }
  }
}

/**
 * Implements hook_bootstrap_colorize_text_alter().
 */
function europa_bootstrap_colorize_text_alter(&$texts) {
  $texts['contains'][t('Save')] = 'primary';
}

/**
 * Overrides theme_form_element().
 */
function europa_form_element(&$variables) {
  $element = &$variables['element'];
  $is_checkbox = FALSE;
  $is_radio = FALSE;
  $feedback_message = FALSE;

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  // Check for errors and set correct error class.
  if (isset($element['#parents']) && form_get_error($element)) {
    $attributes['class'][] = 'has-error';
    $feedback_message = '<p class="feedback-message is-error">' . form_get_error($element) . '</p>';
  }

  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
        ' ' => '-',
        '_' => '-',
        '[' => '-',
        ']' => '',
      ));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  if (!empty($element['#autocomplete_path']) && drupal_valid_path($element['#autocomplete_path'])) {
    $attributes['class'][] = 'form-autocomplete';
  }
  $attributes['class'][] = 'form-item';

  // See http://getbootstrap.com/css/#forms-controls.
  if (isset($element['#type'])) {
    if ($element['#type'] == "radio") {
      $attributes['class'][] = 'radio';
      $is_radio = TRUE;
    }
    elseif ($element['#type'] == "checkbox") {
      $attributes['class'][] = 'checkbox';
      $is_checkbox = TRUE;
    }
    else {
      $attributes['class'][] = 'form-group';
    }
  }

  // Putting description into variable since it is not going to change.
  // Here Bootstrap tooltips have been removed since in current implemenation we
  // will use descriptions that are displayed under <label> element.

  if (!empty($element['#description'])) {
    $description = '<p class="help-block">' . $element['#description'] . '</p>';
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  $prefix = '';
  $suffix = '';
  if (isset($element['#field_prefix']) || isset($element['#field_suffix'])) {
    // Determine if "#input_group" was specified.
    if (!empty($element['#input_group'])) {
      $prefix .= '<div class="input-group">';
      $prefix .= isset($element['#field_prefix']) ? '<span class="input-group-addon">' . $element['#field_prefix'] . '</span>' : '';
      $suffix .= isset($element['#field_suffix']) ? '<span class="input-group-addon">' . $element['#field_suffix'] . '</span>' : '';
      $suffix .= '</div>';
    }
    else {
      $prefix .= isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
      $suffix .= isset($element['#field_suffix']) ? $element['#field_suffix'] : '';
    }
  }

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);

      if (!empty($description)) {
        $output .= $description;
      }

      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      $output .= $feedback_message;

      break;

    case 'after':

      if ($is_radio || $is_checkbox) {
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
      }
      else {
        $variables['#children'] = ' ' . $prefix . $element['#children'] . $suffix;
      }

      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      $output .= $feedback_message;

      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      if (!empty($description)) {
        $output .= $description;
      }

      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      $output .= $feedback_message;

      break;
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Europa theme wrapper function for the service tools menu links.
 */
function europa_menu_tree__menu_service_tools(&$variables) {
  return '<ul class="menu nav footer-menu list-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Europa theme wrapper function for the EC menu links.
 */
function europa_menu_tree__menu_european_commission_links(&$variables) {
  return '<ul class="menu nav footer-menu list-inline footer-menu__bottom-border">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_html_head_alter().
 */
function europa_html_head_alter(&$head_elements) {
  // Creating favicons links and meta tags for the html header.
  $europa_theme_png_path = base_path() . drupal_get_path('theme', 'europa') . '/images/png/favicon/';
  $elements = array(
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '57x57',
        'href' => 'apple-touch-icon-57x57.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '60x60',
        'href' => 'apple-touch-icon-60x60.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '114x114',
        'href' => 'apple-touch-icon-114x114.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '120x120',
        'href' => 'apple-touch-icon-120x120.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '144x144',
        'href' => 'apple-touch-icon-144x144.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '152x152',
        'href' => 'apple-touch-icon-152x152.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '180x180',
        'href' => 'apple-touch-icon-180x180.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '32x32',
        'href' => 'favicon-32x32.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '192x192',
        'href' => 'android-chrome-192x192.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '96x96',
        'href' => 'favicon-96x96.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '16x16',
        'href' => 'favicon-16x16.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileColor',
        'content' => '#034ea1',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileImage',
        'content' => $europa_theme_png_path . 'mstile-144x144.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'theme-color',
        'content' => '#034ea1',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square70x70logo',
        'content' => $europa_theme_png_path . 'mstile-70x70.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square150x150logo',
        'content' => $europa_theme_png_path . 'mstile-150x150.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-wide310x150logo',
        'content' => $europa_theme_png_path . 'mstile-310x150.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square310x310logo',
        'content' => $europa_theme_png_path . 'mstile-310x310.png',
      ),
    ),

  );
  foreach ($elements as $element) {
    $element['#type'] = 'html_tag';
    if (isset($element['#attributes']['href'])) {
      $element['#attributes']['href'] = $europa_theme_png_path . $element['#attributes']['href'];
    }
    $head_elements[] = $element;
  }
}

/**
 * Helper function for display 'meta' view mode field.
 */
function _europa_field_component_listing($variables) {
  $output = '';
  $output .= '<div class="listing">';

  foreach ($variables['items'] as $delta => $item) {
    $output .= '<div class="listing__item">' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';
  return $output;
}

/**
 * Helper function for display 'title' view mode field.
 */
function _europa_field_component_listing_title($variables) {
  $output = '';
  $output .= '<ul class="listing listing--title">';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<li class="listing__item"><h3 class="listing__title">' . drupal_render($item) . '</h3></li>';
  }
  $output .= '</ul>';
  return $output;
}

/**
 * Override of theme_field().
 */
function europa_field($variables) {
  $element = $variables['element'];
  $field_type = isset($element['#field_type']) ? $element['#field_type'] : NULL;
  switch ($field_type) {
    case 'entityreference':
      // First node from entity reference.
      $reference = array_shift($element[0]);
      $first_node = is_array($reference) ? array_shift($reference) : NULL;
      if (isset($first_node['#view_mode'])) {
        switch ($first_node['#view_mode']) {
          case 'title':
            return _europa_field_component_listing_title($variables);

          case 'meta':
            return _europa_field_component_listing($variables);
        }
      }

      break;
  }
}
