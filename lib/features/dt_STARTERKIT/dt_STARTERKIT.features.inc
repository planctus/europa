<?php
/**
 * @file
 * dt_STARTERKIT.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_STARTERKIT_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_STARTERKIT_node_info() {
  $items = array(
    'STARTERKIT_CONTENT_NAME' => array(
      'name' => t('STARTERKIT_CONTENT_HUMAN_NAME'),
      'base' => 'node_content',
      'description' => t('Create content of type STARTERKIT_CONTENT_HUMAN_NAME.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
