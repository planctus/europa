<?php
/**
 * @file
 * dt_law.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_law_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_law_node_info() {
  $items = array(
    'law' => array(
      'name' => t('Law'),
      'base' => 'node_content',
      'description' => t('Create content of type Law.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
