Feature: Aliases based on parent node's URL alias
  In order to reflect the hierarchy in the URL aliases
  As an editor
  I should be able to generate the URL alias reflecting the node's parent defined in specific fields

  @api
  Scenario: Correct URL is generated for "Page"
    Given "Page" content:
      | title            | field_core_description | field_core_introduction | field_core_parent | path[pathauto] | status |
      | First page title | Content description    | Intro                   |                   | 1              | 1      |
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parent | path[pathauto] | status |
      | Second page title | Content description    | Intro                   | First page title  | 1              | 1      |
    And I go to "first-page-title/second-page-title"
    Then I should see "Second page title" in the "title" element

  @api
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

  @api
  Scenario: Circular reference is not allowed
    Given "Policy area" content:
      | title                | field_core_description | field_core_introduction | field_core_policy_areas | path[pathauto] | status |
      | First Circular title | Content description    | Intro                   |                         | 1              | 1      |
    Given "Policy area" content:
      | title                 | field_core_description | field_core_introduction | field_core_policy_areas | path[pathauto] | status |
      | Second Circular title | Content description    | Intro                   | First Circular title    | 1              | 1      |
    Given "Policy area" content:
      | title                | field_core_description | field_core_introduction | field_core_policy_areas | path[pathauto] | status |
      | Third Circular title | Content description    | Intro                   | Second Circular title   | 1              | 1      |

    Given I am logged in as a user with the "administrator" role
    And I cannot set circular reference "field_core_policy_areas" for "First Circular title" to "Third Circular title"