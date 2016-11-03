@api @information
Feature: Page content type

  Scenario: Legacy link should not show if unpublished on navigational concept
    Given "Page" content:
      | title  | status | language | field_core_parents | field_core_quick_nav_links     |
      | Page 1 | 1      | en       | Page 1             | page 1 link - http://google.be |
      | Page 2 | 0      | en       | Page 1             | page 2 link - http://google.be |
    And I am viewing a "Page":
      | title               | Concept page   |
      | field_core_children | Page 1, Page 2 |
      | status              | 1              |
      | language            | en             |
    Then I should see the link "page 1 link" linking to "http://google.be"
    Then I should not see "page 2 link"
    Then I should not see "- Restricted access -"
