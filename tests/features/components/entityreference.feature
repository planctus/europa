@api @information
Feature: Entityreference
  In order to reference content
  As an editor
  I should be able to reference entities using an autocomplete widget

  @javascript @dt_topic @dt_page
  Scenario: Entityreference widgets shows the content type and ID when selecting a node
    Given "Topic" content:
      | title             | language | status | nid   | is_new |
      | Topic title       | en       | 1      | 9890  | 1      |
      | Alternative title | en       | 1      | 10000 | 1      |
    And I am logged in as a user with the "administrator" role
    And I am viewing a "Page" content:
      | title             | Page title  |
      | language          | en          |
      | status            | 1           |
      | field_core_topics | Topic title |
    And I click "New draft" in the "tabs" region
    And I click "Related"
    And I wait for AJAX to finish
    Then the "field_core_topics[und][0][target_id]" field should contain "Topic title (Topic) (9890)"
    And I select the first autocomplete option for "Alternative title" on the "field_core_topics[und][1][target_id]" field
    Then the "field_core_topics[und][1][target_id]" field should contain "Alternative title (Topic - 10000) (10000)"

  @dt_person @dt_event
  Scenario: Event speakers entity reference field is translated
    Given I am logged in as a user with the "administrator" role
    And "Person" content:
      | title                        | field_person_first_name | field_person_last_name | field_person_role | status |
      | Commissioner John Weekley EN | John                    | Weekley                | Commissioner      | 1      |
    And I am viewing an "Event" content:
      | title                       | Translate speaker                     |
      | language                    | en                                    |
      | field_event_status          | no                                    |
      | field_event_is_fully_booked | no                                    |
      | field_event_registration    | Registration title - http://localhost |
      | field_event_date:value      | 1893456000                            |
      | field_event_date:value2     | 1893456000                            |
      | field_event_date:timezone   | Europe/Budapest                       |
      | status                      | 1                                     |
      | field_event_speakers        | Commissioner John Weekley EN          |
    Then I follow "New draft" in the "tabs"
    Then I go to add "hu" translation
    And I fill in "description" with "test"
    And I fill in "edit-title-field-hu-0-value" with "Translate speakers HU"
    And I fill in "edit-field-event-speakers-hu-0-er-override-field-person-role-title" with "Dr Hungarian"
    And I fill in "Moderation state" with "published"
    And I select "Global editorial team" from "Your groups (all languages)"
    And I press "Save"
    Then I should see "Dr Hungarian"
    Then I should see "John"
    Then I should see "Weekley"
