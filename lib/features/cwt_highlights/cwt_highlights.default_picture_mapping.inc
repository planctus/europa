<?php
/**
 * @file
 * cwt_highlights.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function cwt_highlights_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Highlight item image';
  $picture_mapping->machine_name = 'highlight_item_image';
  $picture_mapping->breakpoint_group = 'default_responsive_imags';
  $picture_mapping->mapping = array(
    'custom.user.max_width_479px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
    'custom.user.min_width_960px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'highlight_item_image_290x193',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'highlight_item_image_160x122',
      ),
    ),
  );
  $export['highlight_item_image'] = $picture_mapping;

  return $export;
}
