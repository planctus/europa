<?php

/**
 * @file
 * Brp_nal_resource_types.helpers.
 */

define('NAL_RESOURCE_TYPES', 'http://publications.europa.eu/mdr/resource/authority/resource-type/xml/resourcetypes.xml');

/**
 * Helper to translate NAL resource types taxonomy terms.
 */
function _brp_nal_resource_types_create_translations() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'brp_nal_services', 'brp_nal_services.helpers');

  // The list of items to translate.
  $nal_resource_types = _brp_nal_resource_types_list();
  // Enabled languages.
  $drupal_languages = language_list();

  foreach ($nal_resource_types as $rid => $resource_type) {
    $translations = _brp_nal_services_get_label_translations(NAL_RESOURCE_TYPES, $rid, 'short');
    foreach ($translations as $nal_lang_code => $translation) {
      $language = _brp_nal_services_convert_nal_language_code($nal_lang_code);
      if (array_key_exists($language, $drupal_languages)) {
        _brp_nal_services_translate_term($translations['eng'], $translation, $language);
      }
    }
  }
}

/**
 * Returns a list of useful resource types for the BRP.
 *
 * @return array
 *    Key/value array for resource types.
 */
function _brp_nal_resource_types_list() {
  return [
    'RTY0259' => 'DIR_DEL_DRAFT',
    'RTY0258' => 'DEC_DEL_DRAFT',
    'RTY0260' => 'REG_DEL_DRAFT',
    'RTY0263' => 'DIR_IMPL_DRAFT',
    'RTY0262' => 'DEC_IMPL_DRAFT',
    'RTY0264' => 'REG_IMPL_DRAFT',
    'RTY0067' => 'DIR_DRAFT',
    'RTY0058' => 'DEC_DRAFT',
    'RTY0178' => 'REG_DRAFT',
  ];
}
