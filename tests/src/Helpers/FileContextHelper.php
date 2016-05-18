<?php

namespace Drupal\nexteuropa\Helpers;

/**
 * Helper class to get dummy file entity's.
 */
class FileContextHelper {

  /**
   * Whether the files were copied to the test files directory.
   */
  protected $generatedTestFiles = FALSE;

  /**
   * List of files generated.
   */
  protected $generatedTestFilesList = [];

  /**
   * Generates a plain text token to be inserted into wysiwyg fields.
   *
   * @param object $entity
   *   The entity to generate the token for.
   * @param string $view_mode
   *   The view mode to render the file in.
   *
   * @return string
   *   The plain text json string.
   */
  public function generateTokenbMarkupFromEntity($entity, $view_mode) {
    return $this->generateJsonTokenMarkup($entity->fid, 1, $view_mode);
  }

  /**
   * Gets the generatedTestFilesList.
   */
  public function getGeneratedTestFiles() {
    return $this->generatedTestFilesList;
  }

  /**
   * Generates a dummy image.
   *
   * @return object
   *   The file entity object.
   */
  public function generateImageFileEntity() {
    // Get a single image.
    $file_info = $this->getSingleTestFile('image');

    // Generate the file entity object.
    $file = new \stdClass();
    $file->uri = $file_info->uri;
    $file->filename = drupal_basename($file->uri);
    $file->filemime = 'image/png';
    $file->uid = 1;
    $file->timestamp = REQUEST_TIME;
    $file->filesize = filesize($file->uri);
    $file->status = FILE_STATUS_PERMANENT;
    $file->type = 'image';

    // Save the file entity.
    $file_entity = file_save($file);

    // Add the file to our list, so we can delete them later.
    $this->generatedTestFilesList[] = $file_entity;

    return $file_entity;
  }

  /**
   * Gets just a single test file.
   *
   * @param string $type
   *   File type, possible values: 'binary', 'html', 'image', 'javascript',
   *   'php', 'sql', 'text'.
   *
   * @return object
   *   The actual file object.
   */
  protected function getSingleTestFile($type) {
    $files = $this->getTestFiles($type);
    return reset($files);
  }

  /**
   * Get a list files that can be used in tests.
   *
   * This is a copy of drupal_web_test_case::druplGetTestFiles.
   *
   * @param string $type
   *   File type, possible values: 'binary', 'html', 'image', 'javascript',
   *   'php', 'sql', 'text'.
   * @param int $size
   *   File size in bytes to match. Please check the tests/files folder.
   *
   * @return array
   *   List of files that match filter.
   */
  protected function getTestFiles($type, $size = NULL) {
    if (empty($this->generatedTestFiles)) {
      // Generate binary test files.
      $lines = array(64, 1024);
      $count = 0;
      foreach ($lines as $line) {
        simpletest_generate_file('binary-' . $count++, 64, $line, 'binary');
      }

      // Generate text test files.
      $lines = array(16, 256, 1024, 2048, 20480);
      $count = 0;
      foreach ($lines as $line) {
        simpletest_generate_file('text-' . $count++, 64, $line, 'text');
      }

      // Copy other test files from simpletest.
      $original = drupal_get_path('module', 'simpletest') . '/files';
      $files = file_scan_directory($original, '/(html|image|javascript|php|sql)-.*/');
      foreach ($files as $file) {
        file_unmanaged_copy($file->uri, variable_get('file_public_path', conf_path() . '/files'));
      }

      $this->generatedTestFiles = TRUE;
    }

    $files = array();
    $types_array = [
      'binary',
      'html',
      'image',
      'javascript',
      'php',
      'sql',
      'text',
    ];
    // Make sure type is valid.
    if (in_array($type, $types_array)) {
      $files = file_scan_directory('public://', '/' . $type . '\-.*/');

      // If size is set then remove any files that are not of that size.
      if ($size !== NULL) {
        foreach ($files as $file) {
          $stats = stat($file->uri);
          if ($stats['size'] != $size) {
            unset($files[$file->uri]);
          }
        }
      }
    }
    usort($files, array($this, 'drupalCompareFiles'));
    return $files;
  }

  /**
   * Compare two files based on size and file name.
   */
  protected function drupalCompareFiles($file1, $file2) {
    $compare_size = filesize($file1->uri) - filesize($file2->uri);
    if ($compare_size) {
      // Sort by file size.
      return $compare_size;
    }
    else {
      // The files were the same size, so sort alphabetically.
      return strnatcmp($file1->name, $file2->name);
    }
  }

  /**
   * Generates markup to be inserted for a file.
   *
   * This is a PHP version of InsertMedia.insert() from js/wysiwyg-media.js.
   *
   * @param int $fid
   *   Drupal file id.
   * @param int $count
   *   Quantity of markup to insert.
   * @param array $attributes
   *   Extra attributes to insert.
   * @param array $fields
   *   Extra field values to insert.
   *
   * @return string
   *   Filter markup.
   */
  protected function generateJsonTokenMarkup($fid, $count = 1, $view_mode = 'preview', array $attributes = array(), array $fields = array()) {
    $markup = '';
    // Merge default atttributes.
    $attributes += array(
      'height' => 100,
      'width' => 100,
      'classes' => 'media-element file_' . $view_mode,
    );

    // Build the data that is used in a media tag.
    $data = array(
      'fid' => $fid,
      'type' => 'media',
      'view_mode' => $view_mode,
      'attributes' => $attributes,
      'fields' => $fields,
    );

    // Create the file usage markup.
    for ($i = 1; $i <= $count; $i++) {
      $markup .= '<p>[[' . drupal_json_encode($data) . ']]</p>';
    }

    return $markup;
  }

}
