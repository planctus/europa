@api @information @political @dt_announcement
Feature: As an administrator
  I can customize the subtitle and the links on the Announcements list page

  Scenario: Custom page elements can be defined
    Given I am logged in as a user with the "site manager" role
    And I go to "block/add/list-view-content"
    And I fill in the following:
      | Label                                 | Announcements                                               |
      | Description                           | Description Highlights, press releases and speeches         |
      | Introduction                          | <p>Introduction Highlights, press releases and speeches</p> |
      | List view content                     | <p>List view content</p>                                    |
      | View                                  | announcements.page_1                                        |
      | Link block title                      | Other news sources                                          |
      | edit-field-list-view-links-en-0-title | Title 1                                                     |
      | edit-field-list-view-links-en-0-url   | http://test1.com                                            |
    And I press "Save"
    And I go to "/announcements"
    Then I should see "Other news sources" in the ".link-block" element
    And I should see "Title 1" in the ".link-block .link-block__links" element
    And I should see "Introduction Highlights, press releases and speeches" in the ".page-header" element
    And I should see "List view content" in the "#block-system-main .block__content .view p" element
    And the metatag attribute "description" should have the value "Description Highlights, press releases and speeches"
