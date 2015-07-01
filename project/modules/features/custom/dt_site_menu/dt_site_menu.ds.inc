<?php
/**
 * @file
 * dt_site_menu.ds.inc
 */

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
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'title',
        1 => 'group_site_menu_first_row',
        2 => 'field_site_menu_first',
        3 => 'group_site_menu_second_row',
        4 => 'field_site_menu_second',
        5 => 'field_site_menu_third',
        6 => 'group_site_menu_third_row',
        7 => 'field_site_menu_fifth',
        8 => 'field_site_menu_fourth',
        9 => 'field_site_menu_sixth',
      ),
    ),
    'fields' => array(
      'title' => 'main',
      'group_site_menu_first_row' => 'main',
      'field_site_menu_first' => 'main',
      'group_site_menu_second_row' => 'main',
      'field_site_menu_second' => 'main',
      'field_site_menu_third' => 'main',
      'group_site_menu_third_row' => 'main',
      'field_site_menu_fifth' => 'main',
      'field_site_menu_fourth' => 'main',
      'field_site_menu_sixth' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
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
