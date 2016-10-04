@api @javascript
Feature: Entityreference
  In order to reference content
  As an editor
  I should be able to reference entitys using an autocomplete widget

  @information
  Scenario: Entityreference widgets shows the content type and ID when selecting a node
    Given "Topic" content:
      | title             | language | status | nid   | is_new |
      | Topic title       | en       | 1      | 9890  | 1      |
      | Alternative title | en       | 1      | 10000 | 1      |
    And I am logged in as a user with the "administrator" role
    And I am viewing a "Page" content:
      | title             | Page title  |
      | language          | en          |
      | status            | 1           |
      | field_core_topics | Topic title |
    And I click "New draft" in the "tabs" region
    And I click "Related"
    And I wait for AJAX to finish
    Then the "field_core_topics[und][0][target_id]" field should contain "Topic title (Topic) (9890)"
    And I select the first autocomplete option for "Alternative title" on the "field_core_topics[und][1][target_id]" field
    Then the "field_core_topics[und][1][target_id]" field should contain "Alternative title (Topic - 10000) (10000)"

