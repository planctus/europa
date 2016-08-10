@api @information @political
Feature: Publication content type should have 2 types of visualization.
When I log into the website
As an editor
I should be able to create single or collection publications.

  Scenario: One publication containing files (document)
    Given "Publication" content:
      | title                              | field_publication_collection | field_core_description | field_core_files               | status |
      | Activity Report 2014 Communication | 0                            | Content description    | DG COMM - Activity Report 2014 | 1      |
    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Activity Report 2014 Communication"
    Then I should see text matching "Files"
    But I should not see text matching "Documents"

  Scenario: Collection of publications (documents)
    Given "Publication" content:
      | title                  | field_publication_collection | field_core_description | field_core_publications            | status |
      | Publication collection | 1                            | Content description    | Activity Report 2014 Communication | 1      |
    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Publication collection"
    Then I should see text matching "Documents"
    And I should see text matching "Collection"

  Scenario Outline: Anonymous users can see the date published value in the last-modified metatag
    Given I am an anonymous user
    When I am viewing a "Publication" content:
      | title                     | <title>          |
      | field_core_date_published | <date-published> |
      | field_core_date_updated   | <date-updated>   |
      | status                    | 1                |
    Then the metatag attribute "last-modified" should have the value "<expected-meta>"

    Examples:
      | title            | date-published | date-updated | expected-meta |
      | Test publication | 1400980800     | 1469980800   | 31/07/2016    |
