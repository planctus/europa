<?php
/**
 * @file
 * dt_pri_policy_area_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_pri_policy_area_default_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_policy_area_content|node|priority_policy_area|form';
  $field_group->group_name = 'group_priority_policy_area_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_policy_area_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_priority_policy_area_status',
      2 => 'field_priority_policy_area_type',
      4 => 'field_core_introduction',
      5 => 'field_core_legacy_link',
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
  $export['group_priority_policy_area_content|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_policy_area_editorial|node|priority_policy_area|form';
  $field_group->group_name = 'group_priority_policy_area_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_priority_policy_area_tabgroup';
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
  $export['group_priority_policy_area_editorial|node|priority_policy_area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_policy_area_meta|node|priority_policy_area|teaser';
  $field_group->group_name = 'group_priority_policy_area_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_priority_policy_area_type',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'classes' => 'meta',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_priority_policy_area_meta|node|priority_policy_area|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a info field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_policy_area_tabgroup|node|priority_policy_area|form';
  $field_group->group_name = 'group_priority_policy_area_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority_policy_area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_priority_policy_area_content',
      1 => 'group_priority_policy_area_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_priority_policy_area_tabgroup|node|priority_policy_area|form'] = $field_group;

  return $export;
}
