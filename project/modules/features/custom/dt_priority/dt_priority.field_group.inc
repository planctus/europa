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
  $field_group->identifier = 'group_content_tabgroup|node|priority|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_priority_related',
      1 => 'group_editorial_settings',
      2 => 'group_priority_content',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_content_tabgroup|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|priority|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '5',
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
  $export['group_editorial_settings|node|priority|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_priority_content|node|priority|form';
  $field_group->group_name = 'group_priority_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'title_field',
      1 => 'field_priority_excerpt',
      2 => 'field_priority_issue',
      3 => 'field_priority_objective',
      4 => 'field_core_introduction',
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
      1 => 'field_priority_description',
      2 => 'field_priority_intro',
      3 => 'field_priority_keyword',
      4 => 'field_priority_type',
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
  $field_group->identifier = 'group_priority_related|node|priority|form';
  $field_group->group_name = 'group_priority_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'priority';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_core_department',
      2 => 'field_core_priorities',
      3 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-priority-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_priority_related|node|priority|form'] = $field_group;

  return $export;
}
