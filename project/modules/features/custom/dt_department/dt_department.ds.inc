<?php
/**
 * @file
 * dt_department.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_department_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|department|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'department';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'in_page_navigation' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_core_topics' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|department|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_department_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'find_a_staff_member';
  $ds_field->label = 'Find a staff member';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'department|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="#"><span>Find a staff member</span></a>',
      'format' => 'basic_html',
    ),
    'use_token' => 0,
  );
  $export['find_a_staff_member'] = $ds_field;

  return $export;
}

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
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_department_meta',
        1 => 'title',
      ),
      'left' => array(
        2 => 'in_page_navigation',
      ),
      'central' => array(
        3 => 'group_department_responsibilit',
        4 => 'group_department_leadership',
        5 => 'field_core_persons',
        6 => 'group_department_contact',
        7 => 'field_core_contact',
        8 => 'field_department_organigram',
        9 => 'field_department_action_link',
        10 => 'field_department_work_areas_sent',
        11 => 'field_core_topics',
        12 => 'field_department_intro_sentence',
        13 => 'field_core_priorities',
        14 => 'field_department_tasks',
        15 => 'field_department_tasks_desc',
        16 => 'field_department_plans_reports',
        17 => 'field_department_related_tasks',
      ),
    ),
    'fields' => array(
      'group_department_meta' => 'left_header',
      'title' => 'left_header',
      'in_page_navigation' => 'left',
      'group_department_responsibilit' => 'central',
      'group_department_leadership' => 'central',
      'field_core_persons' => 'central',
      'group_department_contact' => 'central',
      'field_core_contact' => 'central',
      'field_department_organigram' => 'central',
      'field_department_action_link' => 'central',
      'field_department_work_areas_sent' => 'central',
      'field_core_topics' => 'central',
      'field_department_intro_sentence' => 'central',
      'field_core_priorities' => 'central',
      'field_department_tasks' => 'central',
      'field_department_tasks_desc' => 'central',
      'field_department_plans_reports' => 'central',
      'field_department_related_tasks' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
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
