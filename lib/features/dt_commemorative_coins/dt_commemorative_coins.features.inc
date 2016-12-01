<?php
/**
 * @file
 * dt_commemorative_coins.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_commemorative_coins_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_node_info().
 */
function dt_commemorative_coins_node_info() {
  $items = array(
    'commemorative_coins' => array(
      'name' => t('Commemorative coins'),
      'base' => 'node_content',
      'description' => t('Create content of type Commemorative coins.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
