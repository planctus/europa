<?php
/**
 * @file
 * dt_editorial.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_editorial_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_editorial_types'.
  $field_bases['field_editorial_types'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_editorial_types',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '_dt_editorial_types_allowed',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
