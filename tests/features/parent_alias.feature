@api @information
Feature: Aliases based on parent node's URL alias
  In order to reflect the hierarchy in the URL aliases
  As an editor
  I should be able to generate the URL alias reflecting the node's parent defined in specific fields

  Scenario: Correct URL is generated for "Page"
    Given "Page" content:
      | title            | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First page title | Content description    | Intro                   |                   | 1              | 1      |
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | Second page title | Content description    | Intro                   | First page title  | 1              | 1      |
    And I go to "first-page-title/second-page-title"
    Then I should see "Second page title" in the "title" element

  Scenario: Circular reference is not allowed for "Page"
    Given "Page" content:
      | title                     | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First Circular Page title | Content description    | Intro                   |                   | 1              | 1      |
    Given "Page" content:
      | title                      | field_core_description | field_core_introduction | field_core_parents         | path[pathauto] | status |
      | Second Circular Page title | Content description    | Intro                   | First Circular Page title | 1              | 1      |
    Given "Page" content:
      | title                     | field_core_description | field_core_introduction | field_core_parents          | path[pathauto] | status |
      | Third Circular Page title | Content description    | Intro                   | Second Circular Page title | 1              | 1      |
    Given I am logged in as a user with the "administrator" role
    # And I cannot set circular reference "field_core_parents" for "First Circular Page title" to "Second Circular Page title"
    And I go to "first-circular-page-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-parents-und-0-target-id" with "Second Circular Page title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"
    # And I cannot set circular reference "field_core_parents" for "Second Circular Page title" to "Third Circular Page title"
    And I go to "first-circular-page-title/second-circular-page-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-parents-und-0-target-id" with "Third Circular Page title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"

  Scenario: Correct URL is generated for "Policy area"
    Given "Policy area" content:
      | title                   | field_core_description | field_core_introduction | field_core_policy_areas | path[pathauto] | status |
      | First Policy area title | Content description    | Intro                   |                         | 1              | 1      |
    Given "Policy area" content:
      | title                    | field_core_description | field_core_introduction | field_core_policy_areas | path[pathauto] | status |
      | Second Policy area title | Content description    | Intro                   |                         | 1              | 1      |
    Given "Policy area" content:
      | title                   | field_core_description | field_core_introduction | field_core_policy_areas                           | path[pathauto] | status |
      | Third Policy area title | Content description    | Intro                   | First Policy area title, Second Policy area title | 1              | 1      |
    And I go to "strategy/first-policy-area-title/third-policy-area-title"
    Then I should see "Third Policy area title" in the "title" element
    And I go to "strategy/first-title/second-title"
    Then I should see "Page not found"

  Scenario: Circular reference is not allowed for "Policy area"
    Given "Policy area" content:
      | title                            | field_core_description | field_core_introduction | field_core_policy_areas | path[pathauto] | status |
      | First Circular Policy area title | Content description    | Intro                   |                         | 1              | 1      |
    Given "Policy area" content:
      | title                             | field_core_description | field_core_introduction | field_core_policy_areas          | path[pathauto] | status |
      | Second Circular Policy area title | Content description    | Intro                   | First Circular Policy area title | 1              | 1      |
    Given "Policy area" content:
      | title                            | field_core_description | field_core_introduction | field_core_policy_areas           | path[pathauto] | status |
      | Third Circular Policy area title | Content description    | Intro                   | Second Circular Policy area title | 1              | 1      |
    Given I am logged in as a user with the "administrator" role
    #And I cannot set circular reference "field_core_policy_areas" for "First Circular Policy area title" to "Second Circular Policy area title"
    And I go to "strategy/first-circular-policy-area-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-policy-areas-und-0-target-id" with "Second Circular Policy area title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"
    #And I cannot set circular reference "field_core_policy_areas" for "Second Circular Policy area title" to "Third Circular Policy area title"
    And I go to "strategy/first-circular-policy-area-title/second-circular-policy-area-title"
    And I follow "New draft" in the "tabs"
    Then I fill in the reference "edit-field-core-policy-areas-und-0-target-id" with "Third Circular Policy area title"
    When I press the "Save" button
    Then I should see "There is a circular reference between this page and one of its parent!"
