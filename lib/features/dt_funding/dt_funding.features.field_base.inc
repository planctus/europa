<?php
/**
 * @file
 * dt_funding.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_funding_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_funding_status'.
  $field_bases['field_funding_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_funding_status',
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
        'planned' => 'planned',
        'proposed' => 'proposed',
        'adopted' => 'adopted',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
