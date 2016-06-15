@api @information @wip
Feature: In order to guarantee that content can be managed only by the appropriate users
  As a product owner
  I want to have the editorial workflow control access

  Background:
    Given users:
      | name           | mail                      | status | roles       |
      | Mike_First     | MikeFirst@example.com     | 1      |             |
      | Agatha_First   | AgathaFirst@example.com   | 1      | contributor |
      | Vanessa_First  | VanessaFirst@example.com  | 1      | contributor |
      | Rocky_First    | RockyFirst@example.com    | 1      | contributor |
      | Mike_Second    | MikeSecond@example.com    | 1      |             |
      | Agatha_Second  | AgathaSecond@example.com  | 1      | contributor |
      | Vanessa_Second | VanessaSecond@example.com | 1      | contributor |
      | Rocky_Second   | RockySecond@example.com   | 1      | contributor |
      | Mike_Both      | MikeBoth@example.com      | 1      |             |
      | Agatha_Both    | AgathaBoth@example.com    | 1      | contributor |
      | Vanessa_Both   | VanessaBoth@example.com   | 1      | contributor |
      | Rocky_Both     | RockyBoth@example.com     | 1      | contributor |

    Given I am viewing an "editorial_team" content:
      | title                        | First team         |
      | status                       | 1                  |
      | language                     | en                 |
      | og_roles_permissions[und]    | 0                  |
      | field_editorial_types[und][] | announcement, page |
    And I add "Mike_First" to the group as "member"
    And I add "Agatha_First" to the group as "author"
    And I add "Vanessa_First" to the group as "validator"
    And I add "Rocky_First" to the group as "reviewer"
    And I add "Mike_Both" to the group as "member"
    And I add "Agatha_Both" to the group as "author"
    And I add "Vanessa_Both" to the group as "validator"
    And I add "Rocky_Both" to the group as "reviewer"

    Given I am viewing an "editorial_team" content:
      | title                        | Second team              |
      | status                       | 1                        |
      | language                     | en                       |
      | og_roles_permissions[und]    | 0                        |
      | field_editorial_types[und][] | announcement, department |
    And I add "Mike_Second" to the group as "member"
    And I add "Agatha_Second" to the group as "author"
    And I add "Vanessa_Second" to the group as "validator"
    And I add "Rocky_Second" to the group as "reviewer"
    And I add "Mike_Both" to the group as "member"
    And I add "Agatha_Both" to the group as "author"
    And I add "Vanessa_Both" to the group as "validator"
    And I add "Rocky_Both" to the group as "reviewer"

  Scenario Outline: users are allowed to edit only content types for their group
    Given I am logged in as "<user>"
    And I go to "node/add/<type>"
    Then I should get a <response> HTTP response
    Examples:
      | user          | type         | response | groups                  |
      | Mike_First    | department   | 403      | First team              |
      | Mike_First    | page         | 403      | First team              |
      | Mike_First    | announcement | 403      | First team              |
      | Mike_Second   | page         | 403      | Second team             |
      | Mike_Second   | department   | 403      | Second team             |
      | Mike_Second   | announcement | 403      | Second team             |
      | Mike_Both     | page         | 403      | First team, Second team |
      | Mike_Both     | department   | 403      | First team, Second team |
      | Mike_Both     | announcement | 403      | First team, Second team |
      | Agatha_First  | department   | 403      | First team              |
      | Agatha_First  | page         | 200      | First team              |
      | Agatha_First  | announcement | 200      | First team              |
      | Agatha_Second | page         | 403      | Second team             |
      | Agatha_Second | department   | 200      | Second team             |
      | Agatha_Second | announcement | 200      | Second team             |
      | Agatha_Both   | page         | 200      | First team, Second team |
      | Agatha_Both   | department   | 200      | First team, Second team |
      | Agatha_Both   | announcement | 200      | First team, Second team |