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
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
    $this->languageList = reset(language_list('enabled'));
  }

  /**
   * Translates an interface string to a given language.
   *
   * @Then I translate the string :source_string to :language with :target_string
   */
  public function iTranslateTheStringToWith($source_string, $language, $target_string) {
    // Check if the language is enabled.
    foreach ($this->languageList as $lang) {
      if ($lang->name == $language || $lang->native == $language) {
        $langcode = $lang->language;
        break;
      }
    }

    // If it is not available, exception.
    if (!isset($langcode)) {
      throw new ExpectationException($language . " is not found in the enabled languages.", $this->getSession());
    }

    $report = [
      'skips' => 0,
      'updates' => 0,
      'deletes' => 0,
      'additions' => 0,
    ];
    if (!_locale_import_one_string_db($report, $langcode, '', $source_string, $target_string, 'default', '', LOCALE_IMPORT_OVERWRITE)) {
      throw new ExpectationException('Could not translate ' . $source_string . ' into ' . $target_string . '. Language: ' . $language);
    }
  }

}
