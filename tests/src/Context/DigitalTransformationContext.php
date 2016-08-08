<?php

namespace Drupal\nexteuropa\Context;

use Behat\Gherkin\Node\TableNode;
use Behat\Mink\Exception\ExpectationException;
use Drupal\nexteuropa\Helpers\NodeContextHelper;
use Drupal\nexteuropa\Helpers\FileContextHelper;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Contains digital transformation specific step defenitions.
 */
class DigitalTransformationContext extends RawDrupalContext {

  /**
   * List of languages.
   *
   * @var array $languageList
   *   List of available languages.
   */
  private $languageList;

  /**
   * The file context helper.
   *
   * @var \Drupal\nexteuropa\Helpers\FileContextHelper
   *   The filecontexthelper.
   */
  private $fileContextHelper;

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
    $this->languageList = reset(language_list('enabled'));
    $this->fileContextHelper = new FileContextHelper();
  }

  /**
   * Gets the current node information.
   *
   * @return \Drupal\nexteuropa\Helpers\NodeContextHelper
   *   Instance of the NodeContextHelper.
   */
  public function currentNode() {
    // We should reinitialize this every time as caching this would confuse the
    // test runner.
    return new NodeContextHelper($this->getSession());
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
    throw new ExpectationException($native_name . " is not in the correct case.", $this->getSession());
  }

  /**
   * Changes the language of the page to the requested language.
   *
   * @Then I change the language to :language_name
   */
  public function iChangeTheLanguageTo($language_name) {
    $available_languages = language_list('name');

    if (isset($available_languages[$language_name])) {
      $language_code = $available_languages[$language_name]->prefix;
    }
    else {
      throw new ExpectationException('Requested language ' . $language_name . ' not found or inactive', $this->getSession());
    }

    // Redirect the user to the new language page.
    $this->getSession()->visit($this->currentNode()->getNodePath() . '_' . $language_code);
  }

  /**
   * Goes to translation form.
   *
   * @When I go to add :target translation
   */
  public function iGoToAddTranslationFrom($target) {
    $this->getSession()->visit($this->currentNode()->getAddTranslationPath($target));
  }

  /**
   * Goes to the OG group's roles pages.
   *
   * @Given I go to the group roles page
   */
  public function iGoToTheGroupRolesPage() {
    $this->getSession()->visit($this->currentNode()->getGroupRolesPath());
  }

  /**
   * Adds dummy text.
   *
   * @When I fill :field with :length characters of dummy text
   */
  public function iFillWithCharactersOfDummyText($field, $length) {
    $value = $this->getRandom()->name(intval($length));
    $this->getSession()->getPage()->fillField($field, $value);
  }

  /**
   * Prints the current page.
   *
   * @Then print current page
   */
  public function printCurrentPage() {
    throw new ExpectationException(sprintf("The current page is: %s", $this->getSession()->getCurrentUrl()), $this->getSession());
  }

  /**
   * Prints the html.
   *
   * @Then print current html
   */
  public function printCurrentHtml() {
    throw new ExpectationException(sprintf("The current page is: %s", $this->getSession()->getPage()->getHtml()));
  }

  /**
   * Goes to the edit page.
   *
   * @Then I edit the node
   */
  public function iEditTheNode() {
    $this->getSession()->visit($this->currentNode()->getEditPath());
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
    throw new ExpectationException($this->languageList[$arg1]->native . ' has an incorrect weight.', $this->getSession());
  }

  /**
   * Checks if the checkbox is checked.
   *
   * @Then the checkboxes :selector should be checked
   */
  public function theCheckboxesShouldBeChecked($selector) {
    $checkboxes = $this->getSession()->getPage()->findAll('css', $selector);
    if ($checkboxes === NULL) {
      throw new ExpectationException('Could not find checkbox input element matching the selector: ' . $selector, $this->getSession());
    }
    foreach ($checkboxes as $checkbox) {
      if (!$checkbox->isChecked()) {
        throw new ExpectationException('Checkbox with the id ' . $checkbox->getAttribute('id') . ' is not checked and it should be', $this->getSession());
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
      throw new ExpectationException('Could not find select element matching the selector: ' . $selector, $this->getSession());
    }
    foreach ($selects as $select) {
      if ($select->getValue() !== $value) {
        throw new ExpectationException('Select with the id ' . $select->getAttribute('id') . ' is not set to ' . $value . ' and it should be', $this->getSession());
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
      throw new ExpectationException('Could not find element matching the selector: ' . $selector, $this->getSession());
    }
    foreach ($elements as $element) {
      if ($element->getText() == '') {
        throw new ExpectationException('Element ' . $selector . 'is empty and it should not be', $this->getSession());
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
      throw new ExpectationException('Could not find field: ' . $field, $this->getSession());
    }
    if (!$field_element->hasAttribute($attribute)) {
      throw new ExpectationException('Field ' . $field_element->getHtml() . ' does not have the attribute: ' . $attribute, $this->getSession());
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
      throw new ExpectationException('Could not find field: ' . $field, $this->getSession());
    }
    if ($field_element->hasAttribute($attribute)) {
      throw new ExpectationException('Field ' . $field . ' has the attribute: ' . $attribute, $this->getSession());
    }
  }

  /**
   * Search a language metatag.
   *
   * @Then /^the language metatag should have the value "(?P<value>[^"]*)"$/
   *
   * @throws \ExpectationException
   *   If it does not match.
   */
  public function assertLanguageMetaRegion($value) {
    $element = $this->getSession()->getPage()->find('css', "head > meta[http-equiv=content-language]");

    if (!is_object($element) || $value !== $element->getAttribute('content')) {
      throw new ExpectationException(sprintf('The content-language metatag does not contain %s', $value), $this->getSession());
    }
  }

  /**
   * Search a metatag.
   *
   * @Then the metatag attribute :metatag should have the value :value
   *
   * @throws ExpectationException
   *   If it does not match.
   */
  public function theMetatagAttributeShouldHaveTheValue($metatag, $value) {
    $element = $this->getSession()->getPage()->find('css', 'head > meta[name="' . $metatag . '"]');

    if (!is_object($element) || $value !== $element->getAttribute('content')) {
      throw new ExpectationException(sprintf('The ' . $metatag . ' metatag does not contain %s', $value), $this->getSession());
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
   * Fills in an entity reference field.
   *
   * @param string $input_id
   *    HTML id attribute of the input element fo till in.
   * @param string $target_title
   *    Title of the referenced node.
   *
   * @throws ExpectationException
   *    If the nodes cannot be found.
   *
   * @Then I fill in the reference :input_id with :target_title
   */
  public function iFillInTheReferenceWith($input_id, $target_title) {
    $query = new \entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $target_title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->propertyOrderBy('nid', 'DESC')
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $target_title,
        '@type' => $input_id,
      );
      throw new ExpectationException(format_string("Node @title of @type not found.", $params), $this->getSession());
    }
    $target_nid = key($result['node']);

    $this->getSession()->getPage()->find('css', "#$input_id")->setValue("$target_title ($target_nid)");
  }

  /**
   * Checks that a link goes to a specific target.
   *
   * @Then I should see the link :title linking to :target
   */
  public function iShouldSeeTheLinkLinkingTo($title, $target) {
    $element = $this->getSession()->getPage();

    if ($result = $element->findLink($title)) {
      if ($result->getAttribute('href') !== $target) {
        $params = [
          '@title' => $title,
          '@target' => $target,
        ];
        throw new ExpectationException(format_string("Link with title @title found but not linking to @target.", $params), $this->getSession());
      }
    }
    else {
      throw new ExpectationException(format_string("Link with title @title not found.", ['@title' => $title]), $this->getSession());
    }
  }

  /**
   * Creates a dummy file entity, and inserts it into a field.
   *
   * @When I insert dummy image token into the :input_id field
   */
  public function iInsertDummyImageTokenIntoTheField($input_id) {
    // Generate a file.
    $file = $this->fileContextHelper->generateImageFileEntity();

    // Create a token.
    $token = $this->fileContextHelper->generateTokenbMarkupFromEntity($file, 'default');

    // Put the token inside an A tag. We cannot use the l() function here as it
    // sanitizes.
    $linked_token = '<a href="/" class="inline-media-image-link">' . $token . '</a>';

    // Actually fill in the field with the linked token.
    $this->getSession()
      ->getPage()
      ->find('css', "#$input_id")
      ->setValue("$linked_token");
  }

  /**
   * Cleans up files after every scenario.
   *
   * @AfterScenario
   */
  public function cleanUpFiles($event) {
    foreach ($this->fileContextHelper->getGeneratedTestFiles() as $file) {
      file_delete($file, TRUE);
    }
  }

  /**
   * Test implementation.
   *
   * @Then I should see the following in the repeated :element element within the context of the :parentelement element:
   */
  public function assertRepeatedElementContainsText($element, $parentelement, TableNode $table) {
    // Get our parent element.
    $parent = $this->getSession()->getPage()->findAll('css', $parentelement);

    // Store all children.
    $children = $parent[0]->findAll('css', $element);

    // Check all table elements for their position.
    foreach ($table->getHash() as $n => $repeatedelement) {
      // If it is not in the correct spot, we show an error.
      if ($children[$n]->find('css', $element)->getText() !== $repeatedelement['text']) {
        $variables = [
          '@position' => $n,
          '@element' => $element,
          '@text' => $repeatedelement['text'],
          '@falsetext' => $children[$n]->find('css', $element)->getText(),
        ];
        throw new ExpectationException(format_string("The element @element at position @position does not contain @text but @falsetext", $variables), $this->getSession());
      }
    }
  }

  /**
   * Sets the current node as the frontpage.
   *
   * @Given I set the current page as frontpage
   */
  public function iSetTheCurrentPageAsFrontpage() {
    variable_set('site_frontpage', ltrim($this->currentNode()
      ->getNodePath(), '/'));
    variable_set('weight_frontpage', 0);
  }

  /**
   * Test if a css selector is available.
   *
   * @Then /^I should see the css selector "([^"]*)"$/
   * @Then /^I should see the CSS selector "([^"]*)"$/
   *
   * @see: http://www.grasmash.com/article/behat-step-i-should-see-css-selector
   */
  public function iShouldSeeTheCssSelector($css_selector) {
    $element = $this->getSession()->getPage()->find("css", $css_selector);
    if (empty($element)) {
      throw new \Exception(sprintf("The page '%s' does not contain the css selector '%s'", $this->getSession()
        ->getCurrentUrl(), $css_selector));
    }
  }

  /**
   * Test if a css selector is not available.
   *
   * @Then /^I should not see the css selector "([^"]*)"$/
   * @Then /^I should not see the CSS selector "([^"]*)"$/
   *
   * @see: http://www.grasmash.com/article/behat-step-i-should-see-css-selector
   */
  public function iShouldNotSeeTheCssSelector($css_selector) {
    $element = $this->getSession()->getPage()->find("css", $css_selector);
    if (empty(!$element)) {
      throw new \Exception(sprintf("The page '%s' contains the css selector '%s'", $this->getSession()
        ->getCurrentUrl(), $css_selector));
    }
  }

  /**
   * Click testing of an element which has a css selector.
   *
   * @When /^(?:|I )click the element with CSS selector "([^"]*)"$/
   * @When /^(?:|I )click the element with css selector "([^"]*)"$/
   *
   * @see: http://www.grasmash.com/article/behat-step-i-should-see-css-selector
   */
  public function iClickTheElementWithCssSelector($css_selector) {
    $element = $this->getSession()->getPage()->find("css", $css_selector);
    if (empty($element)) {
      throw new \Exception(sprintf("The page '%s' does not contain the css selector '%s'", $this->getSession()
        ->getCurrentUrl(), $css_selector));
    }
    $element->click();
  }

  /**
   * Indexes all indexes.
   *
   * @Given I index all indexes
   */
  public function iIndexAllIndexes() {
    search_api_cron();
  }

}
