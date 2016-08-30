<?php

/**
 * @file
 * Contains BRP WS Clients Entityform integration.
 */

use Drupal\brp_ws_client\FormTools\FormToolsFactory;

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Extension of settings for entityform entity. Adding another properties to
 * the entity to store data about BRP WS connection.
 * This function provide additional tab which can be accessed via UI when
 * you are editing entity properties.
 */
function brp_ws_client_form_entityform_type_form_alter(&$form, &$form_state, $form_id) {
  $brp_entityform = FormToolsFactory::brpEntityformsSettings($form);
  $brp_entityform->injectEntityformSettings();
}
