<?php

namespace Drupal\dt_gallery\EntityWrapper\Node;

use EntityDrupalWrapper;
use Drupal\dt_gallery\DtGallery;
use Drupal\dt_gallery\DtGalleryItems;

/**
 * Class DTGalleryWrapper.
 *
 * Extends the entity wrapper with gallery related methods.
 *
 * @package digital_transformation.
 */
class DTGalleryWrapper extends EntityDrupalWrapper {
  /**
   * The items in the gallery.
   *
   * @var \Drupal\dt_gallery\DtGalleryRow
   */
  private $galleryItems = NULL;

  /**
   * Wrap a node object.
   *
   * @param int|object $data
   *   A nid or node object.
   */
  public function __construct($data) {
    parent::__construct('node', $data);
    if (!empty($this->data->{DtGallery::GALLERY_FIELD})) {
      $field = field_view_field('node', $this->data, DtGallery::GALLERY_FIELD);
      $gallery = new DtGallery($field['#items'], FALSE);
      $this->setGalleryItems($gallery->getGallery());
    }
  }

  /**
   * Entity is a gallery or not.
   *
   * @return bool
   *   If node is a gallery.
   */
  public function isGallery() {
    return !empty($this->getGalleryItems());
  }

  /**
   * Gets the gallery items.
   *
   * @return DtGalleryItems
   *   Items of the gallery.
   */
  public function getGalleryItems() {
    return $this->galleryItems;
  }

  /**
   * Sets the gallery items.
   *
   * @param DtGalleryItems $items
   *   Items of the gallery.
   */
  public function setGalleryItems(DtGalleryItems $items) {
    $this->galleryItems = $items;
  }

}
