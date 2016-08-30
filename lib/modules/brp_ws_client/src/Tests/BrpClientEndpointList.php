<?php

namespace Drupal\brp_ws_client\Tests;

use Drupal\dt_core_brp\BrpTools;

/**
 * Test class for showing given endpoint response.
 */
class BrpClientEndpointList implements \ClientsConnectionTestingInterface {

  /**
   * Alter function for setting up labels for the test form.
   */
  public function testLabels() {
    return [
      'label' => t('Web Service endpoints index'),
      'description' => t('Show available endpoints/services.'),
      'button' => t('Get endpoints'),
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
   * Test function for getting web service endpoints.
   */
  public function test($connection, &$button_form_values) {
    if ($response = $connection->getServiceList()) {
      BrpTools::printHttpResponse($response, '[Service list]');
    }
    else {
      drupal_set_message(t('Connection status: Error.'), 'error');
    }
  }

}
