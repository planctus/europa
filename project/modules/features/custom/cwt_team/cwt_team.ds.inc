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
      'central' => array(
        0 => 'cwt_team_role',
        4 => 'group_team_role_wrapper',
        8 => 'body',
        9 => 'group_team_tab_role',
        10 => 'group_team_tabs',
        11 => 'cwt_team_president',
        12 => 'group_team_tab_project_team',
        13 => 'field_team_links',
        14 => 'cwt_team_name',
        15 => 'group_team_members',
        16 => 'group_team_name_wrapper',
        17 => 'group_team_tab_name',
        18 => 'group_team_comissioners',
        19 => 'cwt_team_project_team',
        20 => 'group_team_project_team_wrapper',
        21 => 'group_team_president',
      ),
      'left_header' => array(
        1 => 'group_team_meta',
        2 => 'team_meta',
        3 => 'title',
        5 => 'field_team_tagline',
      ),
      'top' => array(
        6 => 'group_team_top_image',
        7 => 'field_illustrative_image',
      ),
    ),
    'fields' => array(
      'cwt_team_role' => 'central',
      'group_team_meta' => 'left_header',
      'team_meta' => 'left_header',
      'title' => 'left_header',
      'group_team_role_wrapper' => 'central',
      'field_team_tagline' => 'left_header',
      'group_team_top_image' => 'top',
      'field_illustrative_image' => 'top',
      'body' => 'central',
      'group_team_tab_role' => 'central',
      'group_team_tabs' => 'central',
      'cwt_team_president' => 'central',
      'group_team_tab_project_team' => 'central',
      'field_team_links' => 'central',
      'cwt_team_name' => 'central',
      'group_team_members' => 'central',
      'group_team_name_wrapper' => 'central',
      'group_team_tab_name' => 'central',
      'group_team_comissioners' => 'central',
      'cwt_team_project_team' => 'central',
      'group_team_project_team_wrapper' => 'central',
      'group_team_president' => 'central',
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
