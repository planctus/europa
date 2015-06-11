<?php
/**
 * @file
 * dt_social_network_links.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function dt_social_network_links_image_default_styles() {
  $styles = array();

  // Exported image style: social_network_icon.
  $styles['social_network_icon'] = array(
    'name' => 'social_network_icon',
    'label' => 'Social network icon',
    'effects' => array(
      17 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '40',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
