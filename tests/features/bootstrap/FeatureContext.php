<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;

/**
 * Defines application features from the specific context.
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
   * @Then the language :arg1 should be :arg2
   */
  public function theLanguageShouldBe($arg1, $arg2) {
    // Get the native name.
    $native_name = $this->languageList[$arg1]->native;

    // Check our argument and if the native name is in the correct case.
    if ($arg2 == 'upper' && $native_name === ucfirst($native_name)) {
      return;
    }
    elseif ($arg2 == 'lower' && $native_name === lcfirst($native_name )) {
      return;
    }
    throw new Exception($native_name . " is not in the correct case.");
  }

  /**
   * @When I go to add a :target translation from :source
   */
  public function iGoToAddATranslationFrom($target, $source)
  {
      $this->getSession()->visit($this->getSession()->getCurrentUrl() . '/add/' . $source . '/' . $target);
  }

  /**
   * @When I fill :field with :length characters of dummy text
   */
  public function iFillWithCharactersOfDummyText($field, $length)
  {
      $value = $this->getRandom()->string(intval($length));
      $this->getSession()->getPage()->fillField($field, $value);
  }

  /**
   * @Then print current page
   */
  public function printCurrentPage()
  {
      throw new \Exception(sprintf("The current page is: %s", $this->getSession()->getCurrentUrl()));
  }

  /**
   * @Then I edit the node
   */
  public function iEditTheNode()
  {
      $this->getSession()->visit($this->getSession()->getCurrentUrl() . '/edit');
  }

  /**
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
   * @Then the checkboxes :selector should be checked
   */
  public function theCheckboxesShouldBeChecked($selector)
  {
    $checkboxes = $this->getSession()->getPage()->findAll('css', $selector);
    if ($checkboxes === NULL) {
      throw new Exception('Could not find checkbox input element matching the selector: ' . $selector);
    }
    foreach ($checkboxes as $checkbox) {
      if(!$checkbox->isChecked()) {
        throw new Exception('Checkbox with the id ' . $checkbox->getAttribute('id') . ' is not checked and it should be');
      }
    }
  }

  /**
   * @Then the selects :selector should be set to :value
   */
  public function theSelectsShouldBeSetTo($selector, $value)
  {
    $selects = $this->getSession()->getPage()->findAll('css', $selector);
    if ($selects === NULL) {
      throw new Exception('Could not find select element matching the selector: ' . $selector);
    }
    foreach ($selects as $select) {
      if($select->getValue() !== $value) {
        throw new Exception('Select with the id ' . $select->getAttribute('id') . ' is not set to ' . $value . ' and it should be');
      }
    }
  }

  /**
   * @Then the element :selector should contain text
   */
  public function theElementShouldContainText($selector)
  {
    $elements = $this->getSession()->getPage()->findAll('css', $selector);
    if ($elements === NULL) {
      throw new Exception('Could not find element matching the selector: ' . $selector);
    }
    foreach ($elements as $element) {
      if($element->getText() == '') {
        throw new Exception('Element ' . $selector . 'is empty and it should not be');
      }
    }
  }
}
