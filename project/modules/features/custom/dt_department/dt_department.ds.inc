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
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_core_abbreviation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_ecorganisation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
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
  $ds_layout->layout = 'ne_bootstrap_3_6_3_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'in_page_navigation',
      ),
      'left_header' => array(
        1 => 'group_department_meta',
        2 => 'title',
        3 => 'field_core_ecorganisation',
        4 => 'field_core_abbreviation',
        5 => 'field_core_introduction',
      ),
      'central' => array(
        6 => 'group_department_responsibilit',
        7 => 'field_department_intro_sentence',
        8 => 'field_department_main_tasks',
        9 => 'field_department_tasks_desc',
        10 => 'field_department_plans_reports',
        11 => 'field_department_related_tasks',
        12 => 'field_core_topics',
        13 => 'field_core_persons',
      ),
      'right_header' => array(
        14 => 'field_core_link',
      ),
    ),
    'fields' => array(
      'in_page_navigation' => 'left',
      'group_department_meta' => 'left_header',
      'title' => 'left_header',
      'field_core_ecorganisation' => 'left_header',
      'field_core_abbreviation' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_department_responsibilit' => 'central',
      'field_department_intro_sentence' => 'central',
      'field_department_main_tasks' => 'central',
      'field_department_tasks_desc' => 'central',
      'field_department_plans_reports' => 'central',
      'field_department_related_tasks' => 'central',
      'field_core_topics' => 'central',
      'field_core_persons' => 'central',
      'field_core_link' => 'right_header',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'left' => 'div',
      'central' => 'div',
      'right' => 'div',
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
