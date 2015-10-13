<?php
/**
 * @file
 * dt_featured_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_featured_item_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_featured_item_node_info() {
  $items = array(
    'featured_item' => array(
      'name' => t('Featured item'),
      'base' => 'node_content',
      'description' => t('Featured item content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
