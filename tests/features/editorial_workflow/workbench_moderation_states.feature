@api @information @dt_editorial
Feature: In order to guarantee that content can be moderated
  As a product owner
  I want to have specific editorial workflow states

  Scenario: moderation states are defined and are in the correct order
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/config/workbench/moderation"
    Then I should see the following in the repeated "tbody tr td:nth-child(2)" element within the context of the "#workbench-moderation-states" element:
      | text               |
      | draft              |
      | needs_review       |
      | request_validation |
      | under_validation   |
      | validated          |
      | published          |
      | archived           |
      | expired            |
