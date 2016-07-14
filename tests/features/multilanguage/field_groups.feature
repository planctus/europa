@api @information
Feature: Field groups should follow the content language and should be translateable.

  Background:
    Given "featured item" content:
      | title         | status |
      | Featured item | 1      |

  Scenario: Users can see translated field groups.
    Given I am logged in as a user with the "administrator" role
    Given I am viewing a "info_homepage" content:
      | title                 | test                  |
      | field_info_highlights | Featured item         |
      | language              | en                    |
      | status                | 1                     |
      | og_group_ref          | Global editorial team |
    Then I should see the heading "Featured"
    And I translate the string "Featured" to "German" with "Im Bild"
    And I go to add "de" translation
    And I fill in "title_field[de][0][value]" with "test de"
    And I press "Save"
    Then I should see the heading "Im Bild"
