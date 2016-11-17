<?php

/**
 * @file
 * Contains BRP WS Client Custom Rules conditions.
 */

use Drupal\dt_core_brp\BrpTools;
use Drupal\dt_core_brp\BrpProps;

/**
 * Implements hook_rules_condition_info().
 */
function brp_ws_client_rules_condition_info() {
  return [
    'brp_ws_client_check_status' => [
      'label' => t('Check connection status'),
      'group' => 'BRP WS Client' ,
      'module' => 'brp_ws_client',
      'parameter' => [
        'connection_name' => [
          'type' => 'text',
          'label' => t('Connection name'),
          'description' => t('Select connection that suppose to be checked.'),
          'options list' => '_brp_client_ws_connection_name_options',
          'restriction' => 'input',
        ],
      ],
    ],
  ];
}

/**
 * Helper function which returns array with options for custom condition.
 *
 * @return array
 *    Array with BRP WS Client connection names.
 */
function _brp_client_ws_connection_name_options() {
  return BrpTools::getConnectionList(BrpProps::CONNECTION_TYPE);
}

/**
 * Custom condition callback.
 *
 * @param string $connection_name
 *    BRP WS Client connection name.
 *
 * @return bool
 *    TRUE / FALSE
 */
function brp_ws_client_check_status($connection_name) {
  $client = clients_connection_load($connection_name);
  return $client->checkConnectionStatus();
}
