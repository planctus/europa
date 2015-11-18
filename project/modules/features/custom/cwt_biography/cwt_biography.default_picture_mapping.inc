<?php
/**
 * @file
 * cwt_biography.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function cwt_biography_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Biography portrait large';
  $picture_mapping->machine_name = 'biography_portrait_large';
  $picture_mapping->breakpoint_group = 'default_responsive_imags';
  $picture_mapping->mapping = array(
    'custom.user.max_width_479px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'biography_portrait_large_400px',
      ),
    ),
    'custom.user.min_width_960px' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'biography_portrait_large_500px',
      ),
    ),
  );
  $export['biography_portrait_large'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Biography team';
  $picture_mapping->machine_name = 'biography_team';
  $picture_mapping->breakpoint_group = 'default_responsive_imags';
  $picture_mapping->mapping = array(
    'custom.user.min_width_960px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'team_photo_small',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['biography_team'] = $picture_mapping;

  return $export;
}
