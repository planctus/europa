<?php
/**
 * @file
 * cwt_blogs.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cwt_blogs_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_com_blog_image'
  $field_bases['field_com_blog_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_com_blog_image',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}