@api @shared
Feature: Draft viewer role
  In order to validate visual representation of content before it's published
  As a registered user
  I need to have a draft viewer role to see drafts in the system

  Background:
    Given users:
    # They're all administrators to make it easy for the test to go around the site.
      | name              | mail                   | status | roles         | field_creator              |
      | harinro_test      | harinro@mail.mail      | 1      | administrator | eu.europa.ec/DIGIT.A.3.003 |
      | asselva_test      | asselva@mail.mail      | 1      | administrator | eu.europa.ec/COMM.A.5.002  |
      | site_manager_test | site_manager@mail.mail | 1      | administrator |                            |


  Scenario Outline: Users part of of DG COMM A5 unit should receive the role automatically
    Given I am logged in as "<user>"
    And I go to "admin/people"
    And I follow "<user>"
    And I click "Edit" in the "tabs" region
    Then the checkbox "Draft viewer" <is_expected> be checked

    Examples:
      | user              | is_expected |
      | harinro_test      | should not  |
      | asselva_test      | should      |
      | site_manager_test | should not  |


  Scenario: The user should see the option "View draft" when a node has a draft version.
    Given users:
      | name              | mail                      | status | roles        |
      | Draft viewer user | draft_user_test1@test.com | 1      | Draft viewer |

    And I am logged in as a user with the "administrator" role
    Given I am viewing a "Basic page" content:
      | title  | Lorem ipsum basic page |
      | status | 1                      |
    And I follow "New draft" in the "tabs" region
    And I fill in "Moderation state" with "draft"
    Then I press the "Save" button

    And I am logged in as "Draft viewer user"
    Then I go to "lorem-ipsum-basic-page"
    Then I should see the link "View draft" in the "tabs" region
