<?php
/**
 * @file
 * dt_info_homepage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_info_homepage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_info_homepage';
  $strongarm->value = '0';
  $export['comment_anonymous_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_info_homepage';
  $strongarm->value = 1;
  $export['comment_default_mode_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_info_homepage';
  $strongarm->value = '50';
  $export['comment_default_per_page_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_info_homepage';
  $strongarm->value = 1;
  $export['comment_form_location_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_info_homepage';
  $strongarm->value = '1';
  $export['comment_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_info_homepage';
  $strongarm->value = '1';
  $export['comment_preview_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_info_homepage';
  $strongarm->value = 1;
  $export['comment_subject_field_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__info_homepage';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__info_homepage';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'meta' => array(
        'custom_settings' => FALSE,
      ),
      'title' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_informational' => array(
        'custom_settings' => TRUE,
      ),
      'homepage_political' => array(
        'custom_settings' => TRUE,
      ),
      'highlight' => array(
        'custom_settings' => FALSE,
      ),
      'event_collection' => array(
        'custom_settings' => FALSE,
      ),
      'event_livestream' => array(
        'custom_settings' => FALSE,
      ),
      'event_past' => array(
        'custom_settings' => FALSE,
      ),
      'image_label' => array(
        'custom_settings' => FALSE,
      ),
      'job' => array(
        'custom_settings' => FALSE,
      ),
      'structured_navigation' => array(
        'custom_settings' => FALSE,
      ),
      'event_speaker' => array(
        'custom_settings' => FALSE,
      ),
      'name' => array(
        'custom_settings' => FALSE,
      ),
      'file' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'scheduler_settings' => array(
          'weight' => '8',
        ),
        'language' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_info_homepage';
  $strongarm->value = 4;
  $export['language_content_type_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_info_homepage';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_info_homepage';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_info_homepage';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_info_homepage';
  $strongarm->value = '1';
  $export['node_preview_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_info_homepage';
  $strongarm->value = 1;
  $export['node_submitted_info_homepage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_info_homepage_pattern';
  $strongarm->value = '[node:source:title]';
  $export['pathauto_node_info_homepage_pattern'] = $strongarm;

  return $export;
}
