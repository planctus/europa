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
function dt_roles_permissions_import_drush_command() {
  $items = array();

  $items['dt-revert-permissions'] = array(
    'description' => "Revert all permissions on your site.",
    'options' => array(
      'role' => "Set the role to revert the permissions for.",
      'diff' => "Get only the diff.",
      'force' => "Clear permissions before importing them.",
      'clear' => "Setting the clear parameter will remove all permissions.",
    ),
    'drupal dependencies' => array('dt_roles_permissions_import'),
    'aliases' => array('dt-rp', 'dtrp'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function dt_roles_permissions_import_drush_help($section) {
  switch ($section) {
    case 'drush:dt-revert-permissions':
      return dt("Revert all permissions which are available in the exports folder.");
  }
}

/**
 * Revert all permissions defined in the export files.
 */
function drush_dt_roles_permissions_import_dt_revert_permissions() {
  $role_parameter = drush_get_option('role');

  if ($role_parameter) {
    if (!$role = user_role_load_by_name($role_parameter)) {
      return drush_user_abort(dt('Role could not be found.'));
    }
  }
  else {
    if (drush_get_option('clear')) {
      $role = 'clear';
    }
    else {
      $role = 'all';
    }
  }

  if (drush_get_option('diff')) {
    _dt_roles_permissions_import_get_diff($role);
  }
  else {
    // Actually revert the permissions.
    if (_dt_roles_permissions_import_import($role, drush_get_option('force'))) {
      drush_print(dt('Permissions have been reconfigured.'));
    }
    else {
      drush_print(dt('Something went wrong importing the permissions.'));
    }
  }
}
