<?php
/**
 * @file
 * cwt_team.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function cwt_team_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Team Cabinet Image';
  $picture_mapping->machine_name = 'team_cabinet_image';
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
        'mapping_type' => '_none',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'listings_307x205',
      ),
    ),
  );
  $export['team_cabinet_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Team Cabinet Members Picture';
  $picture_mapping->machine_name = 'team_cabinet_members_picture';
  $picture_mapping->breakpoint_group = 'default_responsive_imags';
  $picture_mapping->mapping = array(
    'custom.user.max_width_479px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'team_members_90x90',
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
        'image_style' => 'team_members_130x130',
      ),
    ),
  );
  $export['team_cabinet_members_picture'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Team Image';
  $picture_mapping->machine_name = 'team_image';
  $picture_mapping->breakpoint_group = 'default_responsive_imags';
  $picture_mapping->mapping = array(
    'custom.user.max_width_479px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'team_image_480px',
      ),
    ),
    'custom.user.min_width_960px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'team_image_1280px',
      ),
    ),
    'custom.user.min_width_480px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'team_image_960px',
      ),
    ),
  );
  $export['team_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Team Members Picture';
  $picture_mapping->machine_name = 'team_members_picture';
  $picture_mapping->breakpoint_group = 'default_responsive_imags';
  $picture_mapping->mapping = array(
    'custom.user.max_width_479px' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'team_members_image_style',
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
        'image_style' => 'members_responsive_custom_user_min_width_480px_1x',
      ),
    ),
  );
  $export['team_members_picture'] = $picture_mapping;

  return $export;
}
