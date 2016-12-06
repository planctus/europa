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
   * @var array
   */
  private $languageList;

  /**
   * List of files currently on the site.
   *
   * @var array
   */
  private $startFiles;

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
    $this->visitPath($this->currentNode()->getNodePath() . '_' . $language_code);
  }

  /**
   * Goes to translation form.
   *
   * @When I go to add :target translation
   */
  public function iGoToAddTranslationFrom($target) {
    $this->visitPath($this->currentNode()
      ->getAddTranslationPath($target));
  }

  /**
   * Goes to the OG group's roles pages.
   *
   * @Given I go to the group roles page
   */
  public function iGoToTheGroupRolesPage() {
    $this->visitPath($this->currentNode()->getGroupRolesPath());
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
    throw new ExpectationException(sprintf("The current page is: %s", $this->getSession()
      ->getCurrentUrl()), $this->getSession());
  }

  /**
   * Prints the html.
   *
   * @Then print current html
   */
  public function printCurrentHtml() {
    throw new ExpectationException(sprintf("The current page is: %s", $this->getSession()
      ->getPage()
      ->getHtml()), $this->getSession());
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
   * @Then the select(s) :selector should be set to :value
   */
  public function theSelectsShouldBeSetTo($selector, $value) {
    $this->assertSession()->elementAttributeContains('css', $selector . ' option[selected="selected"]', 'value', $value);
  }

  /**
   * Check select box value.
   *
   * @Then the selects :selector should not be set to :value
   */
  public function theSelectsShouldNotBeSetTo($selector, $value) {
    $this->assertSession()
      ->elementAttributeNotContains('css', $selector . ' option[selected="selected"]', 'value', $value);
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
    $element = $this->getSession()
      ->getPage()
      ->find('css', "head > meta[http-equiv=content-language]");

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
    $element = $this->getSession()
      ->getPage()
      ->find('css', 'head > meta[name="' . $metatag . '"]');

    if (!is_object($element)) {
      throw new ExpectationException(sprintf('The ' . $metatag . ' is not present.'), $this->getSession());
    }
    elseif($value !== $element->getAttribute('content')) {
      throw new ExpectationException(sprintf('The ' . $metatag . ' metatag is not equal to %s', $value), $this->getSession());

    }
  }

  /**
   * Search part of the canonical link.
   *
   * @Then the canonical link should contain the value :value
   *
   * @throws ExpectationException
   *   If it does not contain.
   */
  public function theMetatagAttributeShouldContainTheValue($value) {
    $element = $this->getSession()
      ->getPage()
      ->find('css', 'head > link[rel="canonical"]');

    if (!is_object($element)) {
      throw new ExpectationException(sprintf('The canonical link is not present'), $this->getSession());
    }
    elseif(FALSE === strpos($element->getAttribute('href'), $value)) {
      throw new ExpectationException(sprintf('The canonical link does not contain %s', $value), $this->getSession());
    }
  }

  /**
   * Assess a metatag does not exist.
   *
   * @Then the metatag attribute :metatag should not exist
   *
   * @throws ExpectationException
   *   If it does not match.
   */
  public function theMetatagAttributeShouldNotExist($metatag) {
    $element = $this->getSession()
      ->getPage()
      ->find('css', 'head > meta[name="' . $metatag . '"]');

    if (is_object($element)) {
      throw new ExpectationException(sprintf('The ' . $metatag . ' metatag does exist'));
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
      $params = [
        '@title' => $target_title,
        '@type' => $input_id,
      ];
      throw new ExpectationException(format_string("Node @title of @type not found.", $params), $this->getSession());
    }
    $target_nid = key($result['node']);

    $this->getSession()
      ->getPage()
      ->find('css', "#$input_id")
      ->setValue("$target_title ($target_nid)");
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
      $child = $children[$n];
      // If it is not in the correct spot, we show an error.
      if ($child->getText() !== $repeatedelement['text']) {
        $variables = [
          '@position' => $n,
          '@element' => $element,
          '@text' => $repeatedelement['text'],
          '@falsetext' => $child->getText(),
        ];
        throw new ExpectationException(format_string("The element @element at position @position does not contain @text but @falsetext", $variables), $this->getSession());
      }
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
   * Sets the last modified date.
   *
   * @Then I set the last modified date to :arg1
   */
  public function iSetTheLastModifiedDateTo($arg1) {
    $node = $this->currentNode()->getNode();
    db_update('node')
      ->fields(['changed' => strtotime($arg1)])
      ->condition('nid', $node->nid)
      ->execute();
  }

  /**
   * Indexes all indexes.
   *
   * @Given I index all indexes
   */
  public function iIndexAllIndexes() {
    search_api_cron();
  }

  /**
   * Switches to an Iframe by ID.
   *
   * @When I switch to the frame :frame
   */
  public function iSwitchToTheFrame($frame) {
    $this->getSession()->switchToIFrame($frame);
  }

  /**
   * Leave the I frames.
   *
   * @When I switch out of all frames
   */
  public function iSwitchOutOfAllFrames() {
    $this->getSession()->switchToIFrame();
  }

  /**
   * Check the file behind a link.
   *
   * This is currently the only working solution. This can be improved.
   *
   * @Then /^I get the file "([^"]*)" after clicking "([^"]*)"(?: in the "([^"]*)" element)?$/i
   */
  public function iGetTheFileAfterClicking($filename, $link, $element = NULL) {
    $element = !is_null($element) ? $element : 'body';

    if ($link = $this->getSession()->getPage()->find('css', $element)->findLink($link)) {
      // Go to the actual url.
      $matches = [];
      preg_match('/file\/(\d*)\/download/', $link->getAttribute('href'), $matches);

      if (isset($matches[1]) && $file_entity = entity_load('file', [$matches[1]])) {
        $file_entity = reset($file_entity);

        if ($file_entity->filename == $filename) {
          // Everything is ok.
          return TRUE;
        }
        throw new ExpectationException('File download goes to the file ' . $file_entity->filename . ' instead of ' . $filename . '.', $this->getSession());
      }
      throw new ExpectationException('Unable to load the file.', $this->getSession());
    }
    throw new ExpectationException('Unable to find the download link.', $this->getSession());
  }

  /**
   * Gathers the current file entity's.
   *
   * @BeforeScenario
   */
  public function getStartFiles() {
    if (is_array($this->startFiles)) {
      return $this->startFiles;
    }
    $this->startFiles = $this->getFileIds();
    return $this->startFiles;
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
    $diff = array_diff($this->getFileIds(), $this->startFiles);

    foreach ($diff as $fid) {
      entity_delete('file', $fid);
    }
  }

  /**
   * Helper function to get all the file id's.
   *
   * @return array
   *   File id's.
   */
  public function getFileIds() {
    $query = new \EntityFieldQuery();
    $query->entityCondition('entity_type', 'file');
    $result = $query->execute();
    return array_keys($result['file']);
  }

  /**
   * Sets the xdebug cookie.
   *
   * @BeforeScenario
   */
  public function xdebugCookie() {
    if ('1' === getenv('XDEBUG')) {
      $this->getSession()->setCookie('XDEBUG_SESSION', 'PHPSTORM');
    }
  }

  /**
   * Generates a number of nodes of a type.
   *
   * @Given I have :quantity :type content:
   */
  public function generateNodes($quantity, $type, TableNode $table) {
    foreach ($table->getHash() as $nodeHash) {
      $node = (object) $nodeHash;
      $node->type = $type;
      for ($i = 0; $i < $quantity; $i++) {
        $new_node = clone($node);
        $new_node->title = $new_node->title . " $i";
        $this->nodeCreate($new_node);
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
   * Selects an element form a chosen box.
   *
   * This requires @javascript.
   *
   * @Given /^I select "([^"]*)" from "([^"]*)" chosen\.js select box$/
   */
  public function iSelectFromChosenJsSelectBox($option, $select) {
    $select = str_replace('\\"', '"', $select);
    $option = str_replace('\\"', '"', $option);

    $page = $this->getSession()->getPage();
    $field = $page->findField($select, TRUE);

    if (NULL === $field) {
      throw new ElementNotFoundException($this->getSession()
        ->getDriver(), 'form field', 'id|name|label|value', $select);
    }

    $id = $field->getAttribute('id');
    $opt = $field->find('named', ['option', $option]);
    $val = $opt->getValue();

    $javascript = "jQuery('#$id').val('$val');
                  jQuery('#$id').trigger('chosen:updated');
                  jQuery('#$id').trigger('change');";

    $this->getSession()->executeScript($javascript);
  }

  /**
   * Checks if the current url matches the requirements.
   *
   * @Then the current URL should be :alias
   */
  public function theCurrentUrlShouldBe($alias) {
    if (substr($alias, 0, 1) !== '/') {
      $alias = '/' . $alias;
    }
    $current_url = str_replace($GLOBALS['base_url'], '', $this->getSession()->getCurrentUrl());
    if ($current_url !== $alias) {
      throw new ExpectationException('The URL ' . $alias . ' does not match the requirements. The current URL is: ' . $current_url, $this->getSession());
    }
  }

  /**
   * Checks if in an input contains a given value.
   *
   * @param string $input_name
   *    The input name attribute to search for.
   * @param string $expected_value
   *    The input value to assert.
   *
   * @throws ExpectationException
   *    If no elements are found or if value is not as expected.
   *
   * @Then the input with name :input_name should have the value :expected_value
   */
  public function theInputWithNameShouldHaveTheValue($input_name, $expected_value) {
    $element = $this->getSession()
      ->getPage()
      ->find('css', 'input[name="' . $input_name . '"]');

    if (!is_object($element) || $expected_value !== $element->getAttribute('value')) {
      throw new ExpectationException(sprintf('The ' . $input_name . ' input does not contain %s', $expected_value), $this->getSession());
    }
  }

  /**
   * Selects an element from a autocomplete field.
   *
   * @When /^I select the first autocomplete option for "([^"]*)" on the "([^"]*)" field$/
   */
  public function iSelectFirstAutocomplete($prefix, $identifier) {
    $session = $this->getSession();
    $page = $session->getPage();
    $element = $page->findField($identifier);
    if (empty($element)) {
      throw new \Exception(sprintf('We couldn\'t find "%s" on the page', $identifier));
    }
    $page->fillField($identifier, $prefix);

    $xpath = $element->getXpath();
    $driver = $session->getDriver();

    // Autocomplete.js uses key down/up events directly.
    // Press the backspace key.
    $driver->keyDown($xpath, 8);
    $driver->keyUp($xpath, 8);

    // Retype the last character.
    $chars = str_split($prefix);
    $last_char = array_pop($chars);
    $driver->keyDown($xpath, $last_char);
    $driver->keyUp($xpath, $last_char);

    // Wait for AJAX to finish.
    $this->getSession()->wait(5000, '(typeof(jQuery)=="undefined" || (0 === jQuery.active && 0 === jQuery(\':animated\').length))');

    // And make sure the autocomplete is showing.
    $this->getSession()->wait(5000, 'jQuery("#autocomplete").show().length > 0');

    // And wait for 1 second just to be sure.
    sleep(1);

    // Press the down arrow to select the first option.
    $driver->keyDown($xpath, 40);
    $driver->keyUp($xpath, 40);

    // Press the Enter key to confirm selection, copying the value into the
    // field.
    $driver->keyDown($xpath, 13);
    $driver->keyUp($xpath, 13);

    // Wait for AJAX to finish.
    $this->getSession()->wait(5000, '(typeof(jQuery)=="undefined" || (0 === jQuery.active && 0 === jQuery(\':animated\').length))');
  }

  /**
   * Sets a variable to a value.
   *
   * @Given I set the variable :variable to :value
   */
  public function iSetTheVariableTo($variable, $value) {
    variable_set($variable, $value);
  }

  /**
   * Waits for a second.
   *
   * @When I wait for a second
   */
  public function iWaitForASecond() {
    sleep(1);
  }

}
