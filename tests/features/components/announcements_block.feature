@api @information @political
Feature: Announcements block
  In order to display announcements on the website
  I want to see the announcements in the announcements block

  Background:
    Given I set the variable "dt_shared_functions_dt_latest_visibility" to "1"

  @information
  Scenario Outline: Visitors should see the latest announcements block on content types
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
    Then I should see the link "Announcement on <content_name>"

    Examples:
      | content_name | reference_fieldname   | label_visible |
      | Department   | field_core_department | should        |
      | Policy       | field_core_policies   | should not    |
      | Topic        | field_core_topics     | should        |
      | Priority     | field_core_priorities | should        |

  @political
  Scenario Outline: Visitors should see the latests announcements block on content types
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
    Then I should see the link "Announcement on <content_name>"

    Examples:
      | content_name | reference_fieldname   | label_visible |
      | Policy       | field_core_policies   | should not    |
      | Topic        | field_core_topics     | should        |
      | Priority     | field_core_priorities | should        |

  Scenario: Visitors should see sticky and promoted highlights above announcements list
    Given "Announcement" content:
      | title                   | status | sticky | promote |
      | Sticky Announcement     | 1      | 1      | 0       |
      | Promoted Announcement 1 | 1      | 0      | 1       |
    When I go to "announcements_en"
    Then the ".node-announcement.node-sticky .featured-item" element should contain "Sticky Announcement"
    Then the ".node-announcement.node-promoted .featured-item" element should contain "Promoted Announcement 1"

  @information @political
  Scenario: Editors can toggle the display of the latest announcements block on Pages
    Given I am logged in as a user with the "administrator" role
    Given "Page" content:
      | title                   | status | field_core_description | field_core_latest_visibility |
      | Page with announcements | 1      | Sample description     | Disable                      |
    Given "Announcement" content:
      | title                | status | field_core_pages        |
      | Announcement on Page | 1      | Page with announcements |
    When I go to "admin/content"
    And I follow "Page with announcements"
    Then I should not see an ".field--announcement-block" element
    Then I should not see the link "Announcement on Page"
    When I follow "New draft" in the "tabs" region
    And I check "Latest visibility"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see an ".field--announcement-block h2" element
    Then I should see the link "Announcement on Page"

  @information @political
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

  @information @political
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

  @information
  Scenario Outline: Latest block should show the "All latest on {Abbreviation}" on departments
    Given I am viewing a "Department":
      | title                        | Department of Rebellion |
      | status                       | 1                       |
      | field_core_latest_visibility | Enable                  |
      | field_core_abbreviation      | <Abbreviation>          |
      | nid                          | 13337                   |
      | is_new                       | 1                       |
    And "Announcement" content:
      | title          | status | field_core_department   |
      | announcement 1 | 1      | Department of Rebellion |
    When I reload the page
    Then I should see "Latest" in the ".field--announcement-block h2" element
    Then I should see the link "All news on <Abbreviation>" linking to "/announcements_en?department=13337"

    Examples:
      | Abbreviation |
      | DG RBLL      |
      | DG A'B       |

  @information
  Scenario: Latest block should show the "All latest on this policy" on policies
    Given I am viewing a "Policy":
      | title  | Policy demo |
      | status | 1           |
      | nid    | 13337       |
      | is_new | 1           |
    And "Announcement" content:
      | title          | status | field_core_policies |
      | announcement 1 | 1      | Policy demo         |
    When I reload the page
    Then I should see the link "All news on this policy" linking to "/announcements_en?policies=13337"

  @information
  Scenario Outline: Latest block should show the "All latest on {title}" on pages
    Given I am viewing a "Page":
      | title                        | <title> |
      | status                       | 1       |
      | nid                          | 13337   |
      | field_core_latest_visibility | Enable  |
      | is_new                       | 1       |
    And "Announcement" content:
      | title          | status | field_core_pages |
      | announcement 1 | 1      | <title>          |
    When I reload the page
    Then I should see the link "All latest on <title>" linking to "/announcements_en?pages=13337"

    Examples:
      | title       |
      | Page demo   |
      | Page's demo |
