<?php
/**
 * @file
 * dt_banner_video.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function dt_banner_video_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|banner_video|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'banner_video';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_banner_caption' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_banner_video_file' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|banner_video|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|banner_video|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'banner_video';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'field_banner_caption' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_banner_video_file' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|banner_video|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function dt_banner_video_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner_video|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner_video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_video_wrapper',
        1 => 'field_banner_video_file',
        2 => 'field_banner_caption',
        3 => 'field_banner_image_file',
        4 => 'field_core_description',
        5 => 'group_video_left',
        6 => 'group_video_video',
        7 => 'group_video_paragraph',
        8 => 'group_video_caption',
      ),
    ),
    'fields' => array(
      'group_video_wrapper' => 'ds_content',
      'field_banner_video_file' => 'ds_content',
      'field_banner_caption' => 'ds_content',
      'field_banner_image_file' => 'ds_content',
      'field_core_description' => 'ds_content',
      'group_video_left' => 'ds_content',
      'group_video_video' => 'ds_content',
      'group_video_paragraph' => 'ds_content',
      'group_video_caption' => 'ds_content',
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
  $export['node|banner_video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner_video|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner_video';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_video_wrapper',
        1 => 'field_banner_video_file',
        2 => 'field_banner_caption',
        3 => 'field_banner_image_file',
        4 => 'field_core_description',
        5 => 'group_video_left',
        6 => 'group_video_paragraph',
        7 => 'group_video_video',
        8 => 'group_video_caption',
      ),
    ),
    'fields' => array(
      'group_video_wrapper' => 'ds_content',
      'field_banner_video_file' => 'ds_content',
      'field_banner_caption' => 'ds_content',
      'field_banner_image_file' => 'ds_content',
      'field_core_description' => 'ds_content',
      'group_video_left' => 'ds_content',
      'group_video_paragraph' => 'ds_content',
      'group_video_video' => 'ds_content',
      'group_video_caption' => 'ds_content',
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
  $export['node|banner_video|teaser'] = $ds_layout;

  return $export;
}
