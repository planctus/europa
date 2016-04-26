<?php
/**
 * @file
 * dt_event.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_event_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dt_event_header';
  $ds_field->label = 'Dt event header';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'event|full';
  $ds_field->properties = array();
  $export['dt_event_header'] = $ds_field;

  return $export;
}
