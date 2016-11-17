<?php

/**
 * @file
 * brp_initiative.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function brp_initiative_ctools_plugin_api($module = NULL, $api = NULL) {
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
function brp_initiative_node_info() {
  $items = array(
    'brp_initiative' => array(
      'name' => t('Initiative'),
      'base' => 'node_content',
      'description' => t('Initiative content type for Better Regulation Portal'),
      'has_title' => '1',
      'title_label' => t('Reference'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
