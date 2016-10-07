<?php

/**
 * @file
 * Drush code for the module.
 */

/**
 * Implements hook_drush_command().
 */
function dt_nal_countries_drush_command() {

  $items['dt-nal-countries-import'] = [
    'description' => t('Runs feeds importer for NAL countries taxonomy.'),
    'aliases' => ['dt-nal-countries-import'],
    'callback' => 'drush_nal_countries_import',
  ];

  $items['dt-nal-countries-translate'] = [
    'description' => t('Translates NAL countries taxonomy terms.'),
    'aliases' => ['dt-nal-countries-translate'],
    'callback' => 'drush_nal_countries_translate',
  ];

  return $items;
}

/**
 * Callback for nal-countries-import command.
 */
function drush_nal_countries_import() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'dt_nal_services', 'dt_nal_services.helpers');
  _dt_nal_services_run_importer('nal_countries_importer', 'http://publications.europa.eu/mdr/resource/authority/country/xml/countries.xml');
}

/**
 * Callback for dt-nal-countries-translate command.
 */
function drush_nal_countries_translate() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'dt_nal_services', 'dt_nal_services.helpers');
  _dt_nal_services_create_translations('nal_countries', 'http://publications.europa.eu/mdr/resource/authority/country/xml/countries.xml');
}
