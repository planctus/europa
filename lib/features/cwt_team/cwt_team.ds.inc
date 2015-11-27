<?php
/**
 * @file
 * cwt_team.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cwt_team_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|team|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'team';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'social_media' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'team_meta' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'meta__item meta__item--type',
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
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'cwt_team_president' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cwt_team_role' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'cwt_team_project_team' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cwt_team_name' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_team_tagline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|team|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function cwt_team_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_meta';
  $ds_field->label = 'Team meta';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-team-subtype] ([node:field-team-term])',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['team_meta'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cwt_team_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|team|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'team';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ne_bootstrap_1col_stacked_bottom_header';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'team_meta',
        1 => 'group_team_meta',
        3 => 'title',
        4 => 'field_team_tagline',
      ),
      'central' => array(
        2 => 'cwt_team_role',
        7 => 'group_team_role',
        8 => 'group_team_links',
        9 => 'body',
        10 => 'group_team_tab_role',
        11 => 'cwt_team_president',
        12 => 'group_team_tab_project_team',
        13 => 'group_team_tabs',
        14 => 'field_team_links',
        15 => 'cwt_team_name',
        16 => 'group_team_tab_name',
        17 => 'group_team_members',
        18 => 'group_team_comissioners',
        19 => 'field_team_attachments',
        20 => 'group_team_files',
        21 => 'cwt_team_project_team',
        22 => 'social_media',
        23 => 'group_team_president',
      ),
      'bottom_header' => array(
        5 => 'group_team_top_image',
        6 => 'field_illustrative_image',
      ),
    ),
    'fields' => array(
      'team_meta' => 'left_header',
      'group_team_meta' => 'left_header',
      'cwt_team_role' => 'central',
      'title' => 'left_header',
      'field_team_tagline' => 'left_header',
      'group_team_top_image' => 'bottom_header',
      'field_illustrative_image' => 'bottom_header',
      'group_team_role' => 'central',
      'group_team_links' => 'central',
      'body' => 'central',
      'group_team_tab_role' => 'central',
      'cwt_team_president' => 'central',
      'group_team_tab_project_team' => 'central',
      'group_team_tabs' => 'central',
      'field_team_links' => 'central',
      'cwt_team_name' => 'central',
      'group_team_tab_name' => 'central',
      'group_team_members' => 'central',
      'group_team_comissioners' => 'central',
      'field_team_attachments' => 'central',
      'group_team_files' => 'central',
      'cwt_team_project_team' => 'central',
      'social_media' => 'central',
      'group_team_president' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
      'bottom_header' => 'div',
      'top' => 'div',
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|team|default'] = $ds_layout;

  return $export;
}
