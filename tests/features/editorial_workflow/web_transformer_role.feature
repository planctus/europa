@api @information @political
Feature: Checking 'web transformer' role, if a user is a member or not the role

  Scenario Outline: The user should or should not edit or delete a content depending on their roles.
    Given I am logged in as a user with the "administrator" role
    # Creating the test user and assigning the role(s).
    And users:
      | name   | status | roles  |
      | <user> | 1      | <role> |
    # Creating an editorial team for checking the availability later.
    And I go to "node/add/editorial-team"
    And I fill in the following:
      | Name                | Test editorial team |
      | Group Content types | page                |
    And I press "Save"
    # The test go to the 'Page' content creating page.
    # The user should see different editorial teams, depending on roles.
    # The 'web tranformer' should see the choice of the new 'Test editorial team',
    # but the simple 'editor' won't see the same.
    And I am logged in as "<user>"
    And I go to "/node/add/basic-page"
    Then the "#edit-og-group-ref" element <availability> contain "Test editorial team"

    Examples:
      | user                 | role                    | availability |
      | Web transformer user | web transformer, editor | should       |
      | Editor user          | editor                  | should not   |
