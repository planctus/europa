<?php

/**
 * @file
 * dt_tender_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_tender_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|tender|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tender_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '10',
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
  $field_groups['group_taxonomy|node|tender|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_content|node|tender|form';
  $field_group->group_name = 'group_tender_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tender_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'body',
      2 => 'field_core_departments',
      3 => 'field_core_topics',
      4 => 'field_tender_status',
      5 => 'field_core_description',
      6 => 'field_core_introduction',
      7 => 'field_core_legacy_link',
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
  $field_groups['group_tender_content|node|tender|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_departments|node|tender|full';
  $field_group->group_name = 'group_tender_departments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Departments',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_departments',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Departments',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related_departments"',
      ),
    ),
  );
  $field_groups['group_tender_departments|node|tender|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_documents|node|tender|form';
  $field_group->group_name = 'group_tender_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tender_tabgroup';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tender-documents field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_tender_documents|node|tender|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_documents|node|tender|full';
  $field_group->group_name = 'group_tender_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '5',
    'children' => array(
      0 => 'field_core_files',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'classes' => 'group-tender-documents field-group-tab',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="documents"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_tender_documents|node|tender|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_editorial|node|tender|form';
  $field_group->group_name = 'group_tender_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tender_tabgroup';
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_tender_editorial|node|tender|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_meta|node|tender|full';
  $field_group->group_name = 'group_tender_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_tender_status',
      1 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'classes' => '',
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_tender_meta|node|tender|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_meta|node|tender|teaser';
  $field_group->group_name = 'group_tender_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
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
  $field_groups['group_tender_meta|node|tender|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_tabgroup|node|tender|form';
  $field_group->group_name = 'group_tender_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_taxonomy',
      1 => 'group_tender_content',
      2 => 'group_tender_documents',
      3 => 'group_tender_editorial',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_tender_tabgroup|node|tender|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tender_topics|node|tender|full';
  $field_group->group_name = 'group_tender_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tender';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topics',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_topics',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Topics',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'section__group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related_topics"',
      ),
    ),
  );
  $field_groups['group_tender_topics|node|tender|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Departments');
  t('Documents');
  t('Editorial settings');
  t('Meta');
  t('Taxonomy');
  t('Topics');

  return $field_groups;
}
