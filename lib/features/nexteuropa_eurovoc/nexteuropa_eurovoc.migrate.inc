<?php

/**
 * @file
 * EuroVoc migration.
 */

/**
 * @file
 * Nexteuropa_eurovoc.module.
 *
 * Provides a way to import terms into the EuroVoc vocabulary.
 */

/**
 * Implements hook_migrate_api().
 */
function nexteuropa_eurovoc_migrate_api() {

  return [
    'api' => 2,
    'groups' => [
      'NextEuropa' => [
        'title' => t('NextEuropa Migrate'),
      ],
    ],
    'migrations' => [
      'EuroVocDomainsMigration' => [
        'class_name' => 'NexteuropaEuroVocDomainsMigration',
        'group_name' => 'NextEuropa EuroVoc',
        'description' => t('Import EuroVoc Domains.'),
      ],
      'EuroVocThesauriMigration' => [
        'class_name' => 'NexteuropaEuroVocThesauriMigration',
        'group_name' => 'NextEuropa EuroVoc',
        'description' => t('Import EuroVoc Thesauri.'),
      ],
      'EuroVocDescriptorsMigration' => [
        'class_name' => 'NexteuropaEuroVocDescriptorsMigration',
        'group_name' => 'NextEuropa EuroVoc',
        'description' => t('Import EuroVoc Descriptors.'),
      ],
    ],
  ];
}
