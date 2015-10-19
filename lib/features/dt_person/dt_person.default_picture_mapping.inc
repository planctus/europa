<?php
/**
 * @file
 * dt_person.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function dt_person_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Person meta';
  $picture_mapping->machine_name = 'person_meta';
  $picture_mapping->breakpoint_group = 'europa';
  $picture_mapping->mapping = array(
    'breakpoints.theme.europa.wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_2x',
      ),
    ),
    'breakpoints.theme.europa.normal' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_2x',
      ),
    ),
    'breakpoints.theme.europa.medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_2x',
      ),
    ),
    'breakpoints.theme.europa.narrow' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_2x',
      ),
    ),
    'breakpoints.theme.europa.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_1x',
      ),
      '2x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'person_80px_2x',
      ),
    ),
  );
  $export['person_meta'] = $picture_mapping;

  return $export;
}
