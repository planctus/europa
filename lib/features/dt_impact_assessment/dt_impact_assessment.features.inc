<?php
/**
 * @file
 * dt_impact_assessment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_impact_assessment_ctools_plugin_api($module = NULL, $api = NULL) {
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
function dt_impact_assessment_node_info() {
  $items = array(
    'impact_assessment' => array(
      'name' => t('Impact Assessment'),
      'base' => 'node_content',
      'description' => t('Create content of type Impact Assessment.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
