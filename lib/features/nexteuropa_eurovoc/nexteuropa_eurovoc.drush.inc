<?php

/**
 * @file
 * Drush code for the module.
 */

// Drupal-specific helpers.
require_once 'nexteuropa_eurovoc.helpers.inc';
// Module settings.
require_once 'nexteuropa_eurovoc.config.php';

/**
 * Implements hook_drush_command().
 */
function nexteuropa_eurovoc_drush_command() {

  $items['nexteuropa-eurovoc'] = [
    'description' => t('Drush plugin EuroVoc.'),
    'aliases' => ['eurovoc'],
    'callback' => 'drush_eurovoc',
    'arguments' => [
      'op' => 'Operation',
    ],
  ];

  return $items;
}

/**
 * Callback for nexteuropa-eurovoc command.
 *
 * @param string $op
 *   Type of operation to run.
 */
function drush_eurovoc($op = 'quickstart') {
  if (!module_exists('migrate')) {
    drush_log(dt('Migrate module is required for this to work.'), 'status');
    // Exit the function.
    return;
  }

  // Possible operations.
  $op_possible = [
    'quickstart',
    'clear',
    'data',
    'import',
    'translate',
    'help',
    'c',
    'd',
    'i',
    't',
    'h',
  ];

  switch ($op) {
    case 'quickstart':
      drush_log(dt('This operation will take a lot of time.'), 'warning');
      drush_log(dt('Existing data in EuroVoc vocabulary will be wiped out.'), 'warning');
      if (drush_confirm(dt('Do you really want to continue?'))) {
        // First clear the vocabulary to re-do everything.
        drush_log(dt('Clearing the vocabulary ...'), 'status');
        if (_nexteuropa_eurovoc_clear_eurovoc_vocabulary()) {
          drush_log(dt('EuroVoc vocabulary was cleared successfully.'), 'success');
        }
        else {
          drush_log(dt('There was no need to clear the vocabulary.'), 'status');
        }

        // Download EuroVoc data.
        drush_invoke('eurovoc', ['data']);

        // Run the importers, one by one, best chance for consistent results.
        drush_invoke('mi', ['EuroVocDomainsMigration']);
        drush_invoke('mi', ['EuroVocThesauriMigration']);
        drush_invoke('mi', ['EuroVocDescriptorsMigration']);

        // Show message that they can translate now.
        drush_log(dt('Eurovoc import complete, you can now run "drush eurovoc translate"'), 'status');
      }
      break;

    // Clears up the vocabulary.
    case 'clear':
    case 'c':
      _nexteuropa_eurovoc_clear();
      break;

    // Get EuroVoc data for the importers.
    case 'data':
    case 'd':
      _nexteuropa_eurovoc_get_data();
      break;

    // Import concepts in the taxonomy.
    case 'import':
    case 'i':
      $concept = _nexteuropa_eurovoc_get_concept();

      // Execute all importers.
      if ($concept == 'all') {
        // Synchronous to ensure consistency.
        drush_invoke('mi', ['EuroVocDomainsMigration']);
        drush_invoke('mi', ['EuroVocThesauriMigration']);
        drush_invoke('mi', ['EuroVocDescriptorsMigration']);
      }
      else {
        // Individual imports.
        switch ($concept) {
          case 'domains':
            drush_invoke('mi', ['EuroVocDomainsMigration']);
            break;

          case 'thesauri':
            drush_invoke('mi', ['EuroVocThesauriMigration']);
            break;

          case 'descriptors':
            drush_invoke('mi', ['EuroVocDescriptorsMigration']);
            break;
        }
      }
      break;

    // Translate concepts with i18 locale interface in Drupal.
    case 'translate':
    case 't':
      // This is a pure Drupal helper, the success message is separate.
      _nexteuropa_eurovoc_translate_terms();
      drush_log(dt('Translations import is ready.'), 'success');
      break;

    // Fallback if a wrong operation is provided.
    default:
      drush_set_error(dt('Operation not available. Please choose between: @options',
        [
          '@options' => implode(', ', $op_possible),
        ]));
      break;
  }

}

/**
 * Drush helper to get the EuroVoc data.
 */
function _nexteuropa_eurovoc_get_data() {
  $path = drupal_get_path('module', 'nexteuropa_eurovoc') . '/' . EUROVOC_DATA_FOLDER;

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', ['@path' => $path]), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive.
  if ($filepath = drush_download_file(EUROVOC_ZIP_URL)) {
    $filename = basename($filepath);
    $dirname = EUROVOC_DATA_FOLDER;

    // Remove any existing EuroVoc data.
    if (is_dir($dirname) || is_dir(EUROVOC_DATA_FOLDER)) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir(EUROVOC_DATA_FOLDER, TRUE);
      drush_log(dt('A existing data folder was deleted from @path', ['@path' => $path]), 'notice');
    }

    // Decompress the zip archive.
    drush_tarball_extract($filename);

  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}

/**
 * Drush helper to get a concept selection.
 *
 * @return string
 *   A concept selection.
 */
function _nexteuropa_eurovoc_get_concept() {
  // Possible service importers.
  $concepts_possible = [
    'all' => dt('All'),
    'domains' => dt('Domains'),
    'thesauri' => dt('Thesauri'),
    'descriptors' => dt('Descriptors'),
  ];
  // Take user input.
  $concept = drush_get_option('concept', 'all');

  if (!in_array($concept, $concepts_possible)) {
    $concept = drush_choice($concepts_possible,
      dt('Please select a concept:'));
  }

  return $concept;
}

/**
 * Drush helper: clears the EuroVoc taxonomy vocabulary.
 */
function _nexteuropa_eurovoc_clear() {
  if (drush_confirm(dt('Do you really want to continue?'))) {
    drush_log(dt('Clearing the vocabulary ...'), 'status');
    if (_nexteuropa_eurovoc_clear_eurovoc_vocabulary()) {
      drush_log(dt('EuroVoc vocabulary was cleared successfully.'), 'success');
    }
    else {
      drush_log(dt('Did not manage to clear EuroVoc vocabulary.'), 'warning');
    }
  }
}
