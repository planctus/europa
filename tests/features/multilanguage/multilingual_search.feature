@api
Feature: Search in views in any given language
  To deliver the best user experience
  As a user
  I want to be able to search in my own language

  Scenario Outline: Content language in meta tag
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "topic" content:
      | title                          | Environment |
      | language                       | en          |
      | status                         | 1           |
      | workbench_moderation_state_new | published   |
    And the "<language>" language is available
    And I go to "/topics_en"
    Then I should see "Environment"
    When I fill in "edit-combine" with "Environment"
    And I press "edit-submit-topics"
    Then I should see "Environment" in the ".view-id-topics .view-content" element
    When I follow "Environment"
    And I go to add "<language>" translation
    And I fill in "Title" with "<title>"
    And I press "Save"
    And I go to "/topics_<language>"
    Then I should see "<title>"
    When I fill in "edit-combine" with "<search>"
    And I press "edit-submit-topics"
    Then I should see "<title>" in the ".view-id-topics .view-content" element

    Examples:
      | title        | language | search     |
      | Околна среда | bg       | Околна     |
      | Περιβάλλον   | el       | Περιβάλλον |
