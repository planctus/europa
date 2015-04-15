<?php
/**
 * @file
 * dt_class.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_class_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_departments|node|class|form';
  $field_group->group_name = 'group_class_departments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Departments',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_department',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-class-departments field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_departments|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_link_group|node|class|form';
  $field_group->group_name = 'group_class_link_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link groups',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-class-link-group field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_link_group|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_metadata|node|class|form';
  $field_group->group_name = 'group_class_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta data',
    'weight' => '7',
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
        'classes' => 'group-class-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_metadata|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_profile_information|node|class|form';
  $field_group->group_name = 'group_class_profile_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile information',
    'weight' => '1',
    'children' => array(
      0 => 'field_class_introduction',
      1 => 'field_class_notification',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-class-profile-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_profile_information|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_related|node|class|form';
  $field_group->group_name = 'group_class_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '6',
    'children' => array(
      0 => 'field_class_related_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-class-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_related|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_topics|node|class|form';
  $field_group->group_name = 'group_class_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topics',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-class-topics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_topics|node|class|form'] = $field_group;

  return $export;
}
