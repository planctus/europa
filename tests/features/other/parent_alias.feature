@api @information @political @dt_shared_functions
Feature: Aliases based on parent node's URL alias
  In order to reflect the hierarchy in the URL aliases
  As an editor
  I should be able to generate the URL alias reflecting the node's parent defined in specific fields

  @dt_page
  Scenario: Correct URL is generated for "Page"
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First page title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second page title | Content description    | Intro                   | First page title   | 1              | 1      |
    And I go to "first-page-title/second-page-title"
    Then I should see "Second page title" in the "title" element

  @dt_page
  Scenario: Circular reference is not allowed for "Page"
    Given "Page" content:
      | title                      | field_core_description | field_core_introduction | field_core_parents         | path[pathauto] | status |
      | First Circular Page title  | Content description    | Intro                   |                            | 1              | 1      |
      | Second Circular Page title | Content description    | Intro                   | First Circular Page title  | 1              | 1      |
      | Third Circular Page title  | Content description    | Intro                   | Second Circular Page title | 1              | 1      |
    Given I am logged in as a user with the "administrator" role
    And I go to "first-circular-page-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-parents-und-0-target-id" with "Second Circular Page title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"
    And I go to "first-circular-page-title/second-circular-page-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-parents-und-0-target-id" with "Third Circular Page title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"

  @dt_law
  Scenario: Correct URL is generated for "Law"
    Given "Law" content:
      | title            | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First law title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second law title | Content description    | Intro                   | First law title    | 1              | 1      |
    And I go to "law/first-law-title/second-law-title"
    Then I should see "Second law title" in the "title" element

  @dt_law
  Scenario: Circular reference is not allowed for "Law"
    Given "Law" content:
      | title                     | field_core_description | field_core_introduction | field_core_parents        | path[pathauto] | status |
      | First Circular Law title  | Content description    | Intro                   |                           | 1              | 1      |
      | Second Circular Law title | Content description    | Intro                   | First Circular Law title  | 1              | 1      |
      | Third Circular Law title  | Content description    | Intro                   | Second Circular Law title | 1              | 1      |
    Given I am logged in as a user with the "administrator" role
    And I go to "law/first-circular-law-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-parents-und-0-target-id" with "Second Circular Law title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"
    And I go to "law/first-circular-law-title/second-circular-law-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-parents-und-0-target-id" with "Third Circular Law title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"

  @javascript @dt_page
  Scenario: Alias updates after changing parents or children "Page"
    # Basic setup.
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First page title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second page title | Content description    | Intro                   | First page title   | 1              | 1      |
      | Third page title  | Content description    | Intro                   | Second page title  | 1              | 1      |
      | Fourth page title | Content description    | Intro                   | Third page title   | 1              | 1      |
    When I go to "first-page-title/second-page-title/third-page-title"
    Then I should see "Third page title" in the "h1" element
    When I go to "first-page-title/second-page-title/third-page-title/fourth-page-title"
    Then I should see "Fourth page title" in the "h1" element

    # Edits the parent field on the Third page.
    When I am logged in as a user with the "administrator" role
    And I go to "first-page-title/second-page-title/third-page-title"
    And I click "New draft" in the "tabs"
    And I click "Page Architecture"
    And I fill in the reference "edit-field-core-parents-und-0-target-id" with "First page title"
    And I click "URL path settings"
    And I check the box "Generate automatic URL alias"
    And I click "Publishing options"
    And I select "published" from "Moderation state"
    And I press the "Save" button

    When I go to "first-page-title/third-page-title"
    Then I should see "Third page title" in the "h1" element
    When I go to "first-page-title/third-page-title/fourth-page-title"
    Then I should see "Fourth page title" in the "h1" element

    # New page with children
    When I go to "node/add/basic-page_en"
    And I fill in "Type selection" with "default"
    And I fill in "title_field[und][0][value]" with "Fifth page title"
    And I fill in "Description" with "test"
    And I click "Page Architecture"
    And I fill in the reference "edit-field-core-children-und-0-target-id" with "First page title"
    And I click "Publishing options"
    And I fill in "Moderation state" with "published"
    And I press the "Save" button

    When I go to "fifth-page-title"
    Then I should see "Fifth page title" in the "h1" element
    When I go to "fifth-page-title/first-page-title"
    Then I should see "First page title" in the "h1" element
    When I go to "fifth-page-title/first-page-title/third-page-title"
    Then I should see "Third page title" in the "h1" element
    When I go to "fifth-page-title/first-page-title/third-page-title/fourth-page-title"
    Then I should see "Fourth page title" in the "h1" element

  @dt_policy_area
  Scenario: Correct URL is generated for "Policy area"
    Given "Policy area" content:
      | title                    | field_core_description | field_core_introduction | field_core_policy_areas                           | path[pathauto] | status |
      | First Policy area title  | Content description    | Intro                   |                                                   | 1              | 1      |
      | Second Policy area title | Content description    | Intro                   |                                                   | 1              | 1      |
      | Third Policy area title  | Content description    | Intro                   | First Policy area title, Second Policy area title | 1              | 1      |
    And I go to "strategy/first-policy-area-title/third-policy-area-title"
    Then I should see "Third Policy area title" in the "title" element
    And I go to "strategy/first-title/second-title"
    Then I should see "Page not found"

  @dt_policy_area
  Scenario: Circular reference is not allowed for "Policy area"
    Given "Policy area" content:
      | title                             | field_core_description | field_core_introduction | field_core_policy_areas           | path[pathauto] | status |
      | First Circular Policy area title  | Content description    | Intro                   |                                   | 1              | 1      |
      | Second Circular Policy area title | Content description    | Intro                   | First Circular Policy area title  | 1              | 1      |
      | Third Circular Policy area title  | Content description    | Intro                   | Second Circular Policy area title | 1              | 1      |
    Given I am logged in as a user with the "administrator" role
    And I go to "strategy/first-circular-policy-area-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-policy-areas-und-0-target-id" with "Second Circular Policy area title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"
    And I go to "strategy/first-circular-policy-area-title/second-circular-policy-area-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-policy-areas-und-0-target-id" with "Third Circular Policy area title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"

  @javascript @dt_page
  Scenario: Batch re-generation of aliases yield correct URLs
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First page title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second page title | Content description    | Intro                   | First page title   | 1              | 1      |
      | Third page title  | Content description    | Intro                   | Second page title  | 1              | 1      |
      | Fourth page title | Content description    | Intro                   | Third page title   | 1              | 1      |
    When I go to "first-page-title/second-page-title/third-page-title"
    Then I should see "Third page title" in the "h1" element
    When I go to "first-page-title/second-page-title/third-page-title/fourth-page-title"
    Then I should see "Fourth page title" in the "h1" element

    Given I am logged in as a user with the "administrator" role
    Then I go to "admin/config/search/path/delete_bulk"
    And I check the box "All aliases"
    And I press "Delete aliases now!"
    And I wait for the batch job to finish

    When I go to "first-page-title/second-page-title/third-page-title"
    Then I should see "Page not found" in the "h1" element
    When I go to "first-page-title/second-page-title/third-page-title/fourth-page-title"
    Then I should see "Page not found" in the "h1" element

    Then I go to "admin/config/search/path/update_bulk"
    And I check the box "Content paths"
    And I press "Update"
    And I wait for the batch job to finish

    When I go to "first-page-title/second-page-title/third-page-title"
    Then I should see "Third page title" in the "h1" element
    When I go to "first-page-title/second-page-title/third-page-title/fourth-page-title"
    Then I should see "Fourth page title" in the "h1" element

  @javascript @wip
  Scenario: Make sure parents field is limited to the same content type as the referring content
    Given "Law" content:
      | title            | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First law title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second law title | Content description    | Intro                   | First law title    | 1              | 1      |
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First page title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second page title | Content description    | Intro                   | First page title   | 1              | 1      |
    Given I am logged in as a user with the "administrator" role
    And I go to "law/first-law-title"
    And I follow "New draft" in the "tabs"
    And I click "Page Architecture"
    And I fill in "edit-field-core-parents-und-0-target-id" with "Second "
    And I wait for AJAX to finish
    Then I should see "Second law title"
    And I should not see "Second page title"

