@api @nexteuropa_legacy_link
Feature: Legacy links
  In order to see links to external content
  As an editor
  I should be able to add multilingual legacy links to content
  As an anonymous user
  I should be able to see legacy link content that is not full view mode

  @information @political @dt_announcement @dt_page
  Scenario: Show external legacy link on announcement teaser
    Given "Page" content:
      | title         | language | field_core_description | status | field_core_latest_visibility |
      | Content title | en       | Content description    | 1      | Enable                       |
    Given "Announcement" content:
      | title                      | language | status | field_core_type_content              | field_core_legacy_link         | field_core_pages | field_announcement_type | field_announcement_location |
      | Announcement title on page | en       | 1      | Teaser linking to external resources | title - http://example.en/test | Content title    | press_release           | Brussels                    |
    And I set the variable "dt_shared_functions_dt_latest_visibility" to "1"
    And I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    And I follow "Content title"
    Then I should see the link "Announcement title on page" linking to "http://example.en/test"
    When I go to "admin/content"
    And I follow "Announcement title on page"
    And I go to add "nl" translation
    And I fill in "edit-title-field-nl-0-value" with "Dutch announcement title on page"
    And I fill in "Moderation state" with "published"
    And I fill in "field_core_legacy_link[nl][0][url]" with "http://example.nl/test"
    And I press "Save"
    And I go to "admin/content"
    And I follow "Content title"
    And I go to add "nl" translation
    And I fill in "edit-title-field-nl-0-value" with "Dutch content title"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see the link "Dutch announcement title on page" linking to "http://example.nl/test"
    And I go to "admin/content"
    And I follow "Content title"
    Then I should see the link "Announcement title on page" linking to "http://example.en/test"

  @information @political @dt_page @dt_announcement
  Scenario: As an anonymous user I should see the referenced legacy link teaser
    Given I am not logged in
    And I set the variable "dt_shared_functions_dt_latest_visibility" to "1"
    And I am viewing a "Page" content:
      | title                        | Content title       |
      | language                     | en                  |
      | field_core_description       | Content description |
      | status                       | 1                   |
      | field_core_latest_visibility | Enable              |
    And "Announcement" content:
      | title                      | language | status | field_core_type_content              | field_core_legacy_link         | field_core_pages | field_announcement_type | field_announcement_location |
      | Announcement title on page | en       | 1      | Teaser linking to external resources | title - http://example.en/test | Content title    | press_release           | Brussels                    |
    When I reload the page
    Then I should see the link "Announcement title on page" linking to "http://example.en/test"

  @information @political @dt_announcement
  Scenario: As an anonymous user I should get an access denied on legacy link full view mode
    Given I am not logged in
    Given I am viewing a "Announcement" content:
      | title                  | Announcement title on page |
      | language               | en                         |
      | field_core_description | Content description        |
      | status                 | 1                          |
      | field_core_legacy_link | title - /user              |
    Then the url should match "/user"

  @information @dt_page @dt_featured_item @dt_info_homepage
  Scenario: As user I can see legacy links to entityreference fields
    Given I am not logged in
    Given "Page" content:
      | title      | language | status | field_core_descriptions |
      | Page Title | en       | 1      | Description             |
    Given "Featured item" content:
      | title         | language | status | field_feat_item_reference |
      | Featured item | en       | 1      | Page Title                |
    Given "Featured item" content:
      | title             | language | status | field_core_legacy_link        |
      | Featured external | en       | 1      | test - http://example.en/test |
    Given "Featured item" content:
      | title                          | language | status | field_core_legacy_link        | field_feat_item_reference |
      | Featured external and internal | en       | 1      | test - http://example.en/test | Page Title                |
    Given I am viewing a "Homepage" content:
      | title                 | Frontpage title                                                  |
      | language              | en                                                               |
      | field_info_highlights | Featured item, Featured external, Featured external and internal |
      | status                | 1                                                                |
    Then I should see the heading "Featured external"
    Then I should see the link "Featured external" linking to "http://example.en/test"
    Then I should see the heading "Featured item"
    And I follow "Featured item"
    Then I should see the heading "Page Title"
    And I move backward one page
    Then I should see the heading "Featured external and internal"
    And I follow "Featured external and internal"
    Then I should see the heading "Page Title"
