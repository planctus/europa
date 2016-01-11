<?php
/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_html().
 */
function political_preprocess_html(&$variables) {
  // Remove the .front class from the body and pretend it's not the home page.
  if ($variables['is_front']) {
    $key = array_search('front', $variables['classes_array']);
    unset($variables['classes_array'][$key]);
  }
}


/**
 * Implements hook_preprocess_page().
 */
function political_preprocess_page(&$variables) {
  // Unset the home page.
  $variables['is_front'] = FALSE;

  // Prepare the url for the "external" homepage.
  global $language;
  $delimiter = variable_get('language_suffix_delimiter', '_');
  $suffix = $delimiter . $language->prefix;
  // Set a variable containing the external url to point to.
  $variables['front_page'] = 'http://ec.europa.eu/index' . $suffix . '.htm';
}

/**
 * Implements of hook_context_load_alter().
 */
function political_context_load_alter(&$context) {
  if ($context->name == 'dt_core_non_homepage_pages') {
    unset($context->conditions['path']);
  }
}
