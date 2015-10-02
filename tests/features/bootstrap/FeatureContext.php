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

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
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
}
