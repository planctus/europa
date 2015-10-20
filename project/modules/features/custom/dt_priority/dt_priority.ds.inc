<?php
/**
 * @file
 * dt_priority.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_priority_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = '10_priorities_preprocess';
  $ds_field->label = '10 priorities preprocess';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'basic_page|*';
  $ds_field->properties = array();
  $export['10_priorities_preprocess'] = $ds_field;

  return $export;
}
