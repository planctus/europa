@api @information
Feature: Display mixed content
  As a user
  I want to see my content
  In my preferred language

  Scenario: View untranslated node should display the metatag robot noindex, follow
    Given I am viewing an "basic_page" content:
      | title  | Test Metatags |
      | status | 1             |
    Then the metatag attribute "robots" should have the value "follow, index"
    And I create the following translations for "basic_page" content with title "Test Metatags":
      | title          | status | language |
      | Teste Metatags | 1      | pt-pt    |
    And I change the language to "Portuguese"
    Then the metatag attribute "robots" should have the value "follow, index"
    And I change the language to "Dutch"
    Then the metatag attribute "robots" should have the value "follow, noindex"


