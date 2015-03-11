<?php
/**
 * @file
 * nexteuropa_policy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nexteuropa_policy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nexteuropa_policy_node_info() {
  $items = array(
    'class' => array(
      'name' => t('Policy'),
      'base' => 'node_content',
      'description' => t('Policy content type for NextEuropa.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
