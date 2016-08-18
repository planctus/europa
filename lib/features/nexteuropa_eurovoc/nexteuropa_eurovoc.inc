<?php

/**
 * @file
 * EuroVoc taxonomy terms migration file.
 */

use Drupal\nexteuropa_eurovoc\EuroVoc;

include_once 'nexteuropa_eurovoc.helpers.inc';

/**
 * Import terms from Domain EuroVoc vocabulary.
 */
class NexteuropaEuroVocDomainsMigration extends XMLMigration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {

    parent::__construct($arguments);
    $this->description = t('Import Domains into EuroVoc vocabulary.');

    $fields = [
      'DOMAINE_ID' => t('Domain ID (DOMAINE_ID)'),
      'LIBELLE' => t('Domain title (LIBELLE)'),
    ];

    // Source.
    $xml_folder = _nexteuropa_eurovoc_get_data_full_path();
    $items_url = $xml_folder . '/dom_en.xml';
    $item_xpath = '/DOMAINES/RECORD';
    $item_ID_xpath = 'DOMAINE_ID';
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);

    // Destination.
    $this->destination = new MigrateDestinationTerm('eurovoc');

    // Mapping.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      [
        'DOMAINE_ID' => [
          'type' => 'varchar',
          'length' => 2,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );
    $this->addFieldMapping('name', 'LIBELLE')->xpath('LIBELLE');
    $this->addFieldMapping('field_eurovoc_id', 'DOMAINE_ID')->xpath('DOMAINE_ID');
    $this->addFieldMapping('field_eurovoc_level')->defaultValue('domain');
    $this->addUnmigratedDestinations(
      [
        'description',
        'parent',
        'parent_name',
        'format',
        'weight',
        'path',
      ]
    );
  }

}

/**
 * Import terms from Thesauri EuroVoc vocabulary.
 */
class NexteuropaEuroVocThesauriMigration extends XMLMigration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {

    parent::__construct($arguments);
    $this->description = t('Import Thesauri into EuroVoc vocabulary.');

    $fields = [
      'THESAURUS_ID' => t('Thesaurus ID (THESAURUS_ID)'),
      'LIBELLE' => t('Thesaurus title (LIBELLE)'),
    ];

    // Source.
    $xml_folder = _nexteuropa_eurovoc_get_data_full_path();
    $items_url = $xml_folder . '/thes_en.xml';
    $item_xpath = '/THESAURUS/RECORD';
    $item_ID_xpath = 'THESAURUS_ID';
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);

    // Destination.
    $this->destination = new MigrateDestinationTerm('eurovoc');

    // Mapping.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      [
        'THESAURUS_ID' => [
          'type' => 'varchar',
          'length' => 6,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );
    $this->addFieldMapping('name', 'LIBELLE')->xpath('LIBELLE');
    $this->addFieldMapping('field_eurovoc_id', 'THESAURUS_ID')->xpath('THESAURUS_ID');
    $this->addFieldMapping('parent', 'parent_id')->sourceMigration('EuroVocDomainsMigration');
    $this->addFieldMapping('field_eurovoc_level')->defaultValue('thesaurus');
    $this->addUnmigratedDestinations(
      [
        'description',
        'parent_name',
        'format',
        'weight',
        'path',
      ]
    );
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->parent_id = substr($row->THESAURUS_ID, 0, 2);
  }

}

/**
 * Import terms from Descriptors EuroVoc vocabulary.
 */
class NexteuropaEuroVocDescriptorsMigration extends XMLMigration {
  /**
   * Helper high-level handler for EuroVoc taxonomy.
   *
   * @var \Drupal\nexteuropa_eurovoc\EuroVoc
   */
  private $eurovoc;

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {

    // EuroVoc helper class.
    $this->eurovoc = new EuroVoc();

    parent::__construct($arguments);
    $this->description = t('Import Descriptors into EuroVoc vocabulary.');

    $fields = [
      'DESCRIPTEUR_ID' => t('Descriptor ID (DESCRIPTEUR_ID)'),
      'LIBELLE' => t('Descriptor title (LIBELLE)'),
    ];

    // Source.
    $xml_folder = _nexteuropa_eurovoc_get_data_full_path();
    $items_url = $xml_folder . '/desc_en.xml';
    $item_xpath = '/DESCRIPTEUR/RECORD';
    $item_ID_xpath = 'DESCRIPTEUR_ID';
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields);

    // Destination.
    $this->destination = new MigrateDestinationTerm('eurovoc');

    // Mapping.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      [
        'DESCRIPTEUR_ID' => [
          'type' => 'varchar',
          'length' => 12,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );
    $this->addFieldMapping('name', 'LIBELLE')->xpath('LIBELLE');
    $this->addFieldMapping('field_eurovoc_id', 'DESCRIPTEUR_ID')->xpath('DESCRIPTEUR_ID');
    $this->addFieldMapping('field_eurovoc_level')->defaultValue('descriptor');
    $this->addFieldMapping('parent', 'parents_ids')->sourceMigration('EuroVocThesauriMigration');
    $this->addUnmigratedDestinations(
      [
        'description',
        'parent_name',
        'format',
        'weight',
        'path',
        'field_eurovoc_related',
        'field_eurovoc_ui',
      ]
    );
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    // Descriptor to thesaurus relationships.
    $row->parents_ids = $this->eurovoc->getParents($row->DESCRIPTEUR_ID);
  }

  /**
   * {@inheritdoc}
   */
  public function postImport() {
    parent::postImport();
    _nexteuropa_eurovoc_organize_broader_descriptors($this->eurovoc);
    _nexteuropa_eurovoc_adopt_orphan_descriptors($this->eurovoc);
    _nexteuropa_eurovoc_connect_related($this->eurovoc);
  }

}
