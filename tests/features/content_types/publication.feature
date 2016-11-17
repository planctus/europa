@api @information @political
Feature: Publication content type should have 2 types of visualization.
  As an editor
  I should be able to create single or collection publications.

  Scenario: One publication containing files (document)
    Given "file" content:
      | title         | status | language |
      | My File Title | 1      | en       |
    Given I am viewing a "Publication" content:
      | title                           | Activity Report 2014 Communication |
      | field_core_date_updated:value   | 1400980800                         |
      | field_core_date_updated:value2  | 1400980800                         |
      | field_core_date_published:value | 1400980800                         |
      | field_core_date_published:value | 1400980800                         |
      | field_publication_collection    | 0                                  |
      | field_core_description          | Content description                |
      | field_core_files                | My File Title                      |
      | status                          | 1                                  |
    Then I should see text matching "Files"
    Then I should not see an ".meta--header" element
    But I should not see text matching "Documents"

  Scenario: Collection of publications (documents)
    Given I am viewing a "Publication" content:
      | title                           | Publication collection             |
      | field_publication_collection    | 1                                  |
      | field_core_description          | Content description                |
      | field_core_publications         | Activity Report 2014 Communication |
      | status                          | 1                                  |
      | field_core_date_updated:value   | 1400980800                         |
      | field_core_date_updated:value2  | 1400980800                         |
      | field_core_date_published:value | 1400980800                         |
      | field_core_date_published:value | 1400980800                         |
    Then I should see text matching "Documents"
    Then I should see "COLLECTION" in the ".meta--header" element
    And I should see text matching "Collection"

  Scenario Outline: Anonymous users can see the date published value in the last-modified metatag
    Given I am viewing a "Publication" content:
      | title                            | <title>          |
      | field_core_date_published:value  | <date-published> |
      | field_core_date_published:value2 | <date-published> |
      | field_core_date_updated:value    | <date-updated>   |
      | field_core_date_updated:value2   | <date-updated>   |
      | status                           | 1                |
    Then the metatag attribute "last-modified" should have the value "<expected-meta>"

    Examples:
      | title            | date-published | date-updated | expected-meta |
      | Test publication | 1400980800     | 1469980800   | 31/07/2016    |
