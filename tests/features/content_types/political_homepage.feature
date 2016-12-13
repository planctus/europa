@api @political @dt_info_homepage
Feature: Political Homepage different layout

  Scenario: Political Homepage site header has different layout from other pages
    Given I am logged in as a user with the "administrator" role
    Given I am viewing a "Homepage":
      | title                   | Political hp           |
      | field_core_introduction | Political introduction |
      | status                  | 1                      |
      | language                | en                     |
      | og_group_ref            | Global editorial team  |
    Then I should see an "header.site-header.site-header--homepage" element
    # Language switch and logo.
    Then I should see an "header div.container-fluid .top-bar .lang-select-site" element
    Then I should see an "header div.container-fluid a.logo.logo--logotypebelow.site-header__logo" element
    # Search bar.
    Then I should see an "header section.header-search-bar div.header-search-bar__wrapper" element
    # Check pages of other content type
    Given I am viewing an "announcement" content:
      | title                         | A new web presence for the Commission |
      | status                        | 1                                     |
      | language                      | en                                    |
    Then I should see an "header.site-header" element
    Then I should not see an "header.site-header--homepage" element
    # Logo, searchbar and language switch.
    Then I should see an "header div.container-fluid a.logo.site-header__logo" element
    Then I should see an "header div.container-fluid .top-bar section.lang-select-site" element
    Then I should see an "header div.container-fluid .top-bar section.block-nexteuropa-europa-search" element

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

  Scenario: Commissioners block is visible and links to the defined urls
    Given I am logged in as a user with the "administrator" role
    Given "Featured item" content:
      | title         | language | status | field_core_legacy_link           | field_feat_item_image |
      | Featured ext1 | en       | 1      | test - http://ec.europa.eu/test1 | img-president.jpg     |
      | Featured ext2 | en       | 1      | test - http://ec.europa.eu/test2 | img-commission.jpg    |
    Given I am viewing a "Homepage" content:
      | title                            | Frontpage title                      |
      | field_info_homepage_hero_linktxt | Hero link text above featured items. |
      | field_info_homepage_hero_links   | Featured ext1, Featured ext2         |
      | language                         | en                                   |
      | status                           | 1                                    |
    Then I should see "Hero link text above featured items." in the ".hero-links__text p" element
    And I should see the link "Featured ext1" linking to "http://ec.europa.eu/test1"
    And I should see the link "Featured ext2" linking to "http://ec.europa.eu/test2"
