<?php
/**
 * @file
 * dt_banner_quote.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_banner_quote_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner_quote|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner_quote';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_quote_wrapper',
        1 => 'field_banner_author',
        2 => 'field_core_description',
        3 => 'group_blockquote',
        4 => 'group_quote_quote',
        5 => 'group_quote_author',
      ),
    ),
    'fields' => array(
      'group_quote_wrapper' => 'ds_content',
      'field_banner_author' => 'ds_content',
      'field_core_description' => 'ds_content',
      'group_blockquote' => 'ds_content',
      'group_quote_quote' => 'ds_content',
      'group_quote_author' => 'ds_content',
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
  $export['node|banner_quote|teaser'] = $ds_layout;

  return $export;
}
