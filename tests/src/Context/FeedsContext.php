<?php

namespace Drupal\nexteuropa\Context;

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Gherkin\Node\TableNode;

/**
 * Contains digital transformation specific step defenitions.
 */
class FeedsContext extends RawDrupalContext {

  /**
   * List of feeds importer nodes.
   *
   * @var array $importers
   */
  private $importers;

  /**
   * Creates feeds importer content of the given type, provided in the form.
   *
   * @Given I am viewing a/an :type importer:
   */
  public function assertViewingFeedsImporter($type, TableNode $fields) {
    $node = (object) [
      'type' => $type,
    ];

    foreach ($fields->getRowsHash() as $field => $value) {
      if ($field == "feeds[FeedsHTTPFetcher][source]") {
        // Allow relative URL to be passed for mocking, but prepend with
        // base-url since feeds requires an absolute value.
        $value = valid_url($value, TRUE) ? $value : $GLOBALS['base_url'] . $value;
        $node->feeds['FeedsHTTPFetcher']['source'] = $value;
      }
      else {
        $node->{$field} = $value;
      }
    }

    $saved = $this->nodeCreate($node);

    $this->importers[] = $saved->nid;
    // Set internal browser on the node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * Cleans up imported nodes.
   *
   * @AfterScenario
   */
  public function deleteImportedNodes() {
    if (is_array($this->importers)) {
      $delete = [];
      foreach ($this->importers as $nid) {
        $delete[] = $nid;
        $result = db_select('feeds_item','fi')
          ->fields('fi', ['entity_id'])
          ->condition('feed_nid', $nid)
          ->execute()
          ->fetchAll();

        foreach ($result as $imported_node) {
          $delete[] = $imported_node->entity_id;
        }
      }
      node_delete_multiple($delete);
    }
  }
  
}

