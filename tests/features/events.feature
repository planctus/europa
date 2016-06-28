@api @information
Feature: Events listing
  As a user
  I want to be able to see and filter events using facets.

  Background:
    Given "Topic" content:
      | title  |
      | Energy |
      | Food   |

    Given "Department" content:
      | title         |
      | Budget        |
      | ClimateAction |

    Given "Event types" terms:
      | name       |
      | Dialogue   |
      | Conference |

    Given I am logged in as a user with the "administrator" role
    And "Event" content:
      | title        | status | field_core_description   | field_event_status | field_core_topics | field_core_departments | field_event_is_online | field_event_is_live_streaming | field_event_type | field_event_date |
      | Energy event | 1      | Energy event description | no                 | Energy            | Budget                 | yes                   | no                            | Dialogue         | 1469952000       |
      | Food event   | 1      | Food event description   | no                 | Food              | ClimateAction          | no                    | yes                           | Conference       | 1469952000       |
      | Extra event  | 1      | Extra event description  | no                 | Food              | ClimateAction          | no                    | yes                           | Conference       | 1469952000       |
    And I index all indexes

  Scenario: On the events listing page I should see the events.
    Given I am on "events"
    Then I should see "Energy event"
    And I should see "Food event"

  Scenario: On the events listing page I should see all the filters.
    Given I am on "events"
    Then I should see "Online events only"
    And I should see "Online events with live streaming available"
    # Here we test select values, simply be selecting them.
    # If they are there, these will not show any error.
    And I select "Energy" from "Topic"
    And I select "Food" from "Topic"
    And I select "Dialogue" from "Event type"
    And I select "Conference" from "Event type"
    And I select "Budget" from "Organizer"
    And I select "ClimateAction" from "Organizer"

  Scenario Outline: I should be able to filter by various filters on the event listing page (select)
    Given I am on "Events"
    And I select "<first_value>" from "<filter>"
    And I press the "Refine results" button
    Then I should <first_value_energy> "Energy event"
    Then I should <first_value_food> "Food event"
    And I select "<all_value>" from "<filter>"
    And I press the "Refine results" button
    And I select "<second_value>" from "<filter>"
    And I press the "Refine results" button
    Then I should <second_value_energy> "Energy event"
    Then I should <second_value_food> "Food event"

    Examples:
      | filter     | all_value     | first_value | first_value_energy | first_value_food | second_value  | second_value_energy | second_value_food |
      | Topic      | Any topic     | Energy      | see                | not see          | Food          | not see             | see               |
      | Event type | Any type      | Conference  | not see            | see              | Dialogue      | see                 | not see           |
      | Organizer  | Any organiser | Budget      | see                | not see          | ClimateAction | not see             | see               |

  Scenario: I should be able to filter by online only (checkbox)
    Given I am on "Events"
    And I check the box "Online events only"
    And I press the "Refine results" button
    Then I should see "Energy event"
    Then I should not see "Food event"

  Scenario: I should be able to filter by livestream (checkbox)
    Given I am on "Events"
    And I check the box "Online events with live streaming available"
    And I press the "Refine results" button
    Then I should not see "Energy event"
    Then I should see "Food event"

  Scenario: I should be able to filter by a combination of facets and views
    Given I am on "Events"
    And I check the box "Online events with live streaming available"
    And I press the "Refine results" button
    Then I should not see "Energy event"
    Then I should see "Food event"
    Then I should see "Extra event"
    And I fill in "Contains" with "Extra"
    And I press the "Refine results" button
    Then I should not see "Energy event"
    Then I should not see "Food event"
    Then I should see "Extra event"
