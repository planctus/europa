<?php

/**
 * @file
 * dt_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
