<?php
/**
 * @file
 * dt_banner_quote.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_banner_quote_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_banner_quote_node_info() {
  $items = array(
    'banner_quote' => array(
      'name' => t('Banner: Quote'),
      'base' => 'node_content',
      'description' => t('Quote Banner content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Quote reference'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
