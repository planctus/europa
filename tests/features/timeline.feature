@api @information
Feature: Timeline schedule field formatter
  In order show information on a timeline
  As a content editor
  I want to display info on a timeline with specific time and time zone.

  Scenario: Timeline schedule variant is available
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    Then I should see "Timeline schedule" in the "#field-ui-field-edit-form" element

  Scenario: Timeline schedule variant option setting saves correctly
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    And I select the "Timeline Schedule" radio button.
    And I press the "Save settings" button
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    Then radio button with label "Timeline Schedule" should be checked

  Scenario: Timeline schedule variant contains an option for a time zone functionality
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    And I check the box "instance[widget][settings][timezone]"
    Then I should see "Use timezone functionality"

  Scenario: Timeline schedule widget time zone functionality saves configuration settings
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    And I uncheck the box "instance[widget][settings][timezone]"
    And I press the "Save settings" button
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    Then the "instance[widget][settings][timezone]" checkbox should not be checked
    Then show last response

  Scenario: Timeline schedule widget input should contain a select for a timezone
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule"
    And I check the box "instance[widget][settings][timezone]"
    And I press the "Save settings" button
    When I go to "node/add/event_en"
    Then I should see "Timezone"

  Scenario: Timeline schedule widget input should contain "Schedule item start"
    Given I am logged in as a user with the "administrator" role
    When I go to "node/add/event"
    Then I should see "Schedule item start"

  Scenario: Timeline schedule widget input should contain "Schedule item end"
    Given I am logged in as a user with the "administrator" role
    When I go to "node/add/event"
    Then I should see "Schedule item end"

  Scenario: Event content can be saved with timeline schedule widget
    Given I am viewing an "Event" content:
      | title    | Event saving success |
      | status   | 1                    |
    And I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    And I follow "Event saving success"
    Then I should see text matching "Event saving success"
