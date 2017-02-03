<?php
/**
 * @file
 * dt_test_flexible_date.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_test_flexible_date_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_test_flexible_date'.
  $field_bases['field_test_flexible_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_test_flexible_date',
    'indexes' => array(),
    'locked' => 1,
    'module' => 'dt_flexible_date',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'dt_flexible_date',
  );

  return $field_bases;
}
