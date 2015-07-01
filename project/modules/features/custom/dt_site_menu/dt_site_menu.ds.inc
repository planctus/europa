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
    'field_site_menu_first' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_site_menu_second' => array(
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
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_site_menu_first',
        2 => 'field_site_menu_third',
        3 => 'field_site_menu_fifth',
      ),
      'right' => array(
        4 => 'field_site_menu_second',
        5 => 'field_site_menu_fourth',
        6 => 'field_site_menu_sixth',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_site_menu_first' => 'left',
      'field_site_menu_third' => 'left',
      'field_site_menu_fifth' => 'left',
      'field_site_menu_second' => 'right',
      'field_site_menu_fourth' => 'right',
      'field_site_menu_sixth' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['bean|site_menu|default'] = $ds_layout;

  return $export;
}
