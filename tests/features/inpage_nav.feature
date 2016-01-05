Feature: In-page navigation
  In order to see in-page navigation on pages that is needed
  As an editor
  I should be able to hide/show in-page navigation on pages

  @api
  Scenario: Show/hide in-page navigation on Page
    Given "Page" content:
    | title         | field_core_description | field_core_introduction | field_core_in_page_navigation | status |
    | Content title | Content description    | Intro                   | Enable                        | 1      |
    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Content title"
    Then I should see an ".inpage-nav__wrapper" element
    And I follow "New draft" in the "tabs"
    And I uncheck the box "In page navigation"
    When I press the "Save" button
    Then I should not see an ".inpage-nav__wrapper" element
