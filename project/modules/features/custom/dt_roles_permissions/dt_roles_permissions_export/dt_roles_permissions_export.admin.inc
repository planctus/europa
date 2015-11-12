<?php
/**
 * @file
 * Holds the admin configuration for dt_priority page.
 */

/**
 * Defines a settings form.
 */
function dt_roles_permissions_export_page($form, &$form_state) {

  // Setup a list of roles.
  $roles_array = user_roles();
  // Add an option to do it for all roles. We cannot unshift because that will
  // reset the keys.
  $roles_array['all'] = 'all';

  $form['dt_roles_permissions_export_role_id'] = array(
    '#type' => 'select',
    '#title' => t('Select the roles you want to export.'),
    '#description' => t('Select in the list of roles the one you want to export.'),
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
function dt_roles_permissions_export_page_submit($form, &$form_state) {
  if ($form_state['values']['dt_roles_permissions_export_role_id'] !== 'all') {
    $role = user_role_load($form_state['values']['dt_roles_permissions_export_role_id']);
  }
  else {
    $role = 'all';
  }
  if (_dt_roles_permissions_export_export($role)) {
    drupal_set_message(t('Roles have been exported.'));
  }
  else {
    drupal_set_message(t('There was an error exporting roles.'), 'error');
  }
}
