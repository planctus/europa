<?php
/**
 * @file
 * dt_policy_stage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_stage_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_stage_content|node|policy_stage|form';
  $field_group->group_name = 'group_policy_stage_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_stage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_policy_stage_when',
      1 => 'title',
      2 => 'field_policy_stage_steps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-stage-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_stage_content|node|policy_stage|form'] = $field_group;

  return $export;
}
