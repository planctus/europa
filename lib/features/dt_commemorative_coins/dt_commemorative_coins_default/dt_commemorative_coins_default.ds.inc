<?php
/**
 * @file
 * dt_commemorative_coins_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_commemorative_coins_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|commemorative_coins|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'commemorative_coins';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'field_core_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|commemorative_coins|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_commemorative_coins_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|commemorative_coins|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'commemorative_coins';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_hitme';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'field_cc_subject',
        1 => 'field_core_description',
        2 => 'field_nal_country',
        3 => 'field_cc_date',
        4 => 'field_cc_volume',
        5 => 'field_core_link',
        6 => 'field_cc_issue_page',
      ),
      'second' => array(
        7 => 'field_core_image',
      ),
    ),
    'fields' => array(
      'field_cc_subject' => 'main',
      'field_core_description' => 'main',
      'field_nal_country' => 'main',
      'field_cc_date' => 'main',
      'field_cc_volume' => 'main',
      'field_core_link' => 'main',
      'field_cc_issue_page' => 'main',
      'field_core_image' => 'second',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'second' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|commemorative_coins|teaser'] = $ds_layout;

  return $export;
}
