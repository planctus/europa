<?php
/**
 * @file
 * dt_policy_implementation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_policy_implementation_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_imp_content|node|policy_implementation|form';
  $field_group->group_name = 'group_policy_imp_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_policy_imp_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '6',
    'children' => array(
      0 => 'title_field',
      1 => 'field_policy_imp_introduction',
      2 => 'field_policy_imp_link',
      3 => 'field_policy_imp_status',
      4 => 'field_policy_imp_type',
      5 => 'field_policy_imp_task',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-imp-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_imp_content|node|policy_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_imp_editorial|node|policy_implementation|form';
  $field_group->group_name = 'group_policy_imp_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_policy_imp_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '7',
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
        'classes' => 'group-policy-imp-editorial field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_policy_imp_editorial|node|policy_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_imp_tabgroup|node|policy_implementation|form';
  $field_group->group_name = 'group_policy_imp_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_policy_imp_content',
      1 => 'group_policy_imp_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-imp-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_policy_imp_tabgroup|node|policy_implementation|form'] = $field_group;

  return $export;
}
