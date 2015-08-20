<?php
/**
 * @file
 * dt_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
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
function dt_core_image_default_styles() {
  $styles = array();

  // Exported image style: header_image_breakpoints_theme_europa_medium_1x.
  $styles['header_image_breakpoints_theme_europa_medium_1x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_medium_1x',
    'label' => 'header_image_breakpoints_theme_europa_medium_1x',
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

  // Exported image style: header_image_breakpoints_theme_europa_medium_2x.
  $styles['header_image_breakpoints_theme_europa_medium_2x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_medium_2x',
    'label' => 'header_image_breakpoints_theme_europa_medium_2x',
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

  // Exported image style: header_image_breakpoints_theme_europa_mobile_1x.
  $styles['header_image_breakpoints_theme_europa_mobile_1x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_mobile_1x',
    'label' => 'header_image_breakpoints_theme_europa_mobile_1x',
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

  // Exported image style: header_image_breakpoints_theme_europa_mobile_2x.
  $styles['header_image_breakpoints_theme_europa_mobile_2x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_mobile_2x',
    'label' => 'header_image_breakpoints_theme_europa_mobile_2x',
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

  // Exported image style: header_image_breakpoints_theme_europa_narrow_1x.
  $styles['header_image_breakpoints_theme_europa_narrow_1x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_narrow_1x',
    'label' => 'header_image_breakpoints_theme_europa_narrow_1x',
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

  // Exported image style: header_image_breakpoints_theme_europa_narrow_2x.
  $styles['header_image_breakpoints_theme_europa_narrow_2x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_narrow_2x',
    'label' => 'header_image_breakpoints_theme_europa_narrow_2x',
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

  // Exported image style: header_image_breakpoints_theme_europa_normal_1x.
  $styles['header_image_breakpoints_theme_europa_normal_1x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_normal_1x',
    'label' => 'header_image_breakpoints_theme_europa_normal_1x',
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

  // Exported image style: header_image_breakpoints_theme_europa_normal_2x.
  $styles['header_image_breakpoints_theme_europa_normal_2x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_normal_2x',
    'label' => 'header_image_breakpoints_theme_europa_normal_2x',
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

  // Exported image style: header_image_breakpoints_theme_europa_wide_1x.
  $styles['header_image_breakpoints_theme_europa_wide_1x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_wide_1x',
    'label' => 'header_image_breakpoints_theme_europa_wide_1x',
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

  // Exported image style: header_image_breakpoints_theme_europa_wide_2x.
  $styles['header_image_breakpoints_theme_europa_wide_2x'] = array(
    'name' => 'header_image_breakpoints_theme_europa_wide_2x',
    'label' => 'header_image_breakpoints_theme_europa_wide_2x',
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

  // Exported image style: header_image_module_picture_empty_srcset_1x.
  $styles['header_image_module_picture_empty_srcset_1x'] = array(
    'name' => 'header_image_module_picture_empty_srcset_1x',
    'label' => 'header_image_module_picture_empty_srcset_1x',
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

  // Exported image style: teaser_image_breakpoints_theme_europa_medium_1x.
  $styles['teaser_image_breakpoints_theme_europa_medium_1x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_medium_1x',
    'label' => 'teaser_image_breakpoints_theme_europa_medium_1x',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_medium_2x.
  $styles['teaser_image_breakpoints_theme_europa_medium_2x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_medium_2x',
    'label' => 'teaser_image_breakpoints_theme_europa_medium_2x',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 333,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_mobile_1x.
  $styles['teaser_image_breakpoints_theme_europa_mobile_1x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_mobile_1x',
    'label' => 'teaser_image_breakpoints_theme_europa_mobile_1x',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 290,
          'height' => 193,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_mobile_2x.
  $styles['teaser_image_breakpoints_theme_europa_mobile_2x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_mobile_2x',
    'label' => 'teaser_image_breakpoints_theme_europa_mobile_2x',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 580,
          'height' => 387,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_narrow_1x.
  $styles['teaser_image_breakpoints_theme_europa_narrow_1x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_narrow_1x',
    'label' => 'teaser_image_breakpoints_theme_europa_narrow_1x',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 450,
          'height' => 300,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_narrow_2x.
  $styles['teaser_image_breakpoints_theme_europa_narrow_2x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_narrow_2x',
    'label' => 'teaser_image_breakpoints_theme_europa_narrow_2x',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 900,
          'height' => 600,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_normal_1x.
  $styles['teaser_image_breakpoints_theme_europa_normal_1x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_normal_1x',
    'label' => 'teaser_image_breakpoints_theme_europa_normal_1x',
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
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_normal_2x.
  $styles['teaser_image_breakpoints_theme_europa_normal_2x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_normal_2x',
    'label' => 'teaser_image_breakpoints_theme_europa_normal_2x',
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
          'width' => 500,
          'height' => 333,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_wide_1x.
  $styles['teaser_image_breakpoints_theme_europa_wide_1x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_wide_1x',
    'label' => 'teaser_image_breakpoints_theme_europa_wide_1x',
    'effects' => array(
      18 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_breakpoints_theme_europa_wide_2x.
  $styles['teaser_image_breakpoints_theme_europa_wide_2x'] = array(
    'name' => 'teaser_image_breakpoints_theme_europa_wide_2x',
    'label' => 'teaser_image_breakpoints_theme_europa_wide_2x',
    'effects' => array(
      20 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 333,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: teaser_image_module_picture_empty_srcset_1x.
  $styles['teaser_image_module_picture_empty_srcset_1x'] = array(
    'name' => 'teaser_image_module_picture_empty_srcset_1x',
    'label' => 'teaser_image_module_picture_empty_srcset_1x',
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
          'width' => 250,
          'height' => 167,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
