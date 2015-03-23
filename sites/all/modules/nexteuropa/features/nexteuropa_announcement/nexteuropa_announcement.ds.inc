<?php
/**
 * @file
 * nexteuropa_announcement.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nexteuropa_announcement_ds_field_settings_info() {
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
  $ds_fieldsetting->id = 'node|announcement|grid_view';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'grid_view';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|announcement|grid_view'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|announcement|list_view';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'announcement';
  $ds_fieldsetting->view_mode = 'list_view';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|announcement|list_view'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nexteuropa_announcement_ds_layout_settings_info() {
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
        6 => 'field_announcement_image',
        7 => 'field_core_introduction',
        8 => 'body',
        9 => 'field_announcement_info',
        10 => 'field_core_link',
        11 => 'field_announcement_media',
        12 => 'comments',
      ),
    ),
    'fields' => array(
      'field_announcement_type' => 'ds_content',
      'post_date' => 'ds_content',
      'title' => 'ds_content',
      'field_core_commissioner' => 'ds_content',
      'field_core_subject' => 'ds_content',
      'field_core_department' => 'ds_content',
      'field_announcement_image' => 'ds_content',
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
  $ds_layout->id = 'node|announcement|grid_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'grid_view';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_announcement_image',
        1 => 'field_announcement_type',
        2 => 'post_date',
        3 => 'field_location',
        4 => 'title',
        5 => 'field_core_introduction',
      ),
    ),
    'fields' => array(
      'field_announcement_image' => 'ds_content',
      'field_announcement_type' => 'ds_content',
      'post_date' => 'ds_content',
      'field_location' => 'ds_content',
      'title' => 'ds_content',
      'field_core_introduction' => 'ds_content',
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
  $export['node|announcement|grid_view'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|announcement|list_view';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'announcement';
  $ds_layout->view_mode = 'list_view';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_announcement_image',
        1 => 'field_announcement_type',
        2 => 'post_date',
        3 => 'field_location',
        4 => 'title',
        5 => 'field_related_topics',
      ),
    ),
    'fields' => array(
      'field_announcement_image' => 'ds_content',
      'field_announcement_type' => 'ds_content',
      'post_date' => 'ds_content',
      'field_location' => 'ds_content',
      'title' => 'ds_content',
      'field_related_topics' => 'ds_content',
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
  $export['node|announcement|list_view'] = $ds_layout;

  return $export;
}
