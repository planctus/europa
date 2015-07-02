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
    'field_site_menu_third' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing--title listing--no-border',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'listing__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_site_menu_fourth' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing--title listing--no-border',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'listing__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_site_menu_fifth' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'listing--title listing--no-border',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'listing__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
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
        2 => 'group_site_menu_first_row',
        3 => 'group_site_menu_second_row',
        4 => 'group_site_menu_first_left',
        5 => 'group_site_menu_third_row',
        6 => 'field_site_menu_first',
        7 => 'group_site_menu_first_right',
        8 => 'field_site_menu_fourth',
        9 => 'field_site_menu_second',
        10 => 'group_site_menu_third_left',
        11 => 'group_site_menu_second_left',
        12 => 'field_site_menu_third',
        13 => 'group_site_menu_third_right',
        14 => 'field_site_menu_fifth',
        15 => 'group_site_menu_second_right',
        16 => 'field_site_menu_sixth',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_site_menu' => 'ds_content',
      'group_site_menu_first_row' => 'ds_content',
      'group_site_menu_second_row' => 'ds_content',
      'group_site_menu_first_left' => 'ds_content',
      'group_site_menu_third_row' => 'ds_content',
      'field_site_menu_first' => 'ds_content',
      'group_site_menu_first_right' => 'ds_content',
      'field_site_menu_fourth' => 'ds_content',
      'field_site_menu_second' => 'ds_content',
      'group_site_menu_third_left' => 'ds_content',
      'group_site_menu_second_left' => 'ds_content',
      'field_site_menu_third' => 'ds_content',
      'group_site_menu_third_right' => 'ds_content',
      'field_site_menu_fifth' => 'ds_content',
      'group_site_menu_second_right' => 'ds_content',
      'field_site_menu_sixth' => 'ds_content',
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
