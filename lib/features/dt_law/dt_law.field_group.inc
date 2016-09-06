<?php

/**
 * @file
 * dt_law.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_law_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|law|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '12',
    'children' => array(
      0 => 'field_eurovoc_taxonomy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_taxonomy|node|law|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Taxonomy');

  return $field_groups;
}
