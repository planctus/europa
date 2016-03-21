@api @shared
Feature: Announcements block
  In order to display announcements on the website
  As a anonymous user
  I want to see the announcements in the announcements block

  Scenario: Editors can toggle the display of the latest annoncements block on a page
    Given I am logged in as a user with the "administrator" role
    Given "Page" content:
      | title                   | status | field_core_description | field_core_latest_visibility |
      | Page with announcements | 1      | Sample description     | Disable                      |
    Given "Announcement" content:
      | title                | status | field_core_pages        |
      | Announcement on page | 1      | Page with announcements |
    When I go to "admin/content"
    And I follow "Page with announcements"
    Then I should not see an ".field--announcement-block" element
    Then I should not see the link "Announcement on page"
    When I follow "New draft" in the "tabs" region
    And I check "Latest visibility"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see "Latest" in the ".field--announcement-block h2" element
    Then I should see the link "Announcement on page"

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
    And I fill in "field_core_social_network_links[en][0][url]" with "http://google.be/"
    And I press "Save"
    Then I should see "Latest" in the ".field--announcement-block h2" element
    Then I should see the link "Announcement on page"
    Then I should see "Follow the latest progress and get involved." in the ".social-media-links" element
    Then I should see "Other social networks" in the ".social-media-links" element
    Then I should see "Facebook" in the ".social-media-links" element

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
