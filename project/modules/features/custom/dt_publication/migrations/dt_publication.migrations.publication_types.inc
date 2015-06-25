<?php
/**
 * @file
 * Publication types taxonomy term migration file.
 */

/**
 * Import terms on "Publication Types" vocabulary.
 */
class DTPublicationPublicationTypesMigration extends Migration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "Publication types" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'publication_type' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Publication type',
        ),
        'publication_subtype' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Publication subtype',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'dt_publication') . '/data/publication_types.csv';
    $this->source = new MigrateSourceCSV($path,
      array(
        array('publication_type', 'Type'),
        array('publication_subtype', 'Subtype'),
      ),
      array(
        'header_rows' => 1,
        'delimiter' => ';',
      )
    );
    $this->destination = new MigrateDestinationTerm('publication_types');

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('parent_name', 'parent_name');
    $this->addUnmigratedDestinations(
      array(
        'description',
        'parent',
        'format',
        'weight',
        'path',
      )
    );
  }

  public function prepareRow($current_row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($current_row) === FALSE) {
      return FALSE;
    }

    if (trim($current_row->publication_subtype)) {
      $current_row->name = $current_row->publication_subtype;
      $current_row->parent_name = $current_row->publication_type;
    }
    else {
      $current_row->name = $current_row->publication_type;
    }
    return TRUE;
  }
}
