<?php
/**
 * @file
 * dt_banner_video.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dt_banner_video_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_select_media_type'
  $field_bases['field_select_media_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_select_media_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'image' => 'Image',
        'video' => 'Video',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
