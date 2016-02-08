<?php

/**
 * @file
 * Contains \FeatureContext.
 */

use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\TableNode;
use Behat\Mink\Element\NodeElement;
use Behat\Mink\Exception\ExpectationException;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Contains generic step definitions.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  private $languageList;

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
    $this->languageList  = reset(language_list('enabled'));
  }

  /**
   * Checks for the language.
   *
   * @Then the language :arg1 should be :arg2
   */
  public function theLanguageShouldBe($arg1, $arg2) {
    // Get the native name.
    $native_name = $this->languageList[$arg1]->native;

    // Check our argument and if the native name is in the correct case.
    if ($arg2 == 'upper' && $native_name === ucfirst($native_name)) {
      return;
    }
    elseif ($arg2 == 'lower' && $native_name === lcfirst($native_name)) {
      return;
    }
    throw new Exception($native_name . " is not in the correct case.");
  }

  /**
   * Goes to translation form.
   *
   * @When I go to add :target translation from :source
   */
  public function iGoToAddTranslationFrom($target, $source) {
    $this->getSession()->visit($this->getSession()->getCurrentUrl() . '/add/' . $source . '/' . $target);
  }

  /**
   * Adds dummy text.
   *
   * @When I fill :field with :length characters of dummy text
   */
  public function iFillWithCharactersOfDummyText($field, $length) {
    $value = $this->getRandom()->name(intval($length));
    echo $value;
    $this->getSession()->getPage()->fillField($field, $value);
  }

  /**
   * Prints the current page.
   *
   * @Then print current page
   */
  public function printCurrentPage() {
    throw new \Exception(sprintf("The current page is: %s", $this->getSession()->getCurrentUrl()));
  }

  /**
   * Prints the html.
   *
   * @Then print current html
   */
  public function printCurrentHtml() {
    throw new \Exception(sprintf("The current page is: %s", $this->getSession()->getPage()->getHtml()));
  }

  /**
   * Goes to the edit page.
   *
   * @Then I edit the node
   */
  public function iEditTheNode() {
    $this->getSession()->visit($this->getSession()->getCurrentUrl() . '/edit');
  }

  /**
   * Checks the language weight.
   *
   * @Then the language :arg1 should have weight :arg2
   */
  public function theLanguageShouldHaveWeight($arg1, $arg2) {
    // Check if the weight is correct.
    if ($this->languageList[$arg1]->weight == $arg2) {
      return;
    }
    throw new Exception($this->languageList[$arg1]->native . ' has an incorrect weight.');
  }

  /**
   * Checks if the checkbox is checked.
   *
   * @Then the checkboxes :selector should be checked
   */
  public function theCheckboxesShouldBeChecked($selector) {
    $checkboxes = $this->getSession()->getPage()->findAll('css', $selector);
    if ($checkboxes === NULL) {
      throw new Exception('Could not find checkbox input element matching the selector: ' . $selector);
    }
    foreach ($checkboxes as $checkbox) {
      if (!$checkbox->isChecked()) {
        throw new Exception('Checkbox with the id ' . $checkbox->getAttribute('id') . ' is not checked and it should be');
      }
    }
  }

  /**
   * Check select box value.
   *
   * @Then the selects :selector should be set to :value
   */
  public function theSelectsShouldBeSetTo($selector, $value) {
    $selects = $this->getSession()->getPage()->findAll('css', $selector);
    if ($selects === NULL) {
      throw new Exception('Could not find select element matching the selector: ' . $selector);
    }
    foreach ($selects as $select) {
      if ($select->getValue() !== $value) {
        throw new Exception('Select with the id ' . $select->getAttribute('id') . ' is not set to ' . $value . ' and it should be');
      }
    }
  }

  /**
   * Checks text content.
   *
   * @Then the element :selector should contain text
   */
  public function theElementShouldContainText($selector) {
    $elements = $this->getSession()->getPage()->findAll('css', $selector);
    if ($elements === NULL) {
      throw new Exception('Could not find element matching the selector: ' . $selector);
    }
    foreach ($elements as $element) {
      if ($element->getText() == '') {
        throw new Exception('Element ' . $selector . 'is empty and it should not be');
      }
    }
  }

  /**
   * Checks for attributes.
   *
   * @Then I see that the :field field has :attribute attribute
   */
  public function iSeeThatTheFieldHasAttribute($field, $attribute) {
    $field_element = $this->getSession()->getPage()->findField($field);
    if ($field_element === NULL) {
      throw new Exception('Could not find field: ' . $field);
    }
    if (!$field_element->hasAttribute($attribute)) {
      throw new Exception('Field ' . $field_element->getHtml() . ' does not have the attribute: ' . $attribute);
    }
  }

  /**
   * Checks for not having attribute.
   *
   * @Then I see that the :arg1 field has no :attribute attribute
   */
  public function iSeeThatTheFieldHasNoAttribute($field, $attribute) {
    $field_element = $this->getSession()->getPage()->findField($field);
    if ($field_element === NULL) {
      throw new Exception('Could not find field: ' . $field);
    }
    if ($field_element->hasAttribute($attribute)) {
      throw new Exception('Field ' . $field . ' has the attribute: ' . $attribute);
    }
  }

  /**
   * Checks that a 403 Access Denied error occurred.
   *
   * @Then I should get an access denied error
   */
  public function assertAccessDenied() {
    $this->assertSession()->statusCodeEquals(403);
  }

  /**
   * Checks that the given select field has the options listed in the table.
   *
   * @Then I should have the following options for :select:
   */
  public function assertSelectOptions($select, TableNode $options) {
    // Retrieve the specified field.
    if (!$field = $this->getSession()->getPage()->findField($select)) {
      throw new ExpectationException("Field '$select' not found.", $this->getSession());
    }

    // Check that the specified field is a <select> field.
    $this->assertElementType($field, 'select');

    // Retrieve the options table from the test scenario and flatten it.
    $expected_options = $options->getColumnsHash();
    array_walk($expected_options, function (&$value) {
      $value = reset($value);
    });

    // Retrieve the actual options that are shown in the page.
    $actual_options = $field->findAll('css', 'option');

    // Convert into a flat list of option text strings.
    array_walk($actual_options, function (&$value) {
      $value = $value->getText();
    });

    // Check that all expected options are present.
    foreach ($expected_options as $expected_option) {
      if (!in_array($expected_option, $actual_options)) {
        throw new ExpectationException("Option '$expected_option' is missing from select list '$select'.", $this->getSession());
      }
    }
  }

  /**
   * Checks that the given select field doesn't have the listed options.
   *
   * @Then I should not have the following options for :select:
   */
  public function assertNoSelectOptions($select, TableNode $options) {
    // Retrieve the specified field.
    if (!$field = $this->getSession()->getPage()->findField($select)) {
      throw new ExpectationException("Field '$select' not found.", $this->getSession());
    }

    // Check that the specified field is a <select> field.
    $this->assertElementType($field, 'select');

    // Retrieve the options table from the test scenario and flatten it.
    $expected_options = $options->getColumnsHash();
    array_walk($expected_options, function (&$value) {
      $value = reset($value);
    });

    // Retrieve the actual options that are shown in the page.
    $actual_options = $field->findAll('css', 'option');

    // Convert into a flat list of option text strings.
    array_walk($actual_options, function (&$value) {
      $value = $value->getText();
    });

    // Check that none of the expected options are present.
    foreach ($expected_options as $expected_option) {
      if (in_array($expected_option, $actual_options)) {
        throw new ExpectationException("Option '$expected_option' is unexpectedly found in select list '$select'.", $this->getSession());
      }
    }
  }

  /**
   * Checks that the given element is of the given type.
   *
   * @param NodeElement $element
   *   The element to check.
   * @param string $type
   *   The expected type.
   *
   * @throws ExpectationException
   *   Thrown when the given element is not of the expected type.
   */
  public function assertElementType(NodeElement $element, $type) {
    if ($element->getTagName() !== $type) {
      throw new ExpectationException("The element is not a '$type'' field.", $this->getSession());
    }
  }

  /**
   * Search a language metatag.
   *
   * @Then /^the language metatag should have the value "(?P<value>[^"]*)"$/
   *
   * @throws \Exception
   *   If it does not match.
   */
  public function assertLanguageMetaRegion($value) {
    $element = $this->getSession()->getPage()->find('css', "head > meta[http-equiv=content-language]");

    if (!is_object($element) || $value !== $element->getAttribute('content')) {
      throw new \Exception(sprintf('The content-language metatag does not contain %s', $value));
    }
  }

  /**
   * Search a metatag.
   *
   * @Then /^the metatag attribute "(?P<attribute>[^"]*)" should have the value "(?P<value>[^"]*)"$/
   *
   * @throws \Exception
   *   If it does not match.
   */
  public function assertMetaRegion($metatag, $value) {
    $element = $this->getSession()->getPage()->find('css', 'head > meta[name="' . $metatag . '"]');

    if (!is_object($element) || $value !== $element->getAttribute('content')) {
      throw new \Exception(sprintf('The ' . $metatag . ' metatag does not contain %s', $value));
    }
  }

  /**
   * Creates a language.
   *
   * @param string $langcode
   *   The ISO code of the language to create.
   *
   * @Given the :language language is available
   */
  public function createLanguages($langcode) {
    $this->languageCreate((object) ['langcode' => $langcode]);
  }

  /**
   * Creates an entity reference.
   *
   * @param string $field_name
   *    The machine name of the entity reference field.
   * @param $host_title
   *    Title of the node containing the entity reference field.
   * @param $target_title
   *    Title of the referenced node.
   *
   * @throws \Exception
   *    If the nodes cannot be found.
   *
   * @When I set the :field_name reference for :host_title to :target_title
   */
  public function iSetTheReferenceForTo($field_name, $host_title, $target_title) {
    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $host_title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new Exception(format_string("Node @title of @type not found.", $params));
    }
    $host_nid = key($result['node']);

    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $target_title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new Exception(format_string("Node @title of @type not found.", $params));
    }
    $target_nid = key($result['node']);

    $host = node_load($host_nid);
    $host->{$field_name}[LANGUAGE_NONE][]['target_id'] = $target_nid;
    $host->path['pathauto'] = TRUE;
    node_save($host);
  }

  /**
   * Check if creation of circular reference is prevented.
   *
   * @param string $field_name
   *    The machine name of the entity reference field.
   * @param $host_title
   *    Title of the node containing the entity reference field.
   * @param $target_title
   *    Title of the referenced node.
   *
   * @return bool
   *
   * @throws \Exception
   *    When circular reference could be created.
   *
   * @Given I cannot set circular reference :field_name for :host_title to :target_title
   */
  public function iCannotSetCircularReferenceForTo($field_name, $host_title, $target_title) {
    try {
      $this->iSetTheReferenceForTo($field_name, $host_title, $target_title);
    }
    catch (DTCoreParentCircular $e) {
      return TRUE;
    }

    throw new \Exception(sprintf('The circular reference in ' . $field_name . ' was created for ' . $host_title));
  }
}
