<?php
/**
 * @file
 * dt_policy_keyfile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_policy_keyfile_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_policy_keyfile_node_info() {
  $items = array(
    'policy_keyfile' => array(
      'name' => t('Policy key file'),
      'base' => 'node_content',
      'description' => t('Policy key file content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
