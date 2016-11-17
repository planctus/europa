<?php

/**
 * @file
 * Drush code for the module.
 */

/**
 * Implements hook_drush_command().
 */
function dt_nal_corporate_bodies_drush_command() {

  $items['dt-nal-corporate-bodies-import'] = [
    'description' => t('Runs feeds importer for NAL corporate bodies taxonomy.'),
    'aliases' => ['dt-nal-corporate-bodies-import'],
    'callback' => 'drush_nal_corporate_bodies_import',
  ];

  $items['dt-nal-corporate-bodies-translate'] = [
    'description' => t('Translates NAL countries taxonomy terms.'),
    'aliases' => ['dt-nal-corporate-bodies-translate'],
    'callback' => 'drush_nal_corporate_bodies_translate',
  ];

  return $items;
}

/**
 * Callback for dt-nal-corporate-bodies-import.
 */
function drush_nal_corporate_bodies_import() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'dt_nal_services', 'dt_nal_services.helpers');
  _dt_nal_services_run_importer('nal_corporate_bodies_importer', 'http://publications.europa.eu/mdr/resource/authority/corporate-body/xml/corporatebodies.xml');
}

/**
 * Callback for dt-nal-corporate-bodies-translate command.
 */
function drush_nal_corporate_bodies_translate() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'dt_nal_services', 'dt_nal_services.helpers');
  _dt_nal_services_create_translations('nal_corporate_bodies', 'http://publications.europa.eu/mdr/resource/authority/corporate-body/xml/corporatebodies.xml');
}
