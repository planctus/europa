@api @political @dt_homepage
Feature: Political Homepage different layout

  Scenario: Political Homepage has different layout and shows translated strings
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "Homepage":
      | title                   | Political hp           |
      | field_core_introduction | Political introduction |
      | status                  | 1                      |
      | language                | en                     |
      | og_group_ref            | Global editorial team  |
    And I translate the string "Highlight" to "French" with "Highlight fr"
    Then I should see "Highlight" in the ".field--field-core-introduction .field__label" element
    Then I should see "Political introduction" in the ".field--field-core-introduction .field__items p" element
    # Translation of fields and label.
    And I go to add "fr" translation
    And I fill in "title_field[fr][0][value]" with "Political hp FR"
    And I fill in "field_core_introduction[fr][0][value]" with "Political introduction FR"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see "Highlight fr" in the ".field--field-core-introduction .field__label" element
    Then I should see "Political introduction FR" in the ".field--field-core-introduction .field__items p" element

  Scenario: Latest block can be turned on and off
    Given "Announcement" content:
      | title                   | status | sticky | promote |
      | Promoted Announcement 1 | 1      | 0      | 1       |
      | Promoted Announcement 2 | 1      | 0      | 0       |
    When I am viewing a "Homepage":
      | title                        | Political hp           |
      | field_core_introduction      | Political introduction |
      | status                       | 1                      |
      | language                     | en                     |
      | field_core_latest_visibility | Enable                 |
    Then I should see "Promoted Announcement 1" in the ".field--announcement-block" element
    Then I should not see "Promoted Announcement 2" in the ".field--announcement-block" element

  Scenario: Latest link can be translated
    Given I am logged in as a user with the "administrator" role
    And "Announcement" content:
      | title                   | status | sticky | promote |
      | Promoted Announcement 1 | 1      | 0      | 1       |
    When I am viewing a "Homepage":
      | title                           | Political hp                 |
      | field_core_introduction         | Political introduction       |
      | status                          | 1                            |
      | language                        | en                           |
      | og_group_ref                    | Global editorial team        |
      | field_core_latest_visibility    | Enable                       |
      | field_info_homepage_latest_link | More news - http://google.be |
    And I translate the string "Latest" to "French" with "Latest fr"
    And I go to add "fr" translation
    And I fill in "title_field[fr][0][value]" with "Political hp FR"
    And I fill in "field_core_introduction[fr][0][value]" with "Political introduction FR"
    And I fill in "field_info_homepage_latest_link[fr][0][title]" with "More news fr"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see "Latest fr" in the ".field--announcement-block" element
    Then I should see "More news fr" in the ".field--field-info-homepage-latest-link" element

  Scenario: Social media block is visible for the latest block
    Given I am logged in as a user with the "administrator" role
    And "Announcement" content:
      | title                   | status | sticky | promote |
      | Promoted Announcement 1 | 1      | 0      | 1       |
    And I am viewing a "Homepage":
      | title                        | Political hp           |
      | field_core_introduction      | Political introduction |
      | status                       | 1                      |
      | language                     | en                     |
      | og_group_ref                 | Global editorial team  |
      | field_core_latest_visibility | Enable                 |
    When I follow "New draft" in the "tabs" region
    And I select "Published" from "Moderation state"
    And I select "Facebook" from "Social Network"
    And I fill in "field_core_social_network_links[en][0][title]" with "Facebook"
    And I fill in "field_core_social_network_links[en][0][url]" with "http://facebook.com/"
    And I press "Save"
    Then I should see "Facebook"
