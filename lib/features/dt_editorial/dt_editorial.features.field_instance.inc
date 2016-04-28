<?php
/**
 * @file
 * dt_editorial.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dt_editorial_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-editorial_team-field_editorial_types'.
  $field_instances['node-editorial_team-field_editorial_types'] = array(
    'bundle' => 'editorial_team',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Content types that are managed by this Editorial team.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_editorial_types',
    'label' => 'Group Content types',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 100,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content types that are managed by this Editorial team.');
  t('Group Content types');

  return $field_instances;
}
