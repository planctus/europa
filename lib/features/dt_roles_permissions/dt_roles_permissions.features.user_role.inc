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

  // Exported role: contributor.
  $roles['contributor'] = (object) array(
    'name' => 'contributor',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = (object) array(
    'name' => 'editor',
    'weight' => 5,
  );

  // Exported role: editorial team member.
  $roles['editorial team member'] = (object) array(
    'name' => 'editorial team member',
    'weight' => 3,
  );

  // Exported role: site manager.
  $roles['site manager'] = (object) array(
    'name' => 'site manager',
    'weight' => 8,
  );

  // Exported role: tester.
  $roles['tester'] = (object) array(
    'name' => 'tester',
    'weight' => 7,
  );

  // Exported role: translator.
  $roles['translator'] = (object) array(
    'name' => 'translator',
    'weight' => 9,
  );

  // Exported role: web transformer.
  $roles['web transformer'] = (object) array(
    'name' => 'web transformer',
    'weight' => 6,
  );

  return $roles;
}
