<?php
/**
 * @file
 * dt_banner_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_banner_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
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
 * Implements hook_image_default_styles().
 */
function dt_banner_video_image_default_styles() {
  $styles = array();

  // Exported image style: banner_image_breakpoints_theme_europa_normal_1x.
  $styles['banner_image_breakpoints_theme_europa_normal_1x'] = array(
    'name' => 'banner_image_breakpoints_theme_europa_normal_1x',
    'label' => 'banner_image_breakpoints_theme_europa_normal_1x',
    'effects' => array(
      14 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 555,
          'height' => 325,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: banner_image_breakpoints_theme_europa_normal_2x.
  $styles['banner_image_breakpoints_theme_europa_normal_2x'] = array(
    'name' => 'banner_image_breakpoints_theme_europa_normal_2x',
    'label' => 'banner_image_breakpoints_theme_europa_normal_2x',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1110,
          'height' => 650,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: banner_image_module_picture_empty_srcset_1x.
  $styles['banner_image_module_picture_empty_srcset_1x'] = array(
    'name' => 'banner_image_module_picture_empty_srcset_1x',
    'label' => 'banner_image_module_picture_empty_srcset_1x',
    'effects' => array(
      22 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 555,
          'height' => 325,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dt_banner_video_node_info() {
  $items = array(
    'banner_video' => array(
      'name' => t('Banner: Audiovisual'),
      'base' => 'node_content',
      'description' => t('Audiovisual Banner content type for dt.'),
      'has_title' => '1',
      'title_label' => t('Banner reference'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
