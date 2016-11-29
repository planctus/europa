<?php
/**
 * @file
 * cwt_biography.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cwt_biography_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create biography content'.
  $permissions['create biography content'] = array(
    'name' => 'create biography content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create biography_timeline content'.
  $permissions['create biography_timeline content'] = array(
    'name' => 'create biography_timeline content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any biography content'.
  $permissions['delete any biography content'] = array(
    'name' => 'delete any biography content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any biography_timeline content'.
  $permissions['delete any biography_timeline content'] = array(
    'name' => 'delete any biography_timeline content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own biography content'.
  $permissions['delete own biography content'] = array(
    'name' => 'delete own biography content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own biography_timeline content'.
  $permissions['delete own biography_timeline content'] = array(
    'name' => 'delete own biography_timeline content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in commissioner_statuses'.
  $permissions['delete terms in commissioner_statuses'] = array(
    'name' => 'delete terms in commissioner_statuses',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in social_networks'.
  $permissions['delete terms in social_networks'] = array(
    'name' => 'delete terms in social_networks',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any biography content'.
  $permissions['edit any biography content'] = array(
    'name' => 'edit any biography content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any biography_timeline content'.
  $permissions['edit any biography_timeline content'] = array(
    'name' => 'edit any biography_timeline content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own biography content'.
  $permissions['edit own biography content'] = array(
    'name' => 'edit own biography content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own biography_timeline content'.
  $permissions['edit own biography_timeline content'] = array(
    'name' => 'edit own biography_timeline content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in commissioner_statuses'.
  $permissions['edit terms in commissioner_statuses'] = array(
    'name' => 'edit terms in commissioner_statuses',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in social_networks'.
  $permissions['edit terms in social_networks'] = array(
    'name' => 'edit terms in social_networks',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
