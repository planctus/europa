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
      $field_value_stripped = explode(" (", $field_value);

      $vars['items'][0]['#markup'] = $field_value_stripped[0];
      break;

    case 'field_core_social_network_links':
      $vars['element']['before'] = t('Follow the latest progress and get involved.');
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
        'data-toggle' => 'popover',
        'data-placement' => 'bottom',
        'data-trigger' => 'focus',
        'data-content' => t('This function is not yet working in Beta.'),
      ),
      'query' => array(drupal_get_destination()),
    );

    // Add class to block.
    $vars['classes_array'][] = 'lang-select-site';

    // Add content to block.
    $vars['content'] = l($label . $code, 'splash', $options);

    // For Beta initial release only: preventing default click behavior.
    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/misc/popovers.js');
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
      drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/filters.js');
    }
  }

  if ($block->delta == 'inline_navigation') {
    $vars['classes_array'][] = 'inpage-nav__wrapper';
    $vars['title_attributes_array']['class'][] = 'inpage-nav__block-title';
  }
}

/**
 * Returns an array with singular and plural form of a bundle.
 *
 * @param string $bundle
 *   Machine name of a bundle.
 *
 * @return array $forms
 *   Containing $forms['singular'] and $forms['plural'].
 */
function _europa_bundle_forms($bundle) {
  // Forming plurals for existing content types.
  $plurals = array(
    'announcement' => t("announcements"),
    'page' => t("pages"),
    'contact' => t("contacts"),
    'department' => t("departments"),
    'editorial_team' => t("editorial teams"),
    'file' => t("files"),
    'basic_page' => t("pages"),
    'person' => t("people"),
    'policy' => t("policies"),
    'policy_area' => t("policy areas"),
    'policy_implementation' => t("policy implementations"),
    'policy_input' => t("policy inputs"),
    'policy_keyfile' => t("policy key files"),
    'priority' => t("priorities"),
    'publication' => t("publications"),
    'class' => t("classes"),
    'topic' => t("topics"),
    'toplink' => t("top links"),
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
 * Implements template_preprocess_views_view().
 */
function europa_preprocess_views_view(&$vars) {
  $view = $vars['view'];

  if ($view->style_plugin->definition['theme'] == 'views_view_unformatted') {
    $vars['classes_array'][] = 'listing';

    if (isset($view->style_plugin->row_plugin->options['view_mode'])) {
      $view_mode = $view->style_plugin->row_plugin->options['view_mode'];
      $vars['classes_array'][] = 'listing--' . $view_mode;
    }
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

    $content_type_forms = _europa_bundle_forms($content_type);

    if ($total_rows == 0) {
      $items_count = t("No @items", array('@items' => $content_type_forms['plural']));
    }
    else {
      $items_count = $total_rows . ' ' .
        format_plural($total_rows, $content_type_forms['singular'], $content_type_forms['plural']);
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
    $variables['content_column_class'] = 'col-md-6';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = 'col-md-9';
  }
  else {
    $variables['content_column_class'] = 'col-md-12';
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
    $variables['field_core_introduction'] = isset($node->field_core_introduction) ?
      field_view_field('node', $node, 'field_core_introduction', array('label' => 'hidden')) :
      NULL;

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

  // Temporary variable that should be removed once the beta notification
  // is gone.
  $variables['node_about_beta'] = url('node/1108');
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
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
    $form['policy_area']['#options']['All'] = t("All policy areas");
    $form['date_before']['value']['#date_format'] = variable_get('date_format_ec_date_j_f_y', "j F Y");
    $form['date_after']['value']['#date_format'] = variable_get('date_format_ec_date_j_f_y', "j F Y");
  }
}

/**
 * Implements hook_date_popup_process_alter().
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
  if (isset($vars['legacy'])) {
    $vars['node_url'] = $vars['legacy'];
  }
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function europa_menu_tree__secondary(&$variables) {
  return '<ul class="menu nav navbar-nav secondary">' . $variables['tree'] . '</ul>';
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
 * @param array $variables
 *   Link render array.
 *
 * @return string
 *   HTML markup
 */
function _europa_menu_link__footer(array &$variables) {
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
 * Override theme_menu_link().
 */
function europa_menu_link__menu_dt_service_links(&$variables) {
  return _europa_menu_link__footer($variables);
}

/**
 * Override theme_menu_link().
 */
function europa_menu_link__menu_dt_menu_social_media(&$variables) {

  return _europa_menu_link__footer($variables);
}

/**
 * Override hook_html_head_alter().
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
 * Helper function for display listings.
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
  if ($config['layout'] == 'two-columns') {
    $columns_num = 2;
  }
  elseif ($config['layout'] == 'three-columns') {
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
      switch ($config['view_mode']) {
        case 'title':
          $rendered_item = '' . drupal_render($item) . '';
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
      $layout_name = isset($variables['nexteuropa_ds_layouts_columns']) ? $variables['nexteuropa_ds_layouts_columns'] : FALSE;
      $layout_name_clean = str_replace('_', '-', $layout_name);

      $settings = array();
      $settings['view_mode'] = $first_node['#view_mode'];
      $settings['layout'] = $layout_name_clean;
      $settings['modifier'] = isset($variables['nexteuropa_ds_layouts_modifier']) ? $variables['nexteuropa_ds_layouts_modifier'] : '';
      $settings['wrapper_modifier'] = isset($variables['nexteuropa_ds_layouts_wrapper_modifier']) ? $variables['nexteuropa_ds_layouts_wrapper_modifier'] : '';

      // Custom listing settings based on view mode.
      $listing_view_modes = array('title', 'meta', 'teaser');
      if (isset($first_node['#view_mode']) && in_array($first_node['#view_mode'], $listing_view_modes)) {
        switch ($first_node['#view_mode']) {
          case 'title':
            $settings['modifier'] .= ' listing--title';
            $settings['wrapper_modifier'] .= ' listing--title__wrapper';
            $settings['listing_wrapper_element'] = 'ul';
            $settings['item_wrapper_element'] = 'li';
            break;

          case 'meta':
            $settings['modifier'] .= ' listing--meta';
            $settings['wrapper_modifier'] .= ' listing--meta__wrapper';

          case 'teaser':
            $settings['modifier'] .= ' listing--teaser';
            $settings['wrapper_modifier'] .= ' listing--teaser__wrapper';
            break;
        }

        return _europa_field_component_listing($variables, $settings);
      }

      break;
  }

  if (isset($element['#formatter'])) {
    switch ($element['#formatter']) {
      case 'context_nav_item':
        $output = '';

        // Render the items.
        foreach ($variables['items'] as $delta => $item) {
          $output .= drupal_render($item);
        }
        return $output;
    }
  }

  $output = '';
  $classes = array();

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field__label"' . $variables['title_attributes'] . '>' . $variables['label'] . '</div>';
    $classes[] = 'field--labeled';
  }

  // Render the items.
  $output .= '<div class="field__items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $output .= drupal_render($item);
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="field field--' . strtr($variables['element']['#field_name'], '_', '-') . ' ' . implode(' ', $classes) . '">' . $output . '</div>';

  return $output;
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
  // Popover to notify the user that the search is not fully functional.
  $form['search_input_group']['europa_search_submit']['#disabled'] = TRUE;
  $form['search_input_group']['QueryText']['#attributes']['data-toggle'][] = 'popover';
  $form['search_input_group']['QueryText']['#attributes']['data-placement'][] = 'bottom';
  $form['search_input_group']['QueryText']['#attributes']['data-trigger'][] = 'focus';
  $form['search_input_group']['QueryText']['#attributes']['data-content'][] = t('This function is not yet working in Beta.');
}

/**
 * Override theme_easy_breadcrumb().
 */
function europa_easy_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $html = '';

  if ($segments_quantity > 0) {
    $html .= '<nav id="breadcrumb" class="breadcrumb" role="navigation" aria-label="breadcrumbs">';
    $html .= '<span class="element-invisible">' . t('You are here') . ':</span>';
    $html .= '<ol class="breadcrumb__segments-wrapper">';

    for ($i = 0, $s = $segments_quantity; $i < $segments_quantity; ++$i) {
      $item = $breadcrumb[$i];

      // Removing classes from $item['class'] array and adding BEM classes.
      $classes = $item['class'];
      // $classes[] = 'breadcrumb__segment-' . ($i + 1);
      $classes[] = 'breadcrumb__segment';

      $attributes = array(
        'class' => array('breadcrumb__link'),
      );

      if ($i == 0) {
        $classes[] = 'breadcrumb__segment--first';
        $attributes += array('rel' => 'home');
      }
      elseif ($i == ($s - 1)) {
        $classes[] = 'breadcrumb__segment--last';
      }

      $content = '<span class="breadcrumb__text">' . check_plain(decode_entities($item['content'])) . '</span>';
      if (isset($item['url'])) {
        // Ugly hotfix.
        // TODO: Remove when following issue is fixed:
        // @see https://webgate.ec.europa.eu/CITnet/jira/browse/NEXTEUROPA-4457
        $item['url'] = $item['url'] == '<front>' ? '' : $item['url'];
        $full_item = l($content, $item['url'], array('attributes' => $attributes, 'html' => TRUE));
      }
      else {
        $full_item = '<span class="' . $class . '">' . $content . '</span>';
      }

      $class = implode(' ', $classes);

      // TODO:
      // Check if the active class actually appears.
      $element_visibility = in_array('active', $classes) ? ' element-invisible' : '';
      $html .= '<li class="' . $class . $element_visibility . '">' . $full_item . '</li>';
    }

    $html .= '</ol></nav>';

    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/breadcrumb.js');
  }
  return $html;
}

/**
 * Helper for providing markup to file component.
 *
 * @param object $file
 *   File object.
 * @param array $url
 *   Url depending on field type.
 *
 * @return string
 *   HTML markup.
 */
function _europa_file_markup($file, array $url) {
  $file_class = '';
  $file_icon_class = '';
  switch ($file->type) {
    case 'image':
      $file_class = 'file--image';
      $file_icon_class = 'icon--image';
      break;

    case 'audio':
      $file_class = 'file--audio';
      $file_icon_class = 'icon--audio';
      break;

    case 'video':
      $file_class = 'file--video';
      $file_icon_class = 'icon--video';
      break;

    default:
      $file_class = 'file--document';
      $file_icon_class = 'icon--file';
      break;
  }

  $file_icon = '<span class="file__icon icon ' . $file_icon_class . '"></span>';
  $file_size = '<span class="file__size">' . format_size($file->filesize) . '</span>';
  $file_name = $file->uri;
  $file_extension = strtoupper(pathinfo($file_name, PATHINFO_EXTENSION));

  $file_info = '<div class="file__info">' . $file_size . ' - ' . $file_extension . '</div>';

  // Use the description as the link text if available.
  if (!empty($file->description)) {
    $file_title = '<span class="file__title">' . $file->description . '</span>';
    $options['attributes']['title'] = check_plain($file->filename);
  }
  else {
    $file_title = '<span class="file__title">' . $file->filename . '</span>';
  }

  $file_metadata = '<div class="file__metadata">' . $file_title . $file_info . '</div>';

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
      'class' => array('file__btn', 'btn', 'btn-default'),
      'title' => check_plain($file->filename),
    ),
    'html' => TRUE,
  );

  $file_btn = l(t('Download'), $url['path'], array_merge($options, $url['options']));

  return '<div class="file ' . $file_class . '">' . $file_icon . $file_metadata . $file_btn . '</div>';
}

/**
 * Override theme_file_link().
 */
function europa_file_link($variables) {
  $file = $variables['file'];
  $url['path'] = file_create_url($file->uri);
  $url['options'] = array();

  return _europa_file_markup($file, $url);
}

/**
 * Override theme_file_entity_download_link().
 */
function europa_file_entity_download_link($variables) {
  $file = $variables['file'];
  $uri = file_entity_download_uri($file);

  return _europa_file_markup($file, $uri);
}

/**
 * Implements template_preprocess_bootstrap_tabs().
 */
function europa_preprocess_bootstrap_fieldgroup_nav(&$variables) {
  $group = &$variables['group'];

  $variables['nav_classes'] = '';

  switch ($group->format_settings['instance_settings']['bootstrap_nav_type']) {
    case 'tabs':
      $variables['nav_classes'] .= ' nav-tabs nav-tabs--with-content';
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
      $variables['panes'][$i]['title'] = check_plain(t($item['#title']));
      $i++;
    }
  }
}

/**
 * Overrides theme_link().
 */
function europa_link($variables) {
  // Link module creates absolute URLs for internal links as well, resulting
  // in having the external link icon on these internal links. We attempt to
  // re-convert these to relative.
  global $base_url;
  $internal_url = explode($base_url, $variables['path']);
  if (count($internal_url) > 1) {
    $variables['path'] = trim($internal_url[1], '/');
  }

  return theme_link($variables);
}

/**
 * Implements theme_pager().
 */
function europa_pager($variables) {
  drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/pager.js');

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

  $li_first = theme('pager_first', array(
    'text' => t('first'),
    'element' => $element,
    'parameters' => $parameters,
  ));
  $li_previous = theme('pager_previous', array(
    'text' => '<span class="sr-only">' . t('previous') . '</span>',
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
    'attributes' => array('class' => 'pager__btn'),
  ));
  $li_next = theme('pager_next', array(
    'text' => '<span>' . t('next') . '</span><span class="subtext">' . t('page %page', array(
        '%page' => $pager_current + 1,
      )) . '</span>',
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
    'attributes' => array('class' => 'pager__btn'),
  ));
  $li_last = theme('pager_last', array(
    'text' => t('last'),
    'element' => $element,
    'parameters' => $parameters,
    'attributes' => array('class' => 'pager__btn'),
  ));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager__previous pager__item'),
        'data' => $li_previous,
      );
    }
    $items[] = array(
      'class' => array('pager__combo pager__item'),
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
        'class' => array('pager__next pager__item'),
        'data' => $li_next,
      );
    }

    return '<h2 class="sr-only">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * Implements theme_pager_link().
 */
function europa_pager_link($variables) {
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
function europa_pager_first($variables) {
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
function europa_pager_previous($variables) {
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
function europa_pager_next($variables) {
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
function europa_pager_last($variables) {
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

