<?php
/**
 * @file
 * cwt_biography.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwt_biography_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|biography|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'biography';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'agenda_block' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'announcements_block' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'biography_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'blog_block' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'timeline_block' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'in_page_navigation' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|biography|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwt_biography_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'agenda_block';
  $ds_field->label = 'Agenda block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|activities-block',
    'block_render' => '3',
  );
  $export['agenda_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'announcements_block';
  $ds_field->label = 'Announcements Block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_news-block',
    'block_render' => '3',
  );
  $export['announcements_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'biography_header';
  $ds_field->label = 'Biography header';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_header-header',
    'block_render' => '3',
  );
  $export['biography_header'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'blog_block';
  $ds_field->label = 'Blog block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|blog_commisioner_bio-block',
    'block_render' => '3',
  );
  $export['blog_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'timeline_block';
  $ds_field->label = 'Timeline block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'biography|full';
  $ds_field->properties = array(
    'block' => 'views|biography_timeline-block',
    'block_render' => '3',
  );
  $export['timeline_block'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwt_biography_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|biography|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'biography';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ne_bootstrap_3_9_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'biography_header',
      ),
      'left' => array(
        1 => 'in_page_navigation',
      ),
      'central' => array(
        2 => 'body',
        3 => 'group_bio_role',
        4 => 'group_bio_team',
        5 => 'group_bio_news',
        6 => 'announcements_block',
        7 => 'group_bio_agenda',
        8 => 'group_bio_blog',
        9 => 'agenda_block',
        10 => 'blog_block',
        11 => 'timeline_block',
        12 => 'group_bio_timeline',
        13 => 'field_biography_team',
      ),
    ),
    'fields' => array(
      'biography_header' => 'left_header',
      'in_page_navigation' => 'left',
      'body' => 'central',
      'group_bio_role' => 'central',
      'group_bio_team' => 'central',
      'group_bio_news' => 'central',
      'announcements_block' => 'central',
      'group_bio_agenda' => 'central',
      'group_bio_blog' => 'central',
      'agenda_block' => 'central',
      'blog_block' => 'central',
      'timeline_block' => 'central',
      'group_bio_timeline' => 'central',
      'field_biography_team' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'top' => 'div',
      'left' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|biography|full'] = $ds_layout;

  return $export;
}
