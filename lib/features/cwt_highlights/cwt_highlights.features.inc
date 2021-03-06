<?php

/**
 * @file
 * cwt_highlights.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_highlights_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_fe_nodequeue_export_fields().
 */
function cwt_highlights_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: highlights.
  $nodequeues['highlights'] = array(
    'name' => 'highlights',
    'title' => 'Highlights',
    'subqueue_title' => 'Highlights for %subqueue',
    'size' => 3,
    'link' => '',
    'link_remove' => '',
    'owner' => 'smartqueue_taxonomy',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 'field_editorial_section',
    'reverse' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'highlight',
    ),
    'roles' => array(),
    'count' => 0,
    'use_parents' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function cwt_highlights_image_default_styles() {
  $styles = array();

  // Exported image style: highlight_item_image_160x122.
  $styles['highlight_item_image_160x122'] = array(
    'label' => 'Highlight item image (160x122)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 122,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: highlight_item_image_290x193.
  $styles['highlight_item_image_290x193'] = array(
    'label' => 'Highlight item image (290x193)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 290,
          'height' => 193,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cwt_highlights_node_info() {
  $items = array(
    'highlight' => array(
      'name' => t('Highlight'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
