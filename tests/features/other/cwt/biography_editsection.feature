@api @cwt @cwt_biography @cwt_core
Feature: Biography content type
  I want to create a biography with an editorial section
  And I want to be able to edit the biography and change the editorial section

  Scenario: Editors create and edit editorial section on biography
    Given I am logged in as a user with the "site manager" role
    Given I am viewing an "biography" content:
      | title                      | Phil Hogan |
      | field_biography_first_name | Phil       |
      | field_biography_last_name  | Hogan      |
    Then I follow "Edit draft" in the "tabs" region
    Then I should see an ".field-name-field-editorial-section" element
