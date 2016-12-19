<?php
/**
 * @file
 * dt_law_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_law_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_architecture|node|law|form';
  $field_group->group_name = 'group_law_architecture';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
  $field_group->data = array(
    'label' => 'Page Architecture',
    'weight' => '13',
    'children' => array(
      0 => 'field_core_children',
      1 => 'field_core_parents',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-law-architecture field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_law_architecture|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_content|node|law|form';
  $field_group->group_name = 'group_law_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_introduction',
      3 => 'field_core_legacy_link',
      4 => 'field_law_status',
      5 => 'field_core_background',
      6 => 'field_core_short_title',
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
  $field_groups['group_law_content|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_departments|node|law|full';
  $field_group->group_name = 'group_law_departments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
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
  $field_groups['group_law_departments|node|law|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_documents|node|law|form';
  $field_group->group_name = 'group_law_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '10',
    'children' => array(
      0 => 'field_core_publications',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-law-documents field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_law_documents|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_documents|node|law|full';
  $field_group->group_name = 'group_law_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '10',
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
  $field_groups['group_law_documents|node|law|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_editorial|node|law|form';
  $field_group->group_name = 'group_law_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
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
  $field_groups['group_law_editorial|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_extra|node|law|form';
  $field_group->group_name = 'group_law_extra';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
  $field_group->data = array(
    'label' => 'Extra fields',
    'weight' => '11',
    'children' => array(
      0 => 'field_core_laws',
      1 => 'field_law_date_apply',
      2 => 'field_law_entry_date',
      3 => 'field_law_link_to_full_text',
      4 => 'field_law_link_to_summary',
      5 => 'field_law_reference_number',
      6 => 'field_law_law_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-law-extra field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_law_extra|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_meta|node|law|full';
  $field_group->group_name = 'group_law_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_law_status',
      1 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'label' => 'Meta',
      'instance_settings' => array(
        'modifier' => 'meta--header',
      ),
    ),
  );
  $field_groups['group_law_meta|node|law|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_meta|node|law|teaser';
  $field_group->group_name = 'group_law_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
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
  $field_groups['group_law_meta|node|law|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_policies|node|law|full';
  $field_group->group_name = 'group_law_policies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Policies',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_policies',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Policies',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="policies"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_law_policies|node|law|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_priorities|node|law|full';
  $field_group->group_name = 'group_law_priorities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Piorities',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_priorities',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Piorities',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="priorities"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_law_priorities|node|law|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_related|node|law|form';
  $field_group->group_name = 'group_law_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_law_tabgroup';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_policies',
      2 => 'field_core_priorities',
      3 => 'field_core_topics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-law-related field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_law_related|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_tabgroup|node|law|form';
  $field_group->group_name = 'group_law_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_law_architecture',
      1 => 'group_law_content',
      2 => 'group_law_documents',
      3 => 'group_law_editorial',
      4 => 'group_law_extra',
      5 => 'group_law_related',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_law_tabgroup|node|law|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_law_topics|node|law|full';
  $field_group->group_name = 'group_law_topics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'law';
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
  $field_groups['group_law_topics|node|law|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Departments');
  t('Documents');
  t('Editorial settings');
  t('Extra fields');
  t('Meta');
  t('Page Architecture');
  t('Piorities');
  t('Policies');
  t('Related');
  t('Topics');

  return $field_groups;
}
