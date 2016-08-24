<?php

/**
 * @file
 * dt_call_for_proposal.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_call_for_proposal_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_call_for_proposal_node_info() {
  $items = array(
    'call_for_proposal' => array(
      'name' => t('Call for proposal'),
      'base' => 'node_content',
      'description' => t('Create content of type Call for proposal.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
