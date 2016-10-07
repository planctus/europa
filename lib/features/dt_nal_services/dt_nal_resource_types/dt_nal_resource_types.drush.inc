<?php

/**
 * @file
 * Drush code for the module.
 */

include_once 'dt_nal_resource_types.helpers.inc';

/**
 * Implements hook_drush_command().
 */
function dt_nal_resource_types_drush_command() {

  $items['dt-nal-resource-types-import'] = [
    'description' => t('Runs feeds importer for NAL resource types taxonomy.'),
    'aliases' => ['dt-nal-resource-types-import'],
    'callback' => 'drush_nal_resource_types_import',
  ];

  $items['dt-nal-resource-types-translate'] = [
    'description' => t('Translates NAL resource types taxonomy terms.'),
    'aliases' => ['dt-nal-resource-types-translate'],
    'callback' => 'drush_nal_resource_types_translate',
  ];

  return $items;
}

/**
 * Callback for dt-nal-resource-types-import command.
 */
function drush_nal_resource_types_import() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'dt_nal_services', 'dt_nal_services.helpers');
  _dt_nal_services_run_importer('nal_resource_types', 'http://publications.europa.eu/mdr/resource/authority/resource-type/xml/resourcetypes.xml');
}

/**
 * Callback for dt-nal-resource-types-translate command.
 */
function drush_nal_resource_types_translate() {
  _dt_nal_resource_types_create_translations();
}
