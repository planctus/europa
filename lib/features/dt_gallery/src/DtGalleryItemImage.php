<?php

namespace Drupal\dt_gallery;

/**
 * Class DtGalleryItemImage.
 *
 * @package digital_transformation.
 */
class DtGalleryItemImage extends DtGalleryItemBase {

  /**
   * {@inheritdoc}
   */
  public function getFileWidth() {
    return isset($this->getFile()->width) ? $this->getFile()->width : FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getFileHeight() {
    return isset($this->getFile()->height) ? $this->getFile()->height : FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getCaption() {
    if (isset($this->getFile()->field_caption) && is_array($this->getFile()->field_caption)) {
      $fmw = entity_metadata_wrapper('file', $this->getFile());
      if ($fmw->__isset('field_caption') && $fmw->field_caption->value()) {
        return $fmw->field_caption->value();
      }
    }
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getIcon() {
    return NULL;
  }

}
