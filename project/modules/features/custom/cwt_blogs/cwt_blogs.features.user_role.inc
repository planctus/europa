<?php
/**
 * @file
 * cwt_blogs.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cwt_blogs_user_default_roles() {
  $roles = array();

  // Exported role: blog editor.
  $roles['blog editor'] = array(
    'name' => 'blog editor',
    'weight' => '9',
  );

  return $roles;
}
