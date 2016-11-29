<?php
/**
 * @file
 * nexteuropa_file.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nexteuropa_file_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_file';
  $strongarm->value = '0';
  $export['comment_anonymous_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_file';
  $strongarm->value = 1;
  $export['comment_default_mode_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_file';
  $strongarm->value = '50';
  $export['comment_default_per_page_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_file';
  $strongarm->value = '0';
  $export['comment_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_file';
  $strongarm->value = 1;
  $export['comment_form_location_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_file';
  $strongarm->value = '1';
  $export['comment_preview_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_file';
  $strongarm->value = 1;
  $export['comment_subject_field_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__file';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__file';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
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
      'file' => array(
        'custom_settings' => TRUE,
      ),
      'name' => array(
        'custom_settings' => FALSE,
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
      'hero_links' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_informational' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_political' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'scheduler_settings' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'file' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_file';
  $strongarm->value = '1';
  $export['i18n_node_extended_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_file';
  $strongarm->value = array();
  $export['i18n_node_options_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_file';
  $strongarm->value = array();
  $export['i18n_sync_node_type_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_file';
  $strongarm->value = 4;
  $export['language_content_type_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_file';
  $strongarm->value = array();
  $export['menu_options_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_file';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_file';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
    2 => 'moderation',
  );
  $export['node_options_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_file';
  $strongarm->value = '0';
  $export['node_preview_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_file';
  $strongarm->value = 0;
  $export['node_submitted_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_file_pattern';
  $strongarm->value = 'files/[node:source:title]';
  $export['pathauto_node_file_pattern'] = $strongarm;

  return $export;
}
