<?php

namespace Drupal\nexteuropa\Context;

use Drupal\nexteuropa\Helpers\NodeContextHelper;
use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Drupal\nexteuropa\Helpers\FileContextHelper;
use Behat\Gherkin\Node\TableNode;

/**
 * Contains digital transformation specific step defenitions.
 */
class DigitalTransformationContext extends RawDrupalContext implements SnippetAcceptingContext {

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
   *   * @var Drupal\nexteuropa\Helpers\FileContextHelper
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
    throw new Exception($native_name . " is not in the correct case.");
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
   * @Then the metatag attribute :metatag should have the value :value
   *
   * @throws \Exception
   *   If it does not match.
   */
  public function theMetatagAttributeShouldHaveTheValue($metatag, $value) {
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
   * Fills in an entity reference field.
   *
   * @param string $input_id
   *    HTML id attribute of the input element fo till in.
   * @param string $target_title
   *    Title of the referenced node.
   *
   * @throws \Exception
   *    If the nodes cannot be found.
   *
   * @Then I fill in the reference :input_id with :target_title
   */
  public function iFillInTheReferenceWith($input_id, $target_title) {
    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $target_title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->propertyOrderBy('nid', 'DESC')
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new Exception(format_string("Node @title of @type not found.", $params));
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
        throw new Exception(format_string("Link with title @title found but not linking to @target.", $params));
      }
    }
    else {
      throw new Exception(format_string("Link with title @title not found.", ['@title' => $title]));
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
        throw new Exception(format_string("The element @element at position @position does not contain @text but @falsetext", $variables));
      }
    }
  }

}
