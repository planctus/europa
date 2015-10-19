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
    'cwt_team_president' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'cwt_team_role' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
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
      'central' => array(
        0 => 'body',
        1 => 'cwt_team_role',
        2 => 'field_team_links',
        3 => 'group_team_members',
        4 => 'group_team_tabs',
        5 => 'group_team_tab_role',
        6 => 'cwt_team_name',
        7 => 'group_team_tab_project_team',
        8 => 'cwt_team_president',
        9 => 'group_team_tab_name',
        10 => 'group_team_name_wrapper',
        11 => 'cwt_team_project_team',
        12 => 'group_team_president',
        13 => 'group_team_project_team_wrapper',
        14 => 'group_team_role_wrapper',
      ),
    ),
    'fields' => array(
      'body' => 'central',
      'cwt_team_role' => 'central',
      'field_team_links' => 'central',
      'group_team_members' => 'central',
      'group_team_tabs' => 'central',
      'group_team_tab_role' => 'central',
      'cwt_team_name' => 'central',
      'group_team_tab_project_team' => 'central',
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
