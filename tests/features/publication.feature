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
      | title                  | field_publication_collection | field_core_description | field_core_publications             | status |
      | Publication collection | 1                            | Content description    | Activity Report 2014 Communication  | 1      |
    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Publication collection"
    Then I should see text matching "Documents"
    And I should see text matching "Collection"
