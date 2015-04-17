<?php
/**
 * @file
 * dt_policy_next_step.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_policy_next_step_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_policy_next_step_node_info() {
  $items = array(
    'policy_next_steps' => array(
      'name' => t('Policy next steps'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
