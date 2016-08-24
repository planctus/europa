@api @information
Feature: Checking different state of events
  In order to fill in an event
  I should be able to see different buttons or messages

  Scenario Outline: Status messages before event.
  Before the event:
  - Current time < Event start time
  Status message:
  - Status field: "no", then see no message.
  - Status field: "reschedule", then see message: "The event has been rescheduled".
  - Status field: "cancelled", then see message: "The event has been cancelled".
    Given I am viewing an "Event" content:
      | title                     | <title>         |
      | field_event_status        | <event_status>  |
      | field_event_date:value    | 1893456000      |
      | field_event_date:value2   | 1893456000      |
      | field_event_date:timezone | Europe/Budapest |
      | status                    | 1               |
    Then I should <is_message> the css selector ".field--dt-event-status-message-1"
    Then I should <is_message> "<message>"
    Examples:
      | title                              | event_status         | is_message | message                         |
      | Event status test: no extra status | no                   | not see    | Not relevant.                   |
      | Event status test: rescheduled     | event is rescheduled | see        | This event has been rescheduled |
      | Event status test: cancelled       | event is cancelled   | see        | This event has been cancelled   |

  # "Book your seat" should appears.
  Scenario: "Book your seat" button should appears.
  "Book your seat" button displaying criteria:
  - Before the event or event is ongoing.
  - Have registration link, minimum the link.
  - Have registration deadline, but the deadline is following the current time, or there is no registration deadline.
  - Not "Fully booked".
  - When the event status is not "cancelled".
    Given I am viewing an "Event" content:
      | title                                 | Book your seat test, button should appears, link and title |
      | field_event_status                    | no                                                         |
      | field_event_is_fully_booked           | no                                                         |
      | field_event_registration              | Registration title - http://localhost                      |
      | field_event_registration_end:value    | 1893456000                                                 |
      | field_event_registration_end:timezone | Europe/Budapest                                            |
      | field_event_date:value                | 1893456000                                                 |
      | field_event_date:value2               | 1893456000                                                 |
      | field_event_date:timezone             | Europe/Budapest                                            |
      | status                                | 1                                                          |
    Then I should see the link "Registration title"

  # "Book your seat" should appears.
  Scenario: "Book your seat" button should appears, when only registration link added.
    Given I am logged in as a user with the "administrator" role
    And I go to "node/add/event"
    And I fill in the following:
      | title_field[und][0][value]                               | Book your seat test, button should appears only with link |
      | field_event_status[und]                                  | no                                                        |
      | field_event_is_fully_booked[und]                         | 0                                                         |
      | field_event_registration[und][0][url]                    | http://localhost                                          |
      | field_event_registration_end[und][0][value][date]        | 01/01/2030                                                |
      | field_event_registration_end[und][0][value][time]        | 10:00                                                     |
      | field_event_registration_end[und][0][timezone][timezone] | Europe/Budapest                                           |
      | field_event_date[und][0][value][date]                    | 01/01/2030                                                |
      | field_event_date[und][0][value][time]                    | 10:00                                                     |
      | field_event_date[und][0][timezone][timezone]             | Europe/Budapest                                           |
      | workbench_moderation_state_new                           | published                                                 |
    And I press "Save"
    Then I should see the link "Book your seat"

  # Status: "cancelled'.
  Scenario: "Book your seat" button should not appears, when event status is "cancelled".
    Given I am viewing an "Event" content:
      | title                       | Book your seat test, status is cancelled |
      | field_event_status          | event is cancelled                       |
      | field_event_is_fully_booked | no                                       |
      | field_event_registration    | Registration title - http://localhost    |
      | field_event_date:value      | 1893456000                               |
      | field_event_date:value2     | 1893456000                               |
      | field_event_date:timezone   | Europe/Budapest                          |
      | status                      | 1                                        |
    Then I should not see the link "Registration title"


  # Fully booked.
  Scenario: "Book your seat" button should not appears, when event is fully booked.
    Given I am viewing an "Event" content:
      | title                       | Book your seat test, fully booked     |
      | field_event_status          | no                                    |
      | field_event_is_fully_booked | yes                                   |
      | field_event_registration    | Registration title - http://localhost |
      | field_event_date:value      | 1893456000                            |
      | field_event_date:value2     | 1893456000                            |
      | field_event_date:timezone   | Europe/Budapest                       |
      | status                      | 1                                     |
    Then I should not see the link "Registration title"

  # Following registration deadline.
  Scenario: "Book your seat" button should not appears, after registration deadline.
    Given I am viewing an "Event" content:
      | title                                 | Book your seat test, after registration deadline |
      | field_event_status                    | no                                               |
      | field_event_is_fully_booked           | no                                               |
      | field_event_registration              | Registration title - http://localhost            |
      | field_event_registration_end:value    | 42854400                                         |
      | field_event_registration_end:timezone | Europe/Budapest                                  |
      | field_event_date:value                | 1893456000                                       |
      | field_event_date:value2               | 1893456000                                       |
      | field_event_date:timezone             | Europe/Budapest                                  |
      | status                                | 1                                                |
    Then I should not see the link "Registration title"


  # Registration link is missing.
  Scenario: "Book your seat" button should not appears, when registration link is missing.
    Given I am viewing an "Event" content:
      | title                       | Book your seat test, registration link is missing |
      | field_event_status          | no                                                |
      | field_event_is_fully_booked | no                                                |
      | field_event_date:value      | 1893456000                                        |
      | field_event_date:value2     | 1893456000                                        |
      | field_event_date:timezone   | Europe/Budapest                                   |
      | status                      | 1                                                 |
    Then I should not see the link "Registration title"

  # "Watch live" button.
  Scenario: "Watch live" button should appears.
  In case of the following conjunction:
  - "Live streaming available": yes.
  - "Date and time of live streaming" current moment is between start and end time of live streaming.
  - When the event status is not "cancelled".
  - "Live streaming link" is given.
    Given I am viewing an "Event" content:
      | title                                       | Watch live streaming test, button should appears |
      | field_event_status                          | no                                               |
      | field_event_is_live_streaming               | yes                                              |
      | field_event_live_streaming_date:show_todate | 1                                                |
      | field_event_live_streaming_date:value       | 42854400                                         |
      | field_event_live_streaming_date:value2      | 1893456000                                       |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                                  |
      | field_event_live_streaming_link             | http://localhost                                 |
      | field_event_date:value                      | 1893456000                                       |
      | field_event_date:value2                     | 1893456000                                       |
      | field_event_date:timezone                   | Europe/Budapest                                  |
      | status                                      | 1                                                |
    Then I should see the link "Watch live"

  # Event cancelled.
  Scenario: "Watch live" button should not appears, when the event "cancelled".
    Given I am viewing an "Event" content:
      | title                                       | Watch live streaming test, event cancelled |
      | field_event_status                          | event is cancelled                         |
      | field_event_is_live_streaming               | yes                                        |
      | field_event_live_streaming_date:show_todate | 1                                          |
      | field_event_live_streaming_date:value       | 42854400                                   |
      | field_event_live_streaming_date:value2      | 1893456000                                 |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                            |
      | field_event_live_streaming_link             | http://localhost                           |
      | field_event_date:value                      | 1893456000                                 |
      | field_event_date:value2                     | 1893456000                                 |
      | field_event_date:timezone                   | Europe/Budapest                            |
      | status                                      | 1                                          |
    Then I should not see the link "Watch live"

  # No live streaming.
  Scenario: "Watch live" button should not appears, when there is no live streaming.
    Given I am viewing an "Event" content:
      | title                                       | Watch live streaming test, no live streaming |
      | field_event_status                          | no                                           |
      | field_event_is_live_streaming               | no                                           |
      | field_event_live_streaming_date:show_todate | 1                                            |
      | field_event_live_streaming_date:value       | 42854400                                     |
      | field_event_live_streaming_date:value2      | 1893456000                                   |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                              |
      | field_event_live_streaming_link             | http://localhost                             |
      | field_event_date:value                      | 1893456000                                   |
      | field_event_date:value2                     | 1893456000                                   |
      | field_event_date:timezone                   | Europe/Budapest                              |
      | status                                      | 1                                            |
    Then I should not see the link "Watch live"

  # Current time is before broadcasting start.
  Scenario: "Watch live" button should not appears, when current time is before is before broadcasting start.
    Given I am viewing an "Event" content:
      | title                                    | Watch live streaming test, current time is before broadcasting start |
      | field_event_status                       | no                                                                   |
      | field_event_is_live_streaming            | yes                                                                  |
      | field_event_live_streaming_date:value    | 1893456000                                                           |
      | field_event_live_streaming_date:value2    | 1893456000                                                           |
      | field_event_live_streaming_date:timezone | Europe/Budapest                                                      |
      | field_event_live_streaming_link          | http://localhost                                                     |
      | field_event_date:value                   | 1893456000                                                           |
      | field_event_date:value2                  | 1893456000                                                           |
      | field_event_date:timezone                | Europe/Budapest                                                      |
      | status                                   | 1                                                                    |
    Then I should not see the link "Watch live"

  # Current time is outside of broadcasting interval.
  Scenario: "Watch live" button should not appears, when current time is outside of broadcasting interval.
    Given I am viewing an "Event" content:
      | title                                       | Watch live streaming test, current time is outside of broadcasting interval |
      | field_event_status                          | no                                                                          |
      | field_event_is_live_streaming               | yes                                                                         |
      | field_event_live_streaming_date:show_todate | 1                                                                           |
      | field_event_live_streaming_date:value       | 1893456000                                                                  |
      | field_event_live_streaming_date:value2      | 1893456001                                                                  |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                                                             |
      | field_event_live_streaming_link             | http://localhost                                                            |
      | field_event_date:value                      | 1893456000                                                                  |
      | field_event_date:value2                     | 1893456000                                                                  |
      | field_event_date:timezone                   | Europe/Budapest                                                             |
      | status                                      | 1                                                                           |
    Then I should not see the link "Watch live"

  # There is no stream link given.
  Scenario: "Watch live" button should not appears, when no stream link.
    Given I am viewing an "Event" content:
      | title                                       | Watch live streaming test, no stream link |
      | field_event_status                          | no                                        |
      | field_event_is_live_streaming               | yes                                       |
      | field_event_live_streaming_date:show_todate | 1                                         |
      | field_event_live_streaming_date:value       | 42854400                                  |
      | field_event_live_streaming_date:value2      | 1893456000                                |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                           |
      | field_event_date:value                      | 1893456000                                |
      | field_event_date:value2                     | 1893456000                                |
      | field_event_date:timezone                   | Europe/Budapest                           |
      | status                                      | 1                                         |
    Then I should not see the link "Watch live"
