<?php

/**
 * @file
 * dt_nal_corporate_bodies.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function dt_nal_corporate_bodies_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'nal_corporate_bodies_importer';
  $feeds_importer->config = array(
    'name' => 'NAL corporate bodies importer',
    'description' => 'Imports data from http://publications.europa.eu/mdr/authority/corporate-body/index.html',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'label/*[@lg="eng"][1]',
          'xpathparser:2' => 'authority-code',
          'xpathparser:3' => 'acronym/*[@lg="eng"][1]',
          'xpathparser:4' => 'agency.type',
          'xpathparser:5' => '@id',
          'xpathparser:6' => 'eurovoc/@conceptID',
          'xpathparser:7' => 'corporate.classification',
          'xpathparser:8' => 'parent.id',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
        ),
        'context' => '//record[@deprecated="false"]',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'name',
            'unique' => TRUE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_authority_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_acronym',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_agency_type',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_nal_service_id',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_eurovoc_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_corporate_classification',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_parent_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'nal_corporate_bodies',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['nal_corporate_bodies_importer'] = $feeds_importer;

  return $export;
}
