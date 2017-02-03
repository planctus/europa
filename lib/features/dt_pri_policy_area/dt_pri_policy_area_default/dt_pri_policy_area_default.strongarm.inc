<?php
/**
 * @file
 * dt_pri_policy_area_default.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dt_pri_policy_area_default_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__priority_policy_area';
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
        'custom_settings' => FALSE,
      ),
      'structured_navigation' => array(
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
      'hero_links' => array(
        'custom_settings' => FALSE,
      ),
      'image_label' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_informational' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_political' => array(
        'custom_settings' => FALSE,
      ),
      'job' => array(
        'custom_settings' => FALSE,
      ),
      'event_speaker' => array(
        'custom_settings' => FALSE,
      ),
      'name' => array(
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
          'weight' => '15',
        ),
        'language' => array(
          'weight' => '12',
        ),
        'metatags' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__priority_policy_area'] = $strongarm;

  return $export;
}
