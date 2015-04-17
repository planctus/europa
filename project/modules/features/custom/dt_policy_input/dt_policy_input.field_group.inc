<?php
/**
 * @file
 * dt_policy_input.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_input_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_input_common|node|policy_input|form';
  $field_group->group_name = 'group_policy_input_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_input';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '1',
    'children' => array(
      0 => 'field_policy_input_introduction',
      1 => 'field_policy_input_link',
      2 => 'field_policy_input_status',
      3 => 'field_policy_input_task_cta',
      4 => 'field_policy_input_type',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-input-common field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_input_common|node|policy_input|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_input_metadata|node|policy_input|form';
  $field_group->group_name = 'group_policy_input_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_input';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '6',
    'children' => array(
      0 => 'group_content_access',
      1 => 'body',
      2 => 'path',
      3 => 'scheduler_settings',
      4 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-input-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_input_metadata|node|policy_input|form'] = $field_group;

  return $export;
}
