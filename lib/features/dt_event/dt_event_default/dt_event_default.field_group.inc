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
  $field_group->identifier = 'group_content_tabgroup|node|event|form';
  $field_group->group_name = 'group_content_tabgroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'group_event_content',
      1 => 'group_editorial_settings',
      2 => 'group_event_description',
      3 => 'group_event_practical_info',
      4 => 'group_event_after',
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
      0 => 'field_event_media',
      1 => 'field_event_what_happened',
      2 => 'field_core_files',
      3 => 'field_event_gallery',
      4 => 'field_event_more_links',
      5 => 'field_core_gallery',
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
  $field_group->identifier = 'group_event_contact|node|event|full';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '12',
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
      1 => 'field_event_type',
      2 => 'field_event_status_description',
      3 => 'field_core_description',
      4 => 'field_core_tagline',
      5 => 'field_core_introduction',
      6 => 'field_core_header_image',
      7 => 'field_event_status',
      8 => 'field_event_parent_events',
      9 => 'field_event_children_events',
      10 => 'field_core_topics',
      11 => 'field_core_social_network_links',
      12 => 'field_core_media',
      13 => 'field_core_legacy_link',
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
      1 => 'field_core_persons',
      2 => 'field_event_schedule',
      3 => 'field_core_contact',
      4 => 'field_event_press_contact',
      5 => 'field_core_links',
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
      0 => 'field_event_date',
      1 => 'field_event_is_online',
      2 => 'field_core_location',
      3 => 'field_event_location_image',
      4 => 'field_event_registration',
      5 => 'field_event_registration_end',
      6 => 'field_event_is_fully_booked',
      7 => 'field_event_is_live_streaming',
      8 => 'field_event_live_streaming_date',
      9 => 'field_event_live_streaming_link',
      10 => 'field_event_scribble_id',
      11 => 'field_event_available_languages',
      12 => 'field_event_target_audience',
      13 => 'field_event_number_seats',
      14 => 'field_event_entrance_fee',
      15 => 'field_core_departments',
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
  $field_group->identifier = 'group_event_schedule|node|event|full';
  $field_group->group_name = 'group_event_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Schedule',
    'weight' => '11',
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
  $field_group->identifier = 'group_event_speakers|node|event|full';
  $field_group->group_name = 'group_event_speakers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Speakers',
    'weight' => '10',
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
      8 => 'book_your_seat_bottom',
      9 => 'livestreaming_bottom',
      10 => 'dt_event_address_oneline',
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
  $field_group->identifier = 'group_practical_information|node|event|full';
  $field_group->group_name = 'group_practical_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Practical information',
    'weight' => '9',
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
  t('After the event');
  t('Contact');
  t('Content');
  t('Description');
  t('Editorial settings');
  t('Left');
  t('Meta');
  t('Practical info left');
  t('Practical info right');
  t('Practical information');
  t('Right');
  t('Schedule');
  t('Speakers');
  t('row');

  return $field_groups;
}
