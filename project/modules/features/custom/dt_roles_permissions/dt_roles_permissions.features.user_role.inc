<?php
/**
 * @file
 * dt_roles_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dt_roles_permissions_user_default_roles() {
  $roles = array();

  // Exported role: site manager.
  $roles['site manager'] = (object) array(
    'name' => 'site manager',
    'weight' => 6,
  );

  return $roles;
}
