<?php
/**
 * @file
 * Holds the admin configuration for dt_priority page.
 */

/**
 * Defines a settings form.
 */
function dt_roles_permissions_import_page($form, &$form_state) {

  // Get the directory where the exports are stored.
  $filedir = _dt_roles_permissions_get_export_dir();

  // Setup a list of roles.
  $roles_array = user_roles();
  // Check which import file are available. If it is not available exclude it
  // from the import list.
  foreach ($roles_array as $rid => $role) {
    if (!file_exists($filedir . '/' . md5($role) . '.php')) {
      unset($roles_array[$rid]);
    }
  }

  // Add an option to do it for all roles.
  array_unshift($roles_array, 'all');

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
    '#value' => t('Export'),
  );

  return $form;
}

/**
 * Submission handler for our form.
 *
 * @see dt_roles_permissions_export_page
 */
function dt_roles_permissions_import_page_submit($form, &$form_state) {
  if ($form_state['values']['dt_roles_permissions_import_role_id'] !== '0') {
    $role = user_role_load($form_state['values']['dt_roles_permissions_import_role_id']);
  }
  else {
    $role = 'all';
  }
  if (_dt_roles_permissions_import_import($role)) {
    drupal_set_message(t('Roles imported'));
  }
}
