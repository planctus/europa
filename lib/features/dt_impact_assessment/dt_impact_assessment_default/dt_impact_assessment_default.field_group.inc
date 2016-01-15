<?php
/**
 * @file
 * dt_impact_assessment_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_impact_assessment_default_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_impact_assessment_content|node|impact_assessment|form';
  $field_group->group_name = 'group_impact_assessment_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'impact_assessment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_impact_assessment_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_introduction',
      3 => 'field_core_legacy_link',
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
  $export['group_impact_assessment_content|node|impact_assessment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_impact_assessment_editorial|node|impact_assessment|form';
  $field_group->group_name = 'group_impact_assessment_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'impact_assessment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_impact_assessment_tabgroup';
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
  $export['group_impact_assessment_editorial|node|impact_assessment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_impact_assessment_meta|node|impact_assessment|teaser';
  $field_group->group_name = 'group_impact_assessment_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'impact_assessment';
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
  $export['group_impact_assessment_meta|node|impact_assessment|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_impact_assessment_tabgroup|node|impact_assessment|form';
  $field_group->group_name = 'group_impact_assessment_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'impact_assessment';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_impact_assessment_content',
      1 => 'group_impact_assessment_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $export['group_impact_assessment_tabgroup|node|impact_assessment|form'] = $field_group;

  return $export;
}
