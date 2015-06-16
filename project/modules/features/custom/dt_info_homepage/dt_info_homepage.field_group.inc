<?php
/**
 * @file
 * dt_info_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_info_homepage_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|info_homepage|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_content',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_content_tabgroup|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|info_homepage|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '11',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_info_homepage_section_1',
      3 => 'field_info_homepage_section_2',
      4 => 'field_info_homepage_section_3',
      5 => 'field_info_homepage_section_4',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_content|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|info_homepage|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '13',
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
        'classes' => 'group-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_editorial_settings|node|info_homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_highlight|node|info_homepage|full';
  $field_group->group_name = 'group_highlight';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'info_homepage';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Highlight',
    'weight' => '3',
    'children' => array(
      0 => 'field_info_homepage_section_3',
      1 => 'topics_atoz',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Highlight',
      'instance_settings' => array(
        'id' => '',
        'classes' => ' listing__wrapper--highlight block--full-width',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_highlight|node|info_homepage|full'] = $field_group;

  return $export;
}
