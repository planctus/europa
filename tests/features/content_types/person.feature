@api @information @dt_person @dt_job
Feature: Person content type tests

  Background:
    Given "Job Role types" terms:
      | name      | tid |
      | Main Role | 987 |

    Given "Job Role types" terms:
      | name        | parent | weight |
      | Sub Role    | 987    | 10     |
      | Other Role  | 987    | 30     |
      | Third Role  | 987    | 20     |
      | Fourth Role | 987    | 40     |
    And I translate the term "Sub Role" to "Dutch" with "Sub rol"
    And I translate the term "Other Role" to "Dutch" with "Andere rol"
    And I translate the term "Third Role" to "Dutch" with "Derde rol"

    Given "Topic" content:
      | title        | status |
      | First topic  | 1      |
      | Second topic | 1      |
      | Third topic  | 1      |
    And I create the following translations for "topic" content with title "First topic":
      | title        | status | language |
      | Eerste topic | 1      | nl       |
    And I create the following translations for "topic" content with title "Second topic":
      | title          | status | language |
      | Volgende topic | 1      | nl       |

    Given "Job" content:
      | title         | field_job_role | status | field_job_responsabilities | field_core_topics | field_job_team_group | field_job_acting_role |
      | Example job 1 | Sub Role       | 1      | Bert his responsibility    | First topic       | press_officer        | 1                     |
      | Example job 2 | Other role     | 1      | Jane her responsibilities  | Second topic      | multimedia_team      | 0                     |
      | Example job 3 | Third role     | 1      |                            | Second topic      | spokesperson         | 0                     |
      | Example job 4 | Fourth Role    | 1      |                            | Third topic       | spokesperson         | 0                     |
    And I create the following translations for "job" content with title "Example job 1":
      | title           | status | language |
      | Voorbeeld job 1 | 1      | nl       |
    And I create the following translations for "job" content with title "Example job 2":
      | title           | status | language |
      | Voorbeeld job 2 | 1      | nl       |
    And I create the following translations for "job" content with title "Example job 3":
      | title           | status | language |
      | Voorbeeld job 3 | 1      | nl       |

    Given "Contact" content:
      | title             | status | field_contact_location_office | field_contact_phone_number | field_contact_mobile_number | field_core_social_network_links:social_network | field_core_social_network_links:title | field_core_social_network_links:url | field_contact_email_address:email |
      | Contact example 1 | 1      | COMM                          | 12345                      | 003212                      | 36                                             | Facebook profile                      | http://facebook.com                 | info@behat.org                    |
      | Contact example 2 | 1      | DIGIT                         | 98765                      | 003298                      | 41                                             | Linkedin profile                      | http://linkedin.com                 | contact@behat.org                 |


    # Create persons with translations. This should be refactored but first we need to improve the NE Multilingual
    # context.
    Given I am logged in as a user with the "Administrator" role
    Given I am viewing a "Person":
      | title                   | Bert Normal       |
      | field_person_first_name | Bert              |
      | field_person_last_name  | Normal            |
      | field_person_gender     | Male              |
      | status                  | 1                 |
      | field_core_jobs         | Example job 1     |
      | field_type_of_person    | 1                 |
      | language                | en                |
      | field_core_contact      | Contact example 1 |
    And I go to add "nl" translation
    And I fill in the following:
      | field_person_first_name[nl][0][value] | Bert      |
      | field_person_last_name[nl][0][value]  | Normaal   |
      | workbench_moderation_state_new        | published |
    And I press "Save"

    Given I am viewing a "Person":
      | title                   | Jane Wilde        |
      | field_person_first_name | Jane              |
      | field_person_last_name  | Wilde             |
      | field_person_gender     | Female            |
      | status                  | 1                 |
      | field_core_jobs         | Example job 2     |
      | field_type_of_person    | 0                 |
      | language                | en                |
      | field_core_contact      | Contact example 2 |
    And I go to add "nl" translation
    And I fill in the following:
      | field_person_first_name[nl][0][value] | Jane      |
      | field_person_last_name[nl][0][value]  | Roekeloos |
      | workbench_moderation_state_new        | published |
    And I press "Save"

    Given I am viewing a "Person":
      | title                   | Alfred Rodeo      |
      | field_person_first_name | Alfred            |
      | field_person_last_name  | Rodeo             |
      | field_person_gender     | Male              |
      | status                  | 1                 |
      | field_core_jobs         | Example job 3     |
      | field_type_of_person    | 0                 |
      | language                | en                |
      | field_core_contact      | Contact example 2 |
    And I go to add "nl" translation
    And I fill in the following:
      | field_person_first_name[nl][0][value] | Fred      |
      | field_person_last_name[nl][0][value]  | Rode      |
      | workbench_moderation_state_new        | published |
    And I press "Save"

    #Add some users with different jobs and topics to test search
    Given "Person" content:
      | title    | field_person_first_name | field_person_last_name | field_person_gender | status | field_core_jobs              | field_type_of_person | language | field_core_contact |
      | Duo Buo  | Duo                     | Buo                    | Male                | 1      | Example job 3, Example job 1 | 0                    | en       | Contact example 2  |
      | John Doe | John                    | Doe                    | Male                | 1      | Example job 4                | 0                    | en       | Contact example 2  |

    #Add some users with the same job different names to test sorting
    Given "Person" content:
      | title      | field_person_first_name | field_person_last_name | field_person_gender | status | field_core_jobs | field_type_of_person | language | field_core_contact |
      | John Smith | John                    | Smith                  | Male                | 1      | Example job 2   | 0                    | en       | Contact Example 2  |
      | Jane Smith | Jane                    | Smith                  | Female              | 1      | Example job 2   | 0                    | en       | Contact Example 2  |
    And I am an anonymous user

  Scenario: Press contact listing should not display a link to their entity
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    Then I should not see the link "Jane Wilde"
    Then I should not see the link "Bert Normal"
    And I should see "(ACTING) SUB ROLE"

  Scenario: Press contact listing should display persons along with their contacts
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    # We only have to verify the labels once.
    Then I should see "Phone number"
    And I should see "Mobile"
    And I should see "E-mail"
    And I should see "Social media"
    And I should see "Office"
    # Check all the fields.
    Then I should see "Bert Normal"
    And I should see "Bert his responsibility"
    And I should see "COMM"
    And I should see "12345"
    And I should see "003212"
    And I should see "Facebook profile"
    And I should see "info@behat.org"
    # Check all the fields.
    Then I should see "Jane Wilde"
    And I should see "Jane her responsibilities"
    And I should see "DIGIT"
    And I should see "98765"
    And I should see "003298"
    And I should see "Linkedin profile"
    And I should see "contact@behat.org"
    # Check multilingual.
    When I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service_nl"
    Then I should see "Bert Normaal"
    And I should see "Jane Roekeloos"

  Scenario: Press contact listing should display additional information
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    Then I should see "People" in the ".filters__items-number" element
    # Avoid false positives.
    And I should not see "People (" in the ".filters__items-number" element
    # Strict version.
    And I should not see "People (5)" in the ".filters__items-number" element

  Scenario: When a responsibility is not entered, the job title should be hidden
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    And I select "Third topic" from "Topics"
    And I press "Refine results"
    Then I should not see "Fourth Role" in the ".view-display-id-page .node-job" element

  Scenario: Press contacts should be sorted by their role type weight, and should not be duplicate
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
#    Then print current html
    And I should see "Duo Buo" in the ".view-display-id-page li:nth-child(1)" element
    Then I should see "Bert Normal" in the ".view-display-id-page li:nth-child(2)" element
    And I should see "Alfred Rodeo" in the ".view-display-id-page li:nth-child(3)" element
    And I should see "Jane Smith" in the ".view-display-id-page li:nth-child(4)" element
    And I should see "John Smith" in the ".view-display-id-page li:nth-child(5)" element
    And I should see "Jane Wilde" in the ".view-display-id-page li:nth-child(6)" element

  @dt_topic
  Scenario: Press contact listing should display filters
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    Then I should see "Responsibilities or portfolio" in the "#block-views-exp-press-contacts-page" element
    Then I should see "Topics" in the "#block-views-exp-press-contacts-page" element
    And I select "First topic" from "Topics"
    And I select "Second topic" from "Topics"
    Then I should see "Team/role" in the "#block-views-exp-press-contacts-page" element
    And I select "Spokesperson" from "Team/role"
    And I select "Assistant" from "Team/role"
    And I select "Press Officer" from "Team/role"
    And I select "Multimedia team" from "Team/role"
    And I select "Communications" from "Team/role"
    Then I should not see "Search by name" in the "#block-views-exp-press-contacts-page" element
    # Check multilingual. This works, but test needs to be rewritten.
    And I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service_nl"
    Then I should see "Topics" in the "#block-views-exp-press-contacts-page" element
    And I select "Eerste topic" from "Topics"
    And I select "Volgende topic" from "Topics"

  @wip
  Scenario: Press contact listing should display filters and can be translated
    Then I should see "Team/role" in the "#block-views-exp-press-contacts-page" element
    And I translate the string "Spokesperson" to "Dutch" with "Woordvoerder"
    And I reload the page
    And I select "Woordvoerder" from "Team/role"

  Scenario: Press contact listing translated
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service_hu"
    Then I translate the string "Press contacts – Spokesperson's Service" to "Hungarian" with "HunPress"
    And the cache has been cleared
    And I reload the page
    Then I should see text matching "HunPress"

  @dt_topic
  Scenario: Press contact listing can be filtered by Topics
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    And I select "First topic" from "Topics"
    And I press "Refine results"
    Then I should see "TOPICS" in the ".filters__active-facets" element
    And I should see "First topic" in the ".filters__active-facets" element
    And I should see "Bert Normal"
    And I should not see "Jane Wilde"
    When I select "- Any -" from "Topics"
    And I press "Refine results"
    And I select "Second topic" from "Topics"
    And I press "Refine results"
    Then I should see "TOPICS" in the ".filters__active-facets" element
    And I should see "Second topic" in the ".filters__active-facets" element
    Then I should not see "Bert Normal"
    And I should see "Jane Wilde"
    And I should see "Reset"
    # Check multilingual, if we test one here it is ok.
    And I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service_nl"
    And I select "Eerste topic" from "Topics"
    And I press "Refine results"
    Then I should see "TOPICS" in the ".filters__active-facets" element
    And I should see "Eerste topic" in the ".filters__active-facets" element
    And I should see "Bert Normaal"
    And I should not see "Jane Roekeloos"

  Scenario: Press contact listing can be filtered by Team/role
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    And I select "Press Officer" from "Team/role"
    And I press "Refine results"
    Then I should see "TEAM/ROLE" in the ".filters__active-facets" element
    And I should see "Press Officer" in the ".filters__active-facets" element
    And I should see "Bert Normal"
    And I should not see "Jane Wilde"
    When I select "- Any -" from "Team/role"
    And I press "Refine results"
    And I select "Spokesperson" from "Team/role"
    And I press "Refine results"
    Then I should see "TEAM/ROLE" in the ".filters__active-facets" element

    And I should see "Spokesperson" in the ".filters__active-facets" element
    Then I should not see "Bert Normal"
    And I should not see "Jane Wilde"
    And I should see "Alfred Rodeo"

  @wip
  Scenario: Press contact listing can be filtered by Team/role and can be translated
    # Check multilingual, if we test one here it is ok.
    And I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service_nl"
    And I select "Woordvoerder" from "Team/role"
    And I press "Refine results"
    Then I should see "TEAM/ROLE" in the ".filters__active-facets" element
    And I should see "Woordvoerder" in the ".filters__active-facets" element
    Then I should not see "Bert Normaal"
    And I should not see "Jane Roekeloos"
    And I should see "Fred Rode"

  Scenario: Press contact listing can be filtered by Responsibilities or portfolio
    Given I am on "contact/press-services/press-contacts/press-contacts-spokespersons-service"
    And I fill in "Responsibilities or portfolio" with "Jane her responsibilities"
    And I press "Refine results"
    Then I should see "Jane Wilde"
    And I should not see "Bert Normal"
    And I should not see "Alfred Rodeo"
