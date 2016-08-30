<?php

/**
 * @file
 * Contains BRP WS Clients node type integration.
 */

use Drupal\dt_core_brp\BrpTools;
use Drupal\dt_core_brp\BrpProps;

/**
 * Implements hook_form_node_type_form_alter().
 */
function brp_ws_client_form_node_type_form_alter(&$form, $form_state) {
  if (isset($form['type'])) {
    $type = $form['#node_type'];

    $form['brp_client'] = [
      '#type' => 'fieldset',
      '#title' => t('BRP WS Client settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#group' => 'additional_settings',
      '#weight' => 130,
      '#tree' => FALSE,
    ];

    $form['brp_client']['brp_client_node_connection'] = [
      '#title' => "BRP WS Connection / Integration",
      '#type' => 'select',
      '#options' => BrpTools::getConnectionList(BrpProps::CONNECTION_TYPE),
      '#description' => t('Select the BRP connection and turn on integration.'),
      '#default_value' => variable_get('brp_ws_client_node_connection_' . $type->type, ''),
      '#empty_value' => 0,
      '#empty_option' => t('- BRP WS integration disabled -'),
    ];
  }
}

/**
 * Implements hook_node_type_update().
 *
 * This tracks the BRP WS Client settings in case if node type is renamed.
 */
function brp_ws_client_node_type_update($info) {
  if (!empty($info->old_type) && $info->old_type != $info->type) {
    variable_set('brp_ws_client_node_connection_' . $info->type, variable_get('brp_ws_client_node_connection_' . $info->old_type, ''));
    variable_del('brp_ws_client_node_connection_' . $info->old_type);
  }
}

/**
 * Implements hook_node_type_delete().
 */
function brp_ws_client_node_type_delete($info) {
  variable_del('brp_ws_client_node_connection_' . $info->type);
}
