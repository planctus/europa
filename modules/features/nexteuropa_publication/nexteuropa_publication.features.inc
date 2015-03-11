<?php
/**
 * @file
 * nexteuropa_publication.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nexteuropa_publication_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nexteuropa_publication_node_info() {
  $items = array(
    'nexteuropa_publication' => array(
      'name' => t('Publication'),
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
