@api @information
Feature: Timeline schedule field formatter
  In order show information on a timeline
  As a content editor
  I want to display info on a timeline with specific time and time zone.

  Scenario: Timeline schedule variant is available
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule_en"
    Then I should see "Timeline schedule" in the "#field-ui-field-edit-form" element

  Scenario: Timeline schedule variant contains an option for a time zone functionality
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/structure/types/manage/event/fields/field_event_schedule_en"
    And I check the box "instance[widget][settings][timezone]"
    Then I should see "Use timezone functionality"
