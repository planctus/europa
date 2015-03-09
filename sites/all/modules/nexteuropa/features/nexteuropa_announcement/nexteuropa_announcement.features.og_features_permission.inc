<?php
/**
 * @file
 * dtt_announcement.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nexteuropa_announcement_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:editorial_team:create announcement content'
  $permissions['node:editorial_team:create announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:delete any announcement content'
  $permissions['node:editorial_team:delete any announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:delete own announcement content'
  $permissions['node:editorial_team:delete own announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:update any announcement content'
  $permissions['node:editorial_team:update any announcement content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:editorial_team:update own announcement content'
  $permissions['node:editorial_team:update own announcement content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
