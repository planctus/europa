<?php

namespace Drupal\dt_gallery;

/**
 * Class DtGalleryRow.
 *
 * @package digital_transformation.
 */
class DtGalleryRow extends DtGalleryItems {

  /**
   * If the gallery row is dynamic.
   *
   * @var bool
   */
  private $dynamic;

  /**
   * DtGalleryRow constructor.
   *
   * @param array $items
   *   The items to be part of this row.
   * @param bool $dynamic
   *   If the row is dynamic.
   */
  public function __construct(array $items, $dynamic = TRUE) {
    parent::__construct($items);
    // Calculate the sizes.
    $this->setDynamic($dynamic);
    $this->calculateSizes();
  }

  /**
   * Calculates the sizes for each item in the row.
   */
  public function calculateSizes() {
    // Set the original order.
    foreach ($this->items as $key => $value) {
      $value->setOriginalKey($key);
    }
    // Sort array by biggest width.
    usort($this->items, [$this, 'sortByWidth']);

    // Init vars.
    $minimum_size = 2;
    $max_size = 3;

    // Get the count of items.
    $items_count = count($this->items);

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
    if (!$this->isDynamic()) {
      $minimum_size = ceil(12 / $items_count);
      $max_size = $minimum_size;
    }

    // Loop over the items.
    $temp_sizes = [];
    /* @var $item DtGalleryItemBase */
    foreach ($this->items as $key => &$item) {
      if (!in_array($max_size, $temp_sizes)) {
        $item->setSize($max_size);
      }
      else {
        // Space per item.
        $space_per_item = (12 - array_sum($temp_sizes)) / ($items_count - count($temp_sizes));
        // Add it to the list.
        $item->setSize($space_per_item > $minimum_size ? ceil($space_per_item) : $minimum_size);
      }
      $temp_sizes[] = $item->getSize();
    }

    // Sort back the array by its original key.
    usort($this->items, [$this, 'sortByOriginalKey']);
  }

  /**
   * Sorts items by width.
   *
   * @param \Drupal\dt_gallery\DtGalleryItemBase $a
   *   First item.
   * @param \Drupal\dt_gallery\DtGalleryItemBase $b
   *   Second item.
   *
   * @return int
   *   The sort weigth.
   */
  private static function sortByWidth(DtGalleryItemBase $a, DtGalleryItemBase $b) {
    if ($a->getFileWidth() && $b->getFileWidth()) {
      if ($a->getFileWidth() / $a->getFileHeight() == $b->getFileWidth() / $b->getFileHeight()) {
        return 0;
      }
      return (($a->getFileWidth() / $a->getFileHeight()) > ($b->getFileWidth() / $b->getFileHeight()) ? -1 : 1);
    }
    // If it is an non image file.
    return 0;
  }

  /**
   * Returns the array sorted.
   *
   * @param \Drupal\dt_gallery\DtGalleryItemBase $a
   *   First sorting parameter.
   * @param \Drupal\dt_gallery\DtGalleryItemBase $b
   *   Second sorting parameter.
   *
   * @return int
   *   The lightest.
   */
  private static function sortByOriginalKey(DtGalleryItemBase $a, DtGalleryItemBase $b) {
    return $a->getOriginalKey() < $b->getOriginalKey() ? -1 : 1;
  }

  /**
   * If the row is dynamic or not.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public function isDynamic() {
    return $this->dynamic;
  }

  /**
   * Sets the dynamic state of the row.
   *
   * @param bool $dynamic
   *   TRUE or FALSE if dynamic or not.
   */
  public function setDynamic($dynamic) {
    $this->dynamic = $dynamic;
  }

}
