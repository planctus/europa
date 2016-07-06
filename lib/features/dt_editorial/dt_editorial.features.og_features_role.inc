<?php

/**
 * @file
 * dt_editorial.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function dt_editorial_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:editorial_team:author'.
  $roles['node:editorial_team:author'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'editorial_team',
    'name' => 'author',
  );

  // Exported OG Role: 'node:editorial_team:reviewer'.
  $roles['node:editorial_team:reviewer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'editorial_team',
    'name' => 'reviewer',
  );

  // Exported OG Role: 'node:editorial_team:translator'.
  $roles['node:editorial_team:translator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'editorial_team',
    'name' => 'translator',
  );

  // Exported OG Role: 'node:editorial_team:translator reviewer'.
  $roles['node:editorial_team:translator reviewer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'editorial_team',
    'name' => 'translator reviewer',
  );

  // Exported OG Role: 'node:editorial_team:validator'.
  $roles['node:editorial_team:validator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'editorial_team',
    'name' => 'validator',
  );

  return $roles;
}
