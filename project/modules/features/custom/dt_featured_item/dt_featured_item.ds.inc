<?php
/**
 * @file
 * dt_featured_item.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_featured_item_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_item|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_item';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'legacy_link_title' => array(
      'weight' => '20',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|featured_item|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|featured_item|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'featured_item';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'legacy_link_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|featured_item|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_featured_item_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_item|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_item';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_featured_item_wrapper',
        1 => 'field_feat_item_image',
        2 => 'group_featured_item_left',
        3 => 'group_featured_item_right',
        4 => 'legacy_link_title',
        5 => 'field_core_description',
        6 => 'field_core_legacy_link',
      ),
    ),
    'fields' => array(
      'group_featured_item_wrapper' => 'ds_content',
      'field_feat_item_image' => 'ds_content',
      'group_featured_item_left' => 'ds_content',
      'group_featured_item_right' => 'ds_content',
      'legacy_link_title' => 'ds_content',
      'field_core_description' => 'ds_content',
      'field_core_legacy_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|featured_item|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|featured_item|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'featured_item';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_featured_item_wrapper',
        1 => 'field_feat_item_image',
        2 => 'legacy_link_title',
        3 => 'field_core_description',
        4 => 'field_core_legacy_link',
        5 => 'group_featured_item_left',
        6 => 'group_featured_item_right',
      ),
    ),
    'fields' => array(
      'group_featured_item_wrapper' => 'ds_content',
      'field_feat_item_image' => 'ds_content',
      'legacy_link_title' => 'ds_content',
      'field_core_description' => 'ds_content',
      'field_core_legacy_link' => 'ds_content',
      'group_featured_item_left' => 'ds_content',
      'group_featured_item_right' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|featured_item|teaser'] = $ds_layout;

  return $export;
}
