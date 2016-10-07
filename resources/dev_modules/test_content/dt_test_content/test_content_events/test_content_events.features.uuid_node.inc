<?php

/**
 * @file
 * test_content_events.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function test_content_events_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
    'title' => 'Demo Past Event',
    'log' => 'Edited by admin.',
    'status' => 1,
    'comment' => 1,
    'promote' => 0,
    'sticky' => 0,
    'dt_node_settings_data' => 'a:2:{s:30:"dt_editorial_linguistic_review";i:0;s:27:"dt_editorial_content_review";i:0;}',
    'ds_switch' => '',
    'type' => 'event',
    'language' => 'en',
    'created' => 1467380495,
    'tnid' => 0,
    'translate' => 0,
    'uuid' => '9d4f343f-baf8-4de8-b291-26a94c0a93ec',
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Demo Past Event',
          'format' => NULL,
        ),
      ),
    ),
    'og_group_ref' => array(),
    'group_content_access' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>Extended description of the event.</p>
',
          'summary' => '',
          'format' => 'full_html',
        ),
      ),
    ),
    'field_core_contact' => array(),
    'field_core_departments' => array(),
    'field_core_files' => array(),
    'field_core_persons' => array(),
    'field_core_topics' => array(),
    'field_event_available_languages' => array(),
    'field_event_children_events' => array(),
    'field_event_collection' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_event_date' => array(
      'und' => array(
        0 => array(
          'value' => 1467305100,
          'value2' => 1467305100,
          'timezone' => 'Europe/Brussels',
          'offset' => 7200,
          'offset2' => 7200,
          'timezone_db' => 'Europe/Brussels',
          'date_type' => 'datestamp',
        ),
      ),
    ),
    'field_event_entrance_fee' => array(),
    'field_event_is_fully_booked' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_event_is_live_streaming' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_event_is_online' => array(
      'und' => array(
        0 => array(
          'value' => 0,
        ),
      ),
    ),
    'field_event_live_streaming_date' => array(),
    'field_event_live_streaming_link' => array(),
    'field_event_location_image' => array(),
    'field_event_media' => array(),
    'field_event_more_links' => array(),
    'field_event_number_seats' => array(),
    'field_event_parent_events' => array(),
    'field_event_registration' => array(),
    'field_event_registration_end' => array(),
    'field_event_schedule' => array(),
    'field_event_scribble_id' => array(),
    'field_event_status' => array(
      'und' => array(
        0 => array(
          'value' => 'no',
        ),
      ),
    ),
    'field_event_status_description' => array(),
    'field_event_target_audience' => array(),
    'field_event_type' => array(),
    'field_event_website' => array(),
    'field_event_what_happened' => array(
      'en' => array(
        0 => array(
          'value' => '<p>Event summary</p>
',
          'format' => 'full_html',
        ),
      ),
    ),
    'field_core_description' => array(
      'en' => array(
        0 => array(
          'value' => 'Description of the event',
          'format' => NULL,
        ),
      ),
    ),
    'field_core_gallery' => array(
      'und' => array(
        0 => array(
          'fid' => 4,
          'title' => NULL,
          'data' => NULL,
        ),
        1 => array(
          'fid' => 3,
          'title' => NULL,
          'data' => NULL,
        ),
        2 => array(
          'fid' => 5,
          'title' => NULL,
          'data' => NULL,
        ),
        3 => array(
          'fid' => 6,
          'title' => NULL,
          'data' => NULL,
        ),
        4 => array(
          'fid' => 8,
          'title' => NULL,
          'data' => NULL,
        ),
        5 => array(
          'fid' => 9,
          'title' => NULL,
          'data' => NULL,
        ),
        6 => array(
          'fid' => 7,
          'title' => NULL,
          'data' => NULL,
        ),
        7 => array(
          'fid' => 8,
          'title' => NULL,
          'data' => NULL,
        ),
        8 => array(
          'fid' => 4,
          'title' => NULL,
          'data' => NULL,
        ),
        9 => array(
          'fid' => 14,
          'title' => NULL,
          'data' => NULL,
        ),
        10 => array(
          'fid' => 6,
          'title' => NULL,
          'data' => NULL,
        ),
        11 => array(
          'fid' => 10,
          'title' => NULL,
          'data' => NULL,
        ),
        12 => array(
          'fid' => 11,
          'title' => NULL,
          'data' => NULL,
        ),
        13 => array(
          'fid' => 15,
          'title' => NULL,
          'data' => NULL,
        ),
      ),
    ),
    'field_core_header_image' => array(),
    'field_core_introduction' => array(
      'en' => array(
        0 => array(
          'value' => '<p>Event introduction</p>
',
          'format' => 'full_html',
        ),
      ),
    ),
    'field_core_legacy_link' => array(),
    'field_core_links' => array(),
    'field_core_location' => array(),
    'field_core_media' => array(),
    'field_core_social_network_links' => array(),
    'field_core_tagline' => array(
      'und' => array(
        0 => array(
          'value' => 'Event tagline',
          'format' => NULL,
        ),
      ),
    ),
    'translations' => (object) array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'node',
          'language' => 'en',
          'source' => '',
          'status' => 1,
          'translate' => 0,
          'created' => 1467380495,
          'entity_uuid' => '9d4f343f-baf8-4de8-b291-26a94c0a93ec',
          'user_uuid' => '9c012b8a-7cb0-407b-8711-56c8f079fa51',
        ),
      ),
    ),
    'event_status_rescheduled' => 0,
    'event_status' => 3,
    'event_livestream_status' => NULL,
    'metatags' => array(
      'en' => array(
        'revisit-after' => array(
          'value' => 15,
          'period' => 'day',
        ),
      ),
    ),
    'entity_type' => 'node',
    'rdf_mapping' => array(
      'rdftype' => array(
        0 => 'sioc:Item',
        1 => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          0 => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          0 => 'dc:date',
          1 => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          0 => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          0 => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          0 => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          0 => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          0 => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          0 => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'path' => array(
      'pathauto' => 0,
      'pid' => NULL,
      'source' => 'node/2',
      'alias' => '',
      'language' => 'en',
    ),
    'comment_count' => 0,
    'weight_weight' => FALSE,
    'print_html_display' => 1,
    'print_html_display_comment' => 0,
    'print_html_display_urllist' => 1,
    'print_mail_display' => 1,
    'print_mail_display_comment' => 0,
    'print_mail_display_urllist' => 1,
    'print_pdf_display' => 1,
    'print_pdf_display_comment' => 0,
    'print_pdf_display_urllist' => 1,
    'print_pdf_size' => NULL,
    'print_pdf_orientation' => NULL,
    'workbench_moderation' => array(
      'current' => (object) array(
        'hid' => 5,
        'vid' => 6,
        'nid' => 2,
        'from_state' => 'published',
        'state' => 'published',
        'uid' => 1,
        'stamp' => 1475585924,
        'published' => 1,
        'is_current' => 1,
        'title' => 'Demo Past Event',
        'timestamp' => 1475585924,
      ),
      'published' => (object) array(
        'hid' => 5,
        'vid' => 6,
        'nid' => 2,
        'from_state' => 'published',
        'state' => 'published',
        'uid' => 1,
        'stamp' => 1475585924,
        'published' => 1,
        'is_current' => 1,
        'title' => 'Demo Past Event',
        'timestamp' => 1475585924,
      ),
      'my_revision' => (object) array(
        'hid' => 5,
        'vid' => 6,
        'nid' => 2,
        'from_state' => 'published',
        'state' => 'published',
        'uid' => 1,
        'stamp' => 1475585924,
        'published' => 1,
        'is_current' => 1,
        'title' => 'Demo Past Event',
        'timestamp' => 1475585924,
      ),
    ),
    'pathauto_perform_alias' => FALSE,
    'date' => '2016-07-01 15:41:35 +0200',
    'user_uuid' => '9c012b8a-7cb0-407b-8711-56c8f079fa51',
  );
  return $nodes;
}
