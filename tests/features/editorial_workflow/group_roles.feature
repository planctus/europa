@api @information
Feature: In order to make roles and permissions management easy
  As an administrator user
  I want to have the same roles and permissions in each Editorial team

  Scenario: Check the default settings for the group type
    Given I am logged in as a user with the "administrator" role
    And am on "admin/config/group/roles/node/editorial_team"
    Then I should see text matching "author"
    And I should see text matching "validator"
    And I should see text matching "reviewer"
    And I should see text matching "translator"
    And I should see text matching "translator reviewer"

  Scenario Outline: All editorial teams have the same OG roles
    Given "editorial_team" content:
      | title   | field_core_description |
      | <title> | Content description    |
    And I go to the group roles page
    Then I should see text matching "author"
    And I should see text matching "validator"
    And I should see text matching "reviewer"
    And I should see text matching "translator"
    And I should see text matching "translator reviewer"

    Examples:
      | title            |
      | Editorial Team 1 |
      | Editorial Team 2 |