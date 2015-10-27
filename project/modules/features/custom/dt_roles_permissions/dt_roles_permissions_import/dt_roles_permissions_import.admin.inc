<?php
/**
 * @file
 * Holds the admin configuration for dt_priority page.
 */

/**
 * Defines a settings form.
 */
function dt_roles_permissions_import_page($form, &$form_state) {
  // Setup a list of roles.
  $roles_array = _dt_roles_permissions_get_importable();

  // Add an option to do it for all roles. We cannot unshift because that will
  // reset the keys.
  $roles_array['all'] = 'all';
  // Option to clear all permissions.
  $roles_array['clear'] = 'clear';

  $form['dt_roles_permissions_import_role_id'] = array(
    '#type' => 'select',
    '#title' => t('Select the roles you want to import.'),
    '#description' => t('Select in the list of roles the one you want to import.'),
    '#options' => $roles_array,
    '#required' => TRUE,
    '#default_value' => 'all',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Submission handler for our form.
 *
 * @see dt_roles_permissions_export_page
 */
function dt_roles_permissions_import_page_submit($form, &$form_state) {
  // Set our basic message.
  $message = t('Roles have been imported');

  if (is_numeric($form_state['values']['dt_roles_permissions_import_role_id'])) {
    $role = user_role_load($form_state['values']['dt_roles_permissions_import_role_id']);
  }
  else {
    $role = $form_state['values']['dt_roles_permissions_import_role_id'];

    // Special message in case of clear.
    if ($form_state['values']['dt_roles_permissions_import_role_id'] == 'clear') {
      $message = t('Permissions have been cleared');
    }
  }
  // If true, return the message.
  if (_dt_roles_permissions_import_import($role)) {
    drupal_set_message($message);
  }
}
