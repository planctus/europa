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
    'team_college_members' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'team_highlights' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'team_view_team_agenda' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'team_view_team_navigation' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
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
  $ds_field->field = 'team_college_members';
  $ds_field->label = 'Team: College members';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'block' => 'cwt_core|college_members',
    'block_render' => '1',
  );
  $export['team_college_members'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_highlights';
  $ds_field->label = 'Team: Highlights';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'block' => 'cwt_highlights|cwt_highlights',
    'block_render' => '1',
  );
  $export['team_highlights'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_view_team_agenda';
  $ds_field->label = 'Team, view: Team agenda';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'block' => 'views|team_agenda-block_1',
    'block_render' => '1',
  );
  $export['team_view_team_agenda'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'team_view_team_navigation';
  $ds_field->label = 'Team View: Team Navigation';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'team|*';
  $ds_field->properties = array(
    'block' => 'views|team_navigation-block',
    'block_render' => '1',
  );
  $export['team_view_team_navigation'] = $ds_field;

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
        0 => 'team_view_team_navigation',
        1 => 'team_highlights',
        2 => 'team_college_members',
        3 => 'team_view_team_agenda',
      ),
    ),
    'fields' => array(
      'team_view_team_navigation' => 'central',
      'team_highlights' => 'central',
      'team_college_members' => 'central',
      'team_view_team_agenda' => 'central',
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
