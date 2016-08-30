<?php

namespace Drupal\brp_ws_client\FormTools;

use Drupal\dt_core_brp\BrpTools;
use Drupal\dt_core_brp\BrpProps;

/**
 * BrpEntityforms class.
 */
class BrpEntityforms {
  public $form;

  /**
   * BrpEntityforms constructor.
   *
   * @param array $form
   *    Reference to the form.
   */
  public function __construct(&$form) {
    $this->form = &$form;
  }

  /**
   * Injects entityform setting.
   */
  public function injectEntityformSettings() {
    $this->form['data']['brp_client'] = array(
      '#type' => 'fieldset',
      '#title' => t('BRP WS Client settings'),
      '#collapsible' => FALSE,
      '#group' => 'additional_settings',
      '#weight' => 50,
    );

    $this->form['data']['brp_client']['connection'] = array(
      '#title' => "BRP WS Connection / Integration",
      '#type' => 'select',
      '#options' => BrpTools::getConnectionList(BrpProps::CONNECTION_TYPE),
      '#description' => t('Select the BRP connection and turn on integration.'),
      '#default_value' => empty(
      $this->form['#entityform_type']->data['brp_client']['connection']) ? ''
      : (string) $this->form['#entityform_type']->data['brp_client']['connection'],
    );
  }

}
