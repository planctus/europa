@api
Feature: Content specific metatag behaviour
  Anonymous users and search robots
  need to see additional information in the metatags

  @information @political
  Scenario Outline: Anonymous users can see the date published value in the date metatag on article's
    Given I am viewing a "Announcement" content:
      | title                     | <title>          |
      | field_core_date_published | <date-published> |
      | status                    | 1                |
    Then I should see "<expected-string>"
    Then the metatag attribute "date" should have the value "<expected-meta>"

    Examples:
      | title             | date-published | expected-string | expected-meta |
      | Test announcement | 696384000      | 26 January 1992 | 26/01/1992    |

  @brp
  Scenario: Users should see the meta description on Initiative content.
    Given "nal_resource_types" terms:
      | name         | description                   |
      | ResourceType | The resource type description |
    Given I am viewing a "Initiative" content:
      | title                        | Initiative Title            |
      | field_core_description       | Initiative meta description |
      | status                       | 1                           |
      | field_brp_inve_resource_type | ResourceType                |
      | field_brp_inve_id            | 1                           |
    Then the metatag attribute "description" should have the value "Initiative meta description"

  @information
  Scenario Outline: Anonymous users can see the changed date value in last-modified metatag on nodes
    Given I am viewing a "Topic" content:
      | title  | <title>   |
      | status | 1         |
      | body   | body text |
    And I set the last modified date to "<date-changed>"
    And the cache has been cleared
    And I reload the page
    Then the metatag attribute "last-modified" should have the value "<expected-meta>"

    Examples:
      | title          | date-changed | expected-meta |
      | Test Topic One | 2016/06/30   | 30/06/2016    |

  @information
  Scenario: Anonymous users can see the changed date value in last-modified metatag on the frontpage
    Given I am viewing a "Page" content:
      | title  | Test page 1 |
      | status | 1           |
      | body   | body text   |
    And I set the last modified date to "2016/06/30"
    And I set the current page as frontpage
    And the cache has been cleared
    And I reload the page
    Then the metatag attribute "last-modified" should have the value "30/06/2016"

  @information @political
  Scenario Outline: Content language in meta tag
    Given I am viewing an "Page" content:
      | title       | <title>         |
      | description | <description>   |
      | language    | <language_code> |
      | status      | 1               |
    Then I should see "<title>" in the "title" element
    Then the language metatag should have the value "<language>"

    Examples:
      | title     | description | language | language_code |
      | nid en    | Node Engl   | en       | en            |
      | nid fr    | Node fren   | fr       | fr            |
      | nid pt-pt | Node PT     | pt       | pt-pt         |
