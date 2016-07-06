@api
Feature: In order to make roles and permissions management easy
  As an administrator user
  I want to have the same roles and permissions in each Editorial team

  @information @political
  Scenario: Check the default settings for the group type
    Given I am logged in as a user with the "administrator" role
    And am on "admin/config/group/roles/node/editorial_team"
    Then I should see text matching "author"
    And I should see text matching "validator"
    And I should see text matching "reviewer"
    And I should see text matching "translator"
    And I should see text matching "translator reviewer"

  @information @political
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

  @brp
  Scenario: Check the default settings for the group type
    Given I am logged in as a user with the "administrator" role
    And am on "admin/config/group/roles/node/editorial_team"
    Then I should see text matching "non-member"
    And I should see text matching "member"
    And I should see text matching "administrator member"
    And I should see text matching "contributor"
    And I should see text matching "validator"
    And I should see text matching "publisher"

  @brp
  Scenario: New editorial teams have the same OG roles
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "editorial_team" content:
      | title    | Editorial Team Test |
      | status   | 1                   |
      | language | en                  |
    And I go to the group roles page
    Then I should see text matching "non-member"
    And I should see text matching "member"
    And I should see text matching "administrator member"
    And I should see text matching "contributor"
    And I should see text matching "validator"
    And I should see text matching "publisher"
