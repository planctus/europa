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
  $field_group->identifier = 'group_cfp_basic_info|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Basic information',
    'weight' => '6',
    'children' => array(
      0 => 'title_field',
      1 => 'field_cfp_call_reference',
      2 => 'field_cfp_status',
      3 => 'field_core_date_opening',
      4 => 'field_core_date_published',
      5 => 'field_core_departments',
      6 => 'field_core_description',
      7 => 'field_core_introduction',
      8 => 'field_core_legacy_link',
      9 => 'field_core_topics',
      10 => 'field_cfp_deadline_model',
      11 => 'field_cfp_program',
      12 => 'field_cfp_publication',
      13 => 'field_grants_awarded_link',
      14 => 'field_core_keywords',
      15 => 'group_cfp_deadlines',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-basic-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_basic_info|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_contacts|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_contacts',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-contacts field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_contacts|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_contact|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_contacts',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-cfp-contact field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="contact"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_contact|node|call_for_proposal|full'] = $field_group;

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
    'weight' => '7',
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
  $field_group->identifier = 'group_cfp_deadlines|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_deadlines';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_basic_info';
  $field_group->data = array(
    'label' => 'Multiple deadlines',
    'weight' => '4',
    'children' => array(
      0 => 'field_core_deadlines',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-deadlines field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cfp_deadlines|node|call_for_proposal|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cfp_details|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_cfp_call_reference',
      1 => 'field_core_departments',
      2 => 'field_core_topics',
      3 => 'field_core_date_opening',
      4 => 'field_cfp_program',
      5 => 'field_grants_awarded_link',
      6 => 'field_core_deadlines',
      7 => 'field_cfp_deadline_model',
      8 => 'hr_1',
      9 => 'dt_call_for_proposal_published',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'group-cfp-details field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="details"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_details|node|call_for_proposal|full'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_core_files',
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
  $field_group->identifier = 'group_cfp_main_content|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_background',
      1 => 'field_core_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-main-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_main_content|node|call_for_proposal|form'] = $field_group;

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
    'label' => 'Description',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_background',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'classes' => 'group-cfp-main-section field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="description"',
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
      0 => 'content_type_label',
      1 => 'dt_call_for_proposal_meta',
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
    'weight' => '10',
    'children' => array(
      0 => 'field_core_links',
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
  $field_group->identifier = 'group_cfp_related|node|call_for_proposal|full';
  $field_group->group_name = 'group_cfp_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related',
      'instance_settings' => array(
        'classes' => 'group-cfp-related field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="related"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_cfp_related|node|call_for_proposal|full'] = $field_group;

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
      0 => 'group_cfp_basic_info',
      1 => 'group_cfp_contacts',
      2 => 'group_cfp_editorial',
      3 => 'group_cfp_main_content',
      4 => 'group_cfp_related',
      5 => 'group_cfp_taxonomy',
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
  $field_group->identifier = 'group_cfp_taxonomy|node|call_for_proposal|form';
  $field_group->group_name = 'group_cfp_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_for_proposal';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cfp_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '11',
    'children' => array(
      0 => 'field_eurovoc_taxonomy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cfp-taxonomy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cfp_taxonomy|node|call_for_proposal|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');
  t('Contact');
  t('Content');
  t('Description');
  t('Details');
  t('Documents');
  t('Editorial settings');
  t('Main content');
  t('Meta');
  t('Multiple deadlines');
  t('Related');
  t('Taxonomy');

  return $field_groups;
}
