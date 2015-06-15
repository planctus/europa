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
  switch ($vars['element']['#field_name']) {
    case 'field_core_ecorganisation':
      $field_value = $vars['element']['#items'][0]['value'];
      $field_value_stripped = substr($field_value, 0, strpos($field_value, " ("));

      $vars['items'][0]['#markup'] = $field_value_stripped;
      break;

    case 'field_core_social_network_links':
      $vars['element']['before'] = t('Follow the latest progress and learn more about getting involved.');
      $vars['element']['after'] = l(t('Other social networks'), 'http://europa.eu/contact/social-networks/index_en.htm');
      break;
  }
}

/**
 * Implements template_preprocess_block().
 */
function europa_preprocess_block(&$vars) {
  $block = $vars['block'];

  switch ($block->delta) {
    case 'nexteuropa_feedback':
      $vars['classes_array'][] = 'block--full-width';
      break;

    case 'menu-dt-menu-social-media':
      $block->subject = t('The European Commission on:');
      break;

    case 'menu-dt-service-links':
      $block->subject = '';
      break;
  }

  if (isset($block->bid) && $block->bid === 'language_selector_site-language_selector_site') {
    // Initialize variables.
    $code = '<span class="lang-select-site__code"><span class="icon icon--language lang-select-site__icon"></span><span class="lang-select-site__code-text">' . $vars['elements']['code']['#markup'] . '</span></span>';
    $label = '<span class="lang-select-site__label">' . $vars['elements']['label']['#markup'] . '</span>';
    $options = array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('lang-select-site__link'),
      ),
      'query' => array(drupal_get_destination()),
    );

    // Add class to block.
    $vars['classes_array'][] = 'lang-select-site';

    // Add content to block.
    $vars['content'] = l($label . $code, 'splash', $options);
  }

  // Replace block-title class with block__title in order to keep BEM structure
  // of classes.
  $block_title_class = array_search('block-title', $vars['title_attributes_array']['class']);
  if ($block_title_class !== FALSE) {
    unset($vars['title_attributes_array']['class'][$block_title_class]);
  }
  $vars['title_attributes_array']['class'][] = 'block__title';

  if (isset($block->bid)) {
    // Check if the block is a exposed form.
    // This is checked by looking at the $block->bid which in case
    // of views exposed filters, always contains 'views--exp-' string.
    if (strpos($block->bid, 'views--exp-') !== FALSE) {
      $vars['classes_array'][] = 'filters';
      $vars['title_attributes_array']['class'][] = 'filters__title';
      $block->subject = t('Refine results');

      // Passing block id to Drupal.settings in order to pass it through data
      // attribute in the collapsible panel.
      drupal_add_js(array('europa' => array('exposedBlockId' => $vars['block_html_id'])), 'setting');

      // Adding filters.js file.
      drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/filters/filters.js');
    }
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

  // Checking if exposed filters are set and add variable that stores active
  // filters.
  if (module_exists('dt_exposed_filter_data')) {
    $vars['active_filters'] = get_exposed_filter_output();
  }
  $content_type = array();
  $content_type_filters = $view->filter['type']->value;
  foreach ($content_type_filters as $filter) {
    $content_type = $filter;
  }

  $vars['items_count'] = '';
  // Checking if .listing exists in classes_array so that result count can be
  // displayed.
  if ((in_array('listing', $vars['classes_array'])) && isset($view->exposed_data)) {
    // Calculate the number of items displayed in a view listing.
    $total_rows = !$view->total_rows ? count($view->result) : $view->total_rows;

    if ($total_rows == 0) {
      $items_count = t("No @content_types", array('@content_type' => $content_type));
    }
    else {
      $items_count = $total_rows . ' ' . format_plural($total_rows, $content_type, t('@content_types', array('@content_type' => $content_type)));
    }

    $vars['items_count'] = $items_count;
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
function europa_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-md-6"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-md-9"';
  }
  else {
    $variables['content_column_class'] = ' class="col-md-12"';
  }

  // Set footer region column classes.
  if (!empty($variables['page']['footer_right'])) {
    $variables['footer_column_class'] = 'col-sm-8';
  }
  else {
    $variables['footer_column_class'] = 'col-sm-12';
  }

  $node = &$variables['node'];

  if (isset($node)) {
    // Adding generic introduction field to be later rendered in page template.
    $variables['field_core_introduction'] = field_view_field('node', $node, 'field_core_introduction', array('label' => 'hidden'));

    // Check if Display Suite is handling node.
    if (ds_get_layout('node', $node->type, 'full')) {
      // This disables message-printing on ALL page displays.
      $variables['show_messages'] = FALSE;

      // Add tabs to node object so we can put it in the DS template instead.
      if (isset($variables['tabs'])) {
        $node->local_tabs = drupal_render($variables['tabs']);
      }

      $variables['theme_hook_suggestions'][] = 'page__ds_node';
    }
  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter() for views exposed form.
 */
function europa_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form') {
    // Button value change on all the views exposed forms is due to a
    // design/ux requirement which uses the 'Refine results' label for all the
    // filter forms.
    $form['submit']['#value'] = t('Refine results');
    $form['submit']['#attributes']['class'][] = 'btn-primary';
    $form['submit']['#attributes']['class'][] = 'filters__btn-submit';
    $form['reset']['#attributes']['class'][] = 'filters__btn-reset';
    $form['type']['#options']['All'] = t("All types");
    $form['department']['#options']['All'] = t("All departments");
    $form['date_before']['value']['#date_format'] = variable_get('date_format_ec_date_j_f_y', "j F Y");
    $form['date_after']['value']['#date_format'] = variable_get('date_format_ec_date_j_f_y', "j F Y");
  }
}

/**
 * Implements hook_date_popup_process_alter().
 * @param $element
 * @param $form_state
 * @param $context
 */
function europa_date_popup_process_alter(&$element, &$form_state, $context) {
  // Removing the description from the datepicker.
  unset($element['date']['#description']);
  unset($element['time']['#description']);
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

  // Override node_url if Legacy Link is set.
  if (isset($vars['path']['legacy'])) {
    $vars['node_url'] = $vars['path']['legacy'];
  }
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
        $html .= '<li>' . l($content, $it['url'], array('attributes' => array('class' => $it['class']))) . '</li>';
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
function europa_menu_tree__menu_dt_service_links(&$variables) {
  return '<ul class="footer__menu footer__menu--separator menu nav list-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Europa theme wrapper function for the EC menu links.
 */
function europa_menu_tree__menu_dt_menu_social_media(&$variables) {
  return '<ul class="footer__menu menu nav list-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Helper applying BEM to footer menu item links.
 *
 * @param $variables
 *
 * @return string
 */
function _europa_menu_link__footer(&$variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $element['#attributes']['class'][] = 'footer__menu-item';

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements theme_menu_link().
 *
 * @param $variables
 *
 * @return string
 */
function europa_menu_link__menu_dt_service_links(&$variables) {
  return _europa_menu_link__footer($variables);
}

/**
 * Implements theme_menu_link().
 *
 * @param $variables
 *
 * @return string
 */
function europa_menu_link__menu_dt_menu_social_media(&$variables) {
  return _europa_menu_link__footer($variables);
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
function _europa_field_component_listing($variables, $config) {
  $config += array(
    'modifier' => 'default',
    'wrapper_modifier' => '',
    'layout' => 'default',
    'listing_wrapper_element' => 'div',
    'item_wrapper_element' => 'div',
  );

  $modifier_class = ' ' . trim($config['modifier']);
  $wrapper_class = $config['modifier'] == 'default' ? '' : ' listing__wrapper--' . $config['layout'];
  $wrapper_class .= ' ' . trim($config['wrapper_modifier']);

  $columns_num = 1;
  if ($config['layout'] == 'two_columns') {
    $columns_num = 2;
  }
  elseif ($config['layout'] == 'three_columns') {
    $columns_num = 3;
  }

  // Distribute them into columns.
  $counter = 1;
  $current_column = 0;
  $total = count($variables['items']);
  $columns = array();
  $max_items_in_column = array();

  for ($i = 0; $i < $columns_num; $i++) {
    $max_items_in_column[] = floor(($total + $columns_num - ($i + 1)) / $columns_num);
  }

  $counter = 0;
  for ($i = 0; $i < $columns_num; $i++) {
    for ($j = 0; $j < $max_items_in_column[$i]; $j++) {
      $item = $variables['items'][$counter];
      // Row content.
      switch ($config['modifier']) {
        case 'title':
          $rendered_item = '<h3 class="listing__title">' . drupal_render($item) . '</h3>';
          break;

        default:
          $rendered_item = drupal_render($item);
          break;
      }
      $columns[$i][] = '<' . $config['item_wrapper_element'] . ' class="listing__item">' . $rendered_item . '</' . $config['item_wrapper_element'] . '>';
      $counter++;
    }
  }

  // Assemble the markup.
  $output = '<div class="listing__wrapper' . $wrapper_class . '">';
  foreach ($columns as $column) {
    $output .= '<' . $config['listing_wrapper_element'] . ' class="listing' . $modifier_class . '">';
    foreach ($column as $item) {
      $output .= $item;
    }
    $output .= '</' . $config['listing_wrapper_element'] . '>';
  }
  $output .= '</div>';

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
      $reference = '';
      if (isset($element[0])) {
        $reference = array_shift($element[0]);
      }
      $first_node = is_array($reference) ? array_shift($reference) : NULL;
      $settings = array();
      $settings['layout'] = isset($variables['nexteuropa_ds_layouts_columns']) ? $variables['nexteuropa_ds_layouts_columns'] : FALSE;
      $settings['wrapper_modifier'] = isset($variables['nexteuropa_ds_layouts_modifier']) ? $variables['nexteuropa_ds_layouts_modifier'] : '';

      // Custom listing settings based on view mode.
      if (isset($first_node['#view_mode'])) {
        switch ($first_node['#view_mode']) {
          case 'title':
            $settings['modifier'] . 'listing--title';
            $settings['wrapper_modifier'] .= ' listing--title__wrapper';
            $settings['listing_wrapper_element'] = 'ul';
            $settings['item_wrapper_element'] = 'li';
            break;

          case 'teaser':
            $settings['modifier'] = 'listing--teaser';
            $settings['wrapper_modifier'] .= ' listing--teaser__wrapper';
            break;
        }
        
        return _europa_field_component_listing($variables, $settings);
      }

      break;
  }
}

/**
 * Implements hook_css_alter().
 */
function europa_css_alter(&$css) {
  unset(
    $css[drupal_get_path('module', 'date') . '/date_api/date.css']
  );
}

/**
 * A search_form alteration.
 */
function europa_form_nexteuropa_europa_search_search_form_alter(&$form, &$form_state, $form_id) {
  $form['search_input_group']['#prefix'] = '';
  $form['search_input_group']['#suffix'] = '';
  $form['search_input_group']['europa_search_submit']['#attributes']['class'][] = 'search-form__btn';
  $form['search_input_group']['QueryText']['#attributes']['class'][] = 'search-form__textfield';
}
