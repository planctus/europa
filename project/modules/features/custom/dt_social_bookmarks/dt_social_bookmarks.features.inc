<?php
/**
 * @file
 * dt_social_bookmarks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_social_bookmarks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
