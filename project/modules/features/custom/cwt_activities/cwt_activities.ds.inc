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
      'weight' => '2',
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
          'fi-cl' => 'listing__meta-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
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
  $ds_layout->layout = 'ne_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'main' => array(
        0 => 'group_agenda_meta',
        1 => 'title',
        2 => 'agenda_with_who',
        4 => 'content_type_label',
      ),
      'second' => array(
        3 => 'field_start_end_date',
      ),
    ),
    'fields' => array(
      'group_agenda_meta' => 'main',
      'title' => 'main',
      'agenda_with_who' => 'main',
      'field_start_end_date' => 'second',
      'content_type_label' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
      'second' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|activities|teaser'] = $ds_layout;

  return $export;
}
