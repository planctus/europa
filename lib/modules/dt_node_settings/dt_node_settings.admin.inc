<?php

/**
 * @file
 * Admin callbacks for the dt_node_settings module.
 */

/**
 * Build the admin settings form.
 */
function dt_node_settings_helpers_overall() {
  $node_types = node_type_get_names();

  $form = [];
  $form['content_types'] = [
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#description' => t('Indicate helper content types for the project.'),
  ];

  foreach ($node_types as $type => $label) {
    $form['content_types'][$type] = [
      '#type' => 'checkbox',
      '#title' => $label,
      '#default_value' => variable_get('dt_node_settings_helper_node_type_' . $type, 0),
    ];
  }
  // Add a submit handler function.
  $form['#submit'][] = 'dt_node_settings_helpers_overall_submit';

  return system_settings_form($form);
}

/**
 * Helper: save information if a node type is helper or not.
 */
function dt_node_settings_helpers_overall_submit($form, &$form_state) {
  $node_types = $form_state['values']['content_types'];
  foreach ($node_types as $type => $selection) {
    variable_set('dt_node_settings_helper_node_type_' . $type, $selection);
  }
}
