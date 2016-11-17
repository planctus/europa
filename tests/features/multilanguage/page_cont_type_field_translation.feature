@api @information
Feature: Display translated content
  As a user
  I want to see content in my preferred language

  Scenario: Quick navigation links should show in the selected language
    Given "Page" content:
      | title          | status | language | field_core_quick_nav_links   |
      | Child page one | 1      | en       | Page test link 1 - http://link1.com |
      | Child page two | 1      | en       | Page test link 2 - http://link2.com |
    And I am logged in as a user with the "administrator" role
    And I go to "admin/content"
    And I follow "Child page one"
    And I go to add "nl" translation
    And I fill in "edit-title-field-nl-0-value" with "Child page one - Dutch"
    And I fill in "field_core_quick_nav_links[nl][0][title]" with "Page test link 1 - Dutch"
    And I fill in "field_core_quick_nav_links[nl][0][url]" with "http://link1.nl"
    And I fill in "Moderation state" with "published"
    And I press "Save"

    Given I am viewing a "Page" content:
      | title               | Content title Lipsum           |
      | language            | en                             |
      | status              | 1                              |
      | field_core_children | Child page one, Child page two |
    And I create the following translations for "basic_page" content with title "Content title Lipsum":
      | title                        | status | language |
      | Content title Lipsum - Dutch | 1      | nl       |
    Then I should see "Content title Lipsum"
    Then I should see "Child page one"
    Then I should see the link "Page test link 1" linking to "http://link1.com"

    Then I change the language to "Dutch"
    Then I should see "Content title Lipsum - Dutch"
    Then I should see "Child page one - Dutch"
    Then I should see the link "Page test link 1 - Dutch" linking to "http://link1.nl"
