<?php
/**
 * @file
 * dt_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dt_core_user_default_roles() {
  $roles = array();

  // Exported role: tester.
  $roles['tester'] = (object) array(
    'name' => 'tester',
    'weight' => 5,
  );

  return $roles;
}
