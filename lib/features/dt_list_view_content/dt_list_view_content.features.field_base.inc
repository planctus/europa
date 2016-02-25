<?php
/**
 * @file
 * dt_list_view_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_list_view_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_list_view_views'.
  $field_bases['field_list_view_views'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_list_view_views',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
