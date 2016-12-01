<?php
/**
 * @file
 * cwt_core.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function cwt_core_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Lists';
  $picture_mapping->machine_name = 'lists';
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
        'image_style' => 'listings',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'listings_307x205',
      ),
    ),
  );
  $export['lists'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Lists Pages';
  $picture_mapping->machine_name = 'lists_pages';
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
        'image_style' => 'listings_307x205',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
  );
  $export['lists_pages'] = $picture_mapping;

  return $export;
}
