<?php

/**
 * @file
 * cwt_translation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_translation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
