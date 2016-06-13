@api @information
Feature: In order to work on drafts that I have started
  As an Author
  I need a screen where I can manage my drafts

  Scenario: 'My drafts' tab is available in my Workbench menu
    Given I am logged in as a user with the "administrator" role
    And am on "admin/workbench"
    Then I should see "My Drafts" in the ".tabs.primary" element

  Scenario: 'My drafts' page callback works correctly
    Given I am logged in as a user with the "administrator" role
    And am on "admin/workbench/drafts"
    Then I should see "My Drafts" in the "#branding" element