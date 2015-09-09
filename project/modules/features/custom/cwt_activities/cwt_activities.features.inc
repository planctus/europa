<?php
/**
 * @file
 * cwt_activities.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_activities_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cwt_activities_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cwt_activities_node_info() {
  $items = array(
    'activities' => array(
      'name' => t('Agenda'),
      'base' => 'node_content',
      'description' => t('As a user I want to see the agenda of the Commissioner so that I know what they are doing in the next few weeks'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
