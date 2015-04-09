<?php
/**
 * @file
 * dt_priority.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_priority_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_priority_node_info() {
  $items = array(
    'priority' => array(
      'name' => t('Priority'),
      'base' => 'node_content',
      'description' => t('Priority content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
