<?php
/**
 * @file
 * dt_policy_stage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_policy_stage_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_policy_stage_node_info() {
  $items = array(
    'policy_stage' => array(
      'name' => t('Policy stage'),
      'base' => 'node_content',
      'description' => t('Policy next steps/stages content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
