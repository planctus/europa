<?php
/**
 * @file
 * Admin callbacks for the nexteuropa_entities module.
 */

/**
 * Build the admin settings form.
 */
function helper_content_types_settings() {
  $node_types = node_type_get_names();

  $form = array();
  $form['content_types'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#description' => t('Indicate helper content types for the project.'),
  );

  foreach($node_types as $type => $label) {
    $form['content_types']['node_type_' . $type] = array(
      '#type' => 'checkbox',
      '#title' => $label,
      '#default_value' => variable_get('helper_node_type_' . $type, 0),
    );
  }
  // Add a submit handler function.
  $form['#submit'][] = 'helper_content_types_settings_submit';

  return system_settings_form($form);
}

/**
 * Helper: save information if a node type is helper or not.
 */
function helper_content_types_settings_submit($form, &$form_state) {
  $node_types = $form_state['values']['content_types'];
  foreach($node_types as $node_type => $selection) {
    variable_set('helper_' . $node_type, $selection);
  }
}
