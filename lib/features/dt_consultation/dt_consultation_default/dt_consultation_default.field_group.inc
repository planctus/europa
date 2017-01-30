<?php
/**
 * @file
 * dt_consultation_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_consultation_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_contact|node|consultation|form';
  $field_group->group_name = 'group_consultation_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_consultation_tabgroup';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-consultation-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_consultation_contact|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_contact|node|consultation|full';
  $field_group->group_name = 'group_consultation_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-consultation-contact field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="contact"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_contact|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_content|node|consultation|form';
  $field_group->group_name = 'group_consultation_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_consultation_tabgroup';
  $field_group->data = array(
    'label' => 'Basic information',
    'weight' => '8',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_legacy_link',
      3 => 'field_core_date_closing',
      4 => 'field_core_date_opening',
      5 => 'field_core_departments',
      6 => 'field_core_policy_areas',
      7 => 'field_core_topics',
      8 => 'field_consultation_status',
      9 => 'field_core_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Basic information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_consultation_content|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_contributions|node|consultation|full';
  $field_group->group_name = 'group_consultation_contributions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'View the contributions',
    'weight' => '10',
    'children' => array(
      0 => 'field_consultation_contributions',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'View the contributions',
      'instance_settings' => array(
        'classes' => 'group-consultation-contributions field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="contributions"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_contributions|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_details|node|consultation|full';
  $field_group->group_name = 'group_consultation_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_policy_areas',
      2 => 'consultation_period',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'group-consultation-details field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="details"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_details|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_editorial|node|consultation|form';
  $field_group->group_name = 'group_consultation_editorial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_consultation_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '13',
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
  $field_groups['group_consultation_editorial|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_how_to_submit|node|consultation|full';
  $field_group->group_name = 'group_consultation_how_to_submit';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How to submit your contribution',
    'weight' => '6',
    'children' => array(
      0 => 'field_consultation_how_to_submit',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'How to submit your contribution',
      'instance_settings' => array(
        'classes' => 'group-consultation-how-to-submit field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="how_to_submit"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_how_to_submit|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_legal_notices|node|consultation|full';
  $field_group->group_name = 'group_consultation_legal_notices';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Legal notices',
    'weight' => '14',
    'children' => array(
      0 => 'field_core_pages',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Legal notices',
      'instance_settings' => array(
        'classes' => 'group-consultation-legal-notices field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="legal_notices"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_legal_notices|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_main_content|node|consultation|form';
  $field_group->group_name = 'group_consultation_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_consultation_tabgroup';
  $field_group->data = array(
    'label' => 'Consultation',
    'weight' => '10',
    'children' => array(
      0 => 'field_consultation_how_to_submit',
      1 => 'field_consultation_objective',
      2 => 'field_consultation_questionnaire',
      3 => 'field_consultation_target_groups',
      4 => 'field_core_files',
      5 => 'field_core_pages',
      6 => 'field_core_publications',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Consultation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-consultation-main-content field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_consultation_main_content|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_meta|node|consultation|full';
  $field_group->group_name = 'group_consultation_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'content_type_label',
    ),
    'format_type' => 'meta_wrapper',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-consultation-meta field-group-meta_wrapper',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_consultation_meta|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_meta|node|consultation|teaser';
  $field_group->group_name = 'group_consultation_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'consultation_status_label',
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
  $field_groups['group_consultation_meta|node|consultation|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_objective|node|consultation|full';
  $field_group->group_name = 'group_consultation_objective';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Objective of the consultation',
    'weight' => '5',
    'children' => array(
      0 => 'field_consultation_objective',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Objective of the consultation',
      'instance_settings' => array(
        'classes' => 'group-consultation-objective field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="objective"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_objective|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_questionnaire|node|consultation|full';
  $field_group->group_name = 'group_consultation_questionnaire';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'View the questionnaire',
    'weight' => '7',
    'children' => array(
      0 => 'field_consultation_questionnaire',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'View the questionnaire',
      'instance_settings' => array(
        'classes' => 'group-consultation-questionnaire field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="questionnaire"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_questionnaire|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_reference|node|consultation|full';
  $field_group->group_name = 'group_consultation_reference';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reference documents',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_files',
      1 => 'field_core_publications',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Reference documents',
      'instance_settings' => array(
        'classes' => 'group-consultation-reference field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="reference"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_reference|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_results|node|consultation|form';
  $field_group->group_name = 'group_consultation_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_consultation_tabgroup';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '11',
    'children' => array(
      0 => 'field_consultation_contributions',
      1 => 'field_consultation_results',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-consultation-results field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_consultation_results|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_results|node|consultation|full';
  $field_group->group_name = 'group_consultation_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Results of the consultation and next steps',
    'weight' => '11',
    'children' => array(
      0 => 'field_consultation_results',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Results of the consultation and next steps',
      'instance_settings' => array(
        'classes' => 'group-consultation-results field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="results"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_results|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_tabgroup|node|consultation|form';
  $field_group->group_name = 'group_consultation_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_consultation_contact',
      1 => 'group_consultation_content',
      2 => 'group_consultation_editorial',
      3 => 'group_consultation_main_content',
      4 => 'group_consultation_results',
      5 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-policy-next-step-tabgroup field-group-tabs',
      ),
    ),
  );
  $field_groups['group_consultation_tabgroup|node|consultation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_consultation_target_group|node|consultation|full';
  $field_group->group_name = 'group_consultation_target_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target group',
    'weight' => '4',
    'children' => array(
      0 => 'field_consultation_target_groups',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Target group',
      'instance_settings' => array(
        'classes' => 'group-consultation-target-group field-group-section_group',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="target_group"',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_consultation_target_group|node|consultation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|consultation|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_consultation_tabgroup';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '12',
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
  $field_groups['group_taxonomy|node|consultation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic information');
  t('Consultation');
  t('Contact');
  t('Content');
  t('Details');
  t('Editorial settings');
  t('How to submit your contribution');
  t('Legal notices');
  t('Meta');
  t('Objective of the consultation');
  t('Reference documents');
  t('Results');
  t('Results of the consultation and next steps');
  t('Target group');
  t('Taxonomy');
  t('View the contributions');
  t('View the questionnaire');

  return $field_groups;
}
