<?php
/**
 * @file
 * dt_toplink.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_toplink_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|top_link|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toplink';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_top_link_content',
      1 => 'group_editorial_settings',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|top_link|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|toplink|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toplink';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '8',
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
  $export['group_editorial_settings|node|toplink|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_top_link_content|node|top_link|form';
  $field_group->group_name = 'group_top_link_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'toplink';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '7',
    'children' => array(
      0 => 'field_toplink_link',
      1 => 'field_toplink_description',
      2 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-top-link-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_top_link_content|node|top_link|form'] = $field_group;

  return $export;
}
