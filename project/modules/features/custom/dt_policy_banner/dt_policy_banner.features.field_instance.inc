<?php
/**
 * @file
 * dt_policy_banner.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dt_policy_banner_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-policy_banner-group_content_access'
  $field_instances['node-policy_banner-group_content_access'] = array(
    'bundle' => 'policy_banner',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'group_content_access',
    'label' => 'Group content visibility',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
    'widget_type' => 'options_select',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Group content visibility');

  return $field_instances;
}
