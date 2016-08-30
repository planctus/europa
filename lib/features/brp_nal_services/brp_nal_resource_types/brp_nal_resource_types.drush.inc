<?php

/**
 * @file
 * Drush code for the module.
 */

include_once 'brp_nal_resource_types.helpers.inc';

/**
 * Implements hook_drush_command().
 */
function brp_nal_resource_types_drush_command() {

  $items['brp-nal-resource-types-import'] = [
    'description' => t('Runs feeds importer for NAL resource types taxonomy.'),
    'aliases' => ['brp-nal-resource-types-import'],
    'callback' => 'drush_nal_resource_types_import',
  ];

  $items['brp-nal-resource-types-translate'] = [
    'description' => t('Translates NAL resource types taxonomy terms.'),
    'aliases' => ['brp-nal-resource-types-translate'],
    'callback' => 'drush_nal_resource_types_translate',
  ];

  return $items;
}

/**
 * Callback for brp-nal-resource-types-import command.
 */
function drush_nal_resource_types_import() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'brp_nal_services', 'brp_nal_services.helpers');
  _brp_nal_services_run_importer('nal_resource_types', 'http://publications.europa.eu/mdr/resource/authority/resource-type/xml/resourcetypes.xml');
}

/**
 * Callback for brp-nal-resource-types-translate command.
 */
function drush_nal_resource_types_translate() {
  _brp_nal_resource_types_create_translations();
}
