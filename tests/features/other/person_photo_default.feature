@api @information
Feature: Event person photo default
  As a user
  I want to be able to see an event with person photo default if the person doesn't have one defined.

  Scenario: I should see the person default female image in person, event and department nodes.
    Given "Person" content:
      | title       | field_person_first_name | field_person_last_name | field_person_gender | status |
      | Joan Person | Joan                    | Person                 | Female              | 1      |

    # "Full content" view mode
    Given I am on "persons/joan-person"
    Then I see the "img.img-responsive" element with the "src" attribute set to "person_photo_female" in the "main_content" region

    # "Event speaker" view mode
    Given "Event" content:
      | title         | status | field_event_speakers | field_event_date:value | field_event_date:value2 | field_event_date:timezone | field_core_location             |
      | Speaker event | 1      | Joan Person        | 1969952000             | 1969952000              | Europe/Budapest           | country: BE - locality: Brussel |
    And I index all indexes
    Given I am on "events/speaker-event"
    Then show last response
    Then I see the "img.img-responsive" element with the "src" attribute set to "person_photo_female" in the "speakers" region

    # "Meta" view mode
    Given I am viewing a "Department" content:
      | title              | My Department |
      | field_core_persons | Joan Person   |
      | status             | 1             |
    Then I see the "img.img-responsive" element with the "src" attribute set to "person_photo_female" in the "main_content" region


  Scenario: I should see the person default male image in person, event and department nodes.
    Given "Person" content:
      | title      | field_person_first_name | field_person_last_name | field_person_gender | status |
      | Joe Person | Joe                     | Person                 | Male                | 1      |

    # "Full content" view mode
    Given I am on "persons/joe-person"
    Then I see the "img.img-responsive" element with the "src" attribute set to "person_photo_male" in the "main_content" region

    # "Event speaker" view mode
    Given "Event" content:
      | title         | status | field_event_speakers | field_event_date:value | field_event_date:value2 | field_event_date:timezone | field_core_location             |
      | Speaker event | 1      | Joe Person         | 1969952000             | 1969952000              | Europe/Budapest           | country: BE - locality: Brussel |
    And I index all indexes
    Given I am on "events/speaker-event"
    Then I see the "img.img-responsive" element with the "src" attribute set to "person_photo_male" in the "speakers" region

    # "Meta" view mode
    Given I am viewing a "Department" content:
      | title              | My Department |
      | field_core_persons | Joe Person    |
      | status             | 1             |
    Then I see the "img.img-responsive" element with the "src" attribute set to "person_photo_male" in the "main_content" region
