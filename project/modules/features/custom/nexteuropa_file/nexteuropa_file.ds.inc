<?php
/**
 * @file
 * nexteuropa_file.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function nexteuropa_file_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|file|file';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'file';
  $ds_layout->view_mode = 'file';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_core_file',
      ),
    ),
    'fields' => array(
      'field_core_file' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|file|file'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function nexteuropa_file_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'file';
  $ds_view_mode->label = 'File';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['file'] = $ds_view_mode;

  return $export;
}
