<?php

/**
 * @file
 * dt_nal_countries.helpers.inc
 */

define('NAL_COUNTRIES', 'http://publications.europa.eu/mdr/resource/authority/country/xml/countries.xml');

/**
 * Helper to run the importer programmatically.
 */
function _dt_nal_countries_run_importer() {
  if ($source = feeds_source('nal_countries_importer')) {
    $fetcher_config = $source->getConfigFor($source->importer->fetcher);
    $fetcher_config['source'] = NAL_COUNTRIES;
    $fetcher_config['process_in_background'] = TRUE;
    $source->importer->addConfig($fetcher_config);
    $source->setConfigFor($source->importer->fetcher, $fetcher_config);
    $source->save();
    $source->startImport();
    // @codingStandardsIgnoreStart
    while (FEEDS_BATCH_COMPLETE != $source->import());
    // @codingStandardsIgnoreEnd
  }
}

/**
 * Helper to translate NAL Country taxonomy terms.
 */
function _dt_nal_countries_create_translations() {
  // Loading common functions useful for NAL service.
  module_load_include('inc', 'dt_nal_services', 'dt_nal_services.helpers');

  // Get information about the languages in Drupal and translate them.
  $enabled_languages = language_list();
  $language_default = language_default();
  $default_drupal = $language_default->language;
  $default_nal = _dt_nal_services_convert_drupal_language_code($default_drupal);

  $countries_vocabulary = taxonomy_vocabulary_machine_name_load('nal_countries');
  if ($countries = taxonomy_get_tree($countries_vocabulary->vid)) {
    foreach ($countries as $country) {
      $country_term = taxonomy_term_load($country->tid);
      $emw = entity_metadata_wrapper('taxonomy_term', $country_term);
      $cid = $emw->field_country_id->value();
      $country_translations = _dt_nal_services_get_label_translations(NAL_COUNTRIES, $cid, 'short');
      if ($country_translations && count($country_translations)) {
        // Getting context based on the Drupal language, but in a NAL code.
        $original_language = $country_translations[$default_nal];
        // Adding a translation for all enabled languages for this language.
        foreach ($country_translations as $nal_lang_code => $nal_translation) {
          $drupal_lang_code = _dt_nal_services_convert_nal_language_code($nal_lang_code);
          // If this is an enabled language, translate with NAL translation.
          if ($drupal_lang_code && array_key_exists($drupal_lang_code, $enabled_languages)) {
            _dt_nal_services_translate_term($original_language, $nal_translation, $drupal_lang_code);
          }
        }
      }
    }
  }
  return FALSE;
}
