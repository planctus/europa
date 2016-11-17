<?php

namespace Drupal\brp_ws_client\Tests;

/**
 * Test class for checking connection status (Clients module specific).
 */
class BrpClientConnectionStatus implements \ClientsConnectionTestingInterface {

  /**
   * Alter function for setting up labels for the test form.
   */
  public function testLabels() {
    return [
      'label' => t('Connection status'),
      'description' => t('Check connection status for selected connection.'),
      'button' => t('Check'),
    ];
  }

  /**
   * Alter function for form elements.
   */
  public function testForm($element) {
    $element['#collapsible'] = TRUE;
    $element['#collapsed'] = TRUE;
    return $element;
  }

  /**
   * Test function for checking connection status.
   */
  public function test($connection, &$button_form_values) {
    if ($connection->checkConnectionStatus()) {
      drupal_set_message(t('Connection status: OK.'), 'status');
    }
    else {
      drupal_set_message(t('Connection status: Error.'), 'error');
    }
  }

}
