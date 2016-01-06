<?php
/**
 * @file
 * dt_banner_video.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function dt_banner_video_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Banner image';
  $picture_mapping->machine_name = 'banner_image';
  $picture_mapping->breakpoint_group = 'europa';
  $picture_mapping->mapping = array(
    'breakpoints.theme.europa.wide' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.europa.normal' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_breakpoints_theme_europa_normal_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'banner_image_breakpoints_theme_europa_normal_2x',
      ),
    ),
    'breakpoints.theme.europa.medium' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.europa.narrow' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.europa.mobile' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
  );
  $export['banner_image'] = $picture_mapping;

  return $export;
}
