<?php

namespace Drupal\brp_ws_client\FormTools;

use Drupal\dt_core_brp\BrpTools;

/**
 * BrpFields class.
 */
class BrpEntityformFields {
  public $form;
  public $entityType;
  public $entityBundle;
  public $fieldInstances;
  public $integratedSelectFields;

  private $client;

  /**
   * BrpFields constructor.
   *
   * @param array $form
   *    Reference to the form.
   */
  public function __construct(&$form) {
    $this->form = &$form;
    $this->setProperties();
    $this->initializeClient(BrpTools::getConnectionNameFromEntityform($this->entityBundle));
    $this->getFormIntegratedSelectFields();
  }

  /**
   * Setting up object properties.
   */
  private function setProperties() {
    $this->entityType = $this->form['#entity_type'];
    $this->entityBundle = $this->form['#bundle'];
    $this->fieldInstances = field_info_instances($this->entityType, $this->entityBundle);
  }

  /**
   * Initializing client to get fields data.
   *
   * @param string $connection_name
   *    Clients connection name.
   */
  private function initializeClient($connection_name) {
    $this->client = clients_connection_load($connection_name);
    $this->client->getFields();
  }

  /**
   * Provides select fields which are integrated with BRP WS Client.
   */
  protected function getFormIntegratedSelectFields() {
    $select_fields = [];
    foreach ($this->fieldInstances as $key => $field_instance) {
      if ($field_instance['widget']['module'] == 'options'
        && isset($field_instance['settings']['brp_ws_fields'])
        && $field_instance['settings']['brp_ws_fields']['field_map']
      ) {
        $select_fields[$key] = $field_instance['settings']['brp_ws_fields'];
      }
    }

    $this->integratedSelectFields = $select_fields;
  }

  /**
   * Method for injecting BRP WS Client select fields options to mapped fields.
   */
  public function injectBrpSelectOptions() {
    foreach ($this->integratedSelectFields as $field_name => $data) {
      $mapped_field = $data['field_map'];
      if (count($this->client->fields['feedback']) > 0) {
        array_unshift($this->client->fields['feedback']['select_options'][$mapped_field], t('- None -'));
        $options = $this->client->fields['feedback']['select_options'][$mapped_field];
        $this->form[$field_name][LANGUAGE_NONE]['#options'] = $options;
      }
    }
  }

}
