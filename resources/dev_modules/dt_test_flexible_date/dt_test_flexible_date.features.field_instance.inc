<?php
/**
 * @file
 * dt_test_flexible_date.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dt_test_flexible_date_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-dt_test_content_type-body'.
  $field_instances['node-dt_test_content_type-body'] = array(
    'bundle' => 'dt_test_content_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'node-dt_test_content_type-field_test_flexible_date'.
  $field_instances['node-dt_test_content_type-field_test_flexible_date'] = array(
    'bundle' => 'dt_test_content_type',
    'default_value' => array(
      0 => array(
        'date' => NULL,
        'granularity' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => NULL,
        'settings' => array(),
        'type' => 'dt_flexible_date',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_test_flexible_date',
    'label' => 'test flexible date',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'dt_flexible_date',
      'settings' => array(),
      'type' => 'dt_flexible_date',
      'weight' => 42,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('test flexible date');

  return $field_instances;
}
