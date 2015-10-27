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
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'paragraph-lg-9',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_team_links' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-lg-9',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
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
  $ds_layout->layout = 'ne_bootstrap_1col_stacked_bottom_header';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'cwt_team_role',
        7 => 'body',
        8 => 'group_team_tab_role',
        9 => 'cwt_team_president',
        10 => 'group_team_tabs',
        11 => 'cwt_team_name',
        12 => 'group_team_tab_project_team',
        13 => 'field_team_links',
        14 => 'group_team_tab_name',
        15 => 'group_team_members',
        16 => 'group_team_comissioners',
        17 => 'cwt_team_project_team',
        18 => 'group_team_president',
      ),
      'left_header' => array(
        1 => 'group_team_meta',
        2 => 'team_meta',
        3 => 'title',
        4 => 'field_team_tagline',
      ),
      'bottom_header' => array(
        5 => 'field_illustrative_image',
        6 => 'group_team_top_image',
      ),
    ),
    'fields' => array(
      'cwt_team_role' => 'central',
      'group_team_meta' => 'left_header',
      'team_meta' => 'left_header',
      'title' => 'left_header',
      'field_team_tagline' => 'left_header',
      'field_illustrative_image' => 'bottom_header',
      'group_team_top_image' => 'bottom_header',
      'body' => 'central',
      'group_team_tab_role' => 'central',
      'cwt_team_president' => 'central',
      'group_team_tabs' => 'central',
      'cwt_team_name' => 'central',
      'group_team_tab_project_team' => 'central',
      'field_team_links' => 'central',
      'group_team_tab_name' => 'central',
      'group_team_members' => 'central',
      'group_team_comissioners' => 'central',
      'cwt_team_project_team' => 'central',
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
