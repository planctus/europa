<?php
/**
 * @file
 * dt_priority.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_priority_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_content|node|priority|form';
  $field_group->group_name = 'group_priority_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_priority_excerpt',
      1 => 'field_priority_issue',
      2 => 'field_priority_objective',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_priority_content|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_meta|node|priority|form';
  $field_group->group_name = 'group_priority_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'field_priority_intro',
      2 => 'field_priority_description',
      3 => 'field_priority_type',
      4 => 'field_priority_keyword',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-meta field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_priority_meta|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_other|node|priority|form';
  $field_group->group_name = 'group_priority_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '42',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'path',
      3 => 'scheduler_settings',
      4 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-other field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_priority_other|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_reference_data|node|priority|form';
  $field_group->group_name = 'group_priority_reference_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Aggregated content',
    'weight' => '2',
    'children' => array(
      0 => 'field_priority_policy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-reference-data field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_priority_reference_data|node|priority|form'] = $field_group;

  return $export;
}
