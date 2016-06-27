@api
Feature: In order to make roles and permissions management easy
  As an administrator user
  I want to have the same roles and permissions in each Editorial team

  @information
  Scenario: Check the default settings for the group type
    Given I am logged in as a user with the "administrator" role
    And am on "admin/config/group/roles/node/editorial_team"
    Then I should see text matching "author"
    And I should see text matching "validator"
    And I should see text matching "reviewer"
    And I should see text matching "translator"
    And I should see text matching "translator reviewer"

  @political
  Scenario: Check the default settings for the group type
    Given I am logged in as a user with the "administrator" role
    And am on "admin/config/group/roles/node/editorial_team"
    Then I should see text matching "author"
    And I should see text matching "validator"

  @information
  Scenario: New editorial teams have the same OG roles
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "editorial_team" content:
      | title    | Editorial Team Test |
      | status   | 1                   |
      | language | en                  |
    And I go to the group roles page
    Then I should see text matching "author"
    And I should see text matching "validator"
    And I should see text matching "reviewer"
    And I should see text matching "translator"
    And I should see text matching "translator reviewer"

  @political
  Scenario: New editorial teams have the same OG roles
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "editorial_team" content:
      | title    | Editorial Team Test |
      | status   | 1                   |
      | language | en                  |
    And I go to the group roles page
    Then I should see text matching "author"
    And I should see text matching "validator"