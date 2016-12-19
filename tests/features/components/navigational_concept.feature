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

  Scenario: Possible content types for child pages have navigational concept
    Given "Temporary class" content:
      | title             | status | language | field_core_description            |
      | Temporary class 1 | 1      | en       | Temporary class description text. |
    Given "Law" content:
      | title | status | language | field_core_description |
      | Law 1 | 1      | en       | Law description text.  |
    Given "Policy" content:
      | title    | status | language | field_core_description   |
      | Policy 1 | 1      | en       | Policy description text. |
    Given "Policy area" content:
      | title         | status | language | field_core_description        |
      | Policy area 1 | 1      | en       | Policy area description text. |
    Given "Priority" content:
      | title      | status | language | field_core_description     |
      | Priority 1 | 1      | en       | Priority description text. |
    Given "Priority policy area" content:
      | title                  | status | language | field_core_description                 |
      | Priority policy area 1 | 1      | en       | Priority policy area description text. |
    Given "Publication" content:
      | title         | status | language | field_core_description        |
      | Publication 1 | 1      | en       | Publication description text. |
    Given "Topic" content:
      | title   | status | language | field_core_description  |
      | Topic 1 | 1      | en       | Topic description text. |
    Given I am viewing a "Page":
      | title               | Concept page                                                                                                           |
      | field_core_children | Child 1, Temporary class 1, Law 1, Policy 1, Policy area 1, Priority 1, Priority policy area 1, Publication 1, Topic 1 |
      | status              | 1                                                                                                                      |
      | language            | en                                                                                                                     |
    Then I should see the link "quick link 1" linking to "http://google.be"
    And I should see the link "Grandchild 3"
    # Confirm it has nav structure html tags and css classes.
    And I should see the following in the repeated ".section__item .listing.listing--navigation a.listing__item-link h2.listing__section-title" element within the context of the ".section--navigation" element:
      | text                   |
      | Child 1                |
      | Temporary class 1      |
      | Law 1                  |
      | Policy 1               |
      | Policy area 1          |
      | Priority 1             |
      | Priority policy area 1 |
      | Publication 1          |
      | Topic 1                |
