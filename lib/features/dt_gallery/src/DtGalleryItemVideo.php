<?php

namespace Drupal\dt_gallery;

/**
 * Class DtGalleryItemImage.
 *
 * @package digital_transformation.
 */
class DtGalleryItemVideo extends DtGalleryItemBase {

  /**
   * {@inheritdoc}
   */
  public function getCaption() {
    if (isset($this->getFile()->field_video_description) && is_array($this->getFile()->field_video_description)) {
      $fmw = entity_metadata_wrapper('file', $this->getFile());
      if ($fmw->__isset('field_video_description') && $fmw->field_video_description->value()) {
        return $fmw->field_video_description->value();
      }
    }
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getIcon() {
    return 'icon--camera';
  }

}
