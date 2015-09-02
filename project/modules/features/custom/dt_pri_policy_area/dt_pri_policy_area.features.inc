<?php
/**
 * @file
 * dt_pri_policy_area.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_pri_policy_area_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_pri_policy_area_node_info() {
  $items = array(
    'priority_policy_area' => array(
      'name' => t('Priority policy area'),
      'base' => 'node_content',
      'description' => t('Priority policy area content type for Digital Transformation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
