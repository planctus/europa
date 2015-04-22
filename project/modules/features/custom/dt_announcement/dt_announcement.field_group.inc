<?php
/**
 * @file
 * dt_announcement.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_announcement_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_content|node|announcement|form';
  $field_group->group_name = 'group_announcement_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_announcement_contact',
      2 => 'field_announcement_type',
      3 => 'field_core_introduction',
      4 => 'field_core_location',
      5 => 'title_field',
      6 => 'field_announcement_department',
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
  $export['group_announcement_content|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_context_info|node|announcement|form';
  $field_group->group_name = 'group_announcement_context_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Context information',
    'weight' => '4',
    'children' => array(
      0 => 'field_announcement_info',
      1 => 'field_core_link',
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
  $export['group_announcement_context_info|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_metadata|node|announcement|form';
  $field_group->group_name = 'group_announcement_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'field_core_location',
      3 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-announcement-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_announcement_metadata|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_related|node|announcement|form';
  $field_group->group_name = 'group_announcement_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_announcement',
      1 => 'field_core_department',
      2 => 'field_core_policy',
      3 => 'field_core_topics',
      4 => 'field_core_persons',
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
  $export['group_announcement_related|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|announcement|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_announcement_content',
      1 => 'group_announcement_context_info',
      2 => 'group_announcement_related',
      3 => 'group_editorial_settings',
      4 => 'group_media',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_content_tabgroup|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|announcement|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '6',
    'children' => array(
      0 => 'group_content_access',
      1 => 'og_group_ref',
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
  $export['group_editorial_settings|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|announcement|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Featured Media',
    'weight' => '3',
    'children' => array(
      0 => 'field_announcement_image',
      1 => 'field_announcement_media',
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
  $export['group_media|node|announcement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scheduler|node|announcement|form';
  $field_group->group_name = 'group_scheduler';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page settings',
    'weight' => '8',
    'children' => array(
      0 => 'path',
      1 => 'scheduler_settings',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Page settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-scheduler field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_scheduler|node|announcement|form'] = $field_group;

  return $export;
}
