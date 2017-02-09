@api @information @dt_event @dt_topic @dt_department
Feature: Checking different state of events
  In order to fill in an event
  I should be able to see different buttons or messages

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

    Given "Event" content:
      | title        | status | field_core_topics | field_core_departments | field_event_is_online | field_event_is_live_streaming | field_event_live_streaming_link | field_event_type | field_event_date:value | field_event_date:value2 | field_event_date:timezone | field_event_date:offset | field_event_date:offset2 | field_core_location               | language |
      | Energy event | 1      | Energy            | Budget                 | yes                   | no                            | N/A                             | Dialogue         | 1969952000             | 1969952000              | Europe/Budapest           | 3600                    | 3600                     | country: BE - locality: Brussel   | en       |
      | Food event   | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1969966401             | 1969966401              | Europe/Budapest           | 3600                    | 3600                     | country: NL - locality: Amsterdam | en       |
      | Extra event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1969952001             | 1969952001              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris     | en       |
    And I index all indexes

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
    Then I should <is_message> an ".field--dt-event-status-message-1" element
    Then I should <is_message> "<message>"
    Examples:
      | title                              | event_status         | is_message | message                         |
      | Event status test: no extra status | no                   | not see    | Not relevant.                   |
      | Event status test: rescheduled     | event is rescheduled | see        | This event has been rescheduled |
      | Event status test: cancelled       | event is cancelled   | see        | This event has been cancelled   |

  # "Book your seat" should appear.
  Scenario: "Book your seat" button should appear and be translatable.
  "Book your seat" button displaying criteria:
  - Before the event or event is ongoing.
  - Have registration link, minimum the link.
  - Have registration deadline, but the deadline is following the current time, or there is no registration deadline.
  - Not "Fully booked".
  - When the event status is not "cancelled".
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "Event" content:
      | title                                 | Book your seat test, button should appears, link and title |
      | field_event_status                    | no                                                         |
      | field_event_is_fully_booked           | no                                                         |
      | field_event_registration              | Registration title - http://google.com                     |
      | field_event_registration_end:value    | 1893456000                                                 |
      | field_event_registration_end:timezone | Europe/Budapest                                            |
      | field_event_date:value                | 1893456000                                                 |
      | field_event_date:value2               | 1893456000                                                 |
      | field_event_date:timezone             | Europe/Budapest                                            |
      | status                                | 1                                                          |
      | language                              | en                                                         |
    Then I should see the link "Registration title" linking to "http://google.com"
    Then I should see "Book your seat test, button should appears, link and title"
    And I go to add "nl" translation
    And I fill in "title_field[nl][0][value]" with "Reserveer je zit test, knop zichtbaar, link en titel"
    And I fill in "field_event_registration[nl][0][title]" with "Registratie titel"
    And I fill in "field_event_registration[nl][0][url]" with "http://google.be"
    And I select "Global editorial team" from "Your groups (all languages)"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    Then I should see "Reserveer je zit test, knop zichtbaar, link en titel"
    Then I should see the link "Registratie titel" linking to "http://google.be"

  # "Book your seat" should appear.
  Scenario: "Book your seat" can link to an e-mail address
    Given I am viewing an "Event" content:
      | title                                 | Book your seat test, button should appears, link and title |
      | field_event_status                    | no                                                         |
      | field_event_is_fully_booked           | no                                                         |
      | field_event_registration              | Registration title - mailto:info@ec.europa.eu              |
      | field_event_registration_end:value    | 1893456000                                                 |
      | field_event_registration_end:timezone | Europe/Budapest                                            |
      | field_event_date:value                | 1893456000                                                 |
      | field_event_date:value2               | 1893456000                                                 |
      | field_event_date:timezone             | Europe/Budapest                                            |
      | status                                | 1                                                          |
    Then I should see the link "Registration title" linking to "mailto:info@ec.europa.eu"

  # "Book your seat" should appear.
  Scenario: "Book your seat" button should appear, when only registration link added.
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
  Scenario: "Book your seat" button should not appear, when event status is "cancelled".
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
  Scenario: "Book your seat" button should not appear, when event is fully booked.
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
  Scenario: "Book your seat" button should not appear, after registration deadline.
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
  Scenario: "Book your seat" button should not appear, when registration link is missing.
    Given I am viewing an "Event" content:
      | title                       | Book your seat test, registration link is missing |
      | field_event_status          | no                                                |
      | field_event_is_fully_booked | no                                                |
      | field_event_date:value      | 1893456000                                        |
      | field_event_date:value2     | 1893456000                                        |
      | field_event_date:timezone   | Europe/Budapest                                   |
      | status                      | 1                                                 |
    Then I should not see the link "Registration title"

  # Past event with social media profile links box.
  Scenario: Event is in the past, should see social media profile links box.
    Given I am viewing an "Event" content:
      | title                                 | Event is in the past |
      | field_event_status                    | no                   |
      | field_event_is_fully_booked           | no                   |
      | field_event_date:value                | 1472724000           |
      | field_event_date:value2               | 1472724000           |
      | field_event_date:timezone             | Europe/Budapest      |
      | field_core_social_network_links:title | Facebook             |
      | field_core_social_network_links:url   | fb.com               |
      | status                                | 1                    |
    Then I should see "Follow the latest progress and get involved."

  # Past event with publications.
  Scenario: Event is in the past, should see publications.
    Given "Publication" content:
      | title                  | status |
      | Publication test title | 1      |
    And I am viewing an "Event" content:
      | title                       | Event is in the past   |
      | field_event_status          | no                     |
      | field_event_is_fully_booked | no                     |
      | field_event_date:value      | 1472724000             |
      | field_event_date:value2     | 1472724000             |
      | field_event_date:timezone   | Europe/Budapest        |
      | status                      | 1                      |
      | field_core_publications     | Publication test title |
    Then I should see "Publication test title"

  # "Watch live streaming" button.
  Scenario: "Watch live streaming" button should appear on ongoing event.
  In case of the following conjunction:
  - "Live streaming available": yes.
  - "Date and time of live streaming" current moment is between start and end time of live streaming.
  - When the event status is not "cancelled".
  - "Live streaming link" is given.
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "Event" content:
      | title                                       | Watch live test, button should appear |
      | field_event_status                          | no                                    |
      | field_event_is_online                       | no                                    |
      | field_event_is_live_streaming               | yes                                   |
      | field_event_live_streaming_date:show_todate | 1                                     |
      | field_event_live_streaming_date:value       | 1420070400                            |
      | field_event_live_streaming_date:value2      | 1893456000                            |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                       |
      | field_event_live_streaming_link             | http://localhost                      |
      | field_event_date:value                      | 1420070400                            |
      | field_event_date:value2                     | 1893456000                            |
      | field_event_date:timezone                   | Europe/Budapest                       |
      | field_core_location                         | country: FR - locality: Paris         |
      | status                                      | 1                                     |
    Then I should see the link "Watch live streaming"
    Then I should see "This event has started"
    Then I should see a ".field--dt-event-status-message-2 .messages--icon-center.live a" element
    Then I should see "Watch live streaming" in the ".messages--icon-center.live" element
    And I translate the string "live streaming available" to "French" with "diffusion en direct disponible"
    And I index all indexes
    And I go to "events"
    Then I should see the link "Watch live streaming"
    Then I change the language to "French"
    Then I should see "diffusion en direct disponible" in the ".icon.icon--livestreaming.icon--text-small" element

  # Event translations
  Scenario: "Watch live streaming", "Live: @title", "Related events", "Topic" should be translatable.
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "Event" content:
      | title                                       | Watch live test, button should appear |
      | field_event_status                          | no                                    |
      | field_event_is_online                       | no                                    |
      | field_event_is_live_streaming               | yes                                   |
      | field_event_type                            | Conference                            |
      | field_event_live_streaming_date:show_todate | 1                                     |
      | field_event_live_streaming_date:value       | 1420070400                            |
      | field_event_live_streaming_date:value2      | 1893456000                            |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                       |
      | field_event_live_streaming_link             | http://localhost                      |
      | field_core_departments                      | ClimateAction                         |
      | field_core_topics                           | Energy                                |
      | field_event_date:value                      | 1420070400                            |
      | field_event_date:value2                     | 1893456000                            |
      | field_event_date:timezone                   | Europe/Budapest                       |
      | field_core_location                         | country: FR - locality: Paris         |
      | status                                      | 1                                     |
      | language                                    | en                                    |
    And I translate the string "Live: @title" to "French" with "En direct: @title"
    And I translate the string "Watch live streaming" to "French" with "Regarder en direct"
    And I translate the string "Topic" to "French" with "Topique"
    And I translate the string "live streaming available" to "French" with "diffusion en direct disponible"
    And I translate the string "Live from @location" to "French" with "En direct de @location"
    And I go to add "fr" translation
    And I fill in "title_field[fr][0][value]" with "Regarder le test en direct, le bouton doit apparaître"
    And I fill in "field_event_live_streaming_link[fr][0][url]" with "http://localhost_fr"
    And I select "Global editorial team" from "Your groups (all languages)"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see "Topique" in the ".context-nav .context-nav__label" element
    Then I should see "diffusion en direct disponible" in the ".icon.icon--livestreaming.page-header__livestreaming" element
    Then I follow "Regarder en direct"
    Then I should see the heading "En direct: Regarder le test en direct, le bouton doit apparaître"
    Then I should see the heading "En direct de Paris"

  # Event cancelled.
  Scenario: "Watch live streaming" button should not appear, when the event "cancelled".
    Given I am viewing an "Event" content:
      | title                                       | Live streaming test, event cancelled |
      | field_event_status                          | event is cancelled                   |
      | field_event_is_live_streaming               | yes                                  |
      | field_event_live_streaming_date:show_todate | 1                                    |
      | field_event_live_streaming_date:value       | 42854400                             |
      | field_event_live_streaming_date:value2      | 1893456000                           |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                      |
      | field_event_live_streaming_link             | http://localhost                     |
      | field_event_date:value                      | 1893456000                           |
      | field_event_date:value2                     | 1893456000                           |
      | field_event_date:timezone                   | Europe/Budapest                      |
      | status                                      | 1                                    |
    Then I should not see the link "Watch live streaming"
    And I index all indexes
    And I go to "events"
    Then I should not see the link "Watch live streaming"

  # No live streaming.
  Scenario: "Watch live streaming" button should not appear, when there is no live streaming.
    Given I am viewing an "Event" content:
      | title                                       | Live streaming test, no live streaming |
      | field_event_status                          | no                                     |
      | field_event_is_live_streaming               | no                                     |
      | field_event_live_streaming_date:show_todate | 1                                      |
      | field_event_live_streaming_date:value       | 42854400                               |
      | field_event_live_streaming_date:value2      | 1893456000                             |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                        |
      | field_event_live_streaming_link             | http://localhost                       |
      | field_event_date:value                      | 1893456000                             |
      | field_event_date:value2                     | 1893456000                             |
      | field_event_date:timezone                   | Europe/Budapest                        |
      | status                                      | 1                                      |
    Then I should not see the link "Watch live streaming"
    And I index all indexes
    And I go to "events"
    Then I should not see the link "Watch live streaming"

  # Current time is before broadcasting start.
  Scenario: "Watch live streaming" button should not appear, when current time is before is before broadcasting start.
    Given I am viewing an "Event" content:
      | title                                    | Live streaming test, current time is before broadcasting start |
      | field_event_status                       | no                                                             |
      | field_event_is_live_streaming            | yes                                                            |
      | field_event_live_streaming_date:value    | 1893456000                                                     |
      | field_event_live_streaming_date:value2   | 1893456000                                                     |
      | field_event_live_streaming_date:timezone | Europe/Budapest                                                |
      | field_event_live_streaming_link          | http://localhost                                               |
      | field_event_date:value                   | 1893456000                                                     |
      | field_event_date:value2                  | 1893456000                                                     |
      | field_event_date:timezone                | Europe/Budapest                                                |
      | status                                   | 1                                                              |
    Then I should not see the link "Watch live streaming"
    And I index all indexes
    And I go to "events"
    Then I should not see the link "Watch live streaming"

  # Current time is outside of broadcasting interval.
  Scenario: "Watch live streaming" button should not appear, when current time is outside of broadcasting interval.
    Given I am viewing an "Event" content:
      | title                                       | Live streaming test, current time is outside of broadcasting interval |
      | field_event_status                          | no                                                                    |
      | field_event_is_live_streaming               | yes                                                                   |
      | field_event_live_streaming_date:show_todate | 1                                                                     |
      | field_event_live_streaming_date:value       | 1893456000                                                            |
      | field_event_live_streaming_date:value2      | 1893456001                                                            |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                                                       |
      | field_event_live_streaming_link             | http://localhost                                                      |
      | field_event_date:value                      | 1893456000                                                            |
      | field_event_date:value2                     | 1893456000                                                            |
      | field_event_date:timezone                   | Europe/Budapest                                                       |
      | status                                      | 1                                                                     |
    Then I should not see the link "Watch live streaming"
    And I index all indexes
    And I go to "events"
    Then I should not see the link "Watch live streaming"

  # There is no stream link given.
  Scenario: "Watch live streaming" button should not appear, when no stream link.
    Given I am viewing an "Event" content:
      | title                                       | Live streaming test, no stream link |
      | field_event_status                          | no                                  |
      | field_event_is_live_streaming               | yes                                 |
      | field_event_live_streaming_date:show_todate | 1                                   |
      | field_event_live_streaming_date:value       | 42854400                            |
      | field_event_live_streaming_date:value2      | 1893456000                          |
      | field_event_live_streaming_date:timezone    | Europe/Budapest                     |
      | field_event_date:value                      | 1893456000                          |
      | field_event_date:value2                     | 1893456000                          |
      | field_event_date:timezone                   | Europe/Budapest                     |
      | status                                      | 1                                   |
    Then I should not see the link "Watch live streaming"
    And I index all indexes
    And I go to "events"
    Then I should not see the link "Watch live streaming"

  Scenario: Event collection "Upcoming events", "Related events" and "About @title" should be translatable.
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "Event" content:
      | title                       | Event collection                      |
      | body:value                  | Event collection body description     |
      | body:format                 | full_html                             |
      | field_event_collection      | A collection with multiple events     |
      | field_event_children_events | Energy event, Food event, Extra event |
      | status                      | 1                                     |
      | language                    | en                                    |
    Then I should see an ".field--current-and-upcoming-events" element
    Then I should see the following in the repeated ".listing__title" element within the context of the ".field--current-and-upcoming-events" element:
      | text         |
      | Energy event |
      | Extra event  |
      | Food event   |
    And I translate the string "About @title" to "French" with "Environ @title"
    And I translate the string "Related events" to "French" with "Evénements associés"
    And I go to add "fr" translation
    And I fill in "title_field[fr][0][value]" with "Collection d'événements"
    And I select "Global editorial team" from "Your groups (all languages)"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see the heading "Environ Collection d'événements"
    Then I follow "Energy event"
    And I go to add "fr" translation
    And I fill in "title_field[fr][0][value]" with "Événement d'énergie"
    And I fill in "field_event_live_streaming_link[fr][0][url]" with "http://localhost_fr"
    And I select "Global editorial team" from "Your groups (all languages)"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see the heading "Evénements associés"
    And I should not see the text "%26lt"
    And I should not see the text "aucun"

  Scenario: Empty event collection should display no results messages
    Given I am viewing an "Event" content:
      | title                  | Event collection                  |
      | field_event_collection | A collection with multiple events |
      | status                 | 1                                 |
    Then I should see "No past events available." in the ".tab-content" element
    Then I should see "No events planned." in the ".tab-content" element

  Scenario: Event collection should display About section only if it has Extended description value
    Given I am logged in as a user with the "administrator" role
    Given I am viewing an "Event" content:
      | title                  | Event collection                  |
      | field_event_collection | A collection with multiple events |
      | body:value             | Event collection body description |
      | body:format            | full_html                         |
      | status                 | 1                                 |
      | language               | en                                |
    Then I should see the heading "About Event collection"
    And I follow "New draft" in the "tabs" region
    And I fill in "body[en][0][value]" with ""
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should not see the heading "About Event collection"

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
    And I select "Budget" from "Organiser"
    And I select "ClimateAction" from "Organiser"
    And I select "Belgium" from "Location"
    And I select "Netherlands" from "Location"
    And I select "France" from "Location"

  Scenario Outline: I should be able to filter by Country
    Given I am on "events"
    And I select "<country>" from "Location"
    And I press the "Refine results" button
    Then I should see "<should_see>"
    And I should not see "<should_not_see_1>"
    And I should not see "<should_not_see_2>"

    Examples:
      | country     | should_see   | should_not_see_1 | should_not_see_2 |
      | Belgium     | Energy event | Food event       | Extra event      |
      | Netherlands | Food event   | Energy event     | Extra event      |
      | France      | Extra event  | Energy event     | Food event       |

  Scenario Outline: I should be able to filter by various filters on the event listing page (select).
    Given I am on "events"
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
      | Organiser  | Any organiser | Budget      | see                | not see          | ClimateAction | not see             | see               |

  Scenario: I should be able to filter by online only (checkbox)
    Given I am on "events"
    And I check the box "Online events only"
    And I press the "Refine results" button
    Then I should see "Energy event"
    Then I should not see "Food event"

  Scenario: I should be able to filter by livestream (checkbox)
    Given I am on "events"
    And I check the box "Online events with live streaming available"
    And I press the "Refine results" button
    Then I should not see "Energy event"
    Then I should see "Food event"

  Scenario: I should be able to filter by a combination of facets and views and I should see the tags.
    Given I am on "events"
    And I check the box "Online events with live streaming available"
    And I press the "Refine results" button
    Then I should not see "Energy event"
    Then I should see "Food event"
    Then I should see "Extra event"
    And I fill in "Keywords" with "Extra"
    And I press the "Refine results" button
    Then I should see "Extra" in the ".filters__active-facets" element
    Then I should see "LIVE STREAMING AVAILABLE" in the ".filters__active-facets" element
    Then I should not see "Energy event"
    Then I should not see "Food event"
    Then I should see "Extra event"

  Scenario Outline: Date and time are displayed differently based on the state of the even.
    Given I am viewing an "Event" content:
      | title                        | Event title        |
      | field_event_date:value       | <event_start_date> |
      | field_event_date:value2      | <event_end_date>   |
      | field_event_date:show_todate | <show_todate>      |
      | field_event_date:timezone    | Europe/London      |
      | status                       | 1                  |
    Then I should see "<expected_header>" in the ".page-header" element
    Then I should see "<expected_practical>" in the ".page-content" element

    Examples:
      | event_start_date | event_end_date | show_todate | expected_header                                | expected_practical                                                 |
      # Single day event
      # PAST:            Thu, 01 Jan 2015 09:00:00 GMT
      | 1420102800       | 1420102800     | 0           | 1 January 2015                                 | 1 January 2015, 9.00 (GMT)                                         |
      # FUTURE:          Mon, 01 Jan 2035 09:00:00 GMT
      | 2051254800       | 2051254800     | 0           | Monday 1 January                               | Monday 1 January 2035, 9.00 (GMT)                                  |

      # Single day event with different hours
      # PAST:            Thu, 01 Jan 2015 09:00:00 GMT - Thu, 01 Jan 2015 10:00:00 GMT
      | 1420102800       | 1420106400     | 1           | 1 January 2015                                 | 1 January 2015, 9.00 - 10.00 (GMT)                                 |
      # FUTURE:          Mon, 01 Jan 2035 09:00:00 GMT - Mon, 01 Jan 2035 10:00:00 GMT
      | 2051254800       | 2051258400     | 1           | Monday 1 January                               | Monday 1 January 2035, 9.00 - 10.00 (GMT)                          |

      # Multiple day event (days following each other) in one month.
      # PAST:            Thu, 01 Jan 2015 09:00:00 GMT - Fri, 02 Jan 2015 09:00:00 GMT
      | 1420102800       | 1420189200     | 1           | 1 - 2 January 2015                             | 1 January 2015, 9.00 - 2 January 2015, 9.00 (GMT)                  |
      # FUTURE:          Mon, 01 Jan 2035 10:00:00 GMT - Mon, 15 Jan 2035 10:00:00 GMT
      | 2051258400       | 2052468000     | 1           | Monday 1 - Monday 15 January                   | Monday 1 January 2035, 10.00 - Monday 15 January 2035, 10.00 (GMT) |

      # Multiple day event (days following each other) in multiple months.
      # PAST:            Thu, 01 Jan 2015 09:00:00 GMT - Mon, 02 Feb 2015 09:00:00 GMT
      | 1420102800       | 1422867600     | 1           | 1 January - 2 February 2015                    | 1 January 2015, 9.00 - 2 February 2015, 9.00 (GMT)                 |
      # FUTURE:          Mon, 01 Jan 2035 10:00:00 GMT - Thu, 15 Mar 2035 10:00:00 GMT
      | 2051258400       | 2057565600     | 1           | Monday 1 January - Thursday 15 March           | Monday 1 January 2035, 10.00 - Thursday 15 March 2035, 10.00 (GMT) |

      # Multiple day event (days following each other) in multiple months and multiple years.
      # PAST:            Thu, 01 Jan 2015 09:00:00 GMT - Fri, 01 Jan 2016 10:00:00 GMT
      | 1420102800       | 1451642400     | 1           | 1 January 2015 - 1 January 2016                | 1 January 2015, 9.00 - 1 January 2016, 10.00 (GMT)                 |
      # FUTURE:          Mon, 01 Jan 2035 10:00:00 GMT - Sat, 15 Mar 2036 10:00:00 GMT
      | 2051258400       | 2089188000     | 1           | Monday 1 January 2035 - Saturday 15 March 2036 | Monday 1 January 2035, 10.00 - Saturday 15 March 2036, 10.00 (GMT) |

  Scenario: Create internal link with teaser view mode in other nodes
    Given "Event" content:
      | title              | language | nid     | is_new | status | field_event_date:value | field_event_date:value2 | field_event_date:timezone | field_event_status |
      | Test Event to show | en       | 1234567 | 1      | 1      | 1893456000             | 1893456000              | Europe/Budapest           | no                 |
    And I am viewing a "Page" content:
      | title       | Event teaser view mode test                         |
      | body:value  | [node:1234567:view-mode:teaser]{Test event to show} |
      | body:format | full_html                                           |
      | status      | 1                                                   |
    Then I should see an ".node.node-event.node-teaser.view-mode-teaser" element

  Scenario: Gallery should not show if no media is uploaded
    Given I am viewing an "Event" content:
      | title                       | Past event      |
      | field_event_status          | no              |
      | field_event_is_fully_booked | no              |
      | field_event_date:value      | 1472724000      |
      | field_event_date:value2     | 1472724000      |
      | field_event_date:timezone   | Europe/Budapest |
      | status                      | 1               |
    Then I should not see "Images and videos"

  Scenario: Event collection "Upcoming and Past events" more link points to event list, using a query filter
    Given I am logged in as a user with the "administrator" role
    Given "Event" content:
      | title         | status | field_core_topics | field_core_departments | field_event_is_online | field_event_is_live_streaming | field_event_live_streaming_link | field_event_type | field_event_date:value | field_event_date:value2 | field_event_date:timezone | field_event_date:offset | field_event_date:offset2 | field_core_location           | language |
      | Extra 2 event | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1969955601             | 1969955601              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Extra 3 event | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1969959201             | 1969959201              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Extra 4 event | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1969962801             | 1969962801              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Past 1 event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1116970001             | 1116970001              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Past 2 event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1116966401             | 1116966401              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Past 3 event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1116962801             | 1116962801              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Past 4 event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1116959201             | 1116959201              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Past 5 event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1116955601             | 1116955601              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
      | Past 6 event  | 1      | Food              | ClimateAction          | no                    | yes                           | http://localhost                | Conference       | 1116952001             | 1116952001              | Europe/Budapest           | 3600                    | 3600                     | country: FR - locality: Paris | en       |
    And I index all indexes

    Given I am viewing an "Event" content:
      | title                       | Event collection                                                                                                                                                       |
      | body:value                  | Event collection body description                                                                                                                                      |
      | body:format                 | full_html                                                                                                                                                              |
      | field_event_collection      | A collection with multiple events                                                                                                                                      |
      | field_event_children_events | Energy event, Food event, Extra event, Extra 2 event, Extra 3 event, Extra 4 event, Past 1 event, Past 2 event, Past 3 event, Past 4 event, Past 5 event, Past 6 event |
      | status                      | 1                                                                                                                                                                      |
      | language                    | en                                                                                                                                                                     |
      | nid                         | 100002                                                                                                                                                                 |
      | is_new                      | 1                                                                                                                                                                      |
    Then I should see an ".field--current-and-upcoming-events" element
    And I should see the following in the repeated ".listing__title" element within the context of the ".field--current-and-upcoming-events" element:
      | text          |
      | Energy event  |
      | Extra event   |
      | Extra 2 event |
      | Extra 3 event |
      | Extra 4 event |
    And I should not see the link "Food event"
    And I should see the link "View all events for Event collection" linking to "/events_en?facet__select__field_event_parent_events=100002"
    Then I should see an ".field--past-events" element
    And I should see the following in the repeated ".listing__title" element within the context of the ".field--past-events" element:
      | text         |
      | Past 1 event |
      | Past 2 event |
      | Past 3 event |
      | Past 4 event |
      | Past 5 event |
    And I should not see the link "Past 6 event"
    Then I follow "View all events for Event collection"
    Then I should see "Event collection" in the ".filters__active-facets" element
