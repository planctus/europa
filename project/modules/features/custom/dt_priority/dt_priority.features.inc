<?php
/**
 * @file
 * dt_priority.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_priority_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_priority_node_info() {
  $items = array(
    'priority' => array(
      'name' => t('Priority'),
      'base' => 'node_content',
      'description' => t('Priority content type for Digital Transformation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}


/**
 * Implements hook_weight_features_default_settings().
 */
function dt_priority_weight_features_default_settings() {
  $settings = array();

  $settings['priority'] = array(
    'enabled' => '1',
    'range' => '10',
    'menu_weight' => '0',
    'default' => '0',
    'sync_translations' => '1',
  );

  return $settings;
}
