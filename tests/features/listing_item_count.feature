@information @political
Feature: Display item count on listing pages
  In order to have a better overview on the amount of items on a listing page
  As an anonymous user
  I want to see the number of items above the listing

  Scenario Outline: Item count is displayed on listing pages
    Given I am not logged in
    When I am at <listing>
    Then I should see an ".filters__result-count .filters__items-number" element
    And the element ".filters__result-count .filters__items-number" should contain text

    Examples:
      | listing         |
      | "departments"   |
      | "announcements" |
      | "policies"      |
      | "topics"        |
