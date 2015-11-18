<?php
/**
 * @file
 * dt_social_bookmarks.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function dt_social_bookmarks_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_bookmarks';
  $ds_field->label = 'Social Bookmarks';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'bean|social-bookmarking---web-tools',
    'block_render' => '1',
  );
  $export['social_bookmarks'] = $ds_field;

  return $export;
}
