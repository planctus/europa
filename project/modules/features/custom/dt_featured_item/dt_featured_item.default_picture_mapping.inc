<?php
/**
 * @file
 * dt_featured_item.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function dt_featured_item_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Featured Item';
  $picture_mapping->machine_name = 'featured_item';
  $picture_mapping->breakpoint_group = 'europa';
  $picture_mapping->mapping = array(
    'breakpoints.theme.europa.wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_wide_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_wide_2x',
      ),
    ),
    'breakpoints.theme.europa.normal' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_normal_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_normal_2x',
      ),
    ),
    'breakpoints.theme.europa.medium' => array(
      '1x' => array(
        'mapping_type' => '_none',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_medium_1x',
      ),
    ),
    'breakpoints.theme.europa.narrow' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_medium_2x',
      ),
      '2x' => array(
        'mapping_type' => '_none',
      ),
    ),
    'breakpoints.theme.europa.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_mobile_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'featured_item_responsivebreakpoints_theme_europa_mobile_2x',
      ),
    ),
  );
  $export['featured_item'] = $picture_mapping;

  return $export;
}
