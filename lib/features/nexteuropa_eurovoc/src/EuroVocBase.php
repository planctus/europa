<?php

namespace Drupal\nexteuropa_eurovoc;

/**
 * Class EuroVocBase.
 *
 * Provides the base methods.
 */
class EuroVocBase {

  /**
   * Equivalent to _nexteuropa_eurovoc_get_data_full_path() in this namespace.
   *
   * @return string
   *   The path to the folder containing XML files to parse.
   */
  public function getDataPath() {
    return DRUPAL_ROOT . '/' . variable_get('file_private_path') . '/' . EUROVOC_DATA_FOLDER;
  }

}
