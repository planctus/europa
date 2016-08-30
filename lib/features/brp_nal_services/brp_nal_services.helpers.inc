<?php

/**
 * @file
 * Brp_nal_countries.helpers.inc.
 */

/**
 * Helper to run a given importer.
 *
 * @param string $feeds_source
 *   The Feeds API source.
 * @param string $http_resource
 *   The address of the resource to import.
 */
function _brp_nal_services_run_importer($feeds_source, $http_resource) {
  if ($source = feeds_source($feeds_source)) {
    $fetcher_config = $source->getConfigFor($source->importer->fetcher);
    $fetcher_config['source'] = $http_resource;
    $fetcher_config['process_in_background'] = TRUE;
    $source->importer->addConfig($fetcher_config);
    $source->setConfigFor($source->importer->fetcher, $fetcher_config);
    $source->save();
    $source->startImport();
    // @codingStandardsIgnoreStart
    while (FEEDS_BATCH_COMPLETE != $source->import()) {
      ;
    }
    // @codingStandardsIgnoreEnd
  }
}

/**
 * Helper to translate all taxonomy terms under a given vocabulary.
 *
 * @param string $vocabulary
 *   The vocabulary marchine name.
 * @param string $http_resource
 *   The address of the resource to import.
 *
 * @return bool
 *   FALSE if nothing happens.
 */
function _brp_nal_services_create_translations($vocabulary, $http_resource) {
  // Get information about the languages in Drupal.
  $enabled_languages = language_list();
  $language_default = language_default();
  $default_drupal = $language_default->language;
  $default_nal = _brp_nal_services_convert_drupal_language_code($default_drupal);

  $voc = taxonomy_vocabulary_machine_name_load($vocabulary);
  if ($terms = taxonomy_get_tree($voc->vid)) {
    foreach ($terms as $term) {
      $term_object = taxonomy_term_load($term->tid);
      $emw = entity_metadata_wrapper('taxonomy_term', $term_object);
      $sid = $emw->field_nal_service_id->value();

      if ($term_translations = _brp_nal_services_get_label_translations($http_resource, $sid, 'short')) {
        if (isset($term_translations) && count($term_translations)) {
          // Getting context based on the Drupal language, but in a NAL code.
          $original_language = $term_translations[$default_nal];
          // Adding a translation for all enabled languages for this language.
          foreach ($term_translations as $nal_lang_code => $nal_translation) {
            $drupal_lang_code = _brp_nal_services_convert_nal_language_code($nal_lang_code);
            // If this is an enabled language, translate with NAL translation.
            if ($drupal_lang_code && array_key_exists($drupal_lang_code, $enabled_languages)) {
              _brp_nal_services_translate_term($original_language, $nal_translation, $drupal_lang_code);
            }
          }
        }
      }
    }
  }
  return FALSE;
}

/**
 * Query label translations by a record ID in an endpoint.
 *
 * An endpoint could be any XML http resource of a NAL authority list.
 *
 * @param string $endpoint
 *    NAL service endpoint for a given resource.
 * @param string $rid
 *    The record ID used for the query.
 * @param string $label_version
 *    Which label version: 'short' and 'long'.
 *
 * @return array $result
 *   The result array with key value pairs of information.
 */
function _brp_nal_services_get_label_translations($endpoint, $rid, $label_version) {
  $request = drupal_http_request($endpoint);
  // If no errors in the connection.
  if ($request->errno != 6) {
    if ($xml = simplexml_load_string($request->data)) {
      $label_translations = [];
      $result = [];

      // Take translation of a label depending on version preference.
      if ($label_version === 'short') {
        $label_translations = $xml->xpath('//record[@id="' . $rid . '"]/label/lg.version');
      }
      elseif ($label_version === 'long') {
        $label_translations = $xml->xpath('//record[@id="' . $rid . '"]/long.label/lg.version');
      }
      if ($label_translations) {
        // Format the information in more convenient way.
        foreach ($label_translations as $translation) {
          $attributes = $translation->attributes();
          $language_key = '';
          foreach ($attributes as $key => $attribute) {
            if ($key === 'lg') {
              $language_key = $attribute->__toString();
            }
          }
          if ($language_key != '') {
            $result[$language_key] = $translation->__toString();
          }
        }
      }
      return $result;
    }
    else {
      // No connection.
      return FALSE;
    }
  }
}

/**
 * Translates a term name in a given language.
 *
 * @param {Mixed} obj|string $term
 *   The term name to translate.
 * @param string $term_translation
 *   The translation to input in the localisation db set.
 * @param string $language
 *   For which language to input the translation.
 *
 * @return mixed
 *   The translation created if successful operation.
 */
function _brp_nal_services_translate_term($term, $term_translation, $language) {
  if (is_object($term)) {
    $terms[$term->tid] = $term;
  }
  else {
    $terms = taxonomy_get_term_by_name($term);
  }

  // If taxonomy term is actually found.
  foreach ($terms as $tid => $term) {

    i18n_string_translation_update(
      ['taxonomy', 'term', $tid, 'name'],
      $term_translation,
      $language,
      $term->name
    );
  }

}

/**
 * Converts Drupal-standard language code into a NAL standard one.
 *
 * @param string $code
 *   Drupal language code.
 *
 * @return bool|string
 *   NAL ISO language code.
 */
function _brp_nal_services_convert_drupal_language_code($code) {
  switch ($code) {
    case 'bg':
      return 'bul';

    case 'cs':
      return 'ces';

    case 'da':
      return 'dan';

    case 'de':
      return 'deu';

    case 'et':
      return 'est';

    case 'el':
      return 'ell';

    case 'en':
      return 'eng';

    case 'es':
      return 'spa';

    case 'fr':
      return 'fra';

    case 'ga':
      return 'gle';

    case 'hr':
      return 'hrv';

    case 'it':
      return 'ita';

    case 'lv':
      return 'lav';

    case 'lt':
      return 'lit';

    case 'hu':
      return 'hun';

    case 'mt':
      return 'mlt';

    case 'nl':
      return 'nld';

    case 'pl':
      return 'pol';

    case 'pt-pt':
      return 'por';

    case 'ro':
      return 'ron';

    case 'sk':
      return 'svk';

    case 'sl':
      return 'slv';

    case 'fi':
      return 'fin';

    case 'sv':
      return 'swe';

    default:
      return FALSE;
  }

}

/**
 * Converts a NAL standard code into a Drupal-standard language code.
 *
 * @param string $code
 *   NAL ISO language code.
 *
 * @return bool|string
 *   Drupal language code.
 */
function _brp_nal_services_convert_nal_language_code($code) {
  switch ($code) {
    case 'bul':
      return 'bg';

    case 'ces':
      return 'cs';

    case 'dan':
      return 'da';

    case 'deu':
      return 'de';

    case 'est':
      return 'et';

    case 'ell':
      return 'el';

    case 'eng':
      return 'en';

    case 'spa':
      return 'es';

    case 'fra':
      return 'fr';

    case 'gle':
      return 'ga';

    case 'hrv':
      return 'hr';

    case 'ita':
      return 'it';

    case 'lav':
      return 'lv';

    case 'lit':
      return 'lt';

    case 'hun':
      return 'hu';

    case 'mlt':
      return 'mt';

    case 'nld':
      return 'nl';

    case 'pol':
      return 'pl';

    case 'por':
      return 'pt-pt';

    case 'ron':
      return 'ro';

    case 'slk':
      return 'sk';

    case 'slv':
      return 'sl';

    case 'fin':
      return 'fi';

    case 'swe':
      return 'sv';

    default:
      return FALSE;
  }

}
