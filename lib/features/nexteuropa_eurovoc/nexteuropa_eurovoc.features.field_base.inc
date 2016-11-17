<?php

/**
 * @file
 * nexteuropa_eurovoc.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nexteuropa_eurovoc_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_eurovoc_id'.
  $field_bases['field_eurovoc_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_eurovoc_id',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_eurovoc_level'.
  $field_bases['field_eurovoc_level'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_eurovoc_level',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_eurovoc_related'.
  $field_bases['field_eurovoc_related'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_eurovoc_related',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'extended_base',
      'handler_settings' => array(
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'eurovoc' => 'eurovoc',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_eurovoc_taxonomy'.
  $field_bases['field_eurovoc_taxonomy'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_eurovoc_taxonomy',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'behaviors' => array(),
      'entity_translation_sync' => FALSE,
      'handler' => 'extended_base',
      'handler_settings' => array(
        'behaviors' => array(
          'titleoverwrite_field_behavior' => array(
            'status' => 0,
          ),
          'tmgmt_field_behavior' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'eurovoc' => 'eurovoc',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_eurovoc_ui'.
  $field_bases['field_eurovoc_ui'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_eurovoc_ui',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'extended_base',
      'handler_settings' => array(
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'eurovoc' => 'eurovoc',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
