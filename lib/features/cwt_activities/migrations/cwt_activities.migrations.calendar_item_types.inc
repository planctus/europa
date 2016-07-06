<?php

/**
 * @file
 * CWT Activities calendar item migration file.
 */

/**
 * Import terms on "Calendar item" vocabulary.
 */
class CwtActivitiesTypesMigration extends Migration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "Calendar item types" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'calendar_item_types' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Calendar item types',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'cwt_activities') . '/migrations/data/calendar_item_types.csv';
    $this->source = new MigrateSourceCSV($path,
      array(
        array('calendar_item_types', 'Calendar item types'),
      ),
      array(
        'header_rows' => 0,
        'delimiter' => ';',
      )
    );
    $this->destination = new MigrateDestinationTerm('calendar_item_types');

    $this->addFieldMapping('name', 'calendar_item_types');
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

}
