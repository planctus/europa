<?php

/**
 * @file
 * dt_policy_implementation.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_policy_implementation_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_policy_imp_introduction'.
  $field_bases['field_policy_imp_introduction'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_policy_imp_introduction',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_policy_imp_status'.
  $field_bases['field_policy_imp_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_policy_imp_status',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'null' => 'no status',
        'planned' => 'planned',
        'proposed' => 'proposed',
        'adopted' => 'adopted',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_policy_imp_type'.
  $field_bases['field_policy_imp_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_policy_imp_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'law' => 'law',
        'funding' => 'funding',
        'coordination' => 'coordination',
        'guidance' => 'guidance',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
