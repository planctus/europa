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
  $field_group->identifier = 'group_class_content|node|class|form';
  $field_group->group_name = 'group_class_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '16',
    'children' => array(
      0 => 'title_field',
      1 => 'field_class_notification',
      2 => 'field_core_introduction',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-class-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_class_content|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_class_link_group|node|class|form';
  $field_group->group_name = 'group_class_link_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Link groups',
    'weight' => '17',
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
  $field_group->identifier = 'group_class_related|node|class|form';
  $field_group->group_name = 'group_class_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '20',
    'children' => array(
      0 => 'field_class_related_links',
      1 => 'field_core_department',
      2 => 'field_core_topics',
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
  $field_group->identifier = 'group_content_tabgroup|node|class|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_class_departments',
      1 => 'group_class_link_group',
      2 => 'group_class_related',
      3 => 'group_class_topics',
      4 => 'group_class_content',
      5 => 'group_editorial_settings',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-tabgroup field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_content_tabgroup|node|class|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|class|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'class';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '21',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'scheduler_settings',
      3 => 'language',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-editorial-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_editorial_settings|node|class|form'] = $field_group;

  return $export;
}
