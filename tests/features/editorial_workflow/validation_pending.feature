@api @information
Feature: In order to revise content I need to send for validation
  As an Author
  I need a screen where I can manage my content in Request Validation state

  Scenario: 'Validation pending' tab is available in my Workbench menu
    Given I am logged in as a user with the "editor" role
    And am on "admin/workbench"
    Then I should see "Validation pending"

  Scenario: 'Validation pending' page callback works correctly
    Given I am logged in as a user with the "editor" role
    And am on "admin/workbench/drafts"
    Then I should see "Validation pending"