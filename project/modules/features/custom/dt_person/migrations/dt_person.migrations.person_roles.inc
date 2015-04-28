<?php
/**
 * Import terms on "Person roles" vocabulary.
 */
class DTPersonRolesMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    
    $this->description = t('Import "Person roles" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Term name',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'dt_person') . '/data/person_roles.csv';
    $this->source = new MigrateSourceCSV($path, array(array('name', 'Name')), array('delimiter' => ';'));
    $this->destination = new MigrateDestinationTerm('person_roles');

    $this->addFieldMapping('name', 'name');
  }

}