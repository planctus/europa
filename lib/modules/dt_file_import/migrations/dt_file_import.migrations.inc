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

  /**
   * DTMigration constructor.
   *
   * @param array $arguments
   *   General migration arguments.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->team = [];
    $this->xmlFilePath = isset($arguments['dt_file_import_file_path']) ? $arguments['dt_file_import_file_path'] : variable_get('dt_file_import_file_path', FALSE);
    $this->xml = $this->xmlFilePath ? simplexml_load_file($this->xmlFilePath) : simplexml_load_string('');
  }

  /**
   * Gets the languages related to a Publication.
   *
   * @param int $pid
   *   Publication ID.
   *
   * @return mixed
   *   - FALSE: when no result.
   *   - array of language ids.
   */
  public function getPublicationLanguages($pid = NULL) {
    $languages = [];
    $xpath = '/import/publication_translations/publication_translation[pid=' . check_plain($pid) . ']/language';
    $xml_lang = $this->xml->xpath($xpath);
    foreach ($xml_lang as $element) {
      $languages[] = (string) $element[0];
    }
    return count($languages) ? $languages : FALSE;
  }

  /**
   * Gives back a translation set, related to a publication.
   *
   * @param int $pid
   *   Publication ID.
   * @param string $language
   *   Language code, like: 'en', 'fr', etc.
   *
   * @return mixed
   *   - FALSE: When no result.
   *   - Object of xml elements.
   */
  public function getPublicationTranslationElementByPidAndLanguage($pid = NULL, $language = 'en') {
    $xpath = '/import/publication_translations/publication_translation[pid=' . check_plain($pid) . ' and language="' . check_plain($language) . '"]';
    $publication_traslation = $this->xml->xpath($xpath);
    return count($publication_traslation) ? $publication_traslation[0] : FALSE;
  }

  /**
   * Gets the languages related to a File.
   *
   * @param int $fid
   *   File ID.
   *
   * @return mixed
   *   - FALSE: when no result.
   *   - array of language ids.
   */
  public function getFileLanguages($fid = NULL) {
    $languages = [];
    $xpath = '/import/file_translations/file_translation[fid=' . check_plain($fid) . ']/language';
    $xml_lang = $this->xml->xpath($xpath);
    foreach ($xml_lang as $element) {
      $languages[] = (string) $element[0];
    }
    return count($languages) ? $languages : FALSE;
  }

  /**
   * Gives back a translation set, related to a file.
   *
   * @param int $fid
   *   File ID.
   * @param string $language
   *   Language code, like: 'en', 'fr', etc.
   *
   * @return mixed
   *   - FALSE: When no result.
   *   - Object of xml elements.
   */
  public function getFileTranslationElementByFidAndLanguage($fid = NULL, $language = 'en') {
    $xpath = '/import/file_translations/file_translation[fid=' . check_plain($fid) . ' and language="' . check_plain($language) . '"]';
    $file_traslation = $this->xml->xpath($xpath);
    return count($file_traslation) ? $file_traslation[0] : FALSE;
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
    $this->addFieldMapping('title')
      ->defaultValue(t('Publication title is missing'));

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
      ->xpath('publication_origin');
    $this->addFieldMapping('field_core_nal_countries:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_core_nal_countries:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_core_nal_countries:ignore_case')
      ->defaultValue(TRUE);

    // Tags.
    $this->addFieldMapping('field_core_tags', 'core_tags')
      ->xpath('publication_origin');
    $this->addFieldMapping('field_core_tags:source_type')
      ->defaultValue('name');
    $this->addFieldMapping('field_core_tags:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_core_tags:ignore_case')
      ->defaultValue(TRUE);

    // Publication reference number.
    $this->addFieldMapping('field_publication_referenceno', 'publication_referenceno')
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

    // Default values.
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('field_publication_collection')->defaultValue(0);
    $this->addFieldMapping('language')->defaultValue('en');
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
        'field_core_legacy_link',
        'field_core_legacy_link:attributes',
        'field_core_legacy_link:language',
        'field_core_legacy_link:title',
        'field_core_publications',
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
   * When a row import completed.
   *
   * @param object $entity
   *   The entity, which already in the database.
   * @param \stdClass $row
   *   Imported row from migration.
   */
  public function complete($entity, stdClass $row) {
    // Publication languages.
    $publication_languages = $this->getPublicationLanguages($row->pid);

    // English title, if empty then indicate it in the title text.
    $xml = $this->getPublicationTranslationElementByPidAndLanguage($row->pid, 'en');
    $entity->title = isset($xml->title) ? (string) $xml->title : t('Publication title is missing, nid: @title', ['@title' => $entity->nid]);

    // Publication collection default setting: 0 - One publication.
    $entity->field_publication_collection[LANGUAGE_NONE][0]['value'] = 0;

    // Translation setting at the content.
    $data = [];

    // Go through all languages.
    foreach ($publication_languages as $language) {
      // Get the xml node related pid and language.
      $xml = $this->getPublicationTranslationElementByPidAndLanguage($row->pid, $language);
      // Title.
      $entity->title_field[$language][0]['value'] = isset($xml->title) ? (string) $xml->title : NULL;
      $entity->field_core_description[$language][0]['value'] = isset($xml->description) ? (string) $xml->description : NULL;
      $entity->body[$language][0]['value'] = isset($xml->summary_of_abstract) ? (string) $xml->summary_of_abstract : NULL;

      $data[$language] = [
        'entity_type' => 'node',
        'entity_id' => $entity->nid,
        'language' => $language,
        'source' => ($language == 'en') ? '' : 'en',
        'uid' => '1',
        'status' => '1',
        'translate' => '0',
        'created' => REQUEST_TIME,
        'changed' => REQUEST_TIME,
      ];
    }

    // Adding language specific settings to file node.
    $entity->translations = (object) [
      'original' => 'en',
      'data' => $data,
    ];

    node_save($entity);
  }

}

/**
 * File import.
 */
class DtFileImportFileImport extends DtFileImportGeneralMigration {

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
          'length' => 6,
          'not null' => TRUE,
        ],
      ],
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('title')
      ->defaultValue(t('File title is missing'));

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
      ->xpath('file_unique_identifier');

    // Publication import.
    $this->addFieldMapping('pid', 'pid')
      ->xpath('pid')
      ->sourceMigration('DTPublication');

    // Default values.
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('language')->defaultValue('en');
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
   *   - FALSE: If there is no mappad value.
   *   - string: mapped value.
   */
  protected function fileLinkUploadMap($value) {
    return array_search($value, [
      'link' => 'Link to file',
      'upload' => 'Upload the file',
    ]);
  }

  /**
   * When a row import completed.
   *
   * @param object $entity
   *   The entity, which already in the database.
   * @param \stdClass $row
   *   Imported row from migration.
   */
  public function complete($entity, stdClass $row) {
    // Languages.
    $file_languages = $this->getFileLanguages($row->fid);

    // English title, if empty then indicate it in the text.
    $xml = $this->getFileTranslationElementByFidAndLanguage($row->fid, 'en');
    $entity->title = isset($xml->title) ? (string) $xml->title : t('File title is missing, nid: @title', ['@title' => $entity->nid]);

    // Translation setting at the content.
    $data = [];

    // Iterate on all languages, which are related to the import.
    foreach ($file_languages as $language) {
      // Get the xml node related fid and language.
      $xml = $this->getFileTranslationElementByFidAndLanguage($row->fid, $language);

      // Title.
      $entity->title_field[$language][0]['value'] = isset($xml->title) ? (string) $xml->title : NULL;

      // File processing, like: download or link to an external resource.
      switch ($row->file_link_upload) {
        // Download and store a file.
        case 'Upload the file':
          $entity->field_core_file[$language][] = (array) $this->getFile($xml);
          break;

        // External link, using legacy link.
        case 'Link to file':
          $url = isset($xml->source_file_url) ? (string) $xml->source_file_url : NULL;
          $entity->field_core_legacy_link[$language][] = [
            'url' => $url,
            'attribute' => [],
          ];
          break;

      }

      // Node specific data.
      $data[$language] = [
        'entity_type' => 'node',
        'entity_id' => $entity->nid,
        'language' => $language,
        'source' => ($language == 'en') ? '' : 'en',
        'uid' => '1',
        'status' => '1',
        'translate' => '0',
        'created' => REQUEST_TIME,
        'changed' => REQUEST_TIME,
      ];
    }

    // Adding language specific settings to file node.
    $entity->translations = (object) [
      'original' => 'en',
      'data' => $data,
    ];

    // Store file node.
    node_save($entity);

    // Publication update.
    if (isset($entity->pid)) {
      $publication = node_load($entity->pid);
      if (isset($publication)) {
        $publication->field_core_files[LANGUAGE_NONE][0]['target_id'] = $entity->nid;
        node_save($publication);
      }
    }
  }

  /**
   * Get the file object.
   *
   * @param object $xml
   *   XML obejct of file translation.
   *
   * @return mixed
   *   - NULL if no file object.
   *   - Otherwise file object.
   */
  private function getFile($xml) {
    $uri = !empty($xml->source_file_url) ? (string) $xml->source_file_url[0] : NULL;
    // Giving a value for the filename.
    $filename = isset($xml->target_filename) ? (string) $xml->target_filename : file_munge_filename(preg_replace('@^.*/@', '', $uri), '', TRUE);

    if (!empty($buffer = $this->getFileContentByCurl($uri))) {
      if ($file_object = file_save_data($buffer, 'public://file_import/' . $filename, FILE_EXISTS_RENAME)) {
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
   *   Remote file for donwload.
   *
   * @return string
   *   Content.
   *
   * @see: http://stackoverflow.com/questions/697472/php-file-get-contents-returns-failed-to-open-stream-http-request-failed#answer-697540
   */
  private function getFileContentByCurl($url) {
    $curl_handle = curl_init();
    curl_setopt($curl_handle, CURLOPT_URL, $url);
    curl_setopt($curl_handle, CURLOPT_CONNECTTIMEOUT, 2);
    curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl_handle, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows; U; Windows NT 5.1; rv:1.7.3) Gecko/20041001 Firefox/0.10.1");
    $query = curl_exec($curl_handle);
    curl_close($curl_handle);
    return $query;
  }

  /**
   * Removing imported managed files at rollback.
   *
   * @param array $entity_ids
   *   Entity IDs which will be removed.
   */
  public function prepareRollback($entity_ids) {
    // Removing all file reference from Publication, which will be deleted.
    // Querying Publications, which has file reference by the given ids.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'publication')
      ->fieldCondition('field_core_files', 'target_id', $entity_ids, 'IN');
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
        if (!isset($item->nid) || array_search($item->nid, $entity_ids) !== FALSE) {
          unset($wrapper->field_core_files[$key]);
        }
      }
      $wrapper->save();
    }

    // Removing managed files.
    $nodes = node_load_multiple($entity_ids);
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
