<?php
/**
 * @file
 * dt_STARTERKIT_DEFAULT.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_STARTERKIT_DEFAULT_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_STARTERKIT_CONTENT_NAME_content|node|STARTERKIT_CONTENT_NAME|form';
  $field_group->group_name = 'group_STARTERKIT_CONTENT_NAME_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'STARTERKIT_CONTENT_NAME';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_STARTERKIT_CONTENT_NAME_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_core_description',
      3 => 'field_core_legacy_link',
      4 => 'field_core_background',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-next-step-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_STARTERKIT_CONTENT_NAME_content|node|STARTERKIT_CONTENT_NAME|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_STARTERKIT_CONTENT_NAME_editorial|node|STARTERKIT_CONTENT_NAME|form';
  $field_group->group_name = 'group_STARTERKIT_CONTENT_NAME_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'STARTERKIT_CONTENT_NAME';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_STARTERKIT_CONTENT_NAME_tabgroup';
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
  $field_groups['group_STARTERKIT_CONTENT_NAME_editorial|node|STARTERKIT_CONTENT_NAME|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_STARTERKIT_CONTENT_NAME_meta|node|STARTERKIT_CONTENT_NAME|teaser';
  $field_group->group_name = 'group_STARTERKIT_CONTENT_NAME_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'STARTERKIT_CONTENT_NAME';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-STARTERKIT_CONTENT_NAME-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_STARTERKIT_CONTENT_NAME_meta|node|STARTERKIT_CONTENT_NAME|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_STARTERKIT_CONTENT_NAME_tabgroup|node|STARTERKIT_CONTENT_NAME|form';
  $field_group->group_name = 'group_STARTERKIT_CONTENT_NAME_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'STARTERKIT_CONTENT_NAME';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_STARTERKIT_CONTENT_NAME_content',
      1 => 'group_STARTERKIT_CONTENT_NAME_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_STARTERKIT_CONTENT_NAME_tabgroup|node|STARTERKIT_CONTENT_NAME|form'] = $field_group;

  return $field_groups;
}
