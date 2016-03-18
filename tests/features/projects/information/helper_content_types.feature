@api
Feature: Helper content types should be not accessible for the public
  In order to have access only to content that is complete
  As a user with no "access helper content types" permission
  I want to be blocked when visiting a node that is of a helper content type.

  Scenario: User without permission cannot see helper content type (assuming toplink is helper and anonymous doesn't have the permission)
    Given I am not logged in
    When I am viewing a "toplink" content:
      | title  | "Test title" |
      | status | 1            |
    Then I should get an access denied error

  Scenario: User with permission can see helper content type (assuming toplink is helper and editor has the permission)
    Given I am logged in as a user with the "editor" role
    When I am viewing a "toplink" content:
      | title  | "Test title" |
      | status | 1            |
    Then I should see "Test title"
