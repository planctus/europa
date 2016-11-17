<?php

namespace Drupal\brp_ws_client\Tests;

use Drupal\dt_core_brp\BrpTools;

/**
 * Test class for listing available metadata endpoints.
 */
class BrpClientMetadataList implements \ClientsConnectionTestingInterface {

  /**
   * Alter function for setting up labels for the test form.
   */
  public function testLabels() {
    return [
      'label' => t('Web Service Metadata index'),
      'description' => t('Show available service metadata schemas.'),
      'button' => t('Get metadata index'),
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
   * Test function for getting metadata service schemas.
   */
  public function test($connection, &$button_form_values) {
    if ($response = $connection->getServiceMetaList()) {
      BrpTools::printHttpResponse($response, '[Metadata schema list]');
    }
    else {
      drupal_set_message(t('Connection status: Error.'), 'error');
    }
  }

}
