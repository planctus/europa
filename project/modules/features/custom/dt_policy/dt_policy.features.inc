<?php
/**
 * @file
 * dt_policy.features.inc
 */

/**
 * Implements hook_node_info().
 */
function dt_policy_node_info() {
  $items = array(
    'policy' => array(
      'name' => t('Policy'),
      'base' => 'node_content',
      'description' => t('Policy content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}