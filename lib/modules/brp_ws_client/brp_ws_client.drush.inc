<?php

/**
 * @file
 * Drush code for the brp_ws_client.
 */

use Drupal\dt_core_brp\BrpProps;

/**
 * Implements hook_drush_command().
 */
function brp_ws_client_drush_command() {
  $items = [];
  // Flush client cache.
  $items['brp-ws-cc'] = [
    'description' => dt('Clears caches for BRP WS Client.'),
    'aliases' => ['brpcc'],
  ];
  $items['brp-ws-setconnection'] = [
    'descritption' => dt('Set default connection.'),
    'aliases' => ['brpsetconn'],
    'callback' => 'drush_brp_ws_setconnection',
    'arguments' => [
      'type' => 'Enviroment type.',
    ],
  ];

  return $items;
}

/**
 * Callback function for clearing BRP Client cashes command.
 */
function drush_brp_ws_client_brp_ws_cc() {
  // TODO: implement clearing cache_clear_all('br_ws_client', 'cache', TRUE);.
  drush_log('BRP WS Client caches cleared.', 'ok');
}

/**
 * Callback function for setting the default client connection.
 */
function drush_brp_ws_setconnection($type = FALSE) {
  // Possible choices.
  $conns = [
    'production',
    'acceptance',
    'development',
  ];

  $conn_mappings = [
    'production' => [
      'name' => BrpProps::CONNECTION_NAME,
    ],
    'acceptance' => [
      'name' => 'brp_acceptance',
    ],
    'development' => [
      'name' => 'brp_acceptance_dev',
    ],
  ];

  // Available connections.
  $available_conns = clients_connection_load_all();

  // Check if argument is valid.
  if (!in_array($type, $conns)) {
    return drush_set_error(dt('Not a valid environment. Please choose from @conns',
      [
        '@conns' => implode(', ', $conns),
      ]));
  }
  // Check what connection we should set.
  switch ($type) {
    case 'production':
      // To get back to default state, we just need to revert the component.
      features_revert(['dt_core_brp' => ['clients_connection']]);
      break;

    case 'acceptance':
    case 'development':
      _brp_ws_client_setdefaultconn($available_conns[$conn_mappings[$type]['name']]->endpoint);
      break;
  }

  drush_log("Default connection is now set to $type.", 'ok');
}

/**
 * Helper to set the default connection.
 *
 * This will update clients connection table and
 * set the brp to the desired endpoint.
 *
 * @param string $conn_endpoint
 *   Endpoint string.
 */
function _brp_ws_client_setdefaultconn($conn_endpoint) {
  $entityQuery = new EntityFieldQuery();
  $entityQuery->entityCondition('entity_type', 'clients_connection');
  $entityQuery->propertyCondition('name', BrpProps::CONNECTION_NAME, '=');
  $entityQuery->range(0, 1);
  $result = $entityQuery->execute();

  if (isset($result['clients_connection']) && is_array($result['clients_connection'])) {
    $endpoint_load = entity_load('clients_connection', array_keys($result['clients_connection']));
    $brp_endpoint = reset($endpoint_load);
    $brp_endpoint->endpoint = $conn_endpoint;
    entity_save('clients_connection', $brp_endpoint);
    entity_get_controller('node')->resetCache([$brp_endpoint->nid]);
  }

}
