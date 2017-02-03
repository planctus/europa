<?php

namespace Drupal\dt_gallery;

use Exception;

/**
 * Class DtGallery.
 *
 * @package digital_transformation
 */
class DtGallery {

  const GALLERY_PATH_SEGMENT = 'gallery';
  const GALLERY_FIELD = 'field_core_gallery';
  /**
   * The amount of images to display per row.
   *
   * @var int
   */
  private $imagesPerRow = 4;

  /**
   * The rows.
   *
   * @var array
   */
  private $rows;

  /**
   * If the gallery is dynamic.
   *
   * @var bool
   */
  private $dynamic;

  private $items;

  private $gallery;

  /**
   * DtGallery constructor.
   *
   * @param array $items
   *   The array of items to use in the gallery.
   * @param bool $dynamic
   *   If the size should be dynamic.
   */
  public function __construct(array $items, $dynamic = TRUE) {
    $this->setItems($items);
    $this->setDynamic($dynamic);
    $this->convertItems();
    $this->setRows($this->calculateRows());
    $this->setGallery($this->allItems());
  }

  /**
   * Sets the items.
   *
   * @param array $items
   *   Items from field value.
   */
  public function setItems($items) {
    $this->items = $items;
  }

  /**
   * Gets the items.
   *
   * @return array
   *   Items of the gallery.
   */
  public function getItems() {
    return $this->items;
  }

  /**
   * Converts the items to objects.
   *
   * Each file type uses their own class. @see DtGalleryItemBase for the base
   * implementation.
   *
   * @throws Exception
   */
  private function convertItems() {
    foreach ($this->items as &$item) {
      switch ($item['file']->type) {
        case 'image':
          $item = new DtGalleryItemImage($item);
          break;

        case 'video':
          $item = new DtGalleryItemVideo($item);
          break;

        default:
          throw new Exception('Tried to load an unimplemented file type into the DtGallery');
      }
    }
  }

  /**
   * Calculates the rows to be used in the gallery.
   *
   * @return array
   *   The items to use in rows.
   */
  public function calculateRows() {
    $total_images = count($this->items);
    $rows = ceil($total_images / $this->getItemsPerRow());

    // Initialize the rows.
    $image_rows = [];

    // Build an array of images per row.
    for ($i = 0; $i < $rows; $i++) {
      $image_rows[$i] = new DtGalleryRow(array_slice($this->items, $i * $this->getItemsPerRow(), $this->getItemsPerRow()), $this->isDynamic());
      // If the images in the row are less then $this->getItemsPerRow(),
      // we can stop.
      if (count($image_rows[$i]) < $this->getItemsPerRow()) {
        break;
      }
    }

    return $image_rows;
  }

  /**
   * Gets the rows.
   *
   * @return array
   *   The rows to use.
   */
  public function getRows() {
    return $this->rows;
  }

  /**
   * Sets the rows.
   *
   * @param array $items
   *   The rows to use.
   */
  public function setRows($items) {
    $this->rows = $items;
  }

  /**
   * Gets the amount of images per row.
   *
   * @return int
   *   The amount.
   */
  public function getItemsPerRow() {
    return $this->imagesPerRow;
  }

  /**
   * Sets the images per row.
   *
   * @param int $images_per_row
   *   The amount.
   */
  public function setImagesPerRow($images_per_row) {
    $this->imagesPerRow = $images_per_row;
    $this->setRows($this->calculateRows());
  }

  /**
   * If the gallery is dynamic or not.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public function isDynamic() {
    return $this->dynamic;
  }

  /**
   * Sets the dynamic state of the gallery.
   *
   * @param bool $dynamic
   *   TRUE or FALSE if dynamic or not.
   */
  public function setDynamic($dynamic) {
    $this->dynamic = $dynamic;
  }

  /**
   * Sets the gallery.
   *
   * @param DtGalleryItems $gallery
   *    Parsed gallery items.
   */
  public function setGallery(DtGalleryItems $gallery) {
    $this->gallery = $gallery;
  }

  /**
   * Gets the gallery.
   *
   * @return DtGalleryItems
   *   Gallery with parsed items.
   */
  public function getGallery() {
    return $this->gallery;
  }

  /**
   * Create a flat list of all gallery items.
   *
   * @return DtGalleryItems
   *   All items in the gallery, not in rows.
   */
  private function allItems() {
    return new DtGalleryItems($this->items);
  }

}
