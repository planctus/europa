@api @information @political @dt_announcement
Feature: Announcements block
  In order to display announcements on the website
  I want to see the announcements in the announcements block

  Background:
    Given I set the variable "dt_shared_functions_dt_latest_visibility" to "0"

  @dt_department @dt_page @dt_policy @dt_topic @dt_priority
  Scenario Outline: Default settings of "Latest visibility" are respected
    Given I am logged in as a user with the "administrator" role
    Given "<content_name>" content:
      | title                             | status | field_core_description |
      | <content_name> with announcements | 1      | Sample description     |
    Given "Announcement" content:
      | title                          | status | <reference_fieldname>             |
      | Announcement on <content_name> | 1      | <content_name> with announcements |
    When I go to "admin/content"
    And I follow "<content_name> with announcements"
    Then I <label_visible> see an ".field--announcement-block h2" element
    Then I <link_visible> see the link "Announcement on <content_name>"

    Examples:
      | content_name | reference_fieldname   | label_visible | link_visible |
      | Department   | field_core_department | should        | should       |
      | Policy       | field_core_policies   | should not    | should not   |
      | Topic        | field_core_topics     | should not    | should not   |
      | Priority     | field_core_priorities | should not    | should not   |
      | Page         | field_core_pages      | should not    | should not   |

  @dt_department @dt_page @dt_policy @dt_topic @dt_priority
  Scenario Outline: "Latest visibility" value is respected
    Given I am viewing a "<content_name>":
      | title                        | <content_name> with announcements |
      | status                       | 1                                 |
      | field_core_description       | Sample description                |
      | field_core_latest_visibility | Enable                            |
      | nid                          | 999999                            |
      | field_core_abbreviation      | DG TEST                           |
      | is_new                       | 1                                 |
    Given "Announcement" content:
      | title                          | status | <reference_fieldname>             |
      | Announcement on <content_name> | 1      | <content_name> with announcements |
    When I reload the page
    Then I <label_visible> see an ".field--announcement-block h2" element
    Then I <link_visible> see the link "Announcement on <content_name>"
    Then I should see the link "<all_link_text>" linking to "<all_link_url>"

    Examples:
      | content_name | reference_fieldname   | label_visible | link_visible | all_link_text                         | all_link_url                        |
      | Department   | field_core_department | should        | should       | All news on DG TEST                   | /announcements_en?department=999999 |
      | Policy       | field_core_policies   | should not    | should       | All news on this policy               | /announcements_en?policies=999999   |
      | Topic        | field_core_topics     | should        | should       | All news on Topic with announcements  | /announcements_en?topics=999999     |
      | Priority     | field_core_priorities | should        | should       | All news on this priority             | /announcements_en?priorities=999999 |
      | Page         | field_core_pages      | should        | should       | All latest on Page with announcements | /announcements_en?pages=999999      |


  Scenario: Visitors should see sticky and promoted highlights above announcements list
    Given "Announcement" content:
      | title                   | status | sticky | promote |
      | Sticky Announcement     | 1      | 1      | 0       |
      | Promoted Announcement 1 | 1      | 0      | 1       |
    When I go to "announcements_en"
    Then the ".node-announcement.node-sticky .featured-item" element should contain "Sticky Announcement"
    Then the ".node-announcement.node-promoted .featured-item" element should contain "Promoted Announcement 1"

  @dt_page @dt_social_network_links
  Scenario: Announcement block can display social media links
    Given I am logged in as a user with the "administrator" role
    Given "Social Networks" terms:
      | name     | name_field |
      | Facebook | Facebook   |
    Given "Page" content:
      | title                   | status | field_core_description | field_core_latest_visibility |
      | Page with announcements | 1      | Sample description     | Disable                      |
    Given "Announcement" content:
      | title                | status | field_core_pages        |
      | Announcement on page | 1      | Page with announcements |
    When I go to "admin/content"
    And I follow "Page with announcements"
    Then I should not see "Follow the latest progress and get involved."
    Then I should not see the link "Other social networks on page"
    When I follow "New draft" in the "tabs" region
    And I check "Latest visibility"
    And I select "Published" from "Moderation state"
    And I select "Facebook" from "Social Network"
    And I fill in "field_core_social_network_links[en][0][title]" with "Facebook"
    And I fill in "field_core_social_network_links[en][0][url]" with "http://facebook.com/"
    And I press "Save"
    Then I should see "Latest" in the ".field--announcement-block h2" element
    Then I should see the link "Announcement on page"
    Then I should see "Follow the latest progress and get involved." in the ".social-media-links" element
    Then I should see "Other social networks" in the ".social-media-links" element
    Then I should see "Facebook" in the ".social-media-links" element

  @dt_page @dt_featured_item
  Scenario: Announcement block can display a featured item
    Given I am logged in as a user with the "administrator" role
    Given "Featured item" content:
      | title         | status |
      | Featured item | 1      |
    Given "Page" content:
      | title                   | status | field_core_description | field_core_latest_visibility | field_core_featured_item |
      | Page with announcements | 1      | Sample description     | Disable                      | Featured item            |
    Given "Announcement" content:
      | title                | status | field_core_pages        |
      | Announcement on page | 1      | Page with announcements |
    When I go to "admin/content"
    And I follow "Page with announcements"
    When I follow "New draft" in the "tabs" region
    And I check "Latest visibility"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see "Latest" in the ".field--announcement-block h2" element
    Then I should see the link "Announcement on page"
    Then I should see "Featured item" in the ".featured-item" element
