<?php
/**
 * @file
 * dt_STARTERKIT.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_STARTERKIT_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_STARTERKIT_CONTENT_NAME';
  $strongarm->value = '0';
  $export['comment_anonymous_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_info_mode_STARTERKIT_CONTENT_NAME';
  $strongarm->value = 1;
  $export['comment_info_mode_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_info_per_page_STARTERKIT_CONTENT_NAME';
  $strongarm->value = '50';
  $export['comment_info_per_page_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_STARTERKIT_CONTENT_NAME';
  $strongarm->value = 1;
  $export['comment_form_location_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_STARTERKIT_CONTENT_NAME';
  $strongarm->value = '1';
  $export['comment_preview_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_STARTERKIT_CONTENT_NAME';
  $strongarm->value = '0';
  $export['comment_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_STARTERKIT_CONTENT_NAME';
  $strongarm->value = 1;
  $export['comment_subject_field_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__STARTERKIT_CONTENT_NAME';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
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
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'scheduler_settings' => array(
          'weight' => '11',
        ),
        'language' => array(
          'weight' => '8',
        ),
        'metatags' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_STARTERKIT_CONTENT_NAME';
  $strongarm->value = 4;
  $export['language_content_type_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_STARTERKIT_CONTENT_NAME';
  $strongarm->value = array();
  $export['menu_options_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_STARTERKIT_CONTENT_NAME';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_STARTERKIT_CONTENT_NAME';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_STARTERKIT_CONTENT_NAME';
  $strongarm->value = '1';
  $export['node_preview_STARTERKIT_CONTENT_NAME'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_STARTERKIT_CONTENT_NAME';
  $strongarm->value = 1;
  $export['node_submitted_STARTERKIT_CONTENT_NAME'] = $strongarm;

  return $export;
}