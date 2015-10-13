<?php
/**
 * @file
 * dt_STARTERKIT_DEFAULT.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_STARTERKIT_DEFAULT_ctools_plugin_api($module = NULL, $api = NULL) {
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
