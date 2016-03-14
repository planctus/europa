@api
Feature: Search in views in any given language
  To deliver the best user experience
  As a user
  I want to be able to search in my own language

  Scenario Outline: Language aware topic search
    Given I am logged in as a user with the "administrator" role
    Given "topic" content:
      | title         | language | status | workbench_moderation_state_new |
      | <sourcetitle> | en       | 1      | published                      |
    And the "<language>" language is available
    And I go to "/topics_en"
    Then I should see "<sourcetitle>"
    When I fill in "edit-combine" with "<sourcetitle>"
    And I press "edit-submit-topics"
    Then I should see "<sourcetitle>" in the ".view-id-topics .view-content" element
    When I follow "<sourcetitle>"
    And I go to add "<language>" translation
    And I fill in "edit-title-field-<language>-0-value" with "<title>"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    And I go to "/topics_<language>"
    Then I should see "<title>"
    When I fill in "edit-combine" with "<search>"
    And I press "edit-submit-topics"
    Then I should see "<title>" in the ".view-id-topics .view-content" element

    Examples:
      | sourcetitle    | title        | language | search     |
      | Example title1 | Околна среда | bg       | Околна     |
      | Example title2 | Περιβάλλον   | el       | Περιβάλλον |

  Scenario Outline: Language aware announcement search
    Given I am logged in as a user with the "administrator" role
    Given "announcement" content:
      | title         | body | language | status | workbench_moderation_state_new | field_announcement_type | field_announcement_location | field_core_introduction | field_core_type_content          |
      | <sourcetitle> | bar  | en       | 1      | published                      | speech                  | Brussels                    | bar                     | A page (default) in this website |
    And the "<language>" language is available
    And I go to "/announcements_en"
    Then I should see "<sourcetitle>"
    When I fill in "edit-combine" with "<sourcetitle>"
    And I press "Refine results"
    Then I should see "<sourcetitle>" in the ".view-id-announcements .view-content" element
    When I follow "<sourcetitle>"
    And I go to add "<language>" translation
    And I fill in "edit-title-field-<language>-0-value" with "<title>"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    And I go to "/announcements_<language>"
    Then I should see "<title>"
    When I fill in "edit-combine" with "<search>"
    And I press "Refine results"
    Then I should see "<title>" in the ".view-id-announcements .view-content" element

    Examples:
      | sourcetitle         | title        | language | search     |
      | Announcement title1 | Околна среда | bg       | Околна     |
      | Announcement title2 | Περιβάλλον   | el       | Περιβάλλον |
