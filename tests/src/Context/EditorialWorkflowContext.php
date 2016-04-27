<?php

namespace Drupal\nexteuropa\Context;


/**
 * Contains editorial workflow specific step definitions.
 */
class EditorialWorkflowContext extends DigitalTransformationContext {

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
    parent::__construct();
  }

  /**
   * Adds current user to current group.
   *
   * @Given /^I am (?:a|an) "([^"]*)" of the current group$/
   */
  public function iAmAnOfTheCurrentGroup($group_role) {
    $group = $this->getCurrentGroupFromUrl();
    $this->addMembertoGroup($group_role, $group);
    $this->getMainContext()->softReload();
  }

  /**
   * Adds a member to an organic group with the specified role.
   *
   * @param string $group_role
   *   The machine name of the group role.
   * @param object $group
   *   The group node.
   * @param string $group_type
   *   (optional) The group's entity type.
   * @param object $user
   *   (optional) The user we assign the role to.
   *
   * @throws \Exception
   */
  public function addMembertoGroup($group_role, $group, $group_type = 'node', $user = NULL) {
    if (!$user) {
      // Get the currently logged in user from DrupalContext.
      /** @var \Drupal\DrupalExtension\Context\DrupalContext $context */
      $context = $this->getContext('\Drupal\DrupalExtension\Context\DrupalContext');
      if (empty($context->user)) {
        throw new \Exception('Cannot assign anonymous user to a group.');
      }
      $user = $context->user;
    }
    list($gid, $vid, $bundle) = entity_extract_ids($group_type, $group);

    $membership = og_group($group_type, $gid, array(
      "entity type" => 'user',
      "entity" => $user,
    ));

    if (!$membership) {
      throw new \Exception("The Organic Group membership could not be created.");
    }

    // Add role for membership.
    $roles = og_roles($group_type, $group->type, $gid);
    $rid = array_search($group_role, $roles);

    if (!$rid) {
      throw new \Exception("'$group_role' is not a valid group role.");
    }

    og_role_grant($group_type, $gid, $user->uid, $rid);

  }

  /**
   * Gets current Organic Group context from URL.
   */
  public function getCurrentGroupFromUrl() {
    // Get group context using node from current URL. Note that we cannot rely
    // on menu_get_item(), or og_context_determine_context() due to $_GET['q']
    // not being set correctly.
    $group_type = 'node';
    $node = $this->currentNode()->getNode();
    $context = _group_context_handler_entity($group_type, $node);
    if (!$context) {
      throw new \Exception("No active organic group context could be found.");
    }
    $gid = reset($context[$group_type]);
    $group = entity_load_single($group_type, $gid);

    return $group;
  }

  /**
   * Go to the parent group.
   *
   * @Given /^I visit the parent group node$/
   */
  public function iVisitTheParentGroupNode() {
    $group = $this->getCurrentGroupFromUrl();
    $this->getSession()->visit('/node/' . $group->nid);
  }

  /**
   * Create content in group.
   *
   * @Given /^I create a "([^"]*)" node belonging to the current organic group$/
   */
  public function iCreateNodeBelongingToTheCurrentOrganicGroup($content_entity_type) {
    // Get the current group.
    $group = $this->getCurrentGroupFromUrl();

    // Create the group content.
    $properties = array('og_group_ref' => $group->nid);
    // Creating the node will automatically redirect the browser to view it.
    $this->createNode($content_entity_type, $properties);
  }

  /**
   * Create a node.
   *
   * @Given /^I am viewing (?:a|an) "([^"]*)" node$/
   * @Given /^I create (?:a|an) "([^"]*)" node$/
   *
   * This overrides the parent createNode() method, allowing node properties
   * to be passes via $properties argument.
   *
   * @override
   */
  public function createNode($type, $properties = array()) {

    $node = (object) array(
      'title' => Random::name(25),
      'type' => $type,
      'uid' => 1,
    );

    if ($properties) {
      foreach ($properties as $key => $value) {
        $node->$key = $value;
      }
    }

    $this->dispatcher->dispatch('beforeNodeCreate', new EntityEvent($this, $node));
    $saved = $this->getDriver()->createNode($node);
    $this->dispatcher->dispatch('afterNodeCreate', new EntityEvent($this, $saved));
    $this->nodes[] = $saved;

    // Set internal page on the new node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));

    return $saved;
  }

  /**
   * Returns the most recently created node.
   *
   * @return object
   *   The most recently created node.
   */
  public function getLastCreatedNode() {
    return end($this->nodes);
  }

  /**
   * Add user to group with a given role.
   *
   * @Given /^I add "([^"]*)" to the group as "([^"]*)"$/
   */
  public function iAddToTheGroupAs($username, $role_name) {
    $user = user_load_by_name($username);
    if (!$user) {
      throw new \Exception("User cannot be found.");
    }
  }

}
