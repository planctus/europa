<?php
/**
 * @file
 * template.php
 */

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
 * Implements hook_form_BASE_FORM_ID_alter()
 */
function europa_form_node_form_alter(&$form, &$form_state, $form_id) {

  // Eventually remove field from vertical tabs or other similar groupings.
  $node_form_sidebar = theme_get_setting('node_form_sidebar');
  if ($node_form_sidebar) {
    foreach ($node_form_sidebar as $field_name) {
      $form[$field_name]['#group'] = NULL;
    }
  }
}

/**
 * Preprocessor for theme('node_form').
 */
function europa_preprocess_node_form(&$variables) {

  $i = 100;
  $variables['sidebar'] = array();
  $node_form_sidebar = theme_get_setting('node_form_sidebar');
  if ($node_form_sidebar) {
    foreach ($node_form_sidebar as $field_name) {
      if (isset($variables['form'][$field_name])) {
        $variables['form'][$field_name]['#weight'] = $i++;
        $variables['sidebar'][$field_name] = $variables['form'][$field_name];
        hide($variables['form'][$field_name]);
      }
    }
  }
  // Extract the form buttons, and put them in independent variable.
  $variables['buttons'] = $variables['form']['actions'];
  hide($variables['form']['actions']);
}


/**
 * Overrides theme_form_required_marker()
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
 * Implementation of preprocess_node().
 */
function europa_preprocess_node(&$vars) {
  $vars['submitted'] = '';
  if (theme_get_setting('display_submitted')) {
    $vars['submitted'] = t('Submitted by !username on !datetime', array(
      '!username' => $vars['name'],
      '!datetime' => $vars['date'],
    ));
  }
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function europa_menu_tree__secondary(&$variables) {
  return '<ul class="menu nav navbar-nav secondary">' . $variables['tree'] . '</ul>';
  // global $user;
  // $username = format_username($user);
  // $toggle = t('Hello, !name', array('!name' => "<b>{$username}</b>"));
  // return '
  //    <ul class="nav navbar-nav navbar-right">
  //      <li class="dropdown">
  //        <a href="#" class="dropdown-toggle" data-toggle="dropdown">' . $toggle . ' <b class="caret"></b></a>
  //        <ul class="dropdown-menu">' . $variables['tree'] . '</ul>
  //      </li>
  //    </ul>';
}

/**
 * Implements preprocess for theme('easy_breadcrumb')
 */
function europa_preprocess_easy_breadcrumb(&$variables) {
  $variables['separator'] = '&raquo;';
}

/**
 * Overrides theme('easy_breadcrumb')
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
  // Fix issue between print module and bootstrap theme, print module put a string instead of an array in $variables['attributes']['class']
  if ($shape = theme_get_setting('bootstrap_image_responsive')) {
    if(isset($variables['attributes']['class'])) {
      if(is_array($variables['attributes']['class'])) {
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
    $feedback_message = '<p class="feedback-message has-error">' . form_get_error($element) . '</p>';
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

      //if (form_get_error($element)) {
        $output .= $feedback_message;
      //}
      break;

    case 'after':

      if ($is_radio || $is_checkbox) {
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
      }
      else {
        $variables['#children'] = ' ' . $prefix . $element['#children'] . $suffix;
      }

      $output .= ' ' . theme('form_element_label', $variables) . "\n";

      //if (form_get_error($element)) {
        $output .= $feedback_message;
      //}
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      if (!empty($description)) {
        $output .= $description;
      }

      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";

      //if (form_get_error($element)) {
        $output .= $feedback_message;
      //}
      break;
  }

  $output .= "</div>\n";

  return $output;
}