<?php

/**
 * @file
 * Contains BRP WS Clients Fields API integration.
 */

use Drupal\dt_core_brp\BrpTools;
use Drupal\dt_core_brp\BrpProps;
use Drupal\brp_ws_client\FormTools\FormToolsFactory;

/**
 * Implements hook_form_node_type_form_alter().
 */
function brp_ws_client_form_field_ui_field_edit_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#instance']['entity_type']) && isset($form['#instance']['bundle'])) {
    // Checking entity type.
    switch ($form['#instance']['entity_type']) {
      case 'node':
        $brp_conn_name = BrpTools::getConnectionNameFromBundle($form['#instance']['bundle']);
        if ($brp_conn_name) {
          $brp_fields = FormToolsFactory::brpFieldsSettings($form, $brp_conn_name);
          $brp_fields->injectInitiativeFieldSettings();
        }
        break;

      case 'entityform':
        $brp_conn_name = BrpTools::getConnectionNameFromEntityform($form['#instance']['bundle']);
        if ($brp_conn_name) {
          brp_ws_client_entityform_field_settings_injection($form, $brp_conn_name);
        }
        break;

      default:
        break;
    }
  }
}

/**
 * Injects BRP WS Client settings to the entity form fields.
 *
 * @param array $form
 *    Field setting form passed as a reference.
 * @param string $brp_conn_name
 *    BRP Client connection name.
 */
function brp_ws_client_entityform_field_settings_injection(&$form, $brp_conn_name) {
  $brp_fields = FormToolsFactory::brpFieldsSettings($form, $brp_conn_name);
  switch ($form['#instance']['bundle']) {
    case BrpProps::FEEDBACK_FORM_BUNDLE:
      $brp_fields->injectFeedbackFieldSettings();
      break;

    case BrpProps::FEEDBACK_REPORT_FORM_BUNDLE:
      $brp_fields->injectFeedbackReportFieldSettings();
      break;
  }
}
