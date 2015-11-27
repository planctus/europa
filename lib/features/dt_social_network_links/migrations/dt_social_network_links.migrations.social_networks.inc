<?php
/**
 * @file
 * Social Networks taxonomy term migration file.
 */

/**
 * Import terms on "Social Networks" vocabulary.
 */
class DTSocialNetworksMigration extends Migration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "Social Networks" terms');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'social_network' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => TRUE,
          'description' => 'Social Networks',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $path = drupal_get_path('module', 'dt_social_network_links') . '/data/social_networks.csv';
    $this->source = new MigrateSourceCSV($path,
      array(
        array('social_network', 'Social Network'),
        array('classname', 'Classname'),
      ),
      array(
        'header_rows' => 1,
        'delimiter' => ';',
      )
    );
    $this->destination = new MigrateDestinationTerm('social_networks');

    $this->addFieldMapping('name', 'social_network');
    $this->addFieldMapping('field_social_network_classname', 'classname');
    $this->addUnmigratedDestinations(
      array(
        'description',
        'description_field',
        'description_field:format',
        'description_field:language',
        'description_field:summary',
        'field_social_network_classname:language',
        'field_social_network_icon',
        'field_social_network_icon:file_class',
        'field_social_network_icon:language',
        'field_social_network_icon:preserve_files',
        'field_social_network_icon:destination_dir',
        'field_social_network_icon:destination_file',
        'field_social_network_icon:file_replace',
        'field_social_network_icon:source_dir',
        'field_social_network_icon:urlencode',
        'field_social_network_icon:alt',
        'field_social_network_icon:title',
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
