<?php
/**
 * @file
 * cwt_blogs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_blogs_ctools_plugin_api() {
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
function cwt_blogs_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cwt_blogs_node_info() {
  $items = array(
    'commisioner_blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
