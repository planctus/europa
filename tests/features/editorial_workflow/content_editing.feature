@api @information @political @dt_editorial
Feature: Content editing within the editorial workflow require advanced configuration and alteration.

  @javascript
  Scenario: Nobody should be able to change "Group content access"
    Given I am logged in as a user with the "administrator" role
    And I go to "/node/add/basic-page"
    And I fill in "title_field[und][0][value]" with "Page Title"
    And I click "Editorial settings"
    Then I should not see "Group content visibility"
    And I press "Save"
    Then the current nodes Group content access should be "Use group defaults"
