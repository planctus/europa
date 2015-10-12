<?php
/**
 * @file
 * dt_core.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_core_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'legacy_link_title';
  $ds_field->label = 'Legacy link title';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[node:legacy-link]">[node:title_field]</a>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['legacy_link_title'] = $ds_field;

  return $export;
}
