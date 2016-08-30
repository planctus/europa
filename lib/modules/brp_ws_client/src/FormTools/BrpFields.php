<?php

namespace Drupal\brp_ws_client\FormTools;

/**
 * BrpFields class.
 */
class BrpFields {
  public $form;
  public $entityType;
  public $entityBundle;
  public $fieldType;
  private $client;

  /**
   * BrpFields constructor.
   *
   * @param array $form
   *    Reference to the form.
   * @param string $connection_name
   *    Connection name.
   */
  public function __construct(&$form, $connection_name) {
    $this->form = &$form;
    $this->setProperties();
    $this->initializeClient($connection_name);
  }

  /**
   * Injects field setting for initiative fields mapping.
   */
  public function injectInitiativeFieldSettings() {
    $this->fieldSettingsForm('initiative');
  }

  /**
   * Injects field setting for feedback fields mapping.
   */
  public function injectFeedbackFieldSettings() {
    $this->fieldSettingsForm('feedback');
  }

  /**
   * Injects field setting for feedback fields mapping.
   */
  public function injectFeedbackReportFieldSettings() {
    $this->fieldSettingsForm('feedback_report');
  }

  /**
   * Provides form field settings with fields option fot the given service.
   *
   * @param string $service
   *    Service like 'initiative' or 'feedback'.
   */
  private function fieldSettingsForm($service) {
    $settings = $this->form['#instance']['settings'];
    $this->form['instance']['settings']['brp_ws_fields'] = array(
      '#title' => t('BRP WS Client settings'),
      '#type' => 'fieldset',
      '#weight' => '50',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    $field_map = isset($settings['brp_ws_fields']['field_map']) ? $settings['brp_ws_fields']['field_map'] : array();

    // Get the correct options in a multidimension readable array.
    if ($type = $this->getFieldType()) {
      foreach ($this->client->fields[$service] as $label => $value) {
        // If it is matching it should be suggested.
        $label = $label == $type ? $label . ' (suggested)' : $label;

        foreach ($value as $item) {
          if (!is_array($item)) {
            $options[$label][$item] = $item;
          }
        }
      }
    }

    $this->form['instance']['settings']['brp_ws_fields']['field_map'] = array(
      '#title' => t('BRP WS field'),
      '#type' => 'select',
      '#options' => isset($options) ? $options : [],
      '#default_value' => !empty($field_map) ? (string) $field_map : 0,
      '#empty_value' => 0,
      '#empty_option' => t('- BRP WS integration disabled -'),
    );
  }

  /**
   * Setting up object properties.
   */
  private function setProperties() {
    $this->entityType = $this->form['#instance']['entity_type'];
    $this->entityBundle = $this->form['#instance']['bundle'];
    $this->fieldType = $this->getFieldType();
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
   * Helper function for getiing field type.
   *
   * This method assumes that every field (but the exception) is handled as a
   * text field.
   *
   * @return string
   *    Type of field which could be 'select' or 'text'.
   */
  private function getFieldType() {
    // Field modules that are using a select list.
    if ($this->form['#instance']['widget']['module'] == 'options') {
      return 'select';
    }

    return 'text';
  }

}
