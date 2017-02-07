<?php

namespace Drupal\dt_gallery;

use Iterator;
use Countable;

/**
 * Class DtGalleryItems.
 *
 * @package digital_transformation.
 */
class DtGalleryItems implements Iterator, Countable {

  /**
   * The items in the row.
   *
   * @var array
   */
  protected $items;

  /**
   * DtGalleryItems constructor.
   *
   * @param array $items
   *   The items to be part of this row.
   */
  public function __construct(array $items) {
    $this->setItems($items);
  }

  /**
   * Finds a gallery item by its $fid.
   *
   * @param int $fid
   *   File id of the file we want to access.
   *
   * @return DtGalleryItemImage|DtGalleryItemVideo|bool
   *   Item with the file ID if exists.
   */
  public function find($fid) {
    foreach ($this->items as $item) {
      if ($item->getId() == $fid) {
        $this->prev();
        return $item;
      }
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function current() {
    return current($this->items);
  }

  /**
   * {@inheritdoc}
   */
  public function next() {
    return next($this->items);
  }

  /**
   * {@inheritdoc}
   */
  public function prev() {
    return prev($this->items);
  }

  /**
   * {@inheritdoc}
   */
  public function key() {
    return key($this->items);
  }

  /**
   * {@inheritdoc}
   */
  public function valid() {
    $key = key($this->items);
    return ($key !== NULL && $key !== FALSE);
  }

  /**
   * {@inheritdoc}
   */
  public function rewind() {
    return reset($this->items);
  }

  /**
   * Gets the items.
   *
   * @return array
   *   Array of items.
   */
  private function getItems() {
    return $this->items;
  }

  /**
   * Sets the items.
   *
   * @param array $items
   *   Array of items.
   */
  private function setItems(array $items) {
    $this->items = $items;
  }

  /**
   * {@inheritdoc}
   */
  public function count() {
    return count($this->getItems());
  }

  /**
   * Gets the next and the previous items in the gallery.
   *
   * Relative to the current key.
   *
   * @return array
   *   Next and previous items.
   */
  public function getNavigation() {
    $key = $this->key();
    // We are not at the last item.
    if ($key !== NULL) {
      $previous = isset($this->items[$key - 1]) ? $this->items[$key - 1] : NULL;
      $next = isset($this->items[$key + 1]) ? $this->items[$key + 1] : NULL;
    }
    // We are at the last item.
    else {
      // Take the penultimate item for previous.
      $previous = isset($this->items[$this->count() - 2]) ? $this->items[$this->count() - 2] : NULL;
      $next = NULL;
    }

    return [
      'previous' => $previous,
      'next' => $next,
    ];
  }

}
