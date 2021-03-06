<?php
/**
 * @file
 * dt_pri_policy_area.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_pri_policy_area_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_core_pri_policy_area'.
  $field_bases['field_core_pri_policy_area'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_core_pri_policy_area',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'extended_base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'priority_policy_area' => 'priority_policy_area',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
