<?php
/**
 * @file
 * dt_event_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_event_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'book_your_seat' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'livestreaming' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'dt_event_header' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_event_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
  );
  $export['node|event|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_event_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_advanced_top_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_meta',
        1 => 'title',
        2 => 'dt_event_header',
        3 => 'field_event_type',
      ),
      'top_middle_right' => array(
        4 => 'field_core_introduction',
        5 => 'book_your_seat',
        6 => 'livestreaming',
      ),
    ),
    'fields' => array(
      'group_meta' => 'left_header',
      'title' => 'left_header',
      'dt_event_header' => 'left_header',
      'field_event_type' => 'left_header',
      'field_core_introduction' => 'top_middle_right',
      'book_your_seat' => 'top_middle_right',
      'livestreaming' => 'top_middle_right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top_top' => 'div',
      'top_middle_left' => 'div',
      'top_middle_right' => 'div',
      'top_bottom_left' => 'div',
      'top_bottom_right' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|full'] = $ds_layout;

  return $export;
}
