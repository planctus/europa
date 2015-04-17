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
    'weight' => '0',
    'children' => array(
      0 => 'field_policy_input_type',
      1 => 'field_policy_input_status',
      2 => 'field_policy_input_introduction',
      3 => 'field_policy_input_link',
      4 => 'title',
      5 => 'field_policy_input_task_cta',
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

  return $export;
}
