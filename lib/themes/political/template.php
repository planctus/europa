<?php
/**
 * @file
 * template.php
 */


/**
 * Implements hook_preprocess_page().
 */
function political_preprocess_page(&$variables) {
  // Prepare the url for the "external" homepage.
  global $language;
  $delimiter = variable_get('language_suffix_delimiter', '_');
  $suffix = $delimiter . $language->prefix;
  // Set a variable containing the external url to point to.
  $variables['front_page'] = 'http://ec.europa.eu/index' . $suffix . '.htm';
}
