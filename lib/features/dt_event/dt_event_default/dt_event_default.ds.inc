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
  $ds_fieldsetting->id = 'node|event|event_collection';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'event_collection';
  $ds_fieldsetting->settings = array(
    'about_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'current_and_upcoming_events' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'past_events' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'social_bookmark_webtools' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'social-media-links--webtool-horizontal',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'announcement_block' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_featured_item' => 1,
        'show_social_media' => 1,
        'label' => 'Latest',
        'ft' => array(),
      ),
    ),
    'field_core_contact' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_core_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|event|event_collection'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|event_livestream';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'event_livestream';
  $ds_fieldsetting->settings = array(
    'event_livestream_title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<h1>',
          'suffix' => '</h1>',
        ),
      ),
    ),
    'social_bookmark_webtools' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_scribble_embed' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_intro' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_stream_embed' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_stream_embed_intro' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_event_livestream_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|event_livestream'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|event_past';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'event_past';
  $ds_fieldsetting->settings = array(
    'event_related_events' => array(
      'weight' => '16',
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
    'hr_1' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hr_2' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_bookmark_webtools' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'social-media-links--webtool-horizontal',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'dt_event_header' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_event_address_oneline' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'show_link' => 0,
        'ft' => array(
          'lb' => 'Where',
        ),
      ),
    ),
    'dt_event_status_message_1' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'event_status_message_formatter',
    ),
    'dt_event_date_and_time' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'When',
        ),
      ),
    ),
    'dt_event_scribble_embed' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_core_departments' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Organizer',
        ),
      ),
    ),
    'field_event_available_languages' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Languages',
        ),
      ),
    ),
    'field_event_parent_events' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Part of',
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
  $export['node|event|event_past'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'event_related_events' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'event_type_of_event' => array(
      'weight' => '91',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Type of event',
        ),
      ),
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
    'hr_1' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'hr_2' => array(
      'weight' => '86',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_bookmark_webtools' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'social-media-links--webtool-horizontal',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'book_your_seat' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'livestreaming' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'no_padding' => 1,
        'ft' => array(),
      ),
    ),
    'attend' => array(
      'weight' => '83',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'no_padding' => 0,
        'ft' => array(
          'lb' => 'Attend',
        ),
      ),
    ),
    'dt_event_header' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_event_address_oneline' => array(
      'weight' => '82',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'show_link' => 0,
        'ft' => array(
          'lb' => 'Where',
        ),
      ),
    ),
    'dt_event_status_message_1' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'event_status_message_formatter',
    ),
    'dt_event_status_message_2' => array(
      'weight' => '80',
      'label' => 'inline',
      'format' => 'event_status_inline_formatter',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Status',
        ),
      ),
    ),
    'dt_event_date_and_time' => array(
      'weight' => '81',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'When',
        ),
      ),
    ),
    'field_event_available_languages' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Languages',
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
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'listing__title',
        'ft' => array(),
      ),
    ),
    'book_your_seat' => array(
      'weight' => '69',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_header' => array(
      'weight' => '68',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'teaser_version' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_status_label' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
  $export['node|event|meta'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'listing__title',
        'ft' => array(),
      ),
    ),
    'book_your_seat' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_header' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'teaser_version' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'dt_event_status_label' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
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
  $export['node|event|teaser'] = $ds_fieldsetting;

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
        13 => 'field_event_schedule',
        14 => 'field_core_contact',
        15 => 'field_core_links',
        16 => 'field_event_date',
        17 => 'field_event_is_online',
        18 => 'field_core_location',
        19 => 'field_event_location_image',
        20 => 'field_event_registration',
        21 => 'field_event_registration_end',
        22 => 'field_event_is_fully_booked',
        23 => 'field_event_is_live_streaming',
        24 => 'field_event_live_streaming_date',
        25 => 'field_event_live_streaming_link',
        26 => 'field_event_scribble_id',
        27 => 'field_event_available_languages',
        28 => 'field_event_target_audience',
        29 => 'field_event_number_seats',
        30 => 'dt_event_header',
        31 => 'field_event_entrance_fee',
        32 => 'field_core_departments',
        33 => 'field_event_website',
        34 => 'field_event_media',
        35 => 'field_event_what_happened',
        36 => 'field_core_files',
        37 => 'field_event_more_links',
        38 => 'field_core_media',
        41 => 'field_core_gallery',
      ),
      'top_top' => array(
        33 => 'book_your_seat',
        36 => 'livestreaming',
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
      'field_event_schedule' => 'left_header',
      'field_core_contact' => 'left_header',
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
      'dt_event_header' => 'left_header',
      'field_event_entrance_fee' => 'left_header',
      'book_your_seat' => 'top_top',
      'field_core_departments' => 'left_header',
      'field_event_website' => 'left_header',
      'livestreaming' => 'top_top',
      'field_event_media' => 'left_header',
      'field_event_what_happened' => 'left_header',
      'field_core_files' => 'left_header',
      'field_event_more_links' => 'left_header',
      'field_core_media' => 'left_header',
      'field_core_gallery' => 'left_header',
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
  $ds_layout->id = 'node|event|event_collection';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'event_collection';
  $ds_layout->layout = 'ne_bootstrap_3_9_advanced_top_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'top_bottom_left' => array(
        0 => 'past_events',
        2 => 'current_and_upcoming_events',
        8 => 'group_events',
        18 => 'group_events_ong_fut',
        19 => 'group_events_past',
      ),
      'left_header' => array(
        0 => 'title',
        4 => 'field_core_tagline',
      ),
      'central' => array(
        1 => 'about_heading',
        5 => 'body',
        10 => 'group_about',
        11 => 'group_related_links',
        12 => 'field_core_links',
        13 => 'group_contact',
        14 => 'announcement_block',
        15 => 'field_core_contact',
        16 => 'social_bookmark_webtools',
        17 => 'group_latest_section',
      ),
      'top_middle_left' => array(
        6 => 'field_core_media',
      ),
      'top_middle_right' => array(
        7 => 'field_core_introduction',
      ),
      'top_bottom_right' => array(
        9 => 'field_core_social_network_links',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
      'past_events' => 'top_bottom_left',
      'current_and_upcoming_events' => 'top_bottom_left',
      'about_heading' => 'central',
      'field_core_tagline' => 'left_header',
      'body' => 'central',
      'field_core_media' => 'top_middle_left',
      'field_core_introduction' => 'top_middle_right',
      'group_events' => 'top_bottom_left',
      'field_core_social_network_links' => 'top_bottom_right',
      'group_about' => 'central',
      'group_related_links' => 'central',
      'field_core_links' => 'central',
      'group_contact' => 'central',
      'announcement_block' => 'central',
      'field_core_contact' => 'central',
      'social_bookmark_webtools' => 'central',
      'group_latest_section' => 'central',
      'group_events_ong_fut' => 'top_bottom_left',
      'group_events_past' => 'top_bottom_left',
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
  $export['node|event|event_collection'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|event_livestream';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'event_livestream';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'event_livestream_title',
      ),
      'central' => array(
        1 => 'dt_event_livestream_header',
        2 => 'dt_event_scribble_embed',
        3 => 'group_section',
        4 => 'dt_event_stream_embed_intro',
        5 => 'dt_event_stream_embed',
        6 => 'social_bookmark_webtools',
        7 => 'group_row',
        8 => 'group_video',
        9 => 'group_chat',
      ),
    ),
    'fields' => array(
      'event_livestream_title' => 'left_header',
      'dt_event_livestream_header' => 'central',
      'dt_event_scribble_embed' => 'central',
      'group_section' => 'central',
      'dt_event_stream_embed_intro' => 'central',
      'dt_event_stream_embed' => 'central',
      'social_bookmark_webtools' => 'central',
      'group_row' => 'central',
      'group_video' => 'central',
      'group_chat' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|event_livestream'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|event_past';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'event_past';
  $ds_layout->layout = 'ne_bootstrap_3_9_advanced_top_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'dt_event_date_and_time',
        3 => 'dt_event_address_oneline',
        5 => 'hr_2',
        9 => 'field_event_available_languages',
        11 => 'field_event_target_audience',
        13 => 'field_core_departments',
        15 => 'field_event_parent_events',
        17 => 'field_event_website',
        20 => 'group_event_audience',
        21 => 'dt_event_scribble_embed',
        23 => 'group_image_video',
        24 => 'group_event_documents',
        25 => 'group_event_speakers',
        26 => 'group_practical_information',
        27 => 'group_event_contact',
        28 => 'event_related_events',
        29 => 'group_related_links',
        30 => 'field_core_contact',
        31 => 'group_related_events',
        32 => 'social_bookmark_webtools',
        33 => 'field_event_location_image',
        34 => 'group_row',
        35 => 'group_practical_info_left',
        36 => 'group_practical_info_right',
        37 => 'field_event_speakers',
        38 => 'field_core_files',
        39 => 'field_core_links',
        40 => 'field_core_gallery',
      ),
      'left_header' => array(
        1 => 'group_meta',
        2 => 'title',
        4 => 'dt_event_header',
        8 => 'field_event_type',
      ),
      'top_top' => array(
        6 => 'dt_event_status_message_1',
      ),
      'top_middle_left' => array(
        7 => 'field_event_media',
      ),
      'top_middle_right' => array(
        10 => 'field_core_introduction',
        12 => 'hr_1',
        14 => 'group_event_context_nav',
        22 => 'field_core_topics',
      ),
      'top_bottom_left' => array(
        16 => 'group_event_whathappened',
        18 => 'field_event_what_happened',
      ),
      'top_bottom_right' => array(
        19 => 'field_core_social_network_links',
      ),
    ),
    'fields' => array(
      'dt_event_date_and_time' => 'central',
      'group_meta' => 'left_header',
      'title' => 'left_header',
      'dt_event_address_oneline' => 'central',
      'dt_event_header' => 'left_header',
      'hr_2' => 'central',
      'dt_event_status_message_1' => 'top_top',
      'field_event_media' => 'top_middle_left',
      'field_event_type' => 'left_header',
      'field_event_available_languages' => 'central',
      'field_core_introduction' => 'top_middle_right',
      'field_event_target_audience' => 'central',
      'hr_1' => 'top_middle_right',
      'field_core_departments' => 'central',
      'group_event_context_nav' => 'top_middle_right',
      'field_event_parent_events' => 'central',
      'group_event_whathappened' => 'top_bottom_left',
      'field_event_website' => 'central',
      'field_event_what_happened' => 'top_bottom_left',
      'field_core_social_network_links' => 'top_bottom_right',
      'group_event_audience' => 'central',
      'dt_event_scribble_embed' => 'central',
      'field_core_topics' => 'top_middle_right',
      'group_image_video' => 'central',
      'group_event_documents' => 'central',
      'group_event_speakers' => 'central',
      'group_practical_information' => 'central',
      'group_event_contact' => 'central',
      'event_related_events' => 'central',
      'group_related_links' => 'central',
      'field_core_contact' => 'central',
      'group_related_events' => 'central',
      'social_bookmark_webtools' => 'central',
      'field_event_location_image' => 'central',
      'group_row' => 'central',
      'group_practical_info_left' => 'central',
      'group_practical_info_right' => 'central',
      'field_event_speakers' => 'central',
      'field_core_files' => 'central',
      'field_core_links' => 'central',
      'field_core_gallery' => 'central',
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
  $export['node|event|event_past'] = $ds_layout;

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
        3 => 'field_event_type',
      ),
      'top_top' => array(
        4 => 'dt_event_status_message_1',
      ),
      'top_middle_left' => array(
        5 => 'field_core_media',
      ),
      'top_middle_right' => array(
        6 => 'field_core_introduction',
        7 => 'book_your_seat',
        8 => 'livestreaming',
        9 => 'field_core_topics',
        10 => 'hr_1',
        11 => 'group_event_context_nav',
      ),
      'top_bottom_left' => array(
        12 => 'body',
      ),
      'top_bottom_right' => array(
        13 => 'field_core_social_network_links',
      ),
      'central' => array(
        14 => 'group_practical_information',
        15 => 'group_event_speakers',
        16 => 'group_event_schedule',
        17 => 'group_event_contact',
        18 => 'group_related_links',
        19 => 'event_related_events',
        20 => 'group_related_events',
        21 => 'social_bookmark_webtools',
        22 => 'group_practical_info_left',
        23 => 'group_practical_info_right',
        24 => 'field_event_schedule',
        25 => 'field_event_speakers',
        26 => 'field_core_contact',
        27 => 'field_event_location_image',
        28 => 'field_core_links',
        29 => 'group_row',
        30 => 'dt_event_status_message_2',
        31 => 'dt_event_date_and_time',
        32 => 'dt_event_address_oneline',
        33 => 'attend',
        34 => 'hr_2',
        35 => 'field_event_available_languages',
        36 => 'field_event_number_seats',
        37 => 'field_event_entrance_fee',
        38 => 'field_event_target_audience',
        39 => 'event_type_of_event',
        40 => 'field_core_departments',
        41 => 'field_event_parent_events',
        42 => 'field_event_website',
      ),
    ),
    'fields' => array(
      'group_meta' => 'left_header',
      'title' => 'left_header',
      'dt_event_header' => 'left_header',
      'field_event_type' => 'left_header',
      'dt_event_status_message_1' => 'top_top',
      'field_core_media' => 'top_middle_left',
      'field_core_introduction' => 'top_middle_right',
      'book_your_seat' => 'top_middle_right',
      'livestreaming' => 'top_middle_right',
      'field_core_topics' => 'top_middle_right',
      'hr_1' => 'top_middle_right',
      'group_event_context_nav' => 'top_middle_right',
      'body' => 'top_bottom_left',
      'field_core_social_network_links' => 'top_bottom_right',
      'group_practical_information' => 'central',
      'group_event_speakers' => 'central',
      'group_event_schedule' => 'central',
      'group_event_contact' => 'central',
      'group_related_links' => 'central',
      'event_related_events' => 'central',
      'group_related_events' => 'central',
      'social_bookmark_webtools' => 'central',
      'group_practical_info_left' => 'central',
      'group_practical_info_right' => 'central',
      'field_event_schedule' => 'central',
      'field_event_speakers' => 'central',
      'field_core_contact' => 'central',
      'field_event_location_image' => 'central',
      'field_core_links' => 'central',
      'group_row' => 'central',
      'dt_event_status_message_2' => 'central',
      'dt_event_date_and_time' => 'central',
      'dt_event_address_oneline' => 'central',
      'attend' => 'central',
      'hr_2' => 'central',
      'field_event_available_languages' => 'central',
      'field_event_number_seats' => 'central',
      'field_event_entrance_fee' => 'central',
      'field_event_target_audience' => 'central',
      'event_type_of_event' => 'central',
      'field_core_departments' => 'central',
      'field_event_parent_events' => 'central',
      'field_event_website' => 'central',
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
  $ds_layout->layout = 'ne_1col_hitme';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_activity_left',
        1 => 'group_activity_right',
        2 => 'field_event_type',
        3 => 'dt_event_status_label',
        4 => 'field_event_date',
        5 => 'group_meta_wrapper',
        6 => 'title',
        7 => 'dt_event_header',
        8 => 'book_your_seat',
      ),
    ),
    'fields' => array(
      'group_activity_left' => 'main',
      'group_activity_right' => 'main',
      'field_event_type' => 'main',
      'dt_event_status_label' => 'main',
      'field_event_date' => 'main',
      'group_meta_wrapper' => 'main',
      'title' => 'main',
      'dt_event_header' => 'main',
      'book_your_seat' => 'main',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_1col_hitme';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'field_event_type',
        1 => 'group_meta_wrapper',
        2 => 'dt_event_status_label',
        3 => 'title',
        4 => 'dt_event_header',
        5 => 'book_your_seat',
        6 => 'field_event_date',
        7 => 'group_activity_left',
        8 => 'group_activity_right',
      ),
    ),
    'fields' => array(
      'field_event_type' => 'main',
      'group_meta_wrapper' => 'main',
      'dt_event_status_label' => 'main',
      'title' => 'main',
      'dt_event_header' => 'main',
      'book_your_seat' => 'main',
      'field_event_date' => 'main',
      'group_activity_left' => 'main',
      'group_activity_right' => 'main',
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
  $export['node|event|teaser'] = $ds_layout;

  return $export;
}
