<?php
/**
 * @file
 * cwt_biography.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_biography_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
 * Implements hook_views_api().
 */
function cwt_biography_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cwt_biography_image_default_styles() {
  $styles = array();

  // Exported image style: biography_portrait_160x160.
  $styles['biography_portrait_160x160'] = array(
    'label' => 'Biography Portrait (160x160)',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: biography_portrait_large_400px.
  $styles['biography_portrait_large_400px'] = array(
    'label' => 'Biography Portrait Large (400px)',
    'effects' => array(
      16 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: biography_portrait_large_500px.
  $styles['biography_portrait_large_500px'] = array(
    'label' => 'Biography Portrait Large (500px)',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
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
function cwt_biography_node_info() {
  $items = array(
    'biography' => array(
      'name' => t('Biography'),
      'base' => 'node_content',
      'description' => t('Use <em>commissioner</em> to add commissioners to the site.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
    'biography_assistant' => array(
      'name' => t('Biography - assistant'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Last Name'),
      'help' => '',
    ),
    'biography_timeline' => array(
      'name' => t('Biography - timeline'),
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

/**
 * Implements hook_weight_features_default_settings().
 */
function cwt_biography_weight_features_default_settings() {
  $settings = array();

  $settings['biography'] = array(
    'enabled' => 1,
    'range' => 100,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 1,
  );

  return $settings;
}
