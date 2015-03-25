<?php
/**
 * @file
 * nexteuropa_strategy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nexteuropa_strategy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nexteuropa_strategy_node_info() {
  $items = array(
    'strategy' => array(
      'name' => t('Strategy'),
      'base' => 'node_content',
      'description' => t('Strategy content type for NextEuropa.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
