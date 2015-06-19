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
    'topics_atoz' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'listing--footer',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'pull-right',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|info_homepage|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_info_homepage_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'topics_atoz';
  $ds_field->label = 'Topics A-Z';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a class="btn btn-ctn " href="/topics">Topics A-Z</a>',
      'format' => 'basic_html',
    ),
    'use_token' => 0,
  );
  $export['topics_atoz'] = $ds_field;

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
      'left_header' => array(
        0 => 'field_core_introduction',
      ),
      'central' => array(
        1 => 'field_info_homepage_section_1',
        2 => 'field_info_homepage_section_2',
        3 => 'group_highlight',
        4 => 'field_info_homepage_section_4',
        5 => 'field_info_homepage_section_3',
        6 => 'group_latest',
        7 => 'topics_atoz',
        8 => 'group_latest_main',
        9 => 'group_latest_sidebar',
        10 => 'field_core_social_network_links',
      ),
    ),
    'fields' => array(
      'field_core_introduction' => 'left_header',
      'field_info_homepage_section_1' => 'central',
      'field_info_homepage_section_2' => 'central',
      'group_highlight' => 'central',
      'field_info_homepage_section_4' => 'central',
      'field_info_homepage_section_3' => 'central',
      'group_latest' => 'central',
      'topics_atoz' => 'central',
      'group_latest_main' => 'central',
      'group_latest_sidebar' => 'central',
      'field_core_social_network_links' => 'central',
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
