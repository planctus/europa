<?php
/**
 * @file
 * cwt_activities.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwt_activities_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|activities|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'activities';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'agenda_with_who' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'listing__author',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'content_type_label' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'meta__item meta__item--type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => 'listing__title',
        'ft' => array(),
      ),
    ),
  );
  $export['node|activities|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwt_activities_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'agenda_with_who';
  $ds_field->label = 'Agenda with who';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'activities|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => 'With: [node:field-editorial-section:name_field]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['agenda_with_who'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwt_activities_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|activities|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'activities';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ne_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'regions' => array(
      'main' => array(
        0 => 'group_activity_left',
        1 => 'group_activity_right',
        2 => 'group_agenda_meta',
        3 => 'title',
        4 => 'agenda_with_who',
        5 => 'field_start_end_date',
        6 => 'content_type_label',
      ),
    ),
    'fields' => array(
      'group_activity_left' => 'main',
      'group_activity_right' => 'main',
      'group_agenda_meta' => 'main',
      'title' => 'main',
      'agenda_with_who' => 'main',
      'field_start_end_date' => 'main',
      'content_type_label' => 'main',
    ),
  );
  $export['node|activities|teaser'] = $ds_layout;

  return $export;
}
