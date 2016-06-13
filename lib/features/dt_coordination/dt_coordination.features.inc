<?php
/**
 * @file
 * dt_coordination.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_coordination_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_coordination_node_info() {
  $items = array(
    'coordination' => array(
      'name' => t('Coordination'),
      'base' => 'node_content',
      'description' => t('Create content of type Coordination.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
