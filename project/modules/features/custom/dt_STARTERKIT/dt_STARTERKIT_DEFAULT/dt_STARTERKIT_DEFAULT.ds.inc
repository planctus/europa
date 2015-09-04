<?php
/**
 * @file
 * dt_STARTERKIT_DEFAULT.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_STARTERKIT_DEFAULT_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|STARTERKIT_CONTENT_NAME|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'STARTERKIT_CONTENT_NAME';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'listing__title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_STARTERKIT_CONTENT_NAME_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_core_introduction' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|STARTERKIT_CONTENT_NAME|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_STARTERKIT_DEFAULT_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|STARTERKIT_CONTENT_NAME|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'STARTERKIT_CONTENT_NAME';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_STARTERKIT_CONTENT_NAME_meta',
        1 => 'title_field',
        2 => 'field_core_introduction',
        3 => 'field_STARTERKIT_CONTENT_NAME_type',
      ),
    ),
    'fields' => array(
      'group_STARTERKIT_CONTENT_NAME_meta' => 'main',
      'title_field' => 'main',
      'field_core_introduction' => 'main',
      'field_STARTERKIT_CONTENT_NAME_type' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'second' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|STARTERKIT_CONTENT_NAME|teaser'] = $ds_layout;

  return $export;
}
