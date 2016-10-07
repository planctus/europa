<?php

namespace Drupal\dt_gallery;

/**
 * Defines the base of a gallery item.
 *
 * @package digital_transformation.
 */
abstract class DtGalleryItemBase {

  /**
   * The file which is part of the item.
   *
   * @var object
   */
  private $file;

  /**
   * The size of the item in the row.
   *
   * @var int
   */
  private $size;

  /**
   * The original key for sorting.
   *
   * @var int
   */
  private $originalKey;

  /**
   * DtGalleryItem constructor.
   *
   * @param array $item
   *   Array containing item information.
   */
  public function __construct(array $item) {
    $this->setFile($item['file']);
  }

  /**
   * Gets the file.
   *
   * @return object
   *   File object.
   */
  public function getFile() {
    return $this->file;
  }

  /**
   * Sets the file.
   *
   * @param object $file
   *   The file object.
   */
  private function setFile($file) {
    $this->file = $file;
  }

  /**
   * Sets the size.
   *
   * @param int $size
   *   The size inside the row.
   */
  public function setSize($size) {
    $this->size = $size;
  }

  /**
   * Gets the size.
   *
   * @return int
   *   The size inside the row.
   */
  public function getSize() {
    return $this->size;
  }

  /**
   * Sets the original key.
   *
   * @param int $original_key
   *   The original key.
   */
  public function setOriginalKey($original_key) {
    $this->originalKey = $original_key;
  }

  /**
   * Gets the original key.
   *
   * @return int
   *   The original key.
   */
  public function getOriginalKey() {
    return $this->originalKey;
  }

  /**
   * Gets the file title.
   *
   * @return string
   *   The file title.
   */
  public function getTitle() {
    return $this->getFile()->title;
  }

  /**
   * Gets the file alt.
   *
   * @return string
   *   The file alt.
   */
  public function getAlt() {
    return $this->getFile()->alt;
  }

  /**
   * Gets the file uri.
   *
   * @return string
   *   The file uri.
   */
  public function getUri() {
    return $this->getFile()->uri;
  }

  /**
   * Gets the caption of the item.
   *
   * @return string
   *   The caption as a string.
   */
  abstract public function getCaption();

  /**
   * Gets the icon class for an item.
   *
   * @return string
   *   The Icon class as a string.
   */
  abstract public function getIcon();

  /**
   * Gets the file width if available.
   *
   * This is used for making the gallery having a dynamic presence.
   *
   * @return mixed
   *   File width. FALSE if not available.
   */
  public function getFileWidth() {
    return FALSE;
  }

  /**
   * Gets the file height if available.
   *
   * This is used for making the gallery having a dynamic presence.
   *
   * @return mixed
   *   File height. FALSE if not available.
   */
  public function getFileHeight() {
    return FALSE;
  }

}
