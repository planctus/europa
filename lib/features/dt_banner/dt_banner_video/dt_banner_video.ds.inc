<?php
/**
 * @file
 * dt_banner_video.ds.inc
 */

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
