@api @shared
Feature: Checking 'Draft viewer' role, if a user has the option "View draft"

  Scenario: The user should see the option "View draft" when a node has a draft version.
    Given users:
      | name              | mail                      | status | roles        |
      | Draft viewer user | draft_user_test1@test.com | 1      | Draft viewer |

    And I am logged in as a user with the "administrator" role
    Given I am viewing a "Basic page" content:
      | title  | Lorem ipsum basic page |
      | status | 1                      |
    Then I follow "New draft" in the "tabs" region
    Then I press the "Save" button

    And I am logged in as "Draft viewer user"
    Then I go to "lorem-ipsum-basic-page"
    Then I should see the link "View draft" in the "tabs" region
