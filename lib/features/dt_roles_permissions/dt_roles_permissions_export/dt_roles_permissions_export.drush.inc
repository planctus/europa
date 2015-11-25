<?php
/**
 * @file
 * Contains drush commands for exporting permissions.
 */

/**
 * Implements hook_drush_command().
 *
 * @see drush_parse_command()
 */
function dt_roles_permissions_export_drush_command() {
  $items = array();

  $items['dt-export-permissions'] = array(
    'description' => "Export all permissions on your site.",
    'options' => array(
      'role' => "Set the role to export the permissions for.",
    ),
    'drupal dependencies' => array('dt_roles_permissions_export'),
    'aliases' => array('dt-ep', 'dtep'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function dt_roles_permissions_export_drush_help($section) {
  switch ($section) {
    case 'drush:dt-export-permissions':
      return dt("Export all or specific permissions.");
  }
}

/**
 * Export permissions drush command.
 */
function drush_dt_roles_permissions_export_dt_export_permissions() {
  $role_parameter = drush_get_option('role');

  if ($role_parameter) {
    if (!$role = user_role_load_by_name($role_parameter)) {
      return drush_user_abort(dt('Role could not be found.'));
    }
  }
  else {
    $role = 'all';
  }

  // Actually export the permissions.
  if (_dt_roles_permissions_export_export($role)) {
    drush_print(dt('Permissions have been exported.'));
  }
}
