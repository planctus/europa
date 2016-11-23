<?php

namespace Drupal\nexteuropa\Context;

use Behat\Mink\Exception\ExpectationException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use EntityFieldQuery;

/**
 * Contains digital transformation specific step defenitions.
 */
class BetterRegulationContext extends RawDrupalContext {

  /**
   * Contains the brp endpoint.
   *
   * @var object $brpEndpoint
   */
  private $brpEndpoint;

  /**
   * List of initiatives with id from the mock import.
   *
   * @var array $initiativeIds
   */
  private $initiativeIds;

  /**
   * Modifies the endpoint to use the mock.
   *
   * @BeforeScenario @brpMock
   */
  public function setBrpMock() {
    $entityQuery = new EntityFieldQuery();
    $entityQuery->entityCondition('entity_type', 'clients_connection');
    $entityQuery->propertyCondition('name', 'brp', '=');
    $entityQuery->range(0, 1);
    $result = $entityQuery->execute();

    if (isset($result['clients_connection']) && is_array($result['clients_connection'])) {
      $endpoint_load = entity_load('clients_connection', array_keys($result['clients_connection']));
      $this->brpEndpoint = reset($endpoint_load);

      // Clone modify and save the entity.
      $modified_entity = clone $this->brpEndpoint;
      $modified_entity->endpoint = 'http://' . $_SERVER['HTTP_HOST'] . '/sites/all/modules/dev_modules/brp_ws_mock/mock.php/';
      entity_save('clients_connection', $modified_entity);

      // Get the full list of initiatives.
      $initiatives_list = brp_ws_client_get_all_initiatives('brp');

      // Store the ids so that we can delete them later.
      $this->initiativeIds = $initiatives_list['initiatives_id_list'];

      // Import.
      foreach ($initiatives_list['initiatives_id_list'] as $initiative_id) {
        $remote_initiative = brp_ws_client_get_initiative_by_id('brp', $initiative_id);
        brp_initiative_create_update(user_load(1), reset($remote_initiative));
      }

      // Run the indexing.
      search_api_cron();
    }
    else {
      throw new ExpectationException('No brp endpoint found.', $this->getSession());
    }
  }

  /**
   * Resets the brp endpoint.
   *
   * @AfterScenario @brpMock
   */
  public function resetBrpEndpoint() {
    // Restore the original endpoint config.
    entity_save('clients_connection', $this->brpEndpoint);

    if (is_array($this->initiativeIds)) {
      // Fetch and delete all the imported initiatives.
      $entityQuery = new EntityFieldQuery();
      $entityQuery->entityCondition('entity_type', 'node');
      $entityQuery->entityCondition('bundle', 'brp_initiative');
      $entityQuery->fieldCondition('field_brp_inve_id', 'value', $this->initiativeIds, 'IN');
      $result = $entityQuery->execute();

      foreach ($result['node'] as $record) {
        node_delete($record->nid);
      }
    }
  }

}
