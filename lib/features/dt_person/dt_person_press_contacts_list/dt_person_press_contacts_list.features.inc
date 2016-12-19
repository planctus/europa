<?php
/**
 * @file
 * dt_person_press_contacts_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_person_press_contacts_list_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function dt_person_press_contacts_list_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
