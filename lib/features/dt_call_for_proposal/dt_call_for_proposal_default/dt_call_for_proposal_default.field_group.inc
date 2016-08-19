<?php

/**
 * @file
 * dt_call_for_proposal_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_call_for_proposal_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_content|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_background',
      2 => 'field_core_date_published',
      3 => 'field_core_description',
      4 => 'field_core_introduction',
      5 => 'field_core_legacy_link',
      6 => 'field_cfp_call_reference',
      7 => 'field_cfp_programme',
      8 => 'field_core_date_opening',
      9 => 'field_cfp_status',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-policy-next-step-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_content|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_deadline|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_deadline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Deadline',
    'weight' => '11',
    'children' => array(
      0 => 'field_core_next_steps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-deadline field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_deadline|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_departments|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_departments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Departments',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_departments',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Departments',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="departments"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_departments|node|call_for_proposal|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_documents|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Publications',
    'weight' => '10',
    'children' => array(
      0 => 'field_core_publications',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-documents field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_documents|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_documents|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_publications',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="documents"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_documents|node|call_for_proposal|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_editorial|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '12',
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
  $field_groups['group_cfp_editorial|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_main_section|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_main_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main section',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_background',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Main section',
      'instance_settings' => array(
        'classes' => 'group-cfp-main-section field-group-section_group',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => 'id="background"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_main_section|node|call_for_proposal|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_meta|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_cfp_status',
      1 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-cfp-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_meta|node|call_for_proposal|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_meta|node|call_for_proposal|teaser';
  $field_group->group_name = 'group_cfp_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_cfp_status',
      1 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-cfp-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_meta|node|call_for_proposal|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_related|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_related|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_tabgroup|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_cfp_content',
      1 => 'group_cfp_related',
      2 => 'group_cfp_documents',
      3 => 'group_cfp_deadline',
      4 => 'group_cfp_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_cfp_tabgroup|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_topics|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topics',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_topics',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Topics',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="topics"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_topics|node|call_for_proposal|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Deadline');
  t('Departments');
  t('Documents');
  t('Editorial settings');
  t('Main section');
  t('Meta');
  t('Publications');
  t('Related');
  t('Topics');

  return $field_groups;
}
