<?php
/**
 * @file
 * dt_core.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 *
 * SocialMedia Bookmark field from Webtools,
 * this field will be used in Info + Pol websites.
 */
function dt_core_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_bookmark_webtools';
  $ds_field->label = 'Social Bookmark Webtools';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'dt_social_media_sharing|social_media_sharing',
    'block_render' => '1',
  );
  $export['social_bookmark_webtools'] = $ds_field;

  return $export;
}