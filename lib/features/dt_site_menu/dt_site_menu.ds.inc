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
    'topics_atoz' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_site_menu_fourth' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_site_menu_third' => array(
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
        2 => 'group_site_menu_first_left',
        3 => 'group_site_menu_first_right',
        4 => 'field_site_menu_first',
        5 => 'field_site_menu_fourth',
        6 => 'field_site_menu_second',
        7 => 'group_site_menu_third_left',
        8 => 'group_site_menu_second_left',
        9 => 'field_site_menu_third',
        10 => 'field_site_menu_fifth',
        11 => 'group_site_menu_third_right',
        12 => 'topics_atoz',
        13 => 'group_site_menu_second_right',
        14 => 'field_site_menu_sixth',
        15 => 'group_site_menu_first_row',
        16 => 'group_site_menu_second_row',
        17 => 'group_site_menu_third_row',
        18 => 'group_site_menu_container',
        19 => 'group_menu_section_first',
        20 => 'group_menu_section_second',
        21 => 'group_menu_section_third',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_site_menu' => 'ds_content',
      'group_site_menu_first_left' => 'ds_content',
      'group_site_menu_first_right' => 'ds_content',
      'field_site_menu_first' => 'ds_content',
      'field_site_menu_fourth' => 'ds_content',
      'field_site_menu_second' => 'ds_content',
      'group_site_menu_third_left' => 'ds_content',
      'group_site_menu_second_left' => 'ds_content',
      'field_site_menu_third' => 'ds_content',
      'field_site_menu_fifth' => 'ds_content',
      'group_site_menu_third_right' => 'ds_content',
      'topics_atoz' => 'ds_content',
      'group_site_menu_second_right' => 'ds_content',
      'field_site_menu_sixth' => 'ds_content',
      'group_site_menu_first_row' => 'ds_content',
      'group_site_menu_second_row' => 'ds_content',
      'group_site_menu_third_row' => 'ds_content',
      'group_site_menu_container' => 'ds_content',
      'group_menu_section_first' => 'ds_content',
      'group_menu_section_second' => 'ds_content',
      'group_menu_section_third' => 'ds_content',
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
