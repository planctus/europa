<?php
/**
 * @file
 * dt_page_default.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_page_default_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_basic_page_pattern';
  $strongarm->value = '[node:field-core-parent:url:path]/[node:source:title]';
  $export['pathauto_node_basic_page_pattern'] = $strongarm;

  return $export;
}
