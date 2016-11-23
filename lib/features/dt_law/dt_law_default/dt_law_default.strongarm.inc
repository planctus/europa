<?php

/**
 * @file
 * dt_law_default.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_law_default_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_law_pattern';
  $strongarm->value = 'law/[node:field-core-parents:0:url:path]/[node:source:title]';
  $export['pathauto_node_law_pattern'] = $strongarm;

  return $export;
}
