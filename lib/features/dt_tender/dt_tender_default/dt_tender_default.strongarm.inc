<?php

/**
 * @file
 * dt_tender_default.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_tender_default_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_tender_pattern';
  $strongarm->value = 'tender/[node:source:title]';
  $export['pathauto_node_tender_pattern'] = $strongarm;

  return $export;
}
