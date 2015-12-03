<?php
/**
 * @file
 * cwt_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_core_field_group_info() {
  $export = array();

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
  $export['group_custom_content|node|custom_page|form'] = $field_group;

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
  $export['group_custom_metadata|node|custom_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_settings|taxonomy_term|editorial_sections|form';
  $field_group->group_name = 'group_team_settings';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'editorial_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Team',
    'weight' => '6',
    'children' => array(
      0 => 'field_team_block_description',
      1 => 'field_team_block_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_settings|taxonomy_term|editorial_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_term|taxonomy_term|editorial_sections|form';
  $field_group->group_name = 'group_term';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'editorial_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Term',
    'weight' => '1',
    'children' => array(),
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
  $export['group_term|taxonomy_term|editorial_sections|form'] = $field_group;

  return $export;
}
