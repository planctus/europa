@api
Feature: In-page navigation
  In order to see in-page navigation on pages that is needed
  As an editor
  I should be able to hide/show in-page navigation on pages

  @shared
  Scenario: Show/hide in-page navigation on Page
    Given "Page" content:
      | title         | field_core_description | field_core_introduction | field_core_in_page_navigation | field_core_latest_visibility | field_core_links              | status |
      | Content title | Content description    | Intro                   | Enable                        | Enable                       | Related - http://ec.europa.eu | 1      |
    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    When I follow "Content title"
    Then I should see an ".inpage-nav__wrapper" element
    And I follow "New draft" in the "tabs"
    And I uncheck the box "In page navigation"
    When I press the "Save" button
    Then I should not see an ".inpage-nav__wrapper" element

  @information
  Scenario: Inpage navigation should have the correct order on Page content
    Given a "File" with the title "File Example"
    And I set the variable "dt_shared_functions_dt_latest_visibility" to "1"
    And "Publication" content:
      | title               | field_core_files | field_publication_collection | status |
      | Publication example | File Example     | 0                            | 1      |
    When I am viewing a "Page" content:
      | title                         | Content title                                  |
      | body:value                    | <h2 id="inpage">Inpage</h2><h2>InpageNoId</h2> |
      | body:format                   | full_html                                      |
      | status                        | 1                                              |
      | field_core_links              | test - http://test.domain                      |
      | field_core_next_steps         | bar - foo                                      |
      | field_core_description        | description                                    |
      | field_core_introduction       | content intro                                  |
      | field_core_publications       | Publication example                            |
      | field_core_latest_visibility  | Enable                                         |
      | field_core_in_page_navigation | Enable                                         |
    Then I should see an ".inpage-nav__wrapper" element
    Then I should see the following in the repeated ".inpage_nav__list-item" element within the context of the ".inpage-nav__list" element:
      | text          |
      | Inpage        |
      | InpageNoId    |
      | Latest        |
      | What's next?  |
      | Documents     |
      | Related links |

  @brp
  Scenario: Inpage navigation should have the correct order on Page content with initiatives
    Given "Initiative" content:
      | title              | status | field_core_description |
      | Initiative example | 1      | Initiative Title       |
    And I am viewing a "Page" content:
      | title                         | Content title               |
      | body:value                    | <h2 id="inpage">Inpage</h2> |
      | body:format                   | full_html                   |
      | status                        | 1                           |
      | field_core_links              | test - http://test.domain   |
      | field_core_description        | description                 |
      | field_core_introduction       | content intro               |
      | field_core_latest_visibility  | Enable                      |
      | field_core_in_page_navigation | Enable                      |
    And I set the variable "dt_shared_functions_dt_latest_visibility" to "1"
    And I set the current page as frontpage
    When I reload the page
    Then I should see an ".inpage-nav__wrapper" element
    Then I should see the following in the repeated ".inpage_nav__list-item" element within the context of the ".inpage-nav__list" element:
      | text               |
      | Inpage             |
      | Latest initiatives |
      | Related links      |

  @information
  Scenario: Inpage navigation should have the correct order on Department content
    Given a "File" with the title "File Example"
    And a "Contact" with the title "Contact Example"
    And a "Person" with the title "Person Example"
    And I set the variable "dt_shared_functions_dt_latest_visibility" to "1"
    When I am viewing a "Department" content:
      | title                                   | Content title               |
      | status                                  | 1                           |
      | field_core_links                        | test - http://test.domain   |
      | field_core_persons                      | Person Example              |
      | field_core_contact                      | Contact Example             |
      | field_core_description                  | description                 |
      | field_core_introduction                 | content intro               |
      | field_department_organigram             | File Example                |
      | field_department_work_areas_sent:value  | <h2 id="inpage">Inpage</h2> |
      | field_department_work_areas_sent:format | full_html                   |
    Then I should see an ".inpage-nav__wrapper" element
    Then I should see the following in the repeated ".inpage_nav__list-item" element within the context of the ".inpage-nav__list" element:
      | text                        |
      | Latest                      |
      | Responsibilities            |
      | Inpage                      |
      | Leadership and organisation |
      | Contact                     |
      | Related links               |
