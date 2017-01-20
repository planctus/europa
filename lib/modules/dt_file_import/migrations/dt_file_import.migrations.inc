<?php

/**
 * @file
 * File and Publication import.
 */

/**
 * Global settings.
 */
abstract class DtFileImportGeneralMigration extends XMLMigration {
  protected $xmlFilePath;
  protected $xml;
  const IMPORT_TYPES = [
    'collection' => 'cid',
    'publication' => 'pid',
    'file' => 'fid',
  ];

  /**
   * DTMigration constructor.
   *
   * @param array $arguments
   *   General migration arguments.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->team = [];
    // Use the uploaded file path.
    $this->xmlFilePath = isset($arguments['dt_file_import_file_path']) ? $arguments['dt_file_import_file_path'] : variable_get('dt_file_import_file_path', FALSE);
    // Load the xml.
    $this->xml = $this->xmlFilePath ? simplexml_load_file($this->xmlFilePath) : simplexml_load_string('');
    // Giving value for folder and check if exists.
    $this->folder = 'public://file_import/';
    if (!file_prepare_directory($this->folder, FILE_CREATE_DIRECTORY)) {
      drupal_mkdir($this->folder);
    }

    $this->team = [
      new MigrateTeamMember('János Kuszing', '',
        t('Implementor')),
      new MigrateTeamMember('Ádám Nagy', '',
        t('Implementor')),
      new MigrateTeamMember('Tamás Kugler', '',
        t('Team Lead')),
      new MigrateTeamMember('Rob Harings', '',
        t('Team Lead')),
      new MigrateTeamMember('Jorge Manuel Alves', '',
        t('Team Member')),
      new MigrateTeamMember('Pedro Rafael Carvalho Da Fonseca ', '',
        t('Team Member')),
      new MigrateTeamMember('Davide Ferrante', '',
        t('Team Member')),
      new MigrateTeamMember('Nelson Jose Filipe Matias', '',
        t('Team Member')),
      new MigrateTeamMember('Guiherme Dos Ramos Almeida', '',
        t('Team Member')),
      new MigrateTeamMember('Dave Coote', '',
        t('Team Member')),
      new MigrateTeamMember('Bruno Van Essche', '',
        t('Team Member')),
      new MigrateTeamMember('Emin Mammadov', '',
        t('Scrum Master')),
      new MigrateTeamMember('Hugh Prior', '',
        t('Product Owner')),
      new MigrateTeamMember('Niki Lin', '',
        t('Product Owner')),
    ];
  }

  /**
   * Validating import types.
   *
   * @param string $type
   *   Import types, following types are allowed as a parameter:
   *   - 'collection',
   *   - 'publication',
   *   - 'file'.
   *
   * @return bool - TRUE when the type is valid.
   *   - TRUE when the type is valid.
   *
   * @throws \Exception
   *   - Trows an exception when invalid string given.
   */
  private function validateImportType($type = NULL) {
    if (isset($type) && in_array($type, array_keys(self::IMPORT_TYPES))) {
      return TRUE;
    }
    throw new Exception('Invalid type:' . $type);
  }

  /**
   * Gets the languages related to a import type.
   *
   * @param int $id
   *   Publication ID.
   *
   * @return mixed
   *   - FALSE: when no result.
   *   - array of language ids.
   */
  public function getLanguages($type, $id = NULL) {
    // Validating type.
    $this->validateImportType($type);

    $id_name = self::IMPORT_TYPES[$type];
    $languages = [];
    // Filter languages by type and id.
    $xpath = "/import/${type}_translations/${type}_translation[${id_name}='${id}']/language";
    $xml_lang = $this->xml->xpath($xpath);
    foreach ($xml_lang as $element) {
      $languages[] = (string) $element[0];
    }
    return count($languages) ? $languages : FALSE;
  }

  /**
   * Gives back a translation set, related to a import type.
   *
   * @param string $type
   *   Import types, following types are allowed as a parameter:
   *   - 'collection',
   *   - 'publication',
   *   - 'file'.
   * @param int $id
   *   ID of item.
   * @param string $language
   *   Language code, like: 'en', 'fr', etc.
   *
   * @return mixed
   *   - FALSE: When no result.
   *   - Object of xml elements.
   */
  public function getTranslationElementByIdAndLanguage($type = NULL, $id = NULL, $language = 'en') {
    // Validating type.
    $this->validateImportType($type);

    // Prepare variables.
    $id_name = self::IMPORT_TYPES[$type];

    // Query xpath.
    $xpath = "/import/${type}_translations/${type}_translation[${id_name}='${id}' and language='${language}']";
    $translation = $this->xml->xpath($xpath);
    return count($translation) ? $translation[0] : FALSE;
  }

  /**
   * Get the primary language of the content.
   *
   * @param string $type
   *   Import types, following types are allowed as a parameter:
   *   - 'collection',
   *   - 'publication',
   *   - 'file'.
   * @param int $id
   *   - ID of item.
   *
   * @return bool|string
   *   - FALSE: When no result.
   *   - Title of the item.
   */
  public function getPrimaryLanguage($type = NULL, $id = NULL) {
    // When the type is 'file', should check the original attribute.
    if ($type == 'file') {
      // Validating type.
      $this->validateImportType($type);
      $id_name = self::IMPORT_TYPES[$type];

      // Check the indicator 'original="true"' for primary language.
      $xpath = "/import/${type}_translations/${type}_translation[${id_name}='${id}' and @original='true']/language";
      $xml_lang = $this->xml->xpath($xpath);
      if (!empty($xml_lang)) {
        // Take the first element of array.
        $language = (string) $xml_lang[0];
        return $language;
      }
    }

    // Check the available languages.
    if ($languages = $this->getLanguages($type, $id)) {
      // Use the English as a primary language (if it is exist),
      // otherwise the first element of the languages array.
      $language = array_search('en', $languages) ? 'en' : $languages[0];
      return $language;
    }

    // In this case there is no title, should report at migration messages.
    $this->queueMessage(t('There was no language given for @type! (ID: @id)', ['@type' => $type, '@id' => $id]));
    return FALSE;
  }

  /**
   * Helper for finding the correct title of an item.
   *
   * @param string $type
   *   Import types, following types are allowed as a parameter:
   *   - 'collection',
   *   - 'publication',
   *   - 'file'.
   * @param int $id
   *   - ID of item.
   *
   * @return bool|string
   *   - FALSE: When no result.
   *   - Title of the item.
   */
  public function getTitleById($type = NULL, $id = NULL) {
    // Check if we have any language.
    if ($language = $this->getPrimaryLanguage($type, $id)) {
      $xml = $this->getTranslationElementByIdAndLanguage($type, $id, $language);
      // Check the language version if there is any title.
      if ($xml && isset($xml->title)) {
        return (string) $xml->title[0];
      }
    }
    // In this case there is no title, should report at migration messages.
    $this->queueMessage(t('There was no title given for @type! (ID: @id)', ['@type' => $type, '@id' => $id]));
    return FALSE;
  }

}

/**
 * Collection import.
 */
class DtFileImportCollectionImport extends DtFileImportGeneralMigration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "Collection" contents.');

    // Used fields.
    $fields = [
      'cid' => t('Collection ID'),
      'publication_type' => t('Publication type'),
      'date_published' => t('First published on'),
      'date_updated' => t('Last updated on'),
      'published_by' => t('Published by'),
      'publication_origin' => t('Origin'),
      'core_nal_countries' => t('NAL Countries'),
      'core_tags' => t('Tags'),
      'publication_referenceno' => t('Identifier of the publication'),
      'core_topics' => t('Related topics'),
      'publication_rel_content' => t('Related content'),
      'core_departments' => t('Related departments'),
      'core_policies' => t('Related policies'),
      'eurovoc_taxonomy' => t('Eurovoc taxonomies'),
      'core_legacy_link' => t('Link to publication'),
    ];

    // Xpath of items.
    $item_xpath = '/import/collections/collection';
    // Unique identifier for import.
    $item_ID_xpath = 'cid';
    // Set up source.
    $this->source = new MigrateSourceXML($this->xmlFilePath, $item_xpath, $item_ID_xpath, $fields);

    // Set up of destination.
    $this->destination = new MigrateDestinationNode('publication');

    // Mapping of the unique ID.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      [
        'cid' => [
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );

    // Mapped fields.
    $this->addFieldMapping('title', 'title');

    // Publication type.
    $this->addFieldMapping('field_publication_type', 'publication_type')
      ->xpath('publication_type');
    $this->addFieldMapping('field_publication_type:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_publication_type:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_publication_type:ignore_case')
      ->defaultValue(TRUE);

    // Dates.
    $this->addFieldMapping('field_core_date_published', 'date_published')
      ->xpath('date_published');
    $this->addFieldMapping('field_core_date_updated', 'date_updated')
      ->xpath('date_updated');

    // Publication author.
    $this->addFieldMapping('field_publication_authors', 'published_by')
      ->separator(',')
      ->xpath('published_by');

    // Publication origin.
    $this->addFieldMapping('field_publication_origin', 'publication_origin')
      ->xpath('publication_origin');
    $this->addFieldMapping('field_publication_origin:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_publication_origin:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_publication_origin:ignore_case')
      ->defaultValue(TRUE);

    // NAL Countries.
    $this->addFieldMapping('field_core_nal_countries', 'core_nal_countries')
      ->separator(',')
      ->xpath('core_nal_countries');
    $this->addFieldMapping('field_core_nal_countries:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_core_nal_countries:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_core_nal_countries:ignore_case')
      ->defaultValue(TRUE);

    // Tags.
    $this->addFieldMapping('field_core_tags', 'core_tags')
      ->separator(',')
      ->xpath('core_tags');
    $this->addFieldMapping('field_core_tags:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_core_tags:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_core_tags:ignore_case')
      ->defaultValue(TRUE);

    // Publication reference number.
    $this->addFieldMapping('field_publication_referenceno', 'publication_referenceno')
      ->separator(',')
      ->xpath('publication_referenceno');

    // Reference fields.
    $this->addFieldMapping('field_core_topics', 'core_topics')
      ->separator(',')
      ->xpath('core_topics');
    $this->addFieldMapping('field_publication_rel_content', 'publication_rel_content')
      ->separator(',')
      ->xpath('publication_rel_content');
    $this->addFieldMapping('field_core_departments', 'core_departments')
      ->separator(',')
      ->xpath('core_departments');
    $this->addFieldMapping('field_core_policies', 'core_policies')
      ->separator(',')
      ->xpath('core_policies');
    $this->addFieldMapping('field_eurovoc_taxonomy', 'eurovoc_taxonomy')
      ->separator(',')
      ->xpath('eurovoc_taxonomy');
    // Legacy link.
    $this->addFieldMapping('field_core_legacy_link', 'core_legacy_link')
      ->xpath('core_legacy_link');

    // Default values.
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('field_publication_collection')->defaultValue(1);

    // Unmapped fields.
    $this->addUnmigratedDestinations(
      [
        'body',
        'body:format',
        'body:language',
        'body:summary',
        'changed',
        'comment',
        'created',
        'field_core_contact',
        'field_core_contact:er_override_title_field',
        'field_core_date_published:rrule',
        'field_core_date_published:timezone',
        'field_core_date_published:to',
        'field_core_date_updated:rrule',
        'field_core_date_updated:timezone',
        'field_core_date_updated:to',
        'field_core_description',
        'field_core_description:language',
        'field_core_files',
        'field_core_legacy_link:attributes',
        'field_core_legacy_link:language',
        'field_core_legacy_link:title',
        'field_core_publications',
        'group_content_access',
        'is_new',
        'language',
        'log',
        'metatag_abstract',
        'metatag_article:author',
        'metatag_article:expiration_time',
        'metatag_article:modified_time',
        'metatag_article:published_time',
        'metatag_article:publisher',
        'metatag_article:section',
        'metatag_article:tag',
        'metatag_author',
        'metatag_book:author',
        'metatag_book:isbn',
        'metatag_book:release_date',
        'metatag_book:tag',
        'metatag_canonical',
        'metatag_classification',
        'metatag_content-language',
        'metatag_creator',
        'metatag_date',
        'metatag_dcterms.contributor',
        'metatag_dcterms.coverage',
        'metatag_dcterms.creator',
        'metatag_dcterms.date',
        'metatag_dcterms.description',
        'metatag_dcterms.format',
        'metatag_dcterms.identifier',
        'metatag_dcterms.language',
        'metatag_dcterms.publisher',
        'metatag_dcterms.relation',
        'metatag_dcterms.rights',
        'metatag_dcterms.source',
        'metatag_dcterms.subject',
        'metatag_dcterms.title',
        'metatag_dcterms.type',
        'metatag_description',
        'metatag_ESS_GF',
        'metatag_ESS_RF',
        'metatag_fb:admins',
        'metatag_fb:app_id',
        'metatag_generator',
        'metatag_geo.placename',
        'metatag_geo.position',
        'metatag_geo.region',
        'metatag_icbm',
        'metatag_image_src',
        'metatag_keywords',
        'metatag_last-modified',
        'metatag_news_keywords',
        'metatag_next',
        'metatag_og:audio',
        'metatag_og:audio:secure_url',
        'metatag_og:audio:type',
        'metatag_og:country_name',
        'metatag_og:description',
        'metatag_og:determiner',
        'metatag_og:email',
        'metatag_og:fax_number',
        'metatag_og:image',
        'metatag_og:image:height',
        'metatag_og:image:secure_url',
        'metatag_og:image:type',
        'metatag_og:image:url',
        'metatag_og:image:width',
        'metatag_og:latitude',
        'metatag_og:locale',
        'metatag_og:locale:alternate',
        'metatag_og:locality',
        'metatag_og:longitude',
        'metatag_og:phone_number',
        'metatag_og:postal_code',
        'metatag_og:region',
        'metatag_og:see_also',
        'metatag_og:site_name',
        'metatag_og:street_address',
        'metatag_og:title',
        'metatag_og:type',
        'metatag_og:updated_time',
        'metatag_og:url',
        'metatag_og:video',
        'metatag_og:video:height',
        'metatag_og:video:secure_url',
        'metatag_og:video:type',
        'metatag_og:video:width',
        'metatag_original-source',
        'metatag_prev',
        'metatag_profile:first_name',
        'metatag_profile:gender',
        'metatag_profile:last_name',
        'metatag_profile:username',
        'metatag_publisher',
        'metatag_rating',
        'metatag_reference',
        'metatag_referrer',
        'metatag_refresh',
        'metatag_revisit-after',
        'metatag_rights',
        'metatag_robots',
        'metatag_shortlink',
        'metatag_standout',
        'metatag_title',
        'metatag_video:actor',
        'metatag_video:actor:role',
        'metatag_video:director',
        'metatag_video:duration',
        'metatag_video:release_date',
        'metatag_video:series',
        'metatag_video:tag',
        'metatag_video:writer',
        'metatag_viewport',
        'metatag_X-UA-Compatible',
        'og_group_ref',
        'path',
        'pathauto',
        'revision_uid',
        'title_field',
        'title_field:language',
        'tnid',
        'translate',
        'uid',
        'workbench_moderation_state_new',
      ]
    );

  }

  /**
   * Prepare the node before migration.
   *
   * @param object $node
   *   - Node.
   * @param array $row
   *   - Rows.
   */
  public function prepare(&$node, $row) {
    $default_language = $this->getPrimaryLanguage('collection', $row->cid);
    $node->translations = (object) [
      'original' => $default_language,
      'data' => [],
    ];
    $node->language = $default_language;
  }

  /**
   * Prepare the row to check for english title first than others.
   *
   * @param object $row
   *    The raw data from the import.
   *
   * @return bool
   *    Return false to skip the row
   */
  public function prepareRow($row) {
    return $row->title = $this->getTitleById('collection', $row->cid);
  }

  /**
   * When a row import completed.
   *
   * @param object|\stdClass $node
   *   The node, which already in the database.
   * @param \stdClass $row
   *   Imported row from migration.
   */
  public function complete(stdClass $node, stdClass $row) {
    // Publication languages.
    $publication_languages = $this->getLanguages('collection', $row->cid);
    $default_language = $this->getPrimaryLanguage('collection', $row->cid);

    // Adding language specific settings to file node.
    $entity_translation_handler = entity_translation_get_handler('node', $node);
    $entity_translation_handler->setOriginalLanguage($default_language);

    // Go through all languages.
    foreach ($publication_languages as $language) {
      // Get the xml node related pid and language.
      $xml = $this->getTranslationElementByIdAndLanguage('collection', $row->cid, $language);
      if (isset($xml->title)) {
        // Title.
        $node->title_field[$language][0]['value'] = (string) $xml->title;
        $node->field_core_description[$language][0]['value'] = isset($xml->description) ? (string) $xml->description : NULL;
        $node->body[$language][0]['value'] = isset($xml->summary_of_abstract) ? (string) $xml->summary_of_abstract : NULL;

        // Set the translation.
        if ($language != $default_language) {
          // Language.
          $translation = [
            'entity_type' => 'node',
            'entity_id' => $node->nid,
            'language' => $language,
            'source' => $default_language,
            'uid' => '1',
            'status' => '1',
            'translate' => '0',
            'created' => REQUEST_TIME,
            'changed' => REQUEST_TIME,
          ];
          $entity_translation_handler->setTranslation($translation);
        }
      }
    }

    // Saving collection.
    node_save($node);
  }

}

/**
 * Publication import.
 */
class DtFileImportPublicationImport extends DtFileImportGeneralMigration {

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "Publication" contents.');

    // Used fields.
    $fields = [
      'pid' => t('Publication ID'),
      'cid' => t('Collection IDs'),
      'publication_type' => t('Publication type'),
      'date_published' => t('First published on'),
      'date_updated' => t('Last updated on'),
      'published_by' => t('Published by'),
      'publication_origin' => t('Origin'),
      'core_nal_countries' => t('NAL Countries'),
      'core_tags' => t('Tags'),
      'publication_referenceno' => t('Identifier of the publication'),
      'core_topics' => t('Related topics'),
      'publication_rel_content' => t('Related content'),
      'core_departments' => t('Related departments'),
      'core_policies' => t('Related policies'),
      'eurovoc_taxonomy' => t('Eurovoc taxonomies'),
      'core_legacy_link' => t('Link to publication'),
    ];

    // Xpath of items.
    $item_xpath = '/import/publications/publication';
    // Unique identifier for import.
    $item_ID_xpath = 'pid';
    // Set up source.
    $this->source = new MigrateSourceXML($this->xmlFilePath, $item_xpath, $item_ID_xpath, $fields);

    // Set up of destination.
    $this->destination = new MigrateDestinationNode('publication');

    // Mapping of the unique ID.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      [
        'pid' => [
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );

    // Mapped fields.
    $this->addFieldMapping('title', 'title');

    // Publication type.
    $this->addFieldMapping('field_publication_type', 'publication_type')
      ->xpath('publication_type');
    $this->addFieldMapping('field_publication_type:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_publication_type:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_publication_type:ignore_case')
      ->defaultValue(TRUE);

    // Dates.
    $this->addFieldMapping('field_core_date_published', 'date_published')
      ->xpath('date_published');
    $this->addFieldMapping('field_core_date_updated', 'date_updated')
      ->xpath('date_updated');

    // Publication author.
    $this->addFieldMapping('field_publication_authors', 'published_by')
      ->separator(',')
      ->xpath('published_by');

    // Publication origin.
    $this->addFieldMapping('field_publication_origin', 'publication_origin')
      ->xpath('publication_origin');
    $this->addFieldMapping('field_publication_origin:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_publication_origin:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_publication_origin:ignore_case')
      ->defaultValue(TRUE);

    // NAL Countries.
    $this->addFieldMapping('field_core_nal_countries', 'core_nal_countries')
      ->separator(',')
      ->xpath('core_nal_countries');
    $this->addFieldMapping('field_core_nal_countries:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_core_nal_countries:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_core_nal_countries:ignore_case')
      ->defaultValue(TRUE);

    // Tags.
    $this->addFieldMapping('field_core_tags', 'core_tags')
      ->separator(',')
      ->xpath('core_tags');
    $this->addFieldMapping('field_core_tags:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_core_tags:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_core_tags:ignore_case')
      ->defaultValue(TRUE);

    // Publication reference number.
    $this->addFieldMapping('field_publication_referenceno', 'publication_referenceno')
      ->separator(',')
      ->xpath('publication_referenceno');

    // Reference fields.
    $this->addFieldMapping('field_core_topics', 'core_topics')
      ->separator(',')
      ->xpath('core_topics');
    $this->addFieldMapping('field_publication_rel_content', 'publication_rel_content')
      ->separator(',')
      ->xpath('publication_rel_content');
    $this->addFieldMapping('field_core_departments', 'core_departments')
      ->separator(',')
      ->xpath('core_departments');
    $this->addFieldMapping('field_core_policies', 'core_policies')
      ->separator(',')
      ->xpath('core_policies');
    $this->addFieldMapping('field_eurovoc_taxonomy', 'eurovoc_taxonomy')
      ->separator(',')
      ->xpath('eurovoc_taxonomy');
    // Legacy link.
    $this->addFieldMapping('field_core_legacy_link', 'core_legacy_link')
      ->xpath('core_legacy_link');

    // Collection import.
    // The `cid` is not a valid field at publication content type,
    // but somehow we should find the related collection
    // (I mean publication with collection) node.
    $this->addFieldMapping('cids', 'cid')
      ->separator(',')
      ->xpath('cid')
      ->sourceMigration('DTCollection');

    // Default values.
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('field_publication_collection')->defaultValue(0);

    // Unmapped fields.
    $this->addUnmigratedDestinations(
      [
        'body',
        'body:format',
        'body:language',
        'body:summary',
        'changed',
        'comment',
        'created',
        'field_core_contact',
        'field_core_contact:er_override_title_field',
        'field_core_date_published:rrule',
        'field_core_date_published:timezone',
        'field_core_date_published:to',
        'field_core_date_updated:rrule',
        'field_core_date_updated:timezone',
        'field_core_date_updated:to',
        'field_core_description',
        'field_core_description:language',
        'field_core_files',
        'field_core_legacy_link:attributes',
        'field_core_legacy_link:language',
        'field_core_legacy_link:title',
        'field_core_publications',
        'group_content_access',
        'is_new',
        'language',
        'log',
        'metatag_abstract',
        'metatag_article:author',
        'metatag_article:expiration_time',
        'metatag_article:modified_time',
        'metatag_article:published_time',
        'metatag_article:publisher',
        'metatag_article:section',
        'metatag_article:tag',
        'metatag_author',
        'metatag_book:author',
        'metatag_book:isbn',
        'metatag_book:release_date',
        'metatag_book:tag',
        'metatag_canonical',
        'metatag_classification',
        'metatag_content-language',
        'metatag_creator',
        'metatag_date',
        'metatag_dcterms.contributor',
        'metatag_dcterms.coverage',
        'metatag_dcterms.creator',
        'metatag_dcterms.date',
        'metatag_dcterms.description',
        'metatag_dcterms.format',
        'metatag_dcterms.identifier',
        'metatag_dcterms.language',
        'metatag_dcterms.publisher',
        'metatag_dcterms.relation',
        'metatag_dcterms.rights',
        'metatag_dcterms.source',
        'metatag_dcterms.subject',
        'metatag_dcterms.title',
        'metatag_dcterms.type',
        'metatag_description',
        'metatag_ESS_GF',
        'metatag_ESS_RF',
        'metatag_fb:admins',
        'metatag_fb:app_id',
        'metatag_generator',
        'metatag_geo.placename',
        'metatag_geo.position',
        'metatag_geo.region',
        'metatag_icbm',
        'metatag_image_src',
        'metatag_keywords',
        'metatag_last-modified',
        'metatag_news_keywords',
        'metatag_next',
        'metatag_og:audio',
        'metatag_og:audio:secure_url',
        'metatag_og:audio:type',
        'metatag_og:country_name',
        'metatag_og:description',
        'metatag_og:determiner',
        'metatag_og:email',
        'metatag_og:fax_number',
        'metatag_og:image',
        'metatag_og:image:height',
        'metatag_og:image:secure_url',
        'metatag_og:image:type',
        'metatag_og:image:url',
        'metatag_og:image:width',
        'metatag_og:latitude',
        'metatag_og:locale',
        'metatag_og:locale:alternate',
        'metatag_og:locality',
        'metatag_og:longitude',
        'metatag_og:phone_number',
        'metatag_og:postal_code',
        'metatag_og:region',
        'metatag_og:see_also',
        'metatag_og:site_name',
        'metatag_og:street_address',
        'metatag_og:title',
        'metatag_og:type',
        'metatag_og:updated_time',
        'metatag_og:url',
        'metatag_og:video',
        'metatag_og:video:height',
        'metatag_og:video:secure_url',
        'metatag_og:video:type',
        'metatag_og:video:width',
        'metatag_original-source',
        'metatag_prev',
        'metatag_profile:first_name',
        'metatag_profile:gender',
        'metatag_profile:last_name',
        'metatag_profile:username',
        'metatag_publisher',
        'metatag_rating',
        'metatag_reference',
        'metatag_referrer',
        'metatag_refresh',
        'metatag_revisit-after',
        'metatag_rights',
        'metatag_robots',
        'metatag_shortlink',
        'metatag_standout',
        'metatag_title',
        'metatag_video:actor',
        'metatag_video:actor:role',
        'metatag_video:director',
        'metatag_video:duration',
        'metatag_video:release_date',
        'metatag_video:series',
        'metatag_video:tag',
        'metatag_video:writer',
        'metatag_viewport',
        'metatag_X-UA-Compatible',
        'og_group_ref',
        'path',
        'pathauto',
        'revision_uid',
        'title_field',
        'title_field:language',
        'tnid',
        'translate',
        'uid',
        'workbench_moderation_state_new',
      ]
    );

  }

  /**
   * Prepare the node before migration.
   *
   * @param object $node
   *   - Node.
   * @param array $row
   *   - Rows.
   */
  public function prepare(&$node, $row) {
    $default_language = $this->getPrimaryLanguage('collection', $row->pid);
    $node->translations = (object) [
      'original' => $default_language,
      'data' => [],
    ];
    $node->language = $default_language;
  }

  /**
   * Prepare the row to check for english title otherwise skip.
   *
   * @param object $row
   *    The raw data from the import.
   *
   * @return bool
   *    Return false to skip the row
   */
  public function prepareRow($row) {
    return $row->title = $this->getTitleById('publication', $row->pid);
  }

  /**
   * When a row import completed.
   *
   * @param object|\stdClass $node
   *   The node, which already in the database.
   * @param \stdClass $row
   *   Imported row from migration.
   */
  public function complete(stdClass $node, stdClass $row) {
    // Publication languages.
    $publication_languages = $this->getLanguages('publication', $row->pid);
    $default_language = $this->getPrimaryLanguage('publication', $row->pid);

    // Adding language specific settings to file node.
    $entity_translation_handler = entity_translation_get_handler('node', $node);
    $entity_translation_handler->setOriginalLanguage($default_language);

    // Go through all languages.
    foreach ($publication_languages as $language) {
      // Get the xml node related pid and language.
      $xml = $this->getTranslationElementByIdAndLanguage('publication', $row->pid, $language);
      if (isset($xml->title)) {
        // Title.
        $node->title_field[$language][0]['value'] = (string) $xml->title;
        $node->field_core_description[$language][0]['value'] = isset($xml->description) ? (string) $xml->description : NULL;
        $node->body[$language][0]['value'] = isset($xml->summary_of_abstract) ? (string) $xml->summary_of_abstract : NULL;

        // Set up translation.
        if ($language != $default_language) {
          // Language.
          $translation = [
            'entity_type' => 'node',
            'entity_id' => $node->nid,
            'language' => $language,
            'source' => $default_language,
            'uid' => '1',
            'status' => '1',
            'translate' => '0',
            'created' => REQUEST_TIME,
            'changed' => REQUEST_TIME,
          ];
          $entity_translation_handler->setTranslation($translation);
        }
      }
    }

    // Saving publication.
    node_save($node);

    // Collection update.
    if (isset($node->cids)) {
      // Using multiple, comma-separated pids.
      foreach ($node->cids as $cid) {
        if ($collection = node_load($cid)) {
          $collection->field_core_publications[LANGUAGE_NONE][]['target_id'] = $node->nid;
          node_save($collection);
        }
        // Drop an error message if there is no related publication.
        else {
          $this->queueMessage(t('The given cid was incorrect at publication (pid: @pid, cid: @cid).', ['@pid' => $row->pid, '@cid' => $cid]));
        }
      }
    }

  }

  /**
   * Removing related publications at rollback.
   *
   * @param array $node_ids
   *   Node IDs which will be removed.
   */
  public function prepareRollback($node_ids) {
    // Removing all file reference from Publication, which will be deleted.
    // Querying Publications, which has file reference by the given ids.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'publication')
      ->fieldCondition('field_core_publications', 'target_id', $node_ids, 'IN');
    $result = $query->execute();
    // Loading affected Collections.
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);
    foreach ($nodes as $node) {
      // Removing only the affected publication references.
      $wrapper = entity_metadata_wrapper('node', $node);
      $publications = $wrapper->field_core_publications->value();
      foreach ($publications as $key => $item) {
        // Should delete the publication reference,
        // when the reference is NULL
        // or Publication ID is in the set of files to be deleted.
        if (!isset($item->nid) || array_search($item->nid, $node_ids) !== FALSE) {
          unset($wrapper->field_core_publications[$key]);
        }
      }
      $wrapper->save();
    }
  }

}

/**
 * File import.
 */
class DtFileImportFileImport extends DtFileImportGeneralMigration {

  /**
   * Stores files order.
   *
   * @var array
   */
  protected $fileWeight;

  /**
   * Constructor of migrations.
   *
   * @param array $arguments
   *   Migration parameters.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import "File" contents.');

    // Used fields.
    $fields = [
      'weight' => t('Weight'),
      'pid' => t('Publication ID'),
      'type_of_file' => t('Type of file'),
      'date_of_publication' => t('Date of publication'),
      'file_location' => t('What do you want to do?'),
      'file_link_upload' => t('Where do you link to?'),
      'file_unique_identifier' => t('Unique identifier of the file'),
    ];

    // Xpath of items.
    $item_xpath = '/import/files/file';
    // Unique identifier for import.
    $item_ID_xpath = 'fid';
    // Set up source.
    $this->source = new MigrateSourceXML($this->xmlFilePath, $item_xpath, $item_ID_xpath, $fields);

    // Set up of destination.
    $this->destination = new MigrateDestinationNode('file');

    // Mapping of the unique ID.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      [
        'fid' => [
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('weight', 'weight')
      ->xpath('@weight');

    // Type of file.
    $this->addFieldMapping('field_file_type_file', 'type_of_file')
      ->xpath('type_of_file');
    $this->addFieldMapping('field_file_type_file:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_file_type_file:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_file_type_file:ignore_case')
      ->defaultValue(TRUE);

    // Date of publication.
    $this->addFieldMapping('field_core_date_published', 'date_of_publication')
      ->xpath('date_of_publication');

    // What do you want to do? E.g.: Link to file, Upload the file.
    $this->addFieldMapping('field_file_link_upload', 'file_link_upload')
      ->defaultValue('Upload the file')
      ->xpath('file_link_upload')
      ->callback([$this, 'fileLinkUploadMap']);

    // Where do you link to? E.g.: No Source, EUR-lex, EC Annual reports.
    $this->addFieldMapping('field_file_location', 'file_location')
      ->xpath('file_location');
    $this->addFieldMapping('field_file_location:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_file_location:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_file_location:ignore_case')
      ->defaultValue(TRUE);

    // Publication reference number.
    $this->addFieldMapping('field_file_unique_identifier', 'file_unique_identifier')
      ->separator(',')
      ->xpath('file_unique_identifier');

    // Publication import.
    // The `pid` is not a valid field at file content type,
    // but somehow we should find the related publication node.
    $this->addFieldMapping('pids', 'pid')
      ->separator(',')
      ->xpath('pid')
      ->sourceMigration('DTPublication');

    // Language.
    $this->addFieldMapping('language', 'language');

    // Default values.
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);

    // Unmapped fields.
    $this->addUnmigratedDestinations(
      [
        'changed',
        'comment',
        'created',
        'field_core_date_published:rrule',
        'field_core_date_published:timezone',
        'field_core_date_published:to',
        'field_core_file',
        'field_core_file:description',
        'field_core_file:destination_dir',
        'field_core_file:destination_file',
        'field_core_file:display',
        'field_core_file:file_class',
        'field_core_file:file_replace',
        'field_core_file:language',
        'field_core_file:preserve_files',
        'field_core_file:source_dir',
        'field_core_file:urlencode',
        'field_core_legacy_link',
        'field_core_legacy_link:attributes',
        'field_core_legacy_link:language',
        'field_core_legacy_link:title',
        'field_file_exclude_from_search',
        'group_content_access',
        'is_new',
        'log',
        'metatag_abstract',
        'metatag_article:author',
        'metatag_article:expiration_time',
        'metatag_article:modified_time',
        'metatag_article:published_time',
        'metatag_article:publisher',
        'metatag_article:section',
        'metatag_article:tag',
        'metatag_author',
        'metatag_book:author',
        'metatag_book:isbn',
        'metatag_book:release_date',
        'metatag_book:tag',
        'metatag_canonical',
        'metatag_classification',
        'metatag_content-language',
        'metatag_creator',
        'metatag_date',
        'metatag_dcterms.contributor',
        'metatag_dcterms.coverage',
        'metatag_dcterms.creator',
        'metatag_dcterms.date',
        'metatag_dcterms.description',
        'metatag_dcterms.format',
        'metatag_dcterms.identifier',
        'metatag_dcterms.language',
        'metatag_dcterms.publisher',
        'metatag_dcterms.relation',
        'metatag_dcterms.rights',
        'metatag_dcterms.source',
        'metatag_dcterms.subject',
        'metatag_dcterms.title',
        'metatag_dcterms.type',
        'metatag_description',
        'metatag_ESS_GF',
        'metatag_ESS_RF',
        'metatag_fb:admins',
        'metatag_fb:app_id',
        'metatag_generator',
        'metatag_geo.placename',
        'metatag_geo.position',
        'metatag_geo.region',
        'metatag_icbm',
        'metatag_image_src',
        'metatag_keywords',
        'metatag_last-modified',
        'metatag_news_keywords',
        'metatag_next',
        'metatag_og:audio',
        'metatag_og:audio:secure_url',
        'metatag_og:audio:type',
        'metatag_og:country_name',
        'metatag_og:description',
        'metatag_og:determiner',
        'metatag_og:email',
        'metatag_og:fax_number',
        'metatag_og:image',
        'metatag_og:image:height',
        'metatag_og:image:secure_url',
        'metatag_og:image:type',
        'metatag_og:image:url',
        'metatag_og:image:width',
        'metatag_og:latitude',
        'metatag_og:locale',
        'metatag_og:locale:alternate',
        'metatag_og:locality',
        'metatag_og:longitude',
        'metatag_og:phone_number',
        'metatag_og:postal_code',
        'metatag_og:region',
        'metatag_og:see_also',
        'metatag_og:site_name',
        'metatag_og:street_address',
        'metatag_og:title',
        'metatag_og:type',
        'metatag_og:updated_time',
        'metatag_og:url',
        'metatag_og:video',
        'metatag_og:video:height',
        'metatag_og:video:secure_url',
        'metatag_og:video:type',
        'metatag_og:video:width',
        'metatag_original-source',
        'metatag_prev',
        'metatag_profile:first_name',
        'metatag_profile:gender',
        'metatag_profile:last_name',
        'metatag_profile:username',
        'metatag_publisher',
        'metatag_rating',
        'metatag_reference',
        'metatag_referrer',
        'metatag_refresh',
        'metatag_revisit-after',
        'metatag_rights',
        'metatag_robots',
        'metatag_shortlink',
        'metatag_standout',
        'metatag_title',
        'metatag_video:actor',
        'metatag_video:actor:role',
        'metatag_video:director',
        'metatag_video:duration',
        'metatag_video:release_date',
        'metatag_video:series',
        'metatag_video:tag',
        'metatag_video:writer',
        'metatag_viewport',
        'metatag_X-UA-Compatible',
        'og_group_ref',
        'path',
        'pathauto',
        'revision_uid',
        'title_field',
        'title_field:language',
        'tnid',
        'translate',
        'uid',
        'workbench_moderation_state_new',
      ]
    );
  }

  /**
   * Callback function for field_file_location.
   *
   * @param string $value
   *   Source value from XML.
   *
   * @return mixed
   *   - FALSE: If there is no mapped value.
   *   - string: mapped value.
   */
  protected function fileLinkUploadMap($value) {
    return array_search($value, [
      'link' => 'Link to file',
      'upload' => 'Upload the file',
    ]);
  }

  /**
   * Set the field_core_files in a publication, related to file weight.
   *
   * @param object $publication
   *   Field_core_files field in a publication content.
   */
  protected function sortFilesInPublication(&$publication) {
    // Takes the nids and sort by their weights.
    $nids = array_column($publication->field_core_files[LANGUAGE_NONE], 'target_id');
    usort($nids, function ($a, $b) {
      return $this->fileWeight[$a] > $this->fileWeight[$b];
    });

    // Empty 'field_core_files' and added sorted NodeIDs.
    $publication->field_core_files[LANGUAGE_NONE] = [];
    foreach ($nids as $nid) {
      $publication->field_core_files[LANGUAGE_NONE][]['target_id'] = $nid;
    }
  }

  /**
   * Prepare the node before migration.
   *
   * @param object $node
   *   - Node.
   * @param array $row
   *   - Rows.
   */
  public function prepare(&$node, $row) {
    $default_language = $this->getPrimaryLanguage('file', $row->fid);
    $node->translations = (object) [
      'original' => $default_language,
      'data' => [],
    ];
    $node->language = $default_language;
  }

  /**
   * Prepare the row to check for english title otherwise skip.
   *
   * @param object $row
   *    The raw data from the import.
   *
   * @return bool
   *    Return false to skip the row.
   */
  public function prepareRow($row) {
    return $row->title = $this->getTitleById('file', $row->fid);
  }

  /**
   * When a row import completed.
   *
   * @param object|\stdClass $node
   *   The node, which already in the database.
   * @param \stdClass $row
   *   Imported row from migration.
   */
  public function complete(stdClass $node, stdClass $row) {
    // Languages.
    $file_languages = $this->getLanguages('file', $row->fid);
    $default_language = $this->getPrimaryLanguage('file', $row->fid);

    // Adding language specific settings to file node.
    $entity_translation_handler = entity_translation_get_handler('node', $node);
    $entity_translation_handler->setOriginalLanguage($default_language);

    // Store NodeID with the related weight.
    $this->fileWeight[$node->nid] = isset($row->weight) ? (int) $row->weight : 50;

    // Iterate on all languages, which are related to the import.
    foreach ($file_languages as $language) {
      // Get the xml node related fid and language.
      $xml = $this->getTranslationElementByIdAndLanguage('file', $row->fid, $language);

      if (isset($xml->title)) {
        // Title.
        $node->title_field[$language][0]['value'] = (string) $xml->title;

        // File processing, like: download or link to an external resource.
        switch ($row->file_link_upload) {
          // Download and store a file.
          case 'Upload the file':
            $file = $this->getFile($xml);
            // Skip the full process if there is no file provided.
            if (empty($file)) {
              break 2;
            }
            $node->field_core_file[$language][] = (array) $this->getFile($xml);
            break;

          // External link, using legacy link.
          case 'Link to file':
            $url = isset($xml->source_file_url) ? (string) $xml->source_file_url : NULL;
            $node->field_core_legacy_link[$language][] = [
              'url' => $url,
              'attribute' => [],
            ];
            break;
        }

        // Set translation.
        if ($language != $default_language) {
          // Language.
          $translation = [
            'entity_type' => 'node',
            'entity_id' => $node->nid,
            'language' => $language,
            'source' => $default_language,
            'uid' => '1',
            'status' => '1',
            'translate' => '0',
            'created' => REQUEST_TIME,
            'changed' => REQUEST_TIME,
          ];
          $entity_translation_handler->setTranslation($translation);
        }
      }
    }

    // Delete the node if there is no file imported and no link given.
    // We need to do this here because translation need a nid, and we don't
    // have nid in prepare process to provide for the node object.
    if (!isset($node->field_core_file) && !isset($node->field_core_legacy_link)) {
      node_delete($node->nid);
    }
    else {
      // Store file node.
      node_save($node);

      // Publication update.
      if (isset($node->pids)) {
        // Check $node->pids is an array.
        if (is_array($node->pids)) {
          $pids = $node->pids;
        }
        else {
          $pids = [$node->pids];
        }
        foreach ($pids as $pid) {
          if ($publication = node_load((integer) $pid)) {
            // Add item to field_core_files.
            $publication->field_core_files[LANGUAGE_NONE][]['target_id'] = $node->nid;
            $this->sortFilesInPublication($publication);
            node_save($publication);
          }
          // Drop an error message if there is no related publication.
          else {
            $this->queueMessage(t('The given pid was incorrect at file (fid: @fid, pid: @pid).', ['@fid' => $row->fid, '@pid' => $pid]));
          }
        }
      }
    }
  }

  /**
   * Get the file object.
   *
   * @param object $xml
   *   XML object of file translation.
   *
   * @return mixed
   *   - NULL if no file object.
   *   - Otherwise file object.
   */
  private function getFile($xml) {
    $uri = !empty($xml->source_file_url) ? (string) $xml->source_file_url[0] : NULL;
    // Giving a value for the filename.
    $filename = isset($xml->target_filename) ? (string) $xml->target_filename : file_munge_filename(preg_replace('@^.*/@', '', $uri), '', TRUE);

    if (!empty($buffer = $this->getFileContentByCurl($uri, $xml->fid))) {
      if ($file_object = file_save_data($buffer, $this->folder . $filename, FILE_EXISTS_RENAME)) {
        $file_object->display = '1';
        return $file_object;
      }
    }

    return NULL;
  }

  /**
   * Get the file content, using CURL.
   *
   * @param string $url
   *   Remote file for download.
   * @param string $fid
   *   The file ID from the source.
   *
   * @return string
   *   Content.
   *
   * @see: http://stackoverflow.com/questions/697472/php-file-get-contents-returns-failed-to-open-stream-http-request-failed#answer-697540
   */
  private function getFileContentByCurl($url, $fid) {
    $curl_handle = curl_init();
    curl_setopt($curl_handle, CURLOPT_URL, $url);
    curl_setopt($curl_handle, CURLOPT_CONNECTTIMEOUT, 2);
    curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl_handle, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows; U; Windows NT 5.1; rv:1.7.3) Gecko/20041001 Firefox/0.10.1");
    $query = curl_exec($curl_handle);
    $curl_info = curl_getinfo($curl_handle);
    if ($curl_info['http_code'] != 200) {
      $this->queueMessage(
        t(
          'The target url of the file is not accessible. Url: !url, FID: @id.',
          ['!url' => l($url, $url), '@id' => $fid]
        )
      );
    }
    curl_close($curl_handle);

    return $query;
  }

  /**
   * Removing imported managed files at rollback.
   *
   * @param array $node_ids
   *   Node IDs which will be removed.
   */
  public function prepareRollback($node_ids) {
    // Removing all file reference from Publication, which will be deleted.
    // Querying Publications, which has file reference by the given ids.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'publication')
      ->fieldCondition('field_core_files', 'target_id', $node_ids, 'IN');
    $result = $query->execute();
    // Loading affected Publications.
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);
    foreach ($nodes as $node) {
      // Removing only the affected file references.
      $wrapper = entity_metadata_wrapper('node', $node);
      $files = $wrapper->field_core_files->value();
      foreach ($files as $key => $item) {
        // Should delete the file reference,
        // when the reference is NULL
        // or File ID is in the set of files to be deleted.
        if (!isset($item->nid) || array_search($item->nid, $node_ids) !== FALSE) {
          unset($wrapper->field_core_files[$key]);
        }
      }
      $wrapper->save();
    }

    // Removing managed files.
    $nodes = node_load_multiple($node_ids);
    $fids = [];
    foreach ($nodes as $node) {
      foreach ($node->field_core_file as $item) {
        $fids[] = (!empty($item[0]['fid'])) ? $item[0]['fid'] : NULL;
      }
    }
    // Delete files from the folder and file_managed database table.
    if (!empty($fids)) {
      file_delete_multiple($fids);
    }
  }

}
