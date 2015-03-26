<?php
/**
 * @file
 * dt_person.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_person_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|person|meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'person';
  $ds_layout->view_mode = 'meta';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_person_first_name',
        1 => 'field_person_last_name',
        2 => 'field_person_photo',
        3 => 'field_core_topics',
      ),
    ),
    'fields' => array(
      'field_person_first_name' => 'ds_content',
      'field_person_last_name' => 'ds_content',
      'field_person_photo' => 'ds_content',
      'field_core_topics' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|person|meta'] = $ds_layout;

  return $export;
}
