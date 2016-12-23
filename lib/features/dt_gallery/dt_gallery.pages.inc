<?php

/**
 * @file
 * Page callbacks for gallery content.
 */

use Drupal\dt_gallery\EntityWrapper\Node\DTGalleryWrapper;

/**
 * Menu callback: Displays the gallery of a node.
 *
 * @param object $node
 *   The gallery node.
 * @param object $file
 *   The file object.
 *
 * @return array|int
 *   A page array suitable for use by drupal_render().
 *
 * @see dt_gallery_menu()
 */
function _dt_gallery_page_view($node, $file = NULL) {
  // If /gallery is accessed without parameters return 404.
  if (!$node) {
    return MENU_NOT_FOUND;
  }

  $gallery_wrapper = new DTGalleryWrapper($node);
  // If not a gallery node return 404.
  if (!$gallery_wrapper->isGallery()) {
    return MENU_NOT_FOUND;
  }

  $gallery = $gallery_wrapper->getGalleryItems();
  // File is in the gallery.
  if ($file) {
    if (!$current = $gallery->find($file->fid)) {
      // File not part of this gallery, potential URL hack.
      return MENU_NOT_FOUND;
    }
  }
  // If no file is set explicitly display the first as default.
  else {
    $current = $gallery->rewind();
  }

  $navigation = $gallery->getNavigation();
  // Build the media render array and other type specific elements.
  switch ($current->getType()) {
    case 'image':
      $media = [
        '#theme' => 'picture',
        '#uri' => $current->getUri(),
        '#style_name' => 'gallery_full',
        '#breakpoints' => picture_get_mapping_breakpoints(picture_mapping_load('gallery_full')),
        '#attributes' => [
          'title' => $current->getTitle(),
          'alt' => $current->getAlt(),
        ],
      ];
      // Create download link.
      $download_options = [
        'attributes' => [
          'class' => ['btn', 'btn--condensed', 'file__btn is-internal'],
        ],
      ];
      $download = l(t('Download photo'), file_create_url($current->getUri()), $download_options);
      break;

    case 'video':
      $media = file_view_file($current->getFile());
      // Videos are not downloadable.
      $download = '';
      break;
  }

  // Set up the variables for the template.
  $item_key = $current->getOriginalKey() + 1;
  $previous_link = !$navigation['previous'] ? FALSE : l(t('Previous'), $navigation['previous']->getGalleryItemLink($node));
  $next_link = !$navigation['next'] ? FALSE : l(t('Next'), $navigation['next']->getGalleryItemLink($node));
  // Close links back to the host node (for no js mostly).
  $close_link = l(t('Close'), url('node/' . $node->nid));

  // Assemble the component markup.
  $render_array = [
    '#theme' => 'gallery_overlay',
    '#previous' => $previous_link,
    '#next' => $next_link,
    '#media' => drupal_render($media),
    '#type' => $current->getType(),
    '#description' => $current->getCaption(),
    '#count' => t('!current of !total', ['!current' => $item_key, '!total' => $gallery->count()]),
    '#close' => $close_link,
    '#download' => $download,
    '#share' => '',
  ];

  // @TODO: Exact title pattern to be defined.
  drupal_set_title(t('Gallery of the page: !title - !current of !total', [
    '!title' => $node->title,
    '!current' => $item_key,
    '!total' => $gallery->count(),
  ]));

  return $render_array;
}
