<?php
/**
 * @file
 * dt_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_person_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_image_default_styles().
 */
function dt_person_image_default_styles() {
  $styles = array();

  // Exported image style: person_80px_1x.
  $styles['person_80px_1x'] = array(
    'name' => 'person_80px_1x',
    'label' => 'person_80px_1x',
    'effects' => array(
      28 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 80,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: person_80px_2x.
  $styles['person_80px_2x'] = array(
    'name' => 'person_80px_2x',
    'label' => 'person_80px_2x',
    'effects' => array(
      29 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 80,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
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
function dt_person_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Feature to structure the person content type and its properties.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
