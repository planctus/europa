<?php

namespace Drupal\nexteuropa\Context;

use Behat\Gherkin\Node\TableNode;
use Behat\Mink\Exception\ExpectationException;

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
    list($gid) = entity_extract_ids($group_type, $group);

    $membership = og_group($group_type, $gid, [
      "entity type" => 'user',
      "entity" => $user,
    ]);

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
    $properties = ['og_group_ref' => $group->nid];
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
  public function createNode($type, $properties = []) {

    $node = (object) [
      'title' => Random::name(25),
      'type' => $type,
      'uid' => 1,
    ];

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
    $group = $this->getCurrentGroupFromUrl();
    $this->addMembertoGroup($role_name, $group, 'node', $user);
  }

  /**
   * Creates content from table with revision.
   *
   * @param string $content_type
   *   Content type.
   * @param \Behat\Gherkin\Node\TableNode $table
   *   Table with data.
   *
   * @Given :content_type content with revisions:
   */
  public function contentWithRevisions($content_type, TableNode $table) {
    foreach ($table->getHash() as $row) {
      $node = (object) $row;
      $node->type = $content_type;

      // Use author information if available.
      if (isset($node->author)) {
        $user = user_load_by_name($node->author);
        $node->uid = $user->uid;
        // Create the node with uid information.
        $new_node = $this->nodeCreate($node);
        // Manually update the table, the driver doesn't do it.
        db_update('node_revision')
          ->fields(['uid' => $user->uid])
          ->condition('nid', $new_node->nid)
          ->execute();
      }

    }
  }

  /**
   * Save a history record for a moderated node.
   *
   * @param string $node
   *   The node being acted upon.
   * @param string $new_state
   *   The new moderation state.
   * @param string $old_state
   *   The former moderation state.
   *
   * @return object
   *   The new history record as saved.
   */
  public function updateRevisionHistory($node, $new_state, $old_state) {
    $vid_count = db_select('node_revision', 'r')
      ->condition('r.nid', $node->nid)
      ->condition('r.vid', $node->vid, '>')
      ->countQuery()->execute()->fetchField();

    $current = ($vid_count == 0);

    // Build a history record.
    $new_revision = (object) [
      'from_state' => $old_state,
      'state' => $new_state,
      'nid' => $node->nid,
      'vid' => $node->vid,
      'uid' => $this->user->uid,
      'is_current' => $current,
      'published' => ($new_state == workbench_moderation_state_published()),
      'stamp' => $_SERVER['REQUEST_TIME'],
    ];

    // If this is the new 'current' moderation record, it should be the only one
    // flagged 'current' in {workbench_moderation_node_history}.
    if ($new_revision->is_current) {
      db_update('workbench_moderation_node_history')
        ->condition('nid', $node->nid)
        ->fields(['is_current' => 0])
        ->execute();
    }

    // If this revision is to be published, the new moderation record should be
    // the only one flagged 'published' in both
    // {workbench_moderation_node_history} AND {node_revision}.
    if ($new_revision->published) {
      db_update('workbench_moderation_node_history')
        ->condition('nid', $node->nid)
        ->condition('vid', $node->vid, '!=')
        ->fields(['published' => 0])
        ->execute();
      db_update('node_revision')
        ->condition('nid', $node->nid)
        ->condition('vid', $node->vid, '!=')
        ->fields(['status' => 0])
        ->execute();
    }

    // Save the node history record.
    drupal_write_record('workbench_moderation_node_history', $new_revision);

    return $new_revision;
  }

  /**
   * Checks if the Group content access corresponds with the requirement.
   *
   * @Then the current nodes Group content access should be :value
   */
  public function theCurrentNodesGroupContentAccessShouldBe($value) {
    // Get the node.
    $node = $this->currentNode()->getNode();

    // Get the allowed values.
    $og_content_access = og_access_og_fields_info();
    $allowed_values = $og_content_access['group_content_access']['field']['settings']['allowed_values'];

    $key = array_search($value, $allowed_values);

    if (FALSE !== $key) {
      if ((string) $node->group_content_access[LANGUAGE_NONE][0]['value'] !== (string) $key) {
        throw new ExpectationException($value . ' is not the configured value for Group content access', $this->getSession());
      }
    }
    else {
      throw new ExpectationException($value . ' is not a valid group content access value', $this->getSession());
    }
  }

}
