@api
Feature: Announcements block
  In order to display announcements on the website
  I want to see the announcements in the announcements block

  @information
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
      | Department   | field_core_department | should        |
      | Policy       | field_core_policies   | should not    |
      | Topic        | field_core_topics     | should        |
      | Priority     | field_core_priorities | should        |

  @shared @brp
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
    And I press "Save"
    Then I should see an ".field--announcement-block h2" element
    Then I should see the link "Announcement on Page"

  @shared
  Scenario: Editors can toggle the display of the latest announcements block on Priority Policy Areas
    Given I am logged in as a user with the "administrator" role
    Given "Priority policy area" content:
      | title                  | status | field_core_description | field_core_latest_visibility | field_core_type_content |
      | PPA with announcements | 1      | Sample description     | Disable                      | default                 |
    Given "Announcement" content:
      | title               | status | field_core_pri_policy_areas |
      | Announcement on PPA | 1      | PPA with announcements      |
    When I go to "admin/content"
    And I follow "PPA with announcements"
    Then I should not see an ".field--announcement-block" element
    Then I should not see the link "Announcement on PPA"
    When I follow "New draft" in the "tabs" region
    And I check "Latest visibility"
    And I press "Save"
    Then I should see an ".field--announcement-block h2" element
    Then I should see the link "Announcement on PPA"

  @information
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

  @information
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
