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
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_activity_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'meta__item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_activity_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_nexteuropa_formatters_meta_item',
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
    'content_type_label' => array(
      'formatter_settings' => array(
        'ft' => array(
          'meta_modifier' => 'meta__item--type',
        ),
      ),
    ),
  );
  $export['node|activities|teaser'] = $ds_fieldsetting;

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
    'regions' => array(
      'main' => array(
        0 => 'group_activity_left',
        1 => 'field_activity_type',
        2 => 'group_activity_right',
        3 => 'group_agenda_meta',
        4 => 'field_activity_address',
        5 => 'title',
        6 => 'agenda_with_who',
        7 => 'field_start_end_date',
      ),
    ),
    'fields' => array(
      'group_activity_left' => 'main',
      'field_activity_type' => 'main',
      'group_activity_right' => 'main',
      'group_agenda_meta' => 'main',
      'field_activity_address' => 'main',
      'title' => 'main',
      'agenda_with_who' => 'main',
      'field_start_end_date' => 'main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'main' => 'div',
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
