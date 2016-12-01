<?php
/**
 * @file
 * cwt_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_core_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom_content|node|custom_page|form';
  $field_group->group_name = 'group_custom_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'custom_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-custom-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_custom_content|node|custom_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom_metadata|node|custom_page|form';
  $field_group->group_name = 'group_custom_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'custom_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_editorial_section',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-custom-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_custom_metadata|node|custom_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Metadata');

  return $field_groups;
}
