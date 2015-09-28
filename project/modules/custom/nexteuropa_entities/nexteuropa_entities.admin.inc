<?php
/**
 * @file
 * Admin callbacks for the nexteuropa_entities module.
 */

/**
 * Build the admin settings form.
 */
function nexteuropa_entities_settings() {
  $node_types = node_type_get_names();

  $form = array();
  $form['nexteuropa_entities_node_types_fieldset'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#description' => t('Indicate helper content types for the project.'),
  );

  foreach($node_types as $type => $label) {
    $form['nexteuropa_entities_node_types_fieldset']['node_types']['node_type_' . $type] = array(
      '#type' => 'checkbox',
      '#title' => $label,
      '#default_value' => variable_get('nexteuropa_entities_helper_node_type_' . $type, 0),
    );
  }
  // Add a submit handler function.
  $form['#submit'][] = 'nexteuropa_entities_settings_submit';

  return system_settings_form($form);
}

/**
 * Helper: save information if a node type is helper or not.
 */
function nexteuropa_entities_settings_submit($form, &$form_state) {
  $node_types = $form_state['values']['nexteuropa_entities_node_types_fieldset']['node_types'];
  foreach($node_types as $node_type => $selection) {
    variable_set('nexteuropa_entities_helper_' . $node_type, $selection);
  }
}
