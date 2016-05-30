<?php
/**
 * @file
 * Department tasks taxonomy term migration file.
 */

/**
 * Import terms on "Department tasks" vocabulary.
 */
class DTDepartmentTasksMigration extends Migration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "Department tasks" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'department_task' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Department task',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'dt_department') . '/data/department_tasks.csv';
    $this->source = new MigrateSourceCSV($path,
      array(
        array('department_task', 'Department Task'),
      ),
      array(
        'header_rows' => 1,
        'delimiter' => ';',
      )
    );
    $this->destination = new MigrateDestinationTerm('department_tasks');

    $this->addFieldMapping('name', 'department_task');
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
