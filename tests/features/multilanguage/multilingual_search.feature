@api @information @political @dt_core
Feature: Search in views in any given language
  To deliver the best user experience
  As a user
  I want to be able to search in my own language

  @dt_topic
  Scenario Outline: Language aware topic search
    Given I am logged in as a user with the "administrator" role
    Given "Topic" content:
      | title         | language | status |
      | <sourcetitle> | en       | 1      |
    And the "<language>" language is available
    And I go to "/topics_en"
    Then I should see "<sourcetitle>"
    When I fill in "by keyword" with "<sourcetitle>"
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
      | sourcetitle  | title        | language | search     |
      | Topic title1 | Околна среда | bg       | Околна     |
      | Topic title2 | Περιβάλλον   | el       | Περιβάλλον |

  @dt_announcement
  Scenario Outline: Language aware announcement search
    Given I am logged in as a user with the "administrator" role
    Given "Announcement" content:
      | title         | body | language | status | field_announcement_type | field_announcement_location | field_core_introduction | field_core_type_content          |
      | <sourcetitle> | bar  | en       | 1      | speech                  | Brussels                    | bar                     | A page (default) in this website |
    And the "<language>" language is available
    And I go to "/news_en"
    Then I fill in the following:
      | Containing | <sourcetitle> |
    Then I press "Refine results"
    Then I should see "<sourcetitle>"
    When I fill in "edit-combine" with "<sourcetitle>"
    And I press "edit-submit-announcements"
    Then I should see "<sourcetitle>" in the ".view-id-announcements .view-content" element
    When I follow "<sourcetitle>"
    And I go to add "<language>" translation
    And I fill in "edit-title-field-<language>-0-value" with "<title>"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    And I go to "/news_<language>"
    Then I fill in the following:
      | Containing | <search> |
    Then I press "edit-submit-announcements"
    Then I should see "<title>"
    When I fill in "edit-combine" with "<search>"
    And I press "edit-submit-announcements"
    Then I should see "<title>" in the ".view-id-announcements .view-content" element

    Examples:
      | sourcetitle         | title        | language | search     |
      | Announcement title1 | Околна среда | bg       | Околна     |
      | Announcement title2 | Περιβάλλον   | el       | Περιβάλλον |

  @dt_policy @dt_policy_area @dt_department @dt_person
  Scenario Outline: Language aware policy search
    Given I am logged in as a user with the "administrator" role
    Given "Policy area" content:
      | title      |
      | PolicyArea |
    Given "Department" content:
      | title      |
      | Department |
    Given "Person" content:
      | title  | field_person_role |
      | Person | Commissioner      |
    Given "Policy" content:
      | title         | field_policy_detail_body | language | status | field_policy_detail_objectives | field_policy_sharable_banner | field_core_department | field_core_persons | field_core_policy_areas | field_core_introduction |
      | <sourcetitle> | bar                      | en       | 1      | Detail objective               | no sharable banner           | Department            | Person             | PolicyArea              | Intro                   |
    And the "<language>" language is available
    And I go to "/policies_en"
    Then I should see "<sourcetitle>"
    When I fill in "edit-keyword" with "<sourcetitle>"
    And I press "edit-submit-policy-overview"
    Then I should see "<sourcetitle>" in the ".view-id-policy_overview .view-content" element
    When I follow "<sourcetitle>"
    And I go to add "<language>" translation
    And I fill in "edit-title-field-<language>-0-value" with "<title>"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    And I go to "/policies_<language>"
    Then I should see "<title>"
    When I fill in "edit-keyword" with "<search>"
    And I press "edit-submit-policy-overview"
    Then I should see "<title>" in the ".view-id-policy_overview .view-content" element

    Examples:
      | sourcetitle   | title        | language | search     |
      | Policy title1 | Околна среда | bg       | Околна     |
      | Policy title2 | Περιβάλλον   | el       | Περιβάλλον |
