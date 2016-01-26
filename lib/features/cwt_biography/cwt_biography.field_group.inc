<?php
/**
 * @file
 * cwt_biography.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cwt_biography_field_group_info() {
  $field_groups = array();

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
  $field_groups['group_assistant|node|biography_assistant|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_agenda|node|biography|full';
  $field_group->group_name = 'group_bio_agenda';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Agenda',
    'weight' => '7',
    'children' => array(
      0 => 'agenda_block',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Agenda',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="agenda"',
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => 'group-bio-agenda field-group-section_group',
        'element' => 'div',
        'required_fields' => 1,
        'id' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_bio_agenda|node|biography|full'] = $field_group;

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
  $field_groups['group_bio_assistants|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_blog|node|biography|full';
  $field_group->group_name = 'group_bio_blog';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Blog',
    'weight' => '8',
    'children' => array(
      0 => 'blog_block',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Blog',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="blog"',
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => 'group-bio-blog field-group-section_group',
        'element' => 'div',
        'required_fields' => 1,
        'id' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_bio_blog|node|biography|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_col|node|biography|full';
  $field_group->group_name = 'group_bio_col';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_bio_top_wrapper';
  $field_group->data = array(
    'label' => 'Column',
    'weight' => '61',
    'children' => array(
      0 => 'group_bio_contextual',
      1 => 'group_bio_top_footer',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Column',
      'instance_settings' => array(
        'classes' => 'group-bio-col field-group-html-element col-md-10',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_bio_col|node|biography|full'] = $field_group;

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
  $field_groups['group_bio_contact|node|biography|default'] = $field_group;

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
  $field_groups['group_bio_contact|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_contact|node|biography|full';
  $field_group->group_name = 'group_bio_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '2',
    'children' => array(
      0 => 'contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => 'id="collapse"',
        'modifier' => 'section__group--full-width',
        'layout' => '',
        'classes' => 'section__group--no-margin section__group--highlight-grey section__group--collapsible collapse',
      ),
    ),
  );
  $field_groups['group_bio_contact|node|biography|full'] = $field_group;

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
  $field_groups['group_bio_content|node|commissioner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_contextual|node|biography|full';
  $field_group->group_name = 'group_bio_contextual';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_bio_col';
  $field_group->data = array(
    'label' => 'Contextual navigation',
    'weight' => '4',
    'children' => array(
      0 => 'departments',
      1 => 'topics',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'label' => 'Contextual navigation',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-bio-contextual field-group',
      ),
    ),
  );
  $field_groups['group_bio_contextual|node|biography|full'] = $field_group;

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
  $field_groups['group_bio_embedded_contact|node|biography|form'] = $field_group;

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
  $field_groups['group_bio_message|node|biography|default'] = $field_group;

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
    'weight' => '24',
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
  $field_groups['group_bio_message|node|biography|form'] = $field_group;

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
      8 => 'field_core_collapse_button_text',
      9 => 'language',
      10 => 'field_biography_team_intro',
      11 => 'group_bio_message',
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
  $field_groups['group_bio_metadata|node|commissioner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_news|node|biography|full';
  $field_group->group_name = 'group_bio_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Announcements',
    'weight' => '6',
    'children' => array(
      0 => 'announcements_block',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Announcements',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="news"',
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => 'group-bio-news field-group-section_group',
        'element' => 'div',
        'required_fields' => 1,
        'id' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_bio_news|node|biography|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_role|node|biography|full';
  $field_group->group_name = 'group_bio_role';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Responsibilities',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_biography_mission_letter',
      2 => 'field_biography_multiple_files',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Responsibilities',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="responsibilities"',
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-bio-role field-group-html-element',
        'element' => 'div',
        'required_fields' => 1,
        'id' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_bio_role|node|biography|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_row|node|biography|full';
  $field_group->group_name = 'group_bio_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bio Top',
    'weight' => '1',
    'children' => array(
      0 => 'group_bio_top_wrapper',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Bio Top',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => 'row section__group--biography-top',
      ),
    ),
  );
  $field_groups['group_bio_row|node|biography|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_team|node|biography|full';
  $field_group->group_name = 'group_bio_team';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Team',
    'weight' => '5',
    'children' => array(
      0 => 'field_biography_team',
      1 => 'field_editorial_section',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Team',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="team"',
        'modifier' => '',
        'layout' => '',
        'classes' => 'group-bio-team field-group-html-element',
        'element' => 'div',
        'required_fields' => 1,
        'id' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_bio_team|node|biography|full'] = $field_group;

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
  $field_groups['group_bio_technical|node|biography|form'] = $field_group;

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
  $field_groups['group_bio_timeline|node|biography|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_timeline|node|biography|full';
  $field_group->group_name = 'group_bio_timeline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Biography',
    'weight' => '9',
    'children' => array(
      0 => 'timeline_block',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Biography',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="timeline"',
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => 'group-bio-timeline field-group-section_group',
        'element' => 'div',
        'required_fields' => 1,
        'id' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_bio_timeline|node|biography|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_top_footer|node|biography|full';
  $field_group->group_name = 'group_bio_top_footer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_bio_col';
  $field_group->data = array(
    'label' => 'Bio top footer',
    'weight' => '5',
    'children' => array(
      0 => 'field_biography_av_portal',
      1 => 'field_social_networks',
      2 => 'collapse_button',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bio top footer',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-bio-top-footer field-group field-group--inline-bottom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_bio_top_footer|node|biography|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio_top_wrapper|node|biography|full';
  $field_group->group_name = 'group_bio_top_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'biography';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_bio_row';
  $field_group->data = array(
    'label' => 'Bio top wrapper',
    'weight' => '59',
    'children' => array(
      0 => 'field_biography_portrait',
      1 => 'group_bio_col',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bio top wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_bio_top_wrapper|node|biography|full'] = $field_group;

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
  $field_groups['group_config|taxonomy_term|biography_roles|form'] = $field_group;

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
  $field_groups['group_portfolio|node|biography|default'] = $field_group;

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
  $field_groups['group_timeline|node|biography_timeline|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Announcements');
  t('Assistant');
  t('Assistants');
  t('Bio Top');
  t('Bio top footer');
  t('Bio top wrapper');
  t('Biography');
  t('Blog');
  t('Column');
  t('Contact');
  t('Content');
  t('Contextual navigation');
  t('Curriculum Vitae');
  t('Embedded Contact Form');
  t('Message');
  t('Metadata');
  t('Portfolio');
  t('Responsibilities');
  t('Role specific configuration');
  t('Team');
  t('Technical fields');
  t('Timeline');

  return $field_groups;
}
