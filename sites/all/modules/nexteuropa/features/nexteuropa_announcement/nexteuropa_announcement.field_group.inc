<?php
/**
 * @file
 * nexteuropa_announcement.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nexteuropa_announcement_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_content|node|announcement|form';
  $field_group->group_name = 'group_announcement_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_core_introduction',
      2 => 'field_core_related_links',
      3 => 'field_announcement_info',
      4 => 'field_announcement_media',
      5 => 'field_announcement_image',
      6 => 'field_announcemnt_img_prominence',
      7 => 'field_announcement_contact',
      8 => 'field_announcement_resp_org',
      9 => 'group_announcement_related',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-announcement-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_announcement_content|node|announcement|form'] = $field_group;

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
    'weight' => '3',
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
  $field_group->parent_name = 'group_announcement_content';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '11',
    'children' => array(
      0 => 'field_announcement_departments',
      1 => 'field_announcement_subjects',
      2 => 'field_announcement_announcements',
      3 => 'field_policies',
      4 => 'field_commissioner',
      5 => 'field_related_topics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-announcement-related field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_announcement_related|node|announcement|form'] = $field_group;

  return $export;
}
