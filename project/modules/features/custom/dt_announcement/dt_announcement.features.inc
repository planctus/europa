<?php
/**
 * @file
 * dt_announcement.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_announcement_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dt_announcement_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dt_announcement_image_default_styles() {
  $styles = array();

  // Exported image style: announcement_header_breakpoints_theme_europa_medium_1x.
  $styles['announcement_header_breakpoints_theme_europa_medium_1x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_medium_1x',
    'label' => 'announcement_header_breakpoints_theme_europa_medium_1x',
    'effects' => array(
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 738,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_medium_2x.
  $styles['announcement_header_breakpoints_theme_europa_medium_2x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_medium_2x',
    'label' => 'announcement_header_breakpoints_theme_europa_medium_2x',
    'effects' => array(
      10 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1476,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_mobile_1x.
  $styles['announcement_header_breakpoints_theme_europa_mobile_1x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_mobile_1x',
    'label' => 'announcement_header_breakpoints_theme_europa_mobile_1x',
    'effects' => array(
      7 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_mobile_2x.
  $styles['announcement_header_breakpoints_theme_europa_mobile_2x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_mobile_2x',
    'label' => 'announcement_header_breakpoints_theme_europa_mobile_2x',
    'effects' => array(
      6 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 580,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_narrow_1x.
  $styles['announcement_header_breakpoints_theme_europa_narrow_1x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_narrow_1x',
    'label' => 'announcement_header_breakpoints_theme_europa_narrow_1x',
    'effects' => array(
      9 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_narrow_2x.
  $styles['announcement_header_breakpoints_theme_europa_narrow_2x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_narrow_2x',
    'label' => 'announcement_header_breakpoints_theme_europa_narrow_2x',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 900,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_normal_1x.
  $styles['announcement_header_breakpoints_theme_europa_normal_1x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_normal_1x',
    'label' => 'announcement_header_breakpoints_theme_europa_normal_1x',
    'effects' => array(
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 962,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_normal_2x.
  $styles['announcement_header_breakpoints_theme_europa_normal_2x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_normal_2x',
    'label' => 'announcement_header_breakpoints_theme_europa_normal_2x',
    'effects' => array(
      12 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1924,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_wide_1x.
  $styles['announcement_header_breakpoints_theme_europa_wide_1x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_wide_1x',
    'label' => 'announcement_header_breakpoints_theme_europa_wide_1x',
    'effects' => array(
      15 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_breakpoints_theme_europa_wide_2x.
  $styles['announcement_header_breakpoints_theme_europa_wide_2x'] = array(
    'name' => 'announcement_header_breakpoints_theme_europa_wide_2x',
    'label' => 'announcement_header_breakpoints_theme_europa_wide_2x',
    'effects' => array(
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 2280,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_header_module_picture_empty_srcset_1x.
  $styles['announcement_header_module_picture_empty_srcset_1x'] = array(
    'name' => 'announcement_header_module_picture_empty_srcset_1x',
    'label' => 'announcement_header_module_picture_empty_srcset_1x',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_medium_1x.
  $styles['announcement_teaser_breakpoints_theme_europa_medium_1x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_medium_1x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_medium_1x',
    'effects' => array(
      23 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_medium_2x.
  $styles['announcement_teaser_breakpoints_theme_europa_medium_2x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_medium_2x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_medium_2x',
    'effects' => array(
      22 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_mobile_1x.
  $styles['announcement_teaser_breakpoints_theme_europa_mobile_1x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_mobile_1x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_mobile_1x',
    'effects' => array(
      19 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 290,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_mobile_2x.
  $styles['announcement_teaser_breakpoints_theme_europa_mobile_2x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_mobile_2x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_mobile_2x',
    'effects' => array(
      18 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 580,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_narrow_1x.
  $styles['announcement_teaser_breakpoints_theme_europa_narrow_1x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_narrow_1x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_narrow_1x',
    'effects' => array(
      21 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_narrow_2x.
  $styles['announcement_teaser_breakpoints_theme_europa_narrow_2x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_narrow_2x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_narrow_2x',
    'effects' => array(
      20 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 900,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_normal_1x.
  $styles['announcement_teaser_breakpoints_theme_europa_normal_1x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_normal_1x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_normal_1x',
    'effects' => array(
      25 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_normal_2x.
  $styles['announcement_teaser_breakpoints_theme_europa_normal_2x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_normal_2x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_normal_2x',
    'effects' => array(
      24 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_wide_1x.
  $styles['announcement_teaser_breakpoints_theme_europa_wide_1x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_wide_1x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_wide_1x',
    'effects' => array(
      27 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_breakpoints_theme_europa_wide_2x.
  $styles['announcement_teaser_breakpoints_theme_europa_wide_2x'] = array(
    'name' => 'announcement_teaser_breakpoints_theme_europa_wide_2x',
    'label' => 'announcement_teaser_breakpoints_theme_europa_wide_2x',
    'effects' => array(
      26 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: announcement_teaser_module_picture_empty_srcset_1x.
  $styles['announcement_teaser_module_picture_empty_srcset_1x'] = array(
    'name' => 'announcement_teaser_module_picture_empty_srcset_1x',
    'label' => 'announcement_teaser_module_picture_empty_srcset_1x',
    'effects' => array(
      17 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
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
function dt_announcement_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'base' => 'node_content',
      'description' => t('A periodic content post directed towards the press audience.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
