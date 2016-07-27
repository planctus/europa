<?php

namespace Drupal\nexteuropa_eurovoc;

/**
 * Class EuroVocTranslations.
 *
 * @package Drupal\nexteuropa_eurovoc
 */
class EuroVocTranslations {

  // This is the data the user wants to get in the end.
  protected $translations;
  // EuroVoc => Drupal codes.
  private $languages = [
    'bg' => 'bg',
    'cs' => 'cs',
    'da' => 'da',
    'de' => 'de',
    'el' => 'el',
    'en' => 'en',
    'es' => 'es',
    'et' => 'et',
    'fi' => 'fi',
    'fr' => 'fr',
    'ga' => 'ga',
    'hr' => 'hr',
    'hu' => 'hu',
    'it' => 'it',
    'lt' => 'lt',
    'lv' => 'lv',
    'mk' => 'mk',
    'mt' => 'mt',
    'nl' => 'nl',
    'pl' => 'pl',
    'pt' => 'pt-pt',
    'ro' => 'ro',
    'sk' => 'sk',
    'sl' => 'sl',
    'sq' => 'sq',
    'sr' => 'sr',
    'sv' => 'sv',
  ];

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    // File name to concept level translator.
    $patterns = [
      'desc' => [
        'level' => 'descriptor',
        'map' => 'DESCRIPTEUR_ID',
      ],
      'dom' => [
        'level' => 'domain',
        'map' => 'DOMAINE_ID',
      ],
      'thes' => [
        'level' => 'thesaurus',
        'map' => 'THESAURUS_ID',
      ],
    ];

    // EuroVoc tree with all necessary information.
    $translations = [];
    foreach ($patterns as $pattern => $pattern_data) {
      foreach ($this->getLanguages() as $lg_ev => $lg_dr) {
        // Load XML files and prepare the information in more convenient way.
        $file_tmp = $this->getDataPath() . $pattern . '_' . $lg_ev . '.xml';
        if (file_exists($file_tmp)) {
          $file_tmp_xml = simplexml_load_file(
            $file_tmp,
            'SimpleXMLElement',
            LIBXML_COMPACT
          );
          foreach ($file_tmp_xml->RECORD as $record) {
            $translations[$pattern_data['level']][$lg_dr][(string) $record->{$pattern_data['map']}] = (string) $record->LIBELLE;
          }
        }
      }
    }
    // Add the info to the instance state of translations.
    $this->setTranslations($translations);
  }

  /**
   * Equivalent to _nexteuropa_eurovoc_get_data_full_path() in this namespace.
   *
   * @return string
   *   The path to the folder containing XML files to parse.
   */
  public function getDataPath() {
    $module_path = drupal_get_path('module', 'nexteuropa_eurovoc');
    return DRUPAL_ROOT . '/' . $module_path . '/data/';
  }

  /**
   * Get a list of all languages of EuroVoc in key-val pairs.
   *
   * @return array
   *   The list of possible languages.
   */
  public function getLanguages() {
    return $this->languages;
  }

  /**
   * Set translations data for the instance.
   *
   * @param array $translations
   *   Array of translations.
   */
  public function setTranslations($translations) {
    $this->translations = $translations;
  }

  /**
   * Get all the data for each language in an array.
   *
   * @return array|mixed
   *
   *   PHP array tree of concepts, their levels, and their translations.
   */
  public function getTranslations() {
    return $this->translations;
  }

}
