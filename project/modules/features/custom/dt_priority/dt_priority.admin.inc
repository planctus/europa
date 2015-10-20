<?php
/**
 * @file
 * Holds the admin configuration for dt_priority page.
 */

/**
 * Defines a settings form.
 */
function dt_priority_settings($form) {
  $form['dt_priority_page_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Priority page node id.'),
    '#description' => t('Set the node id of the page you want to use for the listing.'),
    '#required' => TRUE,
    '#default_value' => variable_get('dt_priority_page_id', ''),
  );

  $form['#validate'][] = 'dt_priority_admin_setting_validate';

  return system_settings_form($form);
}

/**
 * Form validation function
 */
function dt_priority_admin_setting_validate($form, &$form_state) {
  if ($node = node_load($form_state['input']['dt_priority_page_id'])) {
    if ($node->type <> 'basic_page') {
      form_set_error($form_state['input']['dt_priority_page_id'], t('Node <strong>%node_title</strong> is not of type <strong>page</strong>.', array('%node_title' => $node->title)));
    }
    else {
      drupal_set_message(t('Priority listing page has been set to <strong>%node_title</strong>.', array('%node_title' => $node->title)));
    }
  }
  else {
    form_set_error($form_state['input']['dt_priority_page_id'], t('Node id <strong>%nid</strong> could not be validated.', array('%nid' => $form_state['input']['dt_priority_page_id'])));
  }
}
