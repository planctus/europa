<?php

namespace Drupal\brp_ws_client\FormTools;

/**
 * Class FormToolsFactory.
 *
 * @package Drupal\brp_ws_client\FormTools
 */
class FormToolsFactory {

  /**
   * Provide extends for given field form setting.
   *
   * @param array $form
   *    Reference to the form array.
   * @param string $connection_name
   *    Clients connection name.
   *
   * @return \Drupal\brp_ws_client\FormTools\BrpFields
   *    Returns object responsible for extending given field form setting.
   */
  public static function brpFieldsSettings(&$form, $connection_name) {
    return new BrpFields($form, $connection_name);
  }

  /**
   * Provide extends for Entityforms settings.
   *
   * @param array $form
   *    Reference to the entitysettings form array.
   *
   * @return \Drupal\brp_ws_client\FormTools\BrpEntityforms
   *    Returns object responsible for extending entityform settings.
   */
  public static function brpEntityformsSettings(&$form) {
    return new BrpEntityforms($form);
  }

  /**
   * Provide extends for Entityforms fields which are exposed for users.
   *
   * @param array $form
   *       Reference to the entitysettings form array.
   *
   * @return \Drupal\brp_ws_client\FormTools\BrpEntityformFields
   *    Returns object responsible for extending entityforms fields.
   */
  public static function brpEntityformFields(&$form) {
    return new BrpEntityformFields($form);
  }

}
