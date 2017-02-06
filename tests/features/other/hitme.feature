@api @shared @dt_priority @dt_pri_policy_area
Feature: hitMe library tests

  @javascript
  Scenario: Priority Policy Area teaser should show legacy link and call-to-action link
    Given "Priority policy area" content:
      | title                  | status | language | field_core_description                 | field_core_type_content              | field_core_legacy_link                | field_core_link                        |
      | Priority policy area 1 | 1      | en       | Priority policy area description text. | Teaser linking to external resources | test - http://ec.europa.eu/test1.html | C2A - http://ec.europa.eu/test1.1.html |
    Given "Priority policy area" content:
      | title                  | status | language | field_core_description                 | field_core_type_content              | field_core_legacy_link                |
      | Priority policy area 2 | 1      | en       | Priority policy area description text. | Teaser linking to external resources | test - http://ec.europa.eu/test2.html |
    Given I am viewing a "priority" content:
      | title                     | Priority                                       |
      | status                    | 1                                              |
      | language                  | en                                             |
      | field_core_child_policies | Priority policy area 1, Priority policy area 2 |
    Then I should see the link "Priority policy area 1" linking to "http://ec.europa.eu/test1.html"
    Then I should see the link "C2A" linking to "http://ec.europa.eu/test1.1.html"
    Then I should see an ".listing__item-link .listing__column-main .hitMe" element
