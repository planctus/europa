<?php
/**
 * @file
 * dt_site_menu.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_site_menu_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'bean|site_menu|default';
  $ds_fieldsetting->entity_type = 'bean';
  $ds_fieldsetting->bundle = 'site_menu';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_site_menu_classes' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['bean|site_menu|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_site_menu_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|site_menu|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'site_menu';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'group_site_menu',
        2 => 'field_site_menu_links',
        3 => 'group_menu_section_first',
        4 => 'field_site_menu_topic_link',
        5 => 'field_site_menu_classes',
        6 => 'group_site_menu_first_row',
        7 => 'group_site_menu_first_left',
        8 => 'group_site_menu_first_right',
        9 => 'group_site_menu_container',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_site_menu' => 'ds_content',
      'field_site_menu_links' => 'ds_content',
      'group_menu_section_first' => 'ds_content',
      'field_site_menu_topic_link' => 'ds_content',
      'field_site_menu_classes' => 'ds_content',
      'group_site_menu_first_row' => 'ds_content',
      'group_site_menu_first_left' => 'ds_content',
      'group_site_menu_first_right' => 'ds_content',
      'group_site_menu_container' => 'ds_content',
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
  $export['bean|site_menu|default'] = $ds_layout;

  return $export;
}
