<?php
/**
 * @file
 * cwt_biography.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_biography_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assistant|node|biography_assistant|form';
  $field_group->group_name = 'group_assistant';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography_assistant';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assistant',
    'weight' => '0',
    'children' => array(
      0 => 'field_biography_assistant_email',
      1 => 'field_biography_assistant_phone',
      2 => 'field_biography_assistant_fname',
      3 => 'title',
      4 => 'path',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-assistant field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_assistant|node|biography_assistant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_assistants|node|biography|form';
  $field_group->group_name = 'group_bio_assistants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assistants',
    'weight' => '3',
    'children' => array(
      0 => 'field_biography_assistants',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Assistants',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-bio-assistants field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_bio_assistants|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_contact|node|biography|default';
  $field_group->group_name = 'group_bio_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '21',
    'children' => array(
      0 => 'field_biography_address',
      1 => 'field_biography_phone',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-bio-contact field-group-div well well-sm',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bio_contact|node|biography|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_contact|node|biography|form';
  $field_group->group_name = 'group_bio_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_content';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '12',
    'children' => array(
      0 => 'field_biography_address',
      1 => 'field_biography_email',
      2 => 'field_biography_phone',
      3 => 'field_biography_press_contact',
      4 => 'group_bio_embedded_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bio_contact|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_content|node|commissioner|form';
  $field_group->group_name = 'group_bio_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_biography_av_portal',
      2 => 'field_biography_declaration',
      3 => 'field_biography_first_name',
      4 => 'field_biography_last_name',
      5 => 'field_biography_mission_letter',
      6 => 'field_biography_multiple_files',
      7 => 'field_biography_portfolio',
      8 => 'field_biography_portrait',
      9 => 'field_biography_tagline',
      10 => 'field_gender',
      11 => 'field_social_networks',
      12 => 'field_team_membership',
      13 => 'group_bio_contact',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-commissioner-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bio_content|node|commissioner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_embedded_contact|node|biography|form';
  $field_group->group_name = 'group_bio_embedded_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_contact';
  $field_group->data = array(
    'label' => 'Embedded Contact Form',
    'weight' => '15',
    'children' => array(
      0 => 'field_embedded_contact_enabled',
      1 => 'field_remote_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-embedded-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bio_embedded_contact|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_message|node|biography|default';
  $field_group->group_name = 'group_bio_message';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Message',
    'weight' => '0',
    'children' => array(
      0 => 'field_biography_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Message',
      'instance_settings' => array(
        'classes' => 'group-bio-message field-group-div well well-sm',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_biography_full_group_bio_message',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bio_message|node|biography|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_message|node|biography|form';
  $field_group->group_name = 'group_bio_message';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bio_metadata';
  $field_group->data = array(
    'label' => 'Message',
    'weight' => '22',
    'children' => array(
      0 => 'field_biography_message',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Message',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-bio-message field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_bio_message|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_metadata|node|commissioner|form';
  $field_group->group_name = 'group_bio_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'field_biography_departments',
      1 => 'field_biography_project_team',
      2 => 'field_biography_role',
      3 => 'field_biography_status',
      4 => 'field_biography_team',
      5 => 'field_editorial_section',
      6 => 'field_partial_translation',
      7 => 'field_biography_agenda_text',
      8 => 'language',
      9 => 'group_bio_message',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-commissioner-metadata field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bio_metadata|node|commissioner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_technical|node|biography|form';
  $field_group->group_name = 'group_bio_technical';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Technical fields',
    'weight' => '5',
    'children' => array(
      0 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio-technical field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bio_technical|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_timeline|node|biography|form';
  $field_group->group_name = 'group_bio_timeline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Curriculum Vitae',
    'weight' => '1',
    'children' => array(
      0 => 'field_biography_cv',
      1 => 'field_biography_timeline',
      2 => 'field_download_cv_in_pdf_format',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Curriculum Vitae',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-bio-timeline field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_bio_timeline|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config|taxonomy_term|biography_roles|form';
  $field_group->group_name = 'group_config';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'biography_roles';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Role specific configuration',
    'weight' => '4',
    'children' => array(
      0 => 'field_declaration_of_interest',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-config field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_config|taxonomy_term|biography_roles|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portfolio|node|biography|default';
  $field_group->group_name = 'group_portfolio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Portfolio',
    'weight' => '2',
    'children' => array(
      0 => 'field_biography_portfolio',
      1 => 'field_biography_tagline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Portfolio',
      'instance_settings' => array(
        'classes' => 'group-portfolio field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'node_biography_full_group_portfolio',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_portfolio|node|biography|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_timeline|node|biography_timeline|form';
  $field_group->group_name = 'group_timeline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography_timeline';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timeline',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_date',
      2 => 'field_activity_link',
      3 => 'field_timeline_type',
      4 => 'field_timeline_date',
      5 => 'title',
      6 => 'path',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-timeline field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_timeline|node|biography_timeline|form'] = $field_group;

  return $export;
}