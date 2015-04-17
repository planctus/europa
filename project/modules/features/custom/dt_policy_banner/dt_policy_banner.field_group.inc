<?php
/**
 * @file
 * dt_policy_banner.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_banner_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_banner_common|node|policy_banner|form';
  $field_group->group_name = 'group_policy_banner_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_banner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '0',
    'children' => array(
      0 => 'title',
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
  $export['group_policy_banner_common|node|policy_banner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_banner_metadata|node|policy_banner|form';
  $field_group->group_name = 'group_policy_banner_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_banner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '1',
    'children' => array(
      0 => 'group_content_access',
      1 => 'path',
      2 => 'scheduler_settings',
      3 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-banner-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_banner_metadata|node|policy_banner|form'] = $field_group;

  return $export;
}
