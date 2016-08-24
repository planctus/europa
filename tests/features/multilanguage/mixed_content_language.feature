@api @information
Feature: Display mixed content
  As a user
  I want to see my content
  In my preferred language

  Scenario: View translated node should display the translated entity references
    Given "Topic Top Link" content:
      | title               | status | language |
      | first top title     | 1      | en       |
      | secondary top title | 1      | en       |
    And I create the following translations for "toplink" content with title "first top title":
      | title              | status | language |
      | first top title nl | 1      | nl       |
    Given I am viewing a "Topic" content:
      | title             | Topic title                          |
      | field_topic_tasks | first top title, secondary top title |
      | status            | 1                                    |
      | language          | en                                   |
    And I create the following translations for "topic" content with title "Topic title":
      | title          | status | language |
      | Topic titel nl | 1      | nl       |
    Then I should see "first top title"
    Then I should see "secondary top title"
    Then I change the language to "Dutch"
    Then I should see "first top title nl"
    Then I should see "secondary top title"

  Scenario: I can use the secondary language preference
    Given "Topic Top Link" content:
      | title               | status | language |
      | first top title     | 1      | en       |
      | secondary top title | 1      | en       |
    And I create the following translations for "toplink" content with title "first top title":
      | title              | status | language |
      | first top title nl | 1      | nl       |
    Given I am viewing a "Topic" content:
      | title             | Topic title                          |
      | field_topic_tasks | first top title, secondary top title |
      | status            | 1                                    |
      | language          | en                                   |
    And I create the following translations for "topic" content with title "Topic title":
      | title          | status | language |
      | Topic titel nl | 1      | nl       |
    Then I change the language to "French"
    And I follow "Nederlands" in the "secondary_language_selector"
    Then I should see "Topic titel nl"
    Then I should see "first top title nl"
    Then I should see "secondary top title"

  Scenario: If the content is not available in the interface language, entity reference should fall back to the content language
    Given "Topic Top Link" content:
      | title               | status | language |
      | first top title     | 1      | en       |
      | secondary top title | 1      | en       |
    And I create the following translations for "toplink" content with title "first top title":
      | title              | status | language |
      | first top title nl | 1      | nl       |
    Given I am viewing a "Topic" content:
      | title             | Topic title                          |
      | field_topic_tasks | first top title, secondary top title |
      | status            | 1                                    |
      | language          | en                                   |
    Then I should see "first top title"
    Then I should see "secondary top title"
    Then I change the language to "Dutch"
    Then I should see "first top title"
    Then I should see "secondary top title"
    Then I should not see "first top title nl"
