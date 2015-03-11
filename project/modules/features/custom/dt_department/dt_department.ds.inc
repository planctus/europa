<?php
/**
 * @file
 * dt_department.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_department_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|department|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'department';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_core_abbreviation',
        1 => 'field_department_intro_sentence',
        2 => 'field_department_plans_reports',
        3 => 'field_department_contact',
        4 => 'field_department_main_tasks',
        5 => 'field_core_ecorganisation',
        6 => 'field_core_link',
        7 => 'field_core_priorities',
      ),
    ),
    'fields' => array(
      'field_core_abbreviation' => 'ds_content',
      'field_department_intro_sentence' => 'ds_content',
      'field_department_plans_reports' => 'ds_content',
      'field_department_contact' => 'ds_content',
      'field_department_main_tasks' => 'ds_content',
      'field_core_ecorganisation' => 'ds_content',
      'field_core_link' => 'ds_content',
      'field_core_priorities' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|department|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|department|meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'department';
  $ds_layout->view_mode = 'meta';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_core_ecorganisation',
        1 => 'field_core_abbreviation',
        2 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_core_ecorganisation' => 'ds_content',
      'field_core_abbreviation' => 'ds_content',
      'title_field' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => 'content',
    'layout_link_custom' => '',
  );
  $export['node|department|meta'] = $ds_layout;

  return $export;
}
