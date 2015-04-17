<?php
/**
 * @file
 * dt_policy_follow.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_follow_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_follow_common|node|policy_follow|form';
  $field_group->group_name = 'group_policy_follow_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_follow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '0',
    'children' => array(
      0 => 'field_policy_follow_type',
      1 => 'field_policy_follow_link',
      2 => 'title',
      3 => 'field_policy_follow_icon',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-follow-common field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_follow_common|node|policy_follow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_follow_metadata|node|policy_follow|form';
  $field_group->group_name = 'group_policy_follow_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_follow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-follow-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_follow_metadata|node|policy_follow|form'] = $field_group;

  return $export;
}
