<?php

/**
 * @file
 * dt_editorial.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dt_editorial_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use workbench_moderation other content tab'.
  $permissions['use workbench_moderation other content tab'] = array(
    'name' => 'use workbench_moderation other content tab',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'editorial team member' => 'editorial team member',
      'site manager' => 'site manager',
      'translator' => 'translator',
    ),
    'module' => 'dt_editorial',
  );

  return $permissions;
}
