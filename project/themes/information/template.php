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
 * Returns the path to the language specific logo.
 *
 * @param string $langcode
 *   Optional language code for the logo. Defaults to the current language.
 *
 * @return string
 *   The path to the logo in the given language.
 */
function information_logo_path($langcode = NULL) {
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
 * Implements template_preprocess_html().
 */
function information_preprocess_html(&$vars) {
  drupal_add_css(path_to_theme() . '/css/ie8.css', array(
    'group' => CSS_THEME,
    'browsers' => array('IE' => 'IE 8', '!IE' => FALSE),
    'preprocess' => FALSE,
  ));
  $vars['head_title'] = _commissioner_meta_title();
}
