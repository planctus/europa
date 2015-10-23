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
    'title' => array(
      'weight' => '0',
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
    'field_team_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'section section__group',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'sidebar-field-group__main',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|team|default'] = $ds_fieldsetting;

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
  $ds_layout->layout = 'ne_bootstrap_1col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_header' => array(
        0 => 'title',
      ),
      'central' => array(
        1 => 'cwt_team_role',
        2 => 'field_illustrative_image',
        3 => 'body',
        4 => 'field_team_links',
        5 => 'group_team_members',
        6 => 'group_team_tab_role',
        7 => 'cwt_team_name',
        8 => 'group_team_tab_project_team',
        9 => 'group_team_comissioners',
        10 => 'group_team_tabs',
        11 => 'cwt_team_president',
        12 => 'group_team_tab_name',
        13 => 'group_team_name_wrapper',
        14 => 'cwt_team_project_team',
        15 => 'group_team_president',
        16 => 'group_team_project_team_wrapper',
        17 => 'group_team_role_wrapper',
      ),
    ),
    'fields' => array(
      'title' => 'left_header',
      'cwt_team_role' => 'central',
      'field_illustrative_image' => 'central',
      'body' => 'central',
      'field_team_links' => 'central',
      'group_team_members' => 'central',
      'group_team_tab_role' => 'central',
      'cwt_team_name' => 'central',
      'group_team_tab_project_team' => 'central',
      'group_team_comissioners' => 'central',
      'group_team_tabs' => 'central',
      'cwt_team_president' => 'central',
      'group_team_tab_name' => 'central',
      'group_team_name_wrapper' => 'central',
      'cwt_team_project_team' => 'central',
      'group_team_president' => 'central',
      'group_team_project_team_wrapper' => 'central',
      'group_team_role_wrapper' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left_header' => 'div',
      'right_header' => 'div',
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
