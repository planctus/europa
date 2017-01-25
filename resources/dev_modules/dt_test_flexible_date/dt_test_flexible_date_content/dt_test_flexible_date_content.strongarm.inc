<?php
/**
 * @file
 * dt_test_flexible_date_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_test_flexible_date_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_node_dt_test_content_type';
  $strongarm->value = 'dt_test_content_type';
  $export['uuid_features_entity_node_dt_test_content_type'] = $strongarm;

  return $export;
}
