<?php

/**
 * @file
 * brp_initiative.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function brp_initiative_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_content|node|brp_initiative|form';
  $field_group->group_name = 'group_content_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '15',
    'children' => array(
      0 => 'title_field',
      1 => 'field_brp_inve_fb_count',
      2 => 'field_brp_inve_fb_end_date',
      3 => 'field_brp_inve_fb_start_date',
      4 => 'field_brp_inve_id',
      5 => 'field_brp_inve_initiative_status',
      6 => 'field_brp_inve_isc',
      7 => 'field_brp_inve_leading_service',
      8 => 'field_brp_inve_modified_date',
      9 => 'field_brp_inve_publication_date',
      10 => 'field_brp_inve_reference',
      11 => 'field_brp_inve_resource_type',
      12 => 'field_brp_inve_unit',
      13 => 'field_core_description',
      14 => 'field_brp_inve_committee',
      15 => 'field_brp_inve_expert_group',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content_content|node|brp_initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|brp_initiative|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_content_content',
      1 => 'group_editorial_settings',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content|node|brp_initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|brp_initiative|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '16',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'group_content_access',
      2 => 'language',
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
  $field_groups['group_editorial_settings|node|brp_initiative|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_initiative_meta|node|brp_initiative|full';
  $field_group->group_name = 'group_initiative_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'type_of_initiative',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_initiative_meta|node|brp_initiative|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_initiative_meta|node|brp_initiative|teaser';
  $field_group->group_name = 'group_initiative_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'brp_initiative_status_label',
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
  $field_groups['group_initiative_meta|node|brp_initiative|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inve_attachments|node|brp_initiative|full';
  $field_group->group_name = 'group_inve_attachments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attachments',
    'weight' => '4',
    'children' => array(
      0 => 'brp_initiative_attachments',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Attachments',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_inve_attachments|node|brp_initiative|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inve_details|node|brp_initiative|full';
  $field_group->group_name = 'group_inve_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About this initiative',
    'weight' => '3',
    'children' => array(
      0 => 'field_brp_inve_committee',
      1 => 'field_brp_inve_expert_group',
      2 => 'field_brp_inve_leading_service',
      3 => 'field_brp_inve_reference',
      4 => 'field_brp_inve_resource_type',
      5 => 'field_core_description',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'About this initiative',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="initiative-details"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_inve_details|node|brp_initiative|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inve_givefeedback|node|brp_initiative|full';
  $field_group->group_name = 'group_inve_givefeedback';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Give your feedback',
    'weight' => '5',
    'children' => array(
      0 => 'brp_initiative_feedback_block',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Give your feedback',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="initiative-givefeedback"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_inve_givefeedback|node|brp_initiative|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inve_recentfeedback|node|brp_initiative|full';
  $field_group->group_name = 'group_inve_recentfeedback';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'brp_initiative';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recent feedback',
    'weight' => '6',
    'children' => array(
      0 => 'brp_feedbackfieldfield_simple',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Recent feedback',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="initiative-recentfeedback"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_inve_recentfeedback|node|brp_initiative|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About this initiative');
  t('Attachments');
  t('Content');
  t('Editorial settings');
  t('Give your feedback');
  t('Meta');
  t('Recent feedback');

  return $field_groups;
}
