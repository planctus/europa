@api @shared @dt_core
Feature: Europa Search
  In use the Europa Search index results
  As a normal user
  I want to be able to make a search query

  Scenario: Site configuration is correct
    Given I am logged in as a user with the "administrator" role
    When I go to "/admin/config/search/europa_search"
    Then I should see the text "Europa Search settings"
    And the input with name "nexteuropa_europa_search_url" should have the value "http://ec.europa.eu/geninfo/query/index.do?"

  Scenario: Search language attribute is correct
    Given I am not logged in
    When I am on the homepage
    And I follow "English"
    Then the input with name "swlang" should have the value "en"
