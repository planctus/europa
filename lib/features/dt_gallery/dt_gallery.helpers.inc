<?php

/**
 * @file
 * Contains helper functions for dt_gallery.
 */

/**
 * Gets the sizes per item.
 *
 * @param array $row_items
 *   Array of row items.
 *
 * @return array|null
 *   Sizes to render.
 */
function _dt_gallery_get_sizes_for_row($row_items) {
  // Set the original order.
  foreach ($row_items as $key => &$value) {
    $value['original_key'] = $key;
  }
  // Sort array by biggest width.
  usort($row_items, '_dt_gallery_sort_by_width');

  // Init vars.
  $minimum_size = 2;
  $max_size = 3;

  // Get the count of items.
  $items_count = count($row_items);

  switch ($items_count) {
    case 1:
      $max_size = 5;
      break;

    case 2:
      $max_size = 7;
      break;

    case 3:
    case 4:
      $max_size = 5;
      break;
  }

  // Enfore size if non dynamic.
  if (variable_get('_dt_gallery_dynamic', TRUE) == FALSE) {
    $minimum_size = 4;
    $max_size = 4;
  }

  // Loop over the items.
  $temp_sizes = [];
  foreach ($row_items as $key => &$item) {
    if (!in_array($max_size, $temp_sizes)) {
      $item['size']  = $max_size;
    }
    else {
      // Space per item.
      $space_per_item = (12 - array_sum($temp_sizes)) / ($items_count - count($temp_sizes));
      // Add it to the list.
      $item['size'] = $space_per_item > $minimum_size ? ceil($space_per_item) : $minimum_size;
    }
    $temp_sizes[] = $item['size'];
  }

  // Sort back the array by its original key.
  usort($row_items, '_dt_gallery_sort_by_original_key');

  return array_column($row_items, 'size');
}

/**
 * Usort function to sort by aspect ratio.
 *
 * @param array $a
 *   First param.
 * @param array $b
 *   Second param.
 *
 * @return int
 *   The biggest.
 */
function _dt_gallery_sort_by_width($a, $b) {
  if (isset($a['file']->width) && isset($b['file']->width)) {
    if ($a['file']->width / $a['file']->height == $b['file']->width / $b['file']->height) {
      return 0;
    }
    return (($a['file']->width / $a['file']->height) > ($b['file']->width / $b['file']->height) ? -1 : 1);
  }
  // If it is an non image file.
  return 0;
}

/**
 * Sorts array by its original key.
 *
 * @param array $a
 *   First param.
 * @param array $b
 *   Second param.
 *
 * @return int
 *   The lightest.
 */
function _dt_gallery_sort_by_original_key($a, $b) {
  return $a['original_key'] < $b['original_key'] ? -1 : 1;
}

/**
 * Gets the caption of a file.
 *
 * @param object $file
 *   The file object.
 *
 * @return string
 *   The localized caption.
 */
function _dt_gallery_image_get_caption($file) {
  if (isset($file->field_caption) && is_array($file->field_caption)) {
    $fmw = entity_metadata_wrapper('file', $file);
    if ($fmw->__isset('field_caption') && $fmw->field_caption->value()) {
      return $fmw->field_caption->value();
    }
  }
  return NULL;
}

/**
 * Gets the class type of a file.
 *
 * @param object $file
 *   The file object.
 *
 * @return string
 *   The class type of the file.
 */
function _dt_gallery_image_get_type_icon($file) {
  switch ($file->type) {
    case 'image':
    default:
      return NULL;

    case 'audio':
      return 'icon--audio';

    case 'video':
      return 'icon--video';
  }
}
