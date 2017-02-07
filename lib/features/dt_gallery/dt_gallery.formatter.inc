<?php

/**
 * @file
 * Contains the formatter implementation for dt_gallery.
 */

use Drupal\dt_gallery\DtGallery;

/**
 * Implements hook_field_formatter_info().
 */
function dt_gallery_field_formatter_info() {
  return [
    'dt_gallery' => [
      'label' => t('Digital transformation: Gallery'),
      'field types' => [
        'media',
      ],
    ],
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
  // Initialize the element.
  $render_array = NULL;

  // Start a gallery object.
  $gallery = new DtGallery($items);

  /* @var $row_items \Drupal\dt_gallery\DtGalleryRow */
  foreach ($gallery->getRows() as $row_id => $row_items) {
    // Loop over the items in the row.
    /* @var $item \Drupal\dt_gallery\DtGalleryItemBase */
    foreach ($row_items as $item_id => $item) {

      // Image to render inside the item.
      $fallback_image_style = 'gallery_grid_' . $item->getSize();
      switch ($item->getFile()->type) {

        default:
        case 'image':
          $image_data = [
            'title' => $item->getTitle(),
            'alt' => $item->getAlt(),
            'uri' => $item->getUri(),
          ];
          break;

        case 'video':
          // Get the preview, and based on that we can chose how we render it.
          $preview = file_view_file($item->getFile(), 'preview');

          // If it is the large icon formatter, we simply take the path to that
          // icon to our own image rendering array.
          if (!isset($preview['#path'])) {
            $icon_dir = variable_get('media_icon_base_directory', 'public://media-icons') . '/' . variable_get('media_icon_set', 'default');
            $uri = file_icon_path($item->getFile(), $icon_dir);
          }
          else {
            $uri = $preview['#path'];
          }

          $image_data = [
            'title' => $preview['#file']->title,
            'alt' => $preview['#file']->alt,
            'uri' => $uri,
          ];

          unset($preview);

          break;
      }

      // Build the image render array.
      $image = [
        '#theme' => 'picture',
        '#uri' => $image_data['uri'],
        '#style_name' => $fallback_image_style,
        '#breakpoints' => picture_get_mapping_breakpoints(picture_mapping_load('gallery_responsive_grid_' . $item->getSize())),
        '#attributes' => [
          'title' => $image_data['title'],
          'alt' => $image_data['alt'],
        ],
      ];

      // Prepare the render array in case it does not exist.
      if (NULL === $render_array) {
        $render_array = [
          '#prefix' => '<div class="mediagallery">',
          '#suffix' => '</div>',
        ];
      }

      // Prepare the row render array. We should check if it is existing as we
      // don't want to render empty items.
      if (!isset($render_array[$row_id])) {
        $render_array[$row_id] = [
          '#prefix' => '<div class="row">',
          '#suffix' => '</div>',
        ];
      }

      // Add the gallery item to the render array.
      $render_array[$row_id][$item_id] = [
        '#theme' => 'mediagallery_item',
        '#size' => $item->getSize(),
        '#image' => drupal_render($image),
        '#gallery_link' => $item->getGalleryItemLink($entity),
        '#caption' => $item->getCaption(),
        '#type' => $item->getIcon(),
        '#hasicon' => (FALSE !== $item->getIcon()) ? ' has-icon' : '',
      ];
    }
  }

  return $render_array;
}
