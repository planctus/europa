<?php

/**
 * @file
 * dt_guidance_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_guidance_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guidance_content|node|guidance|form';
  $field_group->group_name = 'group_guidance_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'guidance';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_guidance_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_introduction',
      3 => 'field_core_legacy_link',
      4 => 'field_core_keywords',
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
  $field_groups['group_guidance_content|node|guidance|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guidance_editorial|node|guidance|form';
  $field_group->group_name = 'group_guidance_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'guidance';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_guidance_tabgroup';
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
  $field_groups['group_guidance_editorial|node|guidance|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guidance_meta|node|guidance|teaser';
  $field_group->group_name = 'group_guidance_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'guidance';
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
  $field_groups['group_guidance_meta|node|guidance|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guidance_tabgroup|node|guidance|form';
  $field_group->group_name = 'group_guidance_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'guidance';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_taxonomy',
      1 => 'group_guidance_content',
      2 => 'group_guidance_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_guidance_tabgroup|node|guidance|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|guidance|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'guidance';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_guidance_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '9',
    'children' => array(
      0 => 'field_eurovoc_taxonomy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomy|node|guidance|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Editorial settings');
  t('Meta');
  t('Taxonomy');

  return $field_groups;
}
