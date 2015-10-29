<?php
/**
 * @file
 * cwt_team.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function cwt_team_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'team_members';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Commissioners';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'team_members',
      'display' => 'block_2',
      'args' => 'role',
      'title' => 'Role',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'team_members_by_domain',
      'display' => 'block',
      'args' => '',
      'title' => 'Project team',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'team_members',
      'display' => 'block_2',
      'args' => 'name',
      'title' => 'Name',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Commissioners');
  t('Name');
  t('Project team');
  t('Role');

  $export['team_members'] = $quicktabs;

  return $export;
}
