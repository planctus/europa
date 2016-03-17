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
    Given "Page" content:
      | title                   | status | field_core_description | field_core_latest_visibility | field_core_social_network_links[social_network] | field_core_social_network_links[title] | field_core_social_network_links[url] |
      | Page with announcements | 1      | Sample description     | Disable                      | Facebook                                        | Social title                           | /node                                |
    Given "Announcement" content:
      | title                | status | field_core_pages        |
      | Announcement on page | 1      | Page with announcements |
    When I go to "admin/content"
    And I follow "Page with announcements"
    Then I should not see "Follow the latest progress and get involved."
    Then I should not see the link "Other social networks on page"
    When I follow "New draft" in the "tabs" region
    And I check "Latest visibility"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see "Follow the latest progress and get involved." in the ".social-media-links" element
    Then I should see the link "Other social networks on page"
