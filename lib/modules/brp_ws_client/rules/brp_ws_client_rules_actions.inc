<?php

/**
 * @file
 * Contains BRP WS Client Custom Rules actions.
 */

use Drupal\dt_core_brp\BrpProps;
use Drupal\dt_core_brp\BrpTools;

/**
 * Implements hook_rules_action_info().
 */
function brp_ws_client_rules_action_info() {
  $actions = array(
    'brp_ws_client_get_all_initiatives' => array(
      'label' => t('Get all initiatives IDs list.'),
      'parameter' => array(
        'connection_name' => array(
          'type' => 'text',
          'label' => t('Connection name'),
          'description' => t('Select connection that suppose to be checked.'),
          'options list' => '_brp_client_ws_connection_name_options',
          'restriction' => 'input',
        ),
      ),
      'provides' => array(
        'initiatives_id_list' => array(
          'type' => 'list<integer>',
          'label' => t('Initiatives IDs list.'),
        ),
      ),
      'group' => t('BRP WS Client'),
    ),
    'brp_ws_client_get_initiative_by_id' => array(
      'label' => t('Get initiative by ID'),
      'parameter' => array(
        'connection_name' => array(
          'type' => 'text',
          'label' => t('Connection name'),
          'description' => t('Select connection that suppose to be checked.'),
          'options list' => '_brp_client_ws_connection_name_options',
          'restriction' => 'input',
        ),
        'initiative_id' => array(
          'type' => 'text',
          'label' => t("Initiative ID"),
        ),
      ),
      'provides' => array(
        'remote_initiative' => array(
          'type' => 'remote_initiative',
          'label' => t('Remote initiative object.'),
        ),
      ),
      'group' => t('BRP WS Client'),
    ),
    'brp_ws_client_send_feedback' => array(
      'label' => t('Send feedback'),
      'parameter' => array(
        'ef_submission' => array(
          'type' => 'entityform',
          'label' => t('Entity form feedback submission'),
        ),
      ),
      'provides' => array(
        'response' => array(
          'type' => 'remote_feedback',
          'label' => t('Remote feedback object.'),
        ),
      ),
      'group' => t('BRP WS Client'),
    ),
    'brp_ws_client_feedback_submitted' => array(
      'label' => t('Feedback submitted'),
      'group' => t('BRP WS Client'),
    ),
    'brp_ws_client_send_report' => array(
      'label' => t('Send report'),
      'parameter' => array(
        'ef_submission' => array(
          'type' => 'entityform',
          'label' => t('Entity form report submission'),
        ),
      ),
      'provides' => array(
        'response' => array(
          'type' => 'remote_report',
          'label' => t('Remote report object.'),
        ),
      ),
      'group' => t('BRP WS Client'),
    ),
  );

  return $actions;
}

/**
 * Action for fetching and exposing list of all initiatives IDs.
 *
 * @param string $connection_name
 *    BRP WS Client connection name.
 *
 * @return array
 *    Array with all initative IDs.
 */
function brp_ws_client_get_all_initiatives($connection_name) {
  $client = clients_connection_load($connection_name);
  if (!$initiatives_list = $client->getAllInitiativesIds()) {
    $initiatives_list = array();
  }

  return array(
    'initiatives_id_list' => $initiatives_list,
  );
}

/**
 * Action for fetching and exposing list of all initiatives IDs.
 *
 * @param string $connection_name
 *    BRP WS Client connection name.
 * @param int $initiative_id
 *    BRP WS Client initiative ID.
 *
 * @return array
 *    Remote initiative array.
 */
function brp_ws_client_get_initiative_by_id($connection_name, $initiative_id) {
  $client = clients_connection_load($connection_name);
  if (!$remote_initiative = $client->getInitiativeById($initiative_id)) {
    $remote_initiative = array();
  }

  return array(
    'remote_initiative' => $remote_initiative,
  );
}

/**
 * Action for sending feedback for given initiative ID.
 *
 * @param object $ef_submission
 *    Feedback form submission entityform object.
 *
 * @return array Array with all imitative IDs.
 *    Array with all imitative IDs.
 */
function brp_ws_client_send_feedback($ef_submission) {
  $remote_feedback = array();
  if ($connection_name = BrpTools::getConnectionNameFromEntityform(BrpProps::FEEDBACK_FORM_BUNDLE)) {
    $client = clients_connection_load($connection_name);
    $request_data = $client::prepareRequestData($ef_submission);
    $remote_feedback = $client->sendPostRequest(BrpProps::SERVICE_FEEDBACK, $request_data);
  }

  return array(
    'remote_feedback' => $remote_feedback,
  );
}

/**
 * Action to redirect to the page feedback initiative list.
 *
 * The action occurs after submitted feedback.
 */
function brp_ws_client_feedback_submitted() {
  // We need to get the context for the initiative URL.
  if ($initiative = menu_get_object()) {
    drupal_goto('/' . $initiative->path['alias'] . '/' . BrpProps::BRP_INITIATIVE_FEEDBACK_PATH);
  }
}

/**
 * Action for sending report for given feedback ID.
 *
 * @param object $ef_submission
 *    Report form submission entityform object.
 *
 * @return array
 *    HTTP response remote report array.
 */
function brp_ws_client_send_report($ef_submission) {
  $remote_report = array();
  if ($connection_name = BrpTools::getConnectionNameFromEntityform(BrpProps::FEEDBACK_REPORT_FORM_BUNDLE)) {
    $client = clients_connection_load($connection_name);
    $request_data = $client::prepareRequestData($ef_submission);
    $remote_report = $client->sendPostRequest(BrpProps::SERVICE_FEEDBACK_REPORT, $request_data);
  }

  return array(
    'remote_report' => $remote_report,
  );
}
