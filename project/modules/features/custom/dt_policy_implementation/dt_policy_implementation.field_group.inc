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
  $field_group->identifier = 'group_pi_item_meta|node|policy_implementation|teaser';
  $field_group->group_name = 'group_pi_item_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_implementation';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_policy_imp_status',
      1 => 'field_policy_imp_type',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $export['group_pi_item_meta|node|policy_implementation|teaser'] = $field_group;

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
      2 => 'field_policy_imp_status',
      3 => 'field_policy_imp_type',
      4 => 'field_core_link',
      5 => 'field_core_legacy_link',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_policy_implementation_meta|node|policy_implementation|teaser';
  $field_group->group_name = 'group_policy_implementation_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy_implementation';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_policy_imp_status',
      1 => 'field_policy_imp_type',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(),
    ),
  );
  $export['group_policy_implementation_meta|node|policy_implementation|teaser'] = $field_group;

  return $export;
}
