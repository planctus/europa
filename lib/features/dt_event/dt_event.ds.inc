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
  $ds_field->field = 'event_related_events';
  $ds_field->label = 'Event: Related events';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'event|*';
  $ds_field->properties = array(
    'block' => 'views|related_events-block',
    'block_render' => '2',
  );
  $export['event_related_events'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function dt_event_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'event_collection';
  $ds_view_mode->label = 'Event: Collection';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['event_collection'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'event_past';
  $ds_view_mode->label = 'Event: Past';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['event_past'] = $ds_view_mode;

  return $export;
}
