<?php
/**
 * @file
 * template.php
 */

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function information_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form') {
    $form['type']['#options']['All'] = t("All types");
    $form['department']['#options']['All'] = t("All departments");
    $form['policy_area']['#options']['All'] = t("All policy areas");
  }
}

/**
 * Implements hook_preprocess_page().
 */
function information_preprocess_page(&$variables) {
  // Temporary variable that should be removed once the beta notification
  // is gone.
  $variables['node_about_beta'] = url('node/1108');
}

/**
 * Implements hook_preprocess_field().
 */
function information_preprocess_field(&$variables) {
  // Changing label for the field to display stripped out values.
  switch ($variables['element']['#field_name']) {
    case 'field_core_ecorganisation':
      $field_value = $variables['element']['#items'][0]['value'];
      $field_value_stripped = explode(" (", $field_value);

      $variables['items'][0]['#markup'] = $field_value_stripped[0];
      break;
  }
}

/**
 * Override theme_easy_breadcrumb().
 */
function information_easy_breadcrumb($variables) {
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
      $classes[] = 'breadcrumb__segment';

      $attributes = array(
        'class' => array('breadcrumb__link'),
      );

      if ($i == 0) {
        $classes[] = 'breadcrumb__segment--first';
        $attributes['class'][] = 'is-internal';
        $attributes += array('rel' => 'home');
      }
      elseif ($i == ($s - 1)) {
        $classes[] = 'breadcrumb__segment--last';
      }

      $content = '<span class="breadcrumb__text">' . check_plain(decode_entities($item['content'])) . '</span>';
      $class = implode(' ', $classes);
      if (isset($item['url'])) {
        $full_item = l($content, $item['url'], array('attributes' => $attributes, 'html' => TRUE));
      }
      else {
        $full_item = '<span class="' . $class . '">' . $content . '</span>';
      }

      // TODO: Check if the active class actually appears.
      $element_visibility = in_array('active', $classes) ? ' element-invisible' : '';
      $html .= '<li class="' . $class . $element_visibility . '">' . $full_item . '</li>';
    }

    $html .= '</ol></nav>';

    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/breadcrumb.js');
  }
  return $html;
}