<?php

namespace Drupal\nexteuropa\Context;

use Behat\Mink\Exception\ExpectationException;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Contains digital transformation specific step defenitions.
 */
class TranslationContext extends RawDrupalContext {

  /**
   * List of languages.
   *
   * @var array
   *   List of available languages.
   */
  private $languageList;

  /**
   * Gets the list of available languages.
   *
   * @todo this will be overwritten by develop on the next release
   */
  private function getLanguages() {
    if (empty($this->languageList)) {
      $list = language_list('enabled');
      $this->languageList = reset($list);
    }
    return $this->languageList;
  }

  /**
   * Gets the language code.
   *
   * @param string $language
   *
   * @return string
   *   The langcode if found
   *
   * @throws ExpectationException
   *   When the language is not available.
   */
  private function getLangCode($language) {
    // Check if the language is enabled.
    foreach ($this->getLanguages() as $lang) {
      if ($lang->name == $language || $lang->native == $language) {
        $langcode = $lang->language;
        break;
      }
    }

    // If it is not available, exception.
    if (!isset($langcode)) {
      throw new ExpectationException($language . " is not found in the enabled languages.", $this->getSession());
    }
    return $langcode;
  }

  /**
   * Translates an interface string to a given language.
   *
   * @Then I translate the string :source_string to :language with :target_string
   */
  public function iTranslateTheStringToWith($source_string, $language, $target_string) {
    $report = [
      'skips' => 0,
      'updates' => 0,
      'deletes' => 0,
      'additions' => 0,
    ];
    if (!_locale_import_one_string_db($report, $this->getLangCode($language), '', $source_string, $target_string, 'default', '', LOCALE_IMPORT_OVERWRITE)) {
      throw new ExpectationException('Could not translate ' . $source_string . ' into ' . $target_string . '. Language: ' . $language, $this->getSession());
    }
  }

  /**
   * Translates a term into a given language.
   *
   * @Given I translate the term :term_name to :language with :translation
   */
  public function iTranslateTheTermToWith($term_name, $language, $translation) {
    $term = taxonomy_get_term_by_name($term_name);

    if (!empty($term)) {
      $term = reset($term);

      i18n_string_translation_update(
        ['taxonomy', 'term', $term->tid, 'name'],
        $translation,
        $this->getLangCode($language),
        $term->name
      );
      return TRUE;
    }

    throw new ExpectationException('Term ' . $term_name . ' not found.', $this->getSession());
  }

}
