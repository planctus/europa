<?php
/**
 * @file
 * cwt_core.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwt_core_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'collapse_button';
  $ds_field->label = 'Collapse button';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'comment' => 'comment',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<button class="btn btn-collapse" type="button" data-toggle="collapse" data-target="#collapse" aria-expanded="false" aria-controls="collapse"><span class="toggling-text"></span>[node:field-core-collapse-button-text]<i class="icon icon--blue-dark icon--down"></i></button>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['collapse_button'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'content_type_label';
  $ds_field->label = 'Content type label';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:content-type]',
      'format' => 'basic_html',
    ),
    'use_token' => 1,
  );
  $export['content_type_label'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_media';
  $ds_field->label = 'Social media';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'social_bookmark|social-bar',
    'block_render' => '3',
  );
  $export['social_media'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function cwt_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'meta';
  $ds_view_mode->label = 'Meta';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['meta'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'title';
  $ds_view_mode->label = 'Title';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['title'] = $ds_view_mode;

  return $export;
}
