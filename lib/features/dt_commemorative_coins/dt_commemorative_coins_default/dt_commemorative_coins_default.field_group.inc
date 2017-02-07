<?php
/**
 * @file
 * dt_commemorative_coins_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_commemorative_coins_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cc_basic_info|node|commemorative_coins|form';
  $field_group->group_name = 'group_cc_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commemorative_coins';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cc_tabgroup';
  $field_group->data = array(
    'label' => 'Basic information',
    'weight' => '10',
    'children' => array(
      0 => 'title_field',
      1 => 'field_cc_date',
      2 => 'field_cc_subject',
      3 => 'field_core_description',
      4 => 'field_core_image',
      5 => 'field_core_link',
      6 => 'field_nal_country',
      7 => 'field_cc_issue_page',
      8 => 'field_core_keywords',
      9 => 'field_cc_issuing_volumes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cc-basic-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cc_basic_info|node|commemorative_coins|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cc_editorial|node|commemorative_coins|form';
  $field_group->group_name = 'group_cc_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commemorative_coins';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cc_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '11',
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
        'classes' => 'group-cc-editorial field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cc_editorial|node|commemorative_coins|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cc_tabgroup|node|commemorative_coins|form';
  $field_group->group_name = 'group_cc_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commemorative_coins';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_cc_basic_info',
      1 => 'group_cc_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-cc-tabgroup field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cc_tabgroup|node|commemorative_coins|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');
  t('Content');
  t('Editorial settings');

  return $field_groups;
}
