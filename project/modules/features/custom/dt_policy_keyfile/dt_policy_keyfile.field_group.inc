<?php
/**
 * @file
 * dt_policy_keyfile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_keyfile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_keyfile_content|node|policy_keyfile|form';
  $field_group->group_name = 'group_policy_keyfile_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_keyfile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_policy_keyfile_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_policy_keyfile_image',
      2 => 'field_policy_keyfile_type',
      3 => 'field_core_introduction',
      4 => 'field_core_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-next-step-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_keyfile_content|node|policy_keyfile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_keyfile_editorial|node|policy_keyfile|form';
  $field_group->group_name = 'group_policy_keyfile_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_keyfile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_policy_keyfile_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '10',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'scheduler_settings',
      3 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_keyfile_editorial|node|policy_keyfile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_keyfile_tabgroup|node|policy_keyfile|form';
  $field_group->group_name = 'group_policy_keyfile_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_keyfile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_policy_keyfile_content',
      1 => 'group_policy_keyfile_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_policy_keyfile_tabgroup|node|policy_keyfile|form'] = $field_group;

  return $export;
}
