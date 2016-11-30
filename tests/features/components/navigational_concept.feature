@api @information @dt_page
Feature: Navigational concept

  Background:
    Given "Page" content:
      | title        | status | language | field_core_parents | field_core_quick_nav_links      |
      | Child 1      | 1      | en       |                    | quick link 1 - http://google.be |
      | Child 2      | 0      | en       |                    | quick link 2 - http://google.be |
      | Grandchild 3 | 1      | en       | Child 1            | quick link 3 - http://google.be |
      | Grandchild 4 | 0      | en       | Child 1            | quick link 4 - http://google.be |

  Scenario: Unpublished items are not visible in the navigational concept
    Given I am viewing a "Page":
      | title               | Concept page     |
      | field_core_children | Child 1, Child 2 |
      | status              | 1                |
      | language            | en               |
    Then I should see the link "quick link 1" linking to "http://google.be"
    And I should see the link "Grandchild 3"
    But I should not see the link "quick link 2"
    And I should not see the link "Grandchild 4"
    And I should not see "- Restricted access -"

  Scenario: I can opt out from the navigational concept
    Given I am viewing a "Page":
      | title                            | Concept page     |
      | field_core_children              | Child 1, Child 2 |
      | field_core_navigation_visibility | 1                |
      | status                           | 1                |
      | language                         | en               |
    Then I should not see the link "quick link 1"
    And I should not see the link "Grandchild 3"
    And I should not see an ".section__group.section--row-three.section--navigation" element