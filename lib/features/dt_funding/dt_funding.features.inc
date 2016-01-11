<?php
/**
 * @file
 * dt_funding.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_funding_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_funding_node_info() {
  $items = array(
    'funding' => array(
      'name' => t('Funding'),
      'base' => 'node_content',
      'description' => t('Content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
