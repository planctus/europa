<?php
/**
 * @file
 * cwt_biography.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cwt_biography_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cwt_biography_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cwt_biography_image_default_styles() {
  $styles = array();

  // Exported image style: biography_portrait_160x160.
  $styles['biography_portrait_160x160'] = array(
    'name' => 'biography_portrait_160x160',
    'label' => 'Biography Portrait (160x160)',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '160',
          'height' => '160',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: biography_portrait_large_400px.
  $styles['biography_portrait_large_400px'] = array(
    'name' => 'biography_portrait_large_400px',
    'label' => 'Biography Portrait Large (400px)',
    'effects' => array(
      16 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '400',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: biography_portrait_large_500px.
  $styles['biography_portrait_large_500px'] = array(
    'name' => 'biography_portrait_large_500px',
    'label' => 'Biography Portrait Large (500px)',
    'effects' => array(
      15 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '500',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
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
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function cwt_biography_weight_features_default_settings() {
  $settings = array();

  $settings['biography'] = array(
    'enabled' => '1',
    'range' => '100',
    'menu_weight' => '0',
    'default' => '0',
    'sync_translations' => '1',
  );

  return $settings;
}
