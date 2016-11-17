@api @information
Feature: Announcement content type
  In order to get the latest transformation of the announcement content type
  As an anonymous user
  I should see the information of the page in a specific way

  Background:
    Given "Topic" content:
      | title        | language | status |
      | RelatedTopic | en       | 1      |
    Given "Department" content:
      | title             | language | status |
      | RelatedDepartment | en       | 1      |

  @information
  Scenario: Announcement fields are seen in correct places
    Given I am logged in as a user with the "administrator" role
    And I am viewing an "announcement" content:
      | title                         | A new web presence for the Commission |
      | status                        | 1                                     |
      | language                      | en                                    |
      | field_core_type_content       | default                               |
      | field_core_description        | A test description.                   |
      | field_announcement_type       | press_release                         |
      | field_core_date_published     | 1456790400                            |
      | field_core_introduction       | A test introduction                   |
      | body                          | A test body                           |
      | field_announcement_location   | Brussels                              |
      | field_publication_referenceno | Ref#123                               |
      | field_core_topics             | RelatedTopic                          |
      | field_core_department         | RelatedDepartment                     |
      | field_announcement_department | RelatedDepartment                     |
    Then I should see "A test introduction" in the ".page-content" element
    And I should see "Share this page:" in the ".social-media-links--webtool-horizontal" element
    And I should see "RelatedTopic" in the ".page-content" element
    And I should see "RelatedDepartment" in the ".page-content" element
    And I should see "RelatedDepartment" in the ".page-header" element
    And I should see "Published" in the ".page-content" element
    And I should see "Last update" in the ".page-content" element
    And I should see "Location" in the ".page-content" element
    And I should see "Author" in the ".page-content" element
    And I should see "Reference" in the ".page-content" element

  @information @political
  Scenario: I should be able to select different announcement types.
    Given I am logged in as a user with the "administrator" role
    And I go to "node/add/announcement"
    Then I should have the following options for "Announcement type":
      | Press release                    |
      | Factsheet                        |
      | Daily news                       |
      | Speech                           |
      | Commissioners' weekly activity   |
      | Upcoming events                  |
      | Statement                        |
      | News                             |
      | News article                     |
      | Weekly meeting                   |
