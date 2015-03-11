<?php
/**
 * @file
 * dt_announcement.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_announcement_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|announcement|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'changed_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|announcement|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_announcement_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_announcement_type',
        1 => 'post_date',
        2 => 'title',
        3 => 'field_core_commissioner',
        4 => 'field_core_subject',
        5 => 'field_core_department',
        6 => 'field_core_introduction',
        7 => 'body',
        8 => 'field_announcement_info',
        9 => 'field_core_link',
        10 => 'field_announcement_media',
        11 => 'comments',
      ),
    ),
    'fields' => array(
      'field_announcement_type' => 'ds_content',
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'field_core_commissioner' => 'ds_content',
      'field_core_subject' => 'ds_content',
      'field_core_department' => 'ds_content',
      'field_core_introduction' => 'ds_content',
      'body' => 'ds_content',
      'field_announcement_info' => 'ds_content',
      'field_core_link' => 'ds_content',
      'field_announcement_media' => 'ds_content',
      'comments' => 'ds_content',
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
  $export['node|announcement|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'meta';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_core_topics',
        1 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_core_topics' => 'ds_content',
      'title_field' => 'ds_content',
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
  $export['node|announcement|meta'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_announcement_type',
        1 => 'changed_date',
        2 => 'title_field',
        3 => 'field_core_introduction',
        4 => 'field_core_topics',
      ),
    ),
    'fields' => array(
      'field_announcement_type' => 'ds_content',
      'changed_date' => 'ds_content',
      'title_field' => 'ds_content',
      'field_core_introduction' => 'ds_content',
      'field_core_topics' => 'ds_content',
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
  $export['node|announcement|teaser'] = $ds_layout;

  return $export;
}
