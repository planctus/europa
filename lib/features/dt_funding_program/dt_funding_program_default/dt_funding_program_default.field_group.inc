<?php

/**
 * @file
 * dt_funding_program_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_funding_program_default_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_program_content|node|funding_program|form';
  $field_group->group_name = 'group_funding_program_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_funding_program_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_introduction',
      2 => 'field_core_description',
      3 => 'field_core_legacy_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-next-step-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_funding_program_content|node|funding_program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_program_editorial|node|funding_program|form';
  $field_group->group_name = 'group_funding_program_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_funding_program_tabgroup';
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
  $export['group_funding_program_editorial|node|funding_program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_program_meta|node|funding_program|teaser';
  $field_group->group_name = 'group_funding_program_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_program';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_funding_program_meta|node|funding_program|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding_program_tabgroup|node|funding_program|form';
  $field_group->group_name = 'group_funding_program_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'funding_program';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_funding_program_content',
      1 => 'group_funding_program_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_funding_program_tabgroup|node|funding_program|form'] = $field_group;

  return $export;
}
