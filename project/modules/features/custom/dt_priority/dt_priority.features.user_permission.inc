<?php
/**
 * @file
 * dt_priority.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dt_priority_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'assign node weight'.
  $permissions['assign node weight'] = array(
    'name' => 'assign node weight',
    'roles' => array(
      'administrator' => 'administrator',
      'editorial team member' => 'editorial team member',
    ),
    'module' => 'weight',
  );

  return $permissions;
}
