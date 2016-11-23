@api @information @dt_editorial @dt_announcement
Feature: As a content manager
  In order to manage content I have been contributing to
  I want to have a page where I can see only content I have contributed to

  Scenario: In the "All content" tab I can filter content I have worked on
    Given users:
    # Consult OG Role Override module to understand roles matching.
      | name          | mail                     | status | roles           |
      | Agatha_First  | AgathaFirst@example.com  | 1      | web transformer |
      | Vanessa_First | VanessaFirst@example.com | 1      | administrator   |

    Given "Editorial team" content:
      | title      | field_editorial_types |
      | First team | announcement          |
    And I go to "content/first-team"
    And I add "Agatha_First" to the group as "author"
    And I add "Vanessa_First" to the group as "validator"

    Given "announcement" content with revisions:
      | title  | status | workbench_moderation_state_new | og_group_ref | author        |
      | Draft1 | 0      | draft                          | First team   | Agatha_First  |
      | Draft2 | 0      | draft                          | First team   | Vanessa_First |

    # Create a new revision with a validator, a difference in author to (last) revision owner.
    Given I am logged in as "Vanessa_First"
    When I go to "admin/workbench/all-content"
    And I click "Change to Published"
    # Log in as initial author after validator has made a new revision.
    Given I am logged in as "Agatha_First"
    When I go to "admin/workbench/all-content"
    And I check the box "Content I have worked on"
    And I press "Apply"
    # As an author I should see only the content I have a revision at.
    Then I should see "Draft1"
    But I should not see "Draft2"
