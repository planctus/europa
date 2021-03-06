<?php

/**
 * @file
 * Nexteuropa Feedback Admin.
 *
 * Contains all forms and saving function for the Nexteuropa Feedback component.
 */

/**
 * Defines a settings form.
 */
function nexteuropa_feedback_settings($form) {
  $form['nexteuropa_feedback_form_id'] = [
    '#type' => 'textfield',
    '#title' => t('The ID of the form to be used for sending the feedback'),
    '#default_value' => variable_get('nexteuropa_feedback_form_id', ""),
  ];
  return system_settings_form($form);
}
