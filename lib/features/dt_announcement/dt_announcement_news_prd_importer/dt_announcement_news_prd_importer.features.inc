<?php
/**
 * @file
 * dt_announcement_news_prd_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_announcement_news_prd_importer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_announcement_news_prd_importer_node_info() {
  $items = array(
    'news_prd_importer' => array(
      'name' => t('News PRD Importer'),
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
