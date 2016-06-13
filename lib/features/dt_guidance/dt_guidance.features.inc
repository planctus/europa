<?php
/**
 * @file
 * dt_guidance.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_guidance_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_guidance_node_info() {
  $items = array(
    'guidance' => array(
      'name' => t('Guidance'),
      'base' => 'node_content',
      'description' => t('Create content of type Guidance.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
