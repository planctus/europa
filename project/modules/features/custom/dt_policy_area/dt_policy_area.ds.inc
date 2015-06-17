<?php
/**
 * @file
 * dt_policy_area.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_policy_area_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|policy_area|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'policy_area';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'children_policy_areas' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'content_type_label' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
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
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h1',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_persons' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Related commissioners',
        ),
      ),
    ),
  );
  $export['node|policy_area|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_policy_area_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'children_policy_areas';
  $ds_field->label = 'Children policy areas';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'policy_area|*';
  $ds_field->properties = array(
    'block' => 'views|ba106683ecf39aa60372ee99a00fd9aa',
    'block_render' => '1',
  );
  $export['children_policy_areas'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'content_type_label';
  $ds_field->label = 'Content type label';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:content-type]
',
      'format' => 'filtered_html',
    ),
    'use_token' => 1,
  );
  $export['content_type_label'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_policy_area_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|policy_area|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'policy_area';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_policy_area_meta',
        2 => 'title_field',
        3 => 'content_type_label',
        4 => 'field_core_introduction',
      ),
      'central' => array(
        1 => 'children_policy_areas',
      ),
      'top' => array(
        5 => 'group_policy_area_contextual',
        6 => 'field_core_persons',
      ),
    ),
    'fields' => array(
      'group_policy_area_meta' => 'left_header',
      'children_policy_areas' => 'central',
      'title_field' => 'left_header',
      'content_type_label' => 'left_header',
      'field_core_introduction' => 'left_header',
      'group_policy_area_contextual' => 'top',
      'field_core_persons' => 'top',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|policy_area|full'] = $ds_layout;

  return $export;
}
