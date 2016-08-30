<?php

/**
 * @file
 * Drush code for the module.
 */

/**
 * Implements hook_drush_command().
 */
function brp_nal_countries_drush_command() {

  $items['brp-nal-countries-import'] = [
    'description' => t('Runs feeds importer for NAL countries taxonomy.'),
    'aliases' => ['brp-nal-countries-import'],
    'callback' => 'drush_nal_countries_import',
  ];

  $items['brp-nal-countries-translate'] = [
    'description' => t('Translates NAL countries taxonomy terms.'),
    'aliases' => ['brp-nal-countries-translate'],
    'callback' => 'drush_nal_countries_translate',
  ];

  return $items;
}

/**
 * Callback for nal-countries-import command.
 */
function drush_nal_countries_import() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'brp_nal_services', 'brp_nal_services.helpers');
  _brp_nal_services_run_importer('nal_countries_importer', 'http://publications.europa.eu/mdr/resource/authority/country/xml/countries.xml');
}

/**
 * Callback for brp-nal-countries-translate command.
 */
function drush_nal_countries_translate() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'brp_nal_services', 'brp_nal_services.helpers');
  _brp_nal_services_create_translations('nal_countries', 'http://publications.europa.eu/mdr/resource/authority/country/xml/countries.xml');
}
