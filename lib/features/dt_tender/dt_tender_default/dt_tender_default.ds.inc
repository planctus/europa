<?php

/**
 * @file
 * dt_tender_default.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_tender_default_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tender|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tender';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'in_page_navigation' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_tender_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|tender|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tender|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tender';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'content_type_label' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|tender|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_tender_default_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tender|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tender';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked_conditional';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'group_tender_meta',
        1 => 'content_type_label',
        2 => 'field_tender_status',
        3 => 'title',
        4 => 'field_core_introduction',
      ),
      'left' => array(
        5 => 'in_page_navigation',
      ),
      'central' => array(
        6 => 'body',
        7 => 'field_core_departments',
        8 => 'group_tender_departments',
        9 => 'group_tender_topics',
        10 => 'field_core_topics',
      ),
    ),
    'fields' => array(
      'group_tender_meta' => 'left_header',
      'content_type_label' => 'left_header',
      'field_tender_status' => 'left_header',
      'title' => 'left_header',
      'field_core_introduction' => 'left_header',
      'in_page_navigation' => 'left',
      'body' => 'central',
      'field_core_departments' => 'central',
      'group_tender_departments' => 'central',
      'group_tender_topics' => 'central',
      'field_core_topics' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|tender|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tender|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tender';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_2col_sidebar_no_link';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_tender_meta',
        1 => 'title_field',
        2 => 'field_core_description',
        3 => 'content_type_label',
      ),
    ),
    'fields' => array(
      'group_tender_meta' => 'main',
      'title_field' => 'main',
      'field_core_description' => 'main',
      'content_type_label' => 'main',
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
  $export['node|tender|teaser'] = $ds_layout;

  return $export;
}
