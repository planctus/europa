<?php

/**
 * @file
 * template.php
 */

/**
 * Implements tempalate_preprocess_page().
 */
function political_preprocess_page(&$variables) {
  // Prepare the url for the "external" homepage.
  global $language;
  $delimiter = variable_get('language_suffix_delimiter', '_');
  $suffix = $delimiter . $language->prefix;
  // Set a variable containing the external url to point to.
  $variables['front_page'] = 'http://ec.europa.eu/index' . $suffix . '.htm';

  // Update logo class if node is info_homepage.
  $contexts = context_active_contexts();
  if (array_key_exists('homepage-content-type-pages', $contexts)) {
    $variables['logo_classes'] = "logo logo--logotypebelow site-header__logo";
    $variables['theme_hook_suggestions'][] = 'page__front__ds_node';
    unset($variables['page']['header']['nexteuropa_europa_search_nexteuropa_europa_search_form']);
  }
}

/**
 * Implements hook_context_load_alter().
 */
function political_context_load_alter(&$context) {
  if ($context->name == 'dt_core_non_homepage_pages') {
    unset($context->conditions['path']);
  }
}
