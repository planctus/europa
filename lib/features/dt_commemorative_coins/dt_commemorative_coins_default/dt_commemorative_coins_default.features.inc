<?php
/**
 * @file
 * dt_commemorative_coins_default.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_commemorative_coins_default_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dt_commemorative_coins_default_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
