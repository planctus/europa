<?php
/**
 * @file
 * dt_pri_policy_area.features.field_base.inc
 */

/**
 * Implements hook_field_info_field_bases().
 */
function dt_pri_policy_area_field_info_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_priority_policy_area_status'
  $field_bases['field_priority_policy_area_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_priority_policy_area_status',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'null' => 'no status',
        'planned' => 'planned',
        'open' => 'open',
        'closed' => 'closed',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_priority_policy_area_type'
  $field_bases['field_priority_policy_area_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_priority_policy_area_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'consultation' => 'consultation',
        'impact_assessment' => 'impact assessment',
        'tender' => 'tender',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
