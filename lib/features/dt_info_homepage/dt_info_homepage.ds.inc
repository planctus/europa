<?php
/**
 * @file
 * dt_info_homepage.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_info_homepage_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|info_homepage|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'info_homepage';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_info_highlights' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|info_homepage|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_info_homepage_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|info_homepage|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'info_homepage';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'field_core_introduction',
      ),
    ),
    'fields' => array(
      'field_core_introduction' => 'left_header',
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
  $export['node|info_homepage|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|info_homepage|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'info_homepage';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_info_homepage_topic_intro',
        2 => 'group_info_homepage_section_top',
        3 => 'field_info_homepage_topic_link',
        4 => 'field_info_homepage_section_1',
        5 => 'group_info_homepage_section_bot',
        6 => 'field_info_homepage_section_4',
        7 => 'group_info_highlights',
        8 => 'group_topics',
        9 => 'field_info_highlights',
      ),
      'left_header' => array(
        1 => 'field_core_introduction',
      ),
    ),
    'fields' => array(
      'field_info_homepage_topic_intro' => 'central',
      'field_core_introduction' => 'left_header',
      'group_info_homepage_section_top' => 'central',
      'field_info_homepage_topic_link' => 'central',
      'field_info_homepage_section_1' => 'central',
      'group_info_homepage_section_bot' => 'central',
      'field_info_homepage_section_4' => 'central',
      'group_info_highlights' => 'central',
      'group_topics' => 'central',
      'field_info_highlights' => 'central',
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
  $export['node|info_homepage|full'] = $ds_layout;

  return $export;
}
