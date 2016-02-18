<?php
/**
 * @file
 * dt_list_view_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_list_view_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
