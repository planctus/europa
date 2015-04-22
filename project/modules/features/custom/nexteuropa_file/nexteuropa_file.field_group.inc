<?php
/**
 * @file
 * nexteuropa_file.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nexteuropa_file_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|file|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_file_file',
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
  $export['group_content_tabgroup|node|file|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|file|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = '_add_new_group';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '2',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_editorial_settings|node|file|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_file|node|file|form';
  $field_group->group_name = 'group_file_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = '_add_new_group';
  $field_group->data = array(
    'label' => 'File',
    'weight' => '1',
    'children' => array(
      0 => 'field_core_file',
      1 => 'field_file_lang_specific',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-file-file field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_file_file|node|file|form'] = $field_group;

  return $export;
}
