<?php
/**
 * @file
 * cwt_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cwt_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create aggregated_news content'.
  $permissions['create aggregated_news content'] = array(
    'name' => 'create aggregated_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'section editor' => 'section editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news_importer content'.
  $permissions['create news_importer content'] = array(
    'name' => 'create news_importer content',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any aggregated_news content'.
  $permissions['delete any aggregated_news content'] = array(
    'name' => 'delete any aggregated_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'section editor' => 'section editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_importer content'.
  $permissions['delete any news_importer content'] = array(
    'name' => 'delete any news_importer content',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own aggregated_news content'.
  $permissions['delete own aggregated_news content'] = array(
    'name' => 'delete own aggregated_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'section editor' => 'section editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_importer content'.
  $permissions['delete own news_importer content'] = array(
    'name' => 'delete own news_importer content',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any aggregated_news content'.
  $permissions['edit any aggregated_news content'] = array(
    'name' => 'edit any aggregated_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'section editor' => 'section editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news_importer content'.
  $permissions['edit any news_importer content'] = array(
    'name' => 'edit any news_importer content',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own aggregated_news content'.
  $permissions['edit own aggregated_news content'] = array(
    'name' => 'edit own aggregated_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'section editor' => 'section editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news_importer content'.
  $permissions['edit own news_importer content'] = array(
    'name' => 'edit own news_importer content',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
