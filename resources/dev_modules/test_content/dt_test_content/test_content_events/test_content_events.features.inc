<?php

/**
 * @file
 * test_content_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function test_content_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return ["version" => "1"];
  }
}
