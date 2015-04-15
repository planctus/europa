<?php
/**
 * @file
 * dt_class.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_class_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_class_node_info() {
  $items = array(
    'class' => array(
      'name' => t('Temporary class'),
      'base' => 'node_content',
      'description' => t('DT Temporary class content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
