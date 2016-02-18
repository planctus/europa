<?php
/**
 * @file
 * dt_featured_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_featured_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_featured_item_node_info() {
  $items = array(
    'featured_item' => array(
      'name' => t('Featured item'),
      'base' => 'node_content',
      'description' => t('Featured item content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_node_view().
 */
function dt_featured_item_entity_load($entities, $type) {
  if ($type == 'node') {
    foreach ($entities as &$node) {
      if ($node->type == 'featured_item' && isset($node->field_feat_node_reference[LANGUAGE_NONE][0]['target_id'])) {
        $node->legacy = 'node/' . $node->field_feat_node_reference[LANGUAGE_NONE][0]['target_id'];
      }
    }
  }
}
