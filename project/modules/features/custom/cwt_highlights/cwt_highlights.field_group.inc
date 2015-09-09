<?php
/**
 * @file
 * cwt_highlights.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_highlights_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_highlight_content|node|highlight|form';
  $field_group->group_name = 'group_highlight_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'highlight';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_highlight_abstract',
      1 => 'field_highlight_additional_links',
      2 => 'field_highlight_image',
      3 => 'field_highlight_subheader',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-highlight-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_highlight_content|node|highlight|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_highlight_metadata|node|highlight|form';
  $field_group->group_name = 'group_highlight_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'highlight';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'field_editorial_section',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-highlight-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_highlight_metadata|node|highlight|form'] = $field_group;

  return $export;
}
