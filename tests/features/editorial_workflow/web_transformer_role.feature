@api @information @political @wip
# @wip because of a drupal-driver limitation. See: https://github.com/jhedstrom/DrupalDriver/pull/99
# Once it is resolved and the new version is used we can remove the @wip tag.
Feature: Checking 'web transformer' role, if a user is a member or not the role

  Scenario: The user should or should not edit or delete a content depending on their roles.
    Given users:
      | name                 | mail           | status | roles                                  |
      | Web transformer user | test1@test.com | 1      | web transformer, editorial team member |
      | Editor user          | test2@test.com | 1      | editorial team member                  |

    Given "Editorial team" content:
      | title               | field_editorial_types | language |
      | Test editorial team | basic_page            | und      |

    And I am logged in as "Editor user"
    And I go to "node/add/basic-page"
    Then I should get a 403 HTTP response

    And I am logged in as a user with the "administrator" role
    Then I go to "content/test-editorial-team"
    And I add "Editor user" to the group as "author"

    And I am logged in as "Editor user"
    And I go to "node/add/basic-page"
    Then the "#edit-og-group-ref" element should contain "Test editorial team"

    And I am logged in as "Web transformer user"
    And I go to "node/add/basic-page"
    Then the "#edit-og-group-ref" element should contain "Test editorial team"
