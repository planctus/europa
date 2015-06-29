<?php
/**
 * @file
 * dt_policy_input.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_policy_input_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dt_policy_input_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dt_policy_input_node_info() {
  $items = array(
    'policy_input' => array(
      'name' => t('Policy input'),
      'base' => 'node_content',
      'description' => t('Policy input content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
