<?php
/**
 * @file
 * cwt_biography.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function cwt_biography_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'team_cabinet_member';
  $ds_view_mode->label = 'Team cabinet member';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['team_cabinet_member'] = $ds_view_mode;

  return $export;
}
