<?php

/**
 * @file
 * Social Networks taxonomy term migration file.
 */

/**
 * Import terms on "File Types" vocabulary.
 */
class NextEuropaFileTypesMigration extends Migration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "File type" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'file_type' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'File Type',
        ),
        'file_type_classname' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'File Type Classname',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'nexteuropa_file') . '/data/nexteuropa_file.file_types.csv';
    $this->source = new MigrateSourceCSV($path,
      array(
        array('file_type', 'File Type'),
        array('file_type_classname', 'File Type Classname'),
      ),
      array(
        'delimiter' => ';',
      )
    );

    $this->destination = new MigrateDestinationTerm('file_types');

    $this->addFieldMapping('name', 'file_type');
    $this->addFieldMapping('field_file_type_classname', 'file_type_classname');
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

}

/**
 * Import terms on "File Origins" vocabulary.
 */
class NextEuropaFileOriginsMigration extends Migration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "File origin" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'file_origin' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'File Type',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'nexteuropa_file') . '/data/nexteuropa_file.file_origins.csv';
    $this->source = new MigrateSourceCSV($path,
      array(
        array('file_origin', 'File Origin'),
      )
    );

    $this->destination = new MigrateDestinationTerm('file_origins');

    $this->addFieldMapping('name', 'file_origin');
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

}
