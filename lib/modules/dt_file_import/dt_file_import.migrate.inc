<?php

/**
 * @file
 * DT File import migrate api.
 */

/**
 * Implements hook_migrate_api().
 */
function dt_file_import_migrate_api() {
  return [
    'api' => 2,
    'groups' => [
      'NextEuropaFilePublication' => [
        'title' => t('Documentum transformation'),
      ],
    ],
    'migrations' => [
      'DTCollection' => [
        'class_name' => 'DtFileImportCollectionImport',
        'group_name' => 'NextEuropaFilePublication',
      ],
      'DTPublication' => [
        'class_name' => 'DtFileImportPublicationImport',
        'group_name' => 'NextEuropaFilePublication',
        'dependencies' => [
          'DTCollection',
        ],
      ],
      'DTFile' => [
        'class_name' => 'DtFileImportFileImport',
        'group_name' => 'NextEuropaFilePublication',
        'dependencies' => [
          'DTCollection',
          'DTPublication',
        ],
      ],
    ],
  ];
}
