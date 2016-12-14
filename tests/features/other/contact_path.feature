@api @shared @dt_core
Feature: Contact path.
  As an editor
  I can create content that is at "/contact"
  So users do not see the contact form there

  Scenario: Contact form is not at "/contact"
    Given I go to "/contact"
    Then I should not see the heading "Contact"
    But I should see the heading "Page not found"
    Given I go to "/contact-form"
    Then I should see the heading "Contact"
    And I should see the button "Send message"

  Scenario: I can create a page at "/contact"
    Given "Page" content:
      | title   | body      | status | path[pathauto] |
      | Contact | Body text | 1      | 1              |
    And I go to "/contact"
    Then I should see the heading "Contact"
    And I should see "Body text"

