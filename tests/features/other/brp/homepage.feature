@api @brp @dt_page @dt_nal_services @brp_initiative
Feature: As an anonymous user
  I want to be able to see the latest initiatives on the front page.

  Background:
    Given "nal_resource_types" terms:
      | name         | description                   |
      | ResourceType | The resource type description |

  Scenario: The visitor should see the latest initiatives on homepage.
    Given I am viewing a "Initiative" content:
      | title                        | Initiative title       |
      | field_brp_inve_reference     | 1234                   |
      | field_core_description       | Initiative description |
      | field_brp_inve_fb_start_date | 1570665600             |
      | field_brp_inve_fb_end_date   | 1570665600             |
      | status                       | 1                      |
      | field_brp_inve_resource_type | ResourceType           |
      | field_brp_inve_id            | 1                      |
    And I index all indexes
    Given I am viewing a "Page" content:
      | title                         | Frontpage                           |
      | status                        | 1                                   |
      | body:value                    | <h2 id="inpage-body">Body text</h2> |
      | body:format                   | full_html                           |
      | field_core_in_page_navigation | Enable                              |

    And I set the current page as frontpage
    And I go to the homepage
    And I follow "English"
    Then I should see "Latest initiatives"
    Then I should see the link "Initiative title"
    Then I should see "Latest initiatives" in the ".inpage-nav__wrapper" element
    Then I should see "Body text" in the ".inpage-nav__wrapper" element
