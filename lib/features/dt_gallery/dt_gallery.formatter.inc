<?php

/**
 * @file
 * Contains the formatter implementation for dt_gallery.
 */

/**
 * Implements hook_field_formatter_info().
 */
function dt_gallery_field_formatter_info() {
  return [
    'dt_gallery' => array(
      'label' => t('Digital transformation: Gallery'),
      'field types' => array(
        'media',
      ),
    ),
  ];
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function dt_gallery_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  // Run the media prepare function.
  mediafield_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, $items);
}

/**
 * Implements hook_field_formatter_view().
 */
function dt_gallery_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {

  $render_array = [
    '#prefix' => '<div class="mediagallery">',
    '#suffix' => '</div>',
  ];

  // Algorithm for the images.
  $total_images = count($items);
  $images_per_row = 4;
  $rows = ceil($total_images / $images_per_row);

  // Initialize the rows.
  $image_rows = [];

  // Build an array of images per row.
  for ($i = 0; $i <= $rows; $i++) {
    $image_rows[$i] = array_slice($items, $i * 4, 4);
    // If the images in the row are less then 4, we can stop.
    if (count($image_rows[$i]) < 4) {
      break;
    }
  }

  foreach ($image_rows as $row_id => $row_items) {
    // The row.
    $render_array[$row_id] = [
      '#prefix' => '<div class="row">',
      '#suffix' => '</div>',
    ];
    // Get the sizes.
    $sizes = _dt_gallery_get_sizes_for_row($row_items);

    // Loop over the items.
    foreach ($row_items as $img_id => $img) {
      // Image to render inside the item.
      $fallback_image_style = 'gallery_grid_' . $sizes[$img_id];
      $image = [
        '#theme' => 'picture',
        '#uri' => $img['file']->uri,
        '#style_name' => $fallback_image_style,
        '#breakpoints' => picture_get_mapping_breakpoints(picture_mapping_load('gallery_responsive_grid_' . $sizes[$img_id])),
        '#attributes' => [
          'title' => $img['file']->title,
          'alt' => $img['file']->alt,
        ],
      ];
      // The mediagallery_item.
      $render_array[$row_id][$img_id] = [
        '#theme' => 'mediagallery_item',
        '#size' => $sizes[$img_id],
        '#image' => drupal_render($image),
        '#caption' => _dt_gallery_image_get_caption($img['file']),
        '#type' => _dt_gallery_image_get_type_icon($img['file']),
      ];
    }
  }
  return $render_array;
}
