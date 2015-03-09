<?php
/**
 * @file
 * nexteuropa_department.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nexteuropa_department_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta|node|department|form';
  $field_group->group_name = 'group_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CTA',
    'weight' => '3',
    'children' => array(
      0 => 'field_cta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cta field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cta|node|department|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_information|node|department|form';
  $field_group->group_name = 'group_profile_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'department';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile information',
    'weight' => '2',
    'children' => array(
      0 => 'field_ec_organisation',
      1 => 'field_abbreviation',
      2 => 'field_introduction',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_information|node|department|form'] = $field_group;

  return $export;
}
