<?php
/**
 * @file
 * dt_event_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_event_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'book_your_seat' => array(
      'weight' => '42',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'livestreaming' => array(
      'weight' => '43',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_event_header' => array(
      'weight' => '41',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'event_related_events' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'book_your_seat' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'book_your_seat_bottom' => array(
      'weight' => '45',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Attend',
        ),
      ),
    ),
    'livestreaming' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'livestreaming_bottom' => array(
      'weight' => '46',
      'label' => 'inline',
      'format' => 'default',
    ),
    'dt_event_header' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_event_address_oneline' => array(
      'weight' => '43',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Where',
        ),
      ),
    ),
    'field_core_contact' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_event_available_languages' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Languages',
        ),
      ),
    ),
    'field_event_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'When',
        ),
      ),
    ),
    'field_event_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
  );
  $export['node|event|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|meta';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'meta';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '67',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => 'listing__title',
        'ft' => array(),
      ),
    ),
    'dt_event_header' => array(
      'weight' => '68',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'teaser_version' => 1,
        'ft' => array(),
      ),
    ),
    'field_event_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
  );
  $export['node|event|meta'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_event_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_3_9_advanced_top_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'field_core_introduction',
        1 => 'field_event_collection',
        2 => 'field_core_description',
        3 => 'field_event_type',
        4 => 'field_event_status_description',
        5 => 'field_core_tagline',
        6 => 'field_core_header_image',
        7 => 'field_event_status',
        8 => 'field_event_parent_events',
        9 => 'field_event_children_events',
        10 => 'field_core_topics',
        11 => 'field_core_social_network_links',
        12 => 'body',
        13 => 'field_core_persons',
        14 => 'field_event_schedule',
        15 => 'field_core_contact',
        16 => 'field_event_press_contact',
        17 => 'field_core_links',
        18 => 'field_event_date',
        19 => 'field_event_is_online',
        20 => 'field_core_location',
        21 => 'field_event_location_image',
        22 => 'field_event_registration',
        23 => 'field_event_registration_end',
        24 => 'field_event_is_fully_booked',
        25 => 'field_event_is_live_streaming',
        26 => 'field_event_live_streaming_date',
        27 => 'field_event_live_streaming_link',
        28 => 'field_event_scribble_id',
        29 => 'field_event_available_languages',
        30 => 'field_event_target_audience',
        31 => 'field_event_number_seats',
        32 => 'field_event_entrance_fee',
        33 => 'field_core_departments',
        34 => 'field_event_website',
        35 => 'field_event_media',
        36 => 'field_event_what_happened',
        37 => 'field_core_files',
        38 => 'field_event_more_links',
        39 => 'field_core_media',
        40 => 'field_core_gallery',
        41 => 'dt_event_header',
      ),
      'top_top' => array(
        42 => 'book_your_seat',
        43 => 'livestreaming',
      ),
    ),
    'fields' => array(
      'field_core_introduction' => 'left_header',
      'field_event_collection' => 'left_header',
      'field_core_description' => 'left_header',
      'field_event_type' => 'left_header',
      'field_event_status_description' => 'left_header',
      'field_core_tagline' => 'left_header',
      'field_core_header_image' => 'left_header',
      'field_event_status' => 'left_header',
      'field_event_parent_events' => 'left_header',
      'field_event_children_events' => 'left_header',
      'field_core_topics' => 'left_header',
      'field_core_social_network_links' => 'left_header',
      'body' => 'left_header',
      'field_core_persons' => 'left_header',
      'field_event_schedule' => 'left_header',
      'field_core_contact' => 'left_header',
      'field_event_press_contact' => 'left_header',
      'field_core_links' => 'left_header',
      'field_event_date' => 'left_header',
      'field_event_is_online' => 'left_header',
      'field_core_location' => 'left_header',
      'field_event_location_image' => 'left_header',
      'field_event_registration' => 'left_header',
      'field_event_registration_end' => 'left_header',
      'field_event_is_fully_booked' => 'left_header',
      'field_event_is_live_streaming' => 'left_header',
      'field_event_live_streaming_date' => 'left_header',
      'field_event_live_streaming_link' => 'left_header',
      'field_event_scribble_id' => 'left_header',
      'field_event_available_languages' => 'left_header',
      'field_event_target_audience' => 'left_header',
      'field_event_number_seats' => 'left_header',
      'field_event_entrance_fee' => 'left_header',
      'field_core_departments' => 'left_header',
      'field_event_website' => 'left_header',
      'field_event_media' => 'left_header',
      'field_event_what_happened' => 'left_header',
      'field_core_files' => 'left_header',
      'field_event_more_links' => 'left_header',
      'field_core_media' => 'left_header',
      'field_core_gallery' => 'left_header',
      'dt_event_header' => 'left_header',
      'book_your_seat' => 'top_top',
      'livestreaming' => 'top_top',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top_top' => 'div',
      'top_middle_left' => 'div',
      'top_middle_right' => 'div',
      'top_bottom_left' => 'div',
      'top_bottom_right' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_advanced_top_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_meta',
        1 => 'title',
        2 => 'dt_event_header',
        4 => 'field_event_type',
      ),
      'top_middle_left' => array(
        3 => 'field_core_media',
      ),
      'top_middle_right' => array(
        5 => 'field_core_introduction',
        6 => 'book_your_seat',
        7 => 'livestreaming',
      ),
      'top_bottom_left' => array(
        8 => 'body',
      ),
      'top_bottom_right' => array(
        9 => 'field_core_social_network_links',
      ),
      'central' => array(
        10 => 'group_practical_information',
        11 => 'group_event_speakers',
        12 => 'group_event_schedule',
        13 => 'group_event_contact',
        14 => 'event_related_events',
        15 => 'field_event_schedule',
        16 => 'field_core_contact',
        17 => 'field_core_persons',
        18 => 'field_event_date',
        19 => 'dt_event_address_oneline',
        20 => 'book_your_seat_bottom',
        21 => 'field_event_location_image',
        22 => 'livestreaming_bottom',
        23 => 'field_event_available_languages',
        24 => 'field_event_number_seats',
        25 => 'field_event_entrance_fee',
        26 => 'field_event_target_audience',
        27 => 'field_core_departments',
        28 => 'field_event_parent_events',
        29 => 'field_event_website',
        30 => 'group_row',
        31 => 'group_practical_info_left',
        32 => 'group_practical_info_right',
      ),
    ),
    'fields' => array(
      'group_meta' => 'left_header',
      'title' => 'left_header',
      'dt_event_header' => 'left_header',
      'field_core_media' => 'top_middle_left',
      'field_event_type' => 'left_header',
      'field_core_introduction' => 'top_middle_right',
      'book_your_seat' => 'top_middle_right',
      'livestreaming' => 'top_middle_right',
      'body' => 'top_bottom_left',
      'field_core_social_network_links' => 'top_bottom_right',
      'group_practical_information' => 'central',
      'group_event_speakers' => 'central',
      'group_event_schedule' => 'central',
      'group_event_contact' => 'central',
      'event_related_events' => 'central',
      'field_event_schedule' => 'central',
      'field_core_contact' => 'central',
      'field_core_persons' => 'central',
      'field_event_date' => 'central',
      'dt_event_address_oneline' => 'central',
      'book_your_seat_bottom' => 'central',
      'field_event_location_image' => 'central',
      'livestreaming_bottom' => 'central',
      'field_event_available_languages' => 'central',
      'field_event_number_seats' => 'central',
      'field_event_entrance_fee' => 'central',
      'field_event_target_audience' => 'central',
      'field_core_departments' => 'central',
      'field_event_parent_events' => 'central',
      'field_event_website' => 'central',
      'group_row' => 'central',
      'group_practical_info_left' => 'central',
      'group_practical_info_right' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top_top' => 'div',
      'top_middle_left' => 'div',
      'top_middle_right' => 'div',
      'top_bottom_left' => 'div',
      'top_bottom_right' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'meta';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_activity_left',
        1 => 'group_activity_right',
        2 => 'field_event_type',
        3 => 'field_event_date',
        4 => 'group_meta_wrapper',
        5 => 'title',
        6 => 'dt_event_header',
      ),
    ),
    'fields' => array(
      'group_activity_left' => 'main',
      'group_activity_right' => 'main',
      'field_event_type' => 'main',
      'field_event_date' => 'main',
      'group_meta_wrapper' => 'main',
      'title' => 'main',
      'dt_event_header' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|meta'] = $ds_layout;

  return $export;
}
