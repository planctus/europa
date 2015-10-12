<?php
/**
 * @file
 * dt_banner_quote.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_banner_quote_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|banner_quote|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'banner_quote';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'blockquote_author' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'blockquote_text' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|banner_quote|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|banner_quote|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'banner_quote';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'blockquote_author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'blockquote_text' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|banner_quote|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_banner_quote_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'blockquote_author';
  $ds_field->label = 'Blockquote author';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'banner_quote|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => ' - [node:field_banner_author]',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['blockquote_author'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'blockquote_text';
  $ds_field->label = 'Blockquote description';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'banner_quote|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class="blockquote__open"></span>[node:field_core_description]<span class="blockquote__close"></span>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['blockquote_text'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_banner_quote_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner_quote|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner_quote';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_quote_wrapper',
        1 => 'blockquote_text',
        2 => 'blockquote_author',
        3 => 'group_quote_quote',
        4 => 'group_blockquote',
        5 => 'group_quote_author',
      ),
    ),
    'fields' => array(
      'group_quote_wrapper' => 'ds_content',
      'blockquote_text' => 'ds_content',
      'blockquote_author' => 'ds_content',
      'group_quote_quote' => 'ds_content',
      'group_blockquote' => 'ds_content',
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
  $export['node|banner_quote|default'] = $ds_layout;

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
        0 => 'blockquote_author',
        1 => 'blockquote_text',
        2 => 'group_quote_wrapper',
        3 => 'group_quote_quote',
        4 => 'group_blockquote',
        5 => 'group_quote_author',
      ),
    ),
    'fields' => array(
      'blockquote_author' => 'ds_content',
      'blockquote_text' => 'ds_content',
      'group_quote_wrapper' => 'ds_content',
      'group_quote_quote' => 'ds_content',
      'group_blockquote' => 'ds_content',
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
