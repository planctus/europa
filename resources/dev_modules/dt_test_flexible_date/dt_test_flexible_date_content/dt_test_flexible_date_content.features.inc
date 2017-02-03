<?php
/**
 * @file
 * dt_test_flexible_date_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_test_flexible_date_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
