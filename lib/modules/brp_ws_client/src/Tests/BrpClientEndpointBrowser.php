<?php

namespace Drupal\brp_ws_client\Tests;

use Drupal\dt_core_brp\BrpTools;

/**
 * Test class for showing available endpoints (Clients module specific).
 */
class BrpClientEndpointBrowser implements \ClientsConnectionTestingInterface {

  /**
   * Alter function for setting up labels for the test form.
   */
  public function testLabels() {
    return array(
      'label' => t('Web Service Endpoint browser'),
      'description' => t('Shows responses form given service/endpoint.'),
      'button' => t('Browse'),
    );
  }

  /**
   * Alter function for form elements.
   */
  public function testForm($element) {
    $element['#collapsible'] = TRUE;
    $element['#collapsed'] = FALSE;

    $element['params']['meta_endpoint'] = array(
      '#type' => 'textfield',
      '#title' => t('Paste endpoint.'),
      '#required' => TRUE,
      '#default_value' => array(),
    );

    $element['params']['create_dump'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create file dump with exact endpoint HTTP response.'),
    );

    $dump_list_view_link = l(t('Admin view with dump list'), '/admin/brp-client-json-dumps');
    $element['params']['dumps_link'] = array(
      '#type' => 'item',
      '#markup' => $dump_list_view_link,
    );

    return $element;
  }

  /**
   * Test function for getting metadata service schemas.
   */
  public function test($connection, &$button_form_values) {
    $meta_endpoint = $button_form_values['params']['meta_endpoint'];
    $create_dump = $button_form_values['params']['create_dump'];

    if ($response = $connection->sendGetRequest($meta_endpoint)) {
      BrpTools::printHttpResponse($response, '[Endpoint response]');
      if ($create_dump) {
        $file_name = 'brp_ws_dump_' . str_replace('/', '_', $meta_endpoint);
        $file = BrpTools::createJsonDumpFile($response, $file_name);
        if (!$file) {
          drupal_set_message(t('Cannot create JSON dump file.'), 'error');
        }
      }
    }
    else {
      drupal_set_message(t('Connection status: Error.'), 'error');
    }
  }

}
