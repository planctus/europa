<?php

/**
 * @file
 * dt_job_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_job_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_content|node|job|form';
  $field_group->group_name = 'group_job_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_job_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '10',
    'children' => array(
      0 => 'field_core_persons',
      1 => 'field_job_acting_role',
      2 => 'field_job_period_for_this_role',
      3 => 'field_job_representation_role',
      4 => 'field_job_role',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_job_content|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_editorial_settings|node|job|form';
  $field_group->group_name = 'group_job_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_job_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '15',
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
        'classes' => 'group-job-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_job_editorial_settings|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_filtering|node|job|form';
  $field_group->group_name = 'group_job_filtering';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_job_tabgroup';
  $field_group->data = array(
    'label' => 'Filtering',
    'weight' => '14',
    'children' => array(
      0 => 'field_core_topics',
      1 => 'field_job_team_group',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job-filtering field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_job_filtering|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_representation|node|job|form';
  $field_group->group_name = 'group_job_representation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_job_tabgroup';
  $field_group->data = array(
    'label' => 'Representation',
    'weight' => '12',
    'children' => array(
      0 => 'field_core_link',
      1 => 'field_job_city',
      2 => 'field_job_note',
      3 => 'field_nal_country',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job-representation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_job_representation|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_respons_topics|node|job|form';
  $field_group->group_name = 'group_job_respons_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_job_tabgroup';
  $field_group->data = array(
    'label' => 'Responsabilities/Topics',
    'weight' => '13',
    'children' => array(
      0 => 'field_job_responsabilities',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job-respons-topics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_job_respons_topics|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_tabgroup|node|job|form';
  $field_group->group_name = 'group_job_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_job_content',
      1 => 'group_job_editorial_settings',
      2 => 'group_job_filtering',
      3 => 'group_job_representation',
      4 => 'group_job_respons_topics',
      5 => 'group_job_technical_fields',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-job-tabgroup field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_job_tabgroup|node|job|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_technical_fields|node|job|form';
  $field_group->group_name = 'group_job_technical_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_job_tabgroup';
  $field_group->data = array(
    'label' => 'Technical fields',
    'weight' => '11',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job-technical-fields field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_job_technical_fields|node|job|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Editorial settings');
  t('Filtering');
  t('Representation');
  t('Responsabilities/Topics');
  t('Technical fields');

  return $field_groups;
}
