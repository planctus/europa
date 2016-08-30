<?php

/**
 * @file
 * Brp taxonomy terms migration file.
 */

/**
 * Import terms to BRP vocabulary.
 */
// @codingStandardsIgnoreStart
class BRPTermsMigration extends Migration {
// @codingStandardsIgnoreEnd
  private $localize;
  private $languages;

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->localize = $arguments['localized'];
    $this->description = t('Import Dgs terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'code' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Dgs data',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );
    $path = drupal_get_path('module', 'brp_local_importer') . '/data/' . $arguments['data_file'];

    if ($this->localize) {
      $this->languages = language_list();
    }
    $this->source = new MigrateSourceCSV($path,
      _brp_local_importer_csv_cols(),
      array(
        'header_rows' => 1,
        'delimiter' => ',',
      )
    );
    $this->destination = new MigrateDestinationTerm($arguments['destination_voc']);

    $this->addFieldMapping('name', 'label');
    $this->addFieldMapping('field_taxonomy_ws_key', 'code');
    $this->addUnmigratedDestinations(
      array(
        'description',
        'description_field',
        'description_field:format',
        'description_field:language',
        'description_field:summary',
        'format',
        'metatag_abstract',
        'metatag_author',
        'metatag_canonical',
        'metatag_content-language',
        'metatag_description',
        'metatag_generator',
        'metatag_image_src',
        'metatag_keywords',
        'metatag_news_keywords',
        'metatag_original-source',
        'metatag_publisher',
        'metatag_revisit-after',
        'metatag_rights',
        'metatag_robots',
        'metatag_shortlink',
        'metatag_standout',
        'metatag_title',
        'name_field',
        'name_field:language',
        'parent',
        'parent_name',
        'path',
        'weight',
      )
    );
  }

  /**
   * {@inheritdoc}
   */
  public function prepare(stdClass $entity, stdClass $row) {
    $entity->weight = $row->csvrownum;
  }

  /**
   * {@inheritdoc}
   */
  public function complete($entity, stdClass $row) {
    // Translate terms if required.
    if ($this->localize) {
      // Loading function to create translations.
      module_load_include('inc', 'brp_nal_services', 'brp_nal_services.helpers');
      // Load current term.
      $term = taxonomy_term_load($entity->tid);
      $languages = language_list();
      foreach ($languages as $lang_values) {
        _brp_nal_services_translate_term($term->name, $row->{$lang_values->language}, $lang_values->language);
      }
    }
  }

}
