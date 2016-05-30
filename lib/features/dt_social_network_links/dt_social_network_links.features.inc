<?php
/**
 * @file
 * dt_social_network_links.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_social_network_links_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dt_social_network_links_image_default_styles() {
  $styles = array();

  // Exported image style: social_network_icon.
  $styles['social_network_icon'] = array(
    'label' => 'Social network icon',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 40,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
