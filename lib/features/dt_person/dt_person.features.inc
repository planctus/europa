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
function dt_person_image_default_styles() {
  $styles = array();

  // Exported image style: person_130px_1x.
  $styles['person_130px_1x'] = array(
    'label' => 'person_130px_1x',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 130,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: person_130px_2x.
  $styles['person_130px_2x'] = array(
    'label' => 'person_130px_2x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 130,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: person_160px_1x.
  $styles['person_160px_1x'] = array(
    'label' => 'person_160px_1x',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: person_160px_2x.
  $styles['person_160px_2x'] = array(
    'label' => 'person_160px_2x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 160,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: person_80px_1x.
  $styles['person_80px_1x'] = array(
    'label' => 'person_80px_1x',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
          'retinafy' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: person_80px_2x.
  $styles['person_80px_2x'] = array(
    'label' => 'person_80px_2x',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
          'retinafy' => 1,
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
