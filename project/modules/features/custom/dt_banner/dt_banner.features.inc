<?php
/**
 * @file
 * dt_banner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_banner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}