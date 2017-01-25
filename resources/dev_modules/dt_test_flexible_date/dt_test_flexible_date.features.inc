<?php
/**
 * @file
 * dt_test_flexible_date.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_test_flexible_date_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dt_test_flexible_date_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dt_test_flexible_date_node_info() {
  $items = array(
    'dt_test_content_type' => array(
      'name' => t('dt_test_content_type'),
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
