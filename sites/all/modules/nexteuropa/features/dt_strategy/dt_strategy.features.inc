<?php
/**
 * @file
 * dt_strategy.features.inc
 */

/**
 * Implements hook_node_info().
 */
function dt_strategy_node_info() {
  $items = array(
    'strategy' => array(
      'name' => t('Strategy'),
      'base' => 'node_content',
      'description' => t('Strategy content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
