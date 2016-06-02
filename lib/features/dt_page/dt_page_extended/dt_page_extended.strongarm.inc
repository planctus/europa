<?php
/**
 * @file
 * dt_page_extended.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_page_extended_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_basic_page_pattern';
  $strongarm->value = '[node:field-core-parents:0:url:path]/[node:source:title]';
  $export['pathauto_node_basic_page_pattern'] = $strongarm;

  return $export;
}
