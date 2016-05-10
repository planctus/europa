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

  // Translatables
  // Included for use with string extractors like potx.
  t('After the event');
  t('Content');
  t('Description');
  t('Editorial settings');
  t('Practical information');

  return $field_groups;
}
