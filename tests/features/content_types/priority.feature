@api @shared @dt_priority
Feature: Priority content type tests

  Scenario: Priority alias generation
    Given I am viewing a "priority" content:
      | title  | Priority |
      | status | 1        |
    Then the canonical link should contain the value "/priorities/priority_en"
