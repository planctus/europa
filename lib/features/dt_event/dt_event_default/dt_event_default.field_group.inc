<?php
/**
 * @file
 * dt_event_default.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dt_event_default_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|event|event_collection';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '6',
    'children' => array(
      0 => 'body',
      1 => 'about_heading',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'About',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_about|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_left|node|event|meta';
  $field_group->group_name = 'group_activity_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '0',
    'children' => array(
      0 => 'field_event_date',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'listing__column-second column-second',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_activity_left|node|event|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_right|node|event|meta';
  $field_group->group_name = 'group_activity_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '1',
    'children' => array(
      0 => 'title',
      1 => 'dt_event_header',
      2 => 'group_meta_wrapper',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'listing__column-main column-main',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_activity_right|node|event|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|event|event_collection';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_contact|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_tabgroup|node|event|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'group_editorial_settings',
      1 => 'group_event_after',
      2 => 'group_event_content',
      3 => 'group_event_description',
      4 => 'group_event_practical_info',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content_tabgroup|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_settings|node|event|form';
  $field_group->group_name = 'group_editorial_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Editorial settings',
    'weight' => '23',
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
        'classes' => 'group-editorial-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_editorial_settings|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_after|node|event|form';
  $field_group->group_name = 'group_event_after';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'After the event',
    'weight' => '22',
    'children' => array(
      0 => 'field_core_files',
      1 => 'field_core_gallery',
      2 => 'field_event_media',
      3 => 'field_event_more_links',
      4 => 'field_event_what_happened',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-after field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_after|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_audience|node|event|event_past';
  $field_group->group_name = 'group_event_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'From the audience',
    'weight' => '10',
    'children' => array(
      0 => 'dt_event_scribble_embed',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'From the audience',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_audience|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|event|event_collection';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '19',
    'children' => array(),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_contact|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|event|event_past';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '14',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_contact|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|event|full';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '15',
    'children' => array(
      0 => 'field_core_contact',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_contact|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_content|node|event|form';
  $field_group->group_name = 'group_event_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '19',
    'children' => array(
      0 => 'title_field',
      1 => 'field_core_description',
      2 => 'field_core_header_image',
      3 => 'field_core_introduction',
      4 => 'field_core_legacy_link',
      5 => 'field_core_media',
      6 => 'field_core_social_network_links',
      7 => 'field_core_tagline',
      8 => 'field_core_topics',
      9 => 'field_event_children_events',
      10 => 'field_event_parent_events',
      11 => 'field_event_status',
      12 => 'field_event_status_description',
      13 => 'field_event_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_content|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_context_nav|node|event|event_collection';
  $field_group->group_name = 'group_event_context_nav';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Context nav',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_topics',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-event-context-nav field-group-context_nav',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_context_nav|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_context_nav|node|event|event_past';
  $field_group->group_name = 'group_event_context_nav';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Context nav',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_topics',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-event-context-nav field-group-context_nav',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_context_nav|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_context_nav|node|event|full';
  $field_group->group_name = 'group_event_context_nav';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Context nav',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_topics',
    ),
    'format_type' => 'context_nav',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'modifier' => '',
        'classes' => 'group-event-context-nav field-group-context_nav',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_context_nav|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_description|node|event|form';
  $field_group->group_name = 'group_event_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '20',
    'children' => array(
      0 => 'body',
      1 => 'field_core_contact',
      2 => 'field_core_links',
      3 => 'field_core_persons',
      4 => 'field_event_press_contact',
      5 => 'field_event_schedule',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-description field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_description|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_documents|node|event|event_past';
  $field_group->group_name = 'group_event_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '11',
    'children' => array(
      0 => 'field_core_files',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => 'col-md-9',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_documents|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_practical_info|node|event|form';
  $field_group->group_name = 'group_event_practical_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_tabgroup';
  $field_group->data = array(
    'label' => 'Practical information',
    'weight' => '21',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_core_location',
      2 => 'field_event_available_languages',
      3 => 'field_event_date',
      4 => 'field_event_entrance_fee',
      5 => 'field_event_is_fully_booked',
      6 => 'field_event_is_live_streaming',
      7 => 'field_event_is_online',
      8 => 'field_event_live_streaming_date',
      9 => 'field_event_live_streaming_link',
      10 => 'field_event_location_image',
      11 => 'field_event_number_seats',
      12 => 'field_event_registration',
      13 => 'field_event_registration_end',
      14 => 'field_event_scribble_id',
      15 => 'field_event_target_audience',
      16 => 'field_event_website',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-practical-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_practical_info|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_schedule|node|event|event_collection';
  $field_group->group_name = 'group_event_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Schedule',
    'weight' => '18',
    'children' => array(),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Schedule',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_schedule|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_schedule|node|event|event_past';
  $field_group->group_name = 'group_event_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Schedule',
    'weight' => '42',
    'children' => array(),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Schedule',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_schedule|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_schedule|node|event|full';
  $field_group->group_name = 'group_event_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Schedule',
    'weight' => '14',
    'children' => array(
      0 => 'field_event_schedule',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Schedule',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_schedule|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_speakers|node|event|event_collection';
  $field_group->group_name = 'group_event_speakers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Speakers',
    'weight' => '17',
    'children' => array(),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Speakers',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="speakers"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_speakers|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_speakers|node|event|event_past';
  $field_group->group_name = 'group_event_speakers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Speakers',
    'weight' => '12',
    'children' => array(
      0 => 'field_core_persons',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Speakers',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="speakers"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_speakers|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_speakers|node|event|full';
  $field_group->group_name = 'group_event_speakers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Speakers',
    'weight' => '13',
    'children' => array(
      0 => 'field_core_persons',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Speakers',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="speakers"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_speakers|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_whathappened|node|event|event_past';
  $field_group->group_name = 'group_event_whathappened';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What happened',
    'weight' => '8',
    'children' => array(
      0 => 'field_event_what_happened',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'What happened',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_event_whathappened|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_ong_fut|node|event|event_collection';
  $field_group->group_name = 'group_events_ong_fut';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = 'group_events';
  $field_group->data = array(
    'label' => 'Ongoing and future',
    'weight' => '86',
    'children' => array(
      0 => 'current_and_upcoming_events',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Ongoing and future',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_events_ong_fut|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_past|node|event|event_collection';
  $field_group->group_name = 'group_events_past';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = 'group_events';
  $field_group->data = array(
    'label' => 'Past events',
    'weight' => '87',
    'children' => array(
      0 => 'past_events',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav_item',
    'format_settings' => array(
      'label' => 'Past events',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_events_past|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events|node|event|event_collection';
  $field_group->group_name = 'group_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '4',
    'children' => array(
      0 => 'group_events_ong_fut',
      1 => 'group_events_past',
    ),
    'format_type' => 'bootstrap_fieldgroup_nav',
    'format_settings' => array(
      'label' => 'Events',
      'instance_settings' => array(
        'bootstrap_nav_type' => 'tabs',
        'bootstrap_stacked' => '0',
        'bootstrap_orientation' => '0',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_events|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_latest_section|node|event|event_collection';
  $field_group->group_name = 'group_latest_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Latest section',
    'weight' => '10',
    'children' => array(
      0 => 'social_bookmark_webtools',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Latest section',
      'instance_settings' => array(
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_latest_section|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_wrapper|node|event|meta';
  $field_group->group_name = 'group_meta_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'meta';
  $field_group->parent_name = 'group_activity_right';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '66',
    'children' => array(
      0 => 'field_event_type',
      1 => 'dt_event_status_label',
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
  $field_groups['group_meta_wrapper|node|event|meta'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|event|event_collection';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_event_type',
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
  $field_groups['group_meta|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|event|event_past';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_event_type',
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
  $field_groups['group_meta|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|event|full';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_event_type',
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
  $field_groups['group_meta|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info_left|node|event|event_collection';
  $field_group->group_name = 'group_practical_info_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practical info left',
    'weight' => '33',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Practical info left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-9',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_practical_info_left|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info_left|node|event|event_past';
  $field_group->group_name = 'group_practical_info_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Practical info left',
    'weight' => '34',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_event_available_languages',
      2 => 'field_event_date',
      3 => 'field_event_parent_events',
      4 => 'field_event_target_audience',
      5 => 'field_event_website',
      6 => 'hr_2',
      7 => 'dt_event_address_oneline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Practical info left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-9',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_practical_info_left|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info_left|node|event|full';
  $field_group->group_name = 'group_practical_info_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Practical info left',
    'weight' => '79',
    'children' => array(
      0 => 'field_core_departments',
      1 => 'field_event_available_languages',
      2 => 'field_event_date',
      3 => 'field_event_entrance_fee',
      4 => 'field_event_number_seats',
      5 => 'field_event_parent_events',
      6 => 'field_event_target_audience',
      7 => 'field_event_website',
      8 => 'hr_2',
      9 => 'book_your_seat_bottom',
      10 => 'livestreaming_bottom',
      11 => 'dt_event_address_oneline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Practical info left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-9',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_practical_info_left|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info_right|node|event|event_collection';
  $field_group->group_name = 'group_practical_info_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practical info right',
    'weight' => '34',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Practical info right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-3',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_practical_info_right|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info_right|node|event|event_past';
  $field_group->group_name = 'group_practical_info_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Practical info right',
    'weight' => '35',
    'children' => array(
      0 => 'field_event_location_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Practical info right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-3',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_practical_info_right|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info_right|node|event|full';
  $field_group->group_name = 'group_practical_info_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Practical info right',
    'weight' => '80',
    'children' => array(
      0 => 'field_event_location_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Practical info right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'col-md-3',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_practical_info_right|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_information|node|event|event_collection';
  $field_group->group_name = 'group_practical_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practical information',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Practical information',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="practicalinformation"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_practical_information|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_information|node|event|event_past';
  $field_group->group_name = 'group_practical_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practical information',
    'weight' => '13',
    'children' => array(
      0 => 'group_row',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Practical information',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="practicalinformation"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_practical_information|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_information|node|event|full';
  $field_group->group_name = 'group_practical_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practical information',
    'weight' => '12',
    'children' => array(
      0 => 'group_row',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Practical information',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => 'id="practicalinformation"',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_practical_information|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_events|node|event|event_past';
  $field_group->group_name = 'group_related_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related events',
    'weight' => '15',
    'children' => array(
      0 => 'event_related_events',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related events',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_related_events|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_events|node|event|full';
  $field_group->group_name = 'group_related_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related events',
    'weight' => '17',
    'children' => array(
      0 => 'event_related_events',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related events',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'required_fields' => 1,
        'description' => '',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_related_events|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_links|node|event|event_collection';
  $field_group->group_name = 'group_related_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related links',
    'weight' => '7',
    'children' => array(
      0 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related links',
      'instance_settings' => array(
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_related_links|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_links|node|event|full';
  $field_group->group_name = 'group_related_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related links',
    'weight' => '16',
    'children' => array(
      0 => 'field_core_links',
    ),
    'format_type' => 'section_group',
    'format_settings' => array(
      'label' => 'Related links',
      'instance_settings' => array(
        'classes' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'modifier' => '',
        'layout' => '',
      ),
    ),
  );
  $field_groups['group_related_links|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|node|event|event_collection';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_collection';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'row',
    'weight' => '32',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_row|node|event|event_collection'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|node|event|event_past';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'event_past';
  $field_group->parent_name = 'group_practical_information';
  $field_group->data = array(
    'label' => 'row',
    'weight' => '33',
    'children' => array(
      0 => 'group_practical_info_left',
      1 => 'group_practical_info_right',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_row|node|event|event_past'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|node|event|full';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_practical_information';
  $field_group->data = array(
    'label' => 'row',
    'weight' => '78',
    'children' => array(
      0 => 'group_practical_info_left',
      1 => 'group_practical_info_right',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_row|node|event|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('After the event');
  t('Contact');
  t('Content');
  t('Context nav');
  t('Description');
  t('Documents');
  t('Editorial settings');
  t('Events');
  t('From the audience');
  t('Latest section');
  t('Left');
  t('Meta');
  t('Ongoing and future');
  t('Past events');
  t('Practical info left');
  t('Practical info right');
  t('Practical information');
  t('Related events');
  t('Related links');
  t('Right');
  t('Schedule');
  t('Speakers');
  t('What happened');
  t('row');

  return $field_groups;
}
