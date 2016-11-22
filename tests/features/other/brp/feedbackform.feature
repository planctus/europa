@api @brp @brp_feedback_form @dt_nal_services @brp_initiative
Feature: As an authenticated user I should be able to submit a feedback.
When I log into the website
As an authenticated user
I should be able to submit a feedback form

  Background:
    Given I am logged in as a user with the "administrator" role
    Then I go to "admin/structure/taxonomy/nal_countries/add"
    Then I fill in the following:
      | name                      | Bulgarian |
      | field_iso3[und][0][value] | BRG       |
    Then I press "Save"

  @wip
  Scenario Outline:
    Given I am logged in as a user with the "authenticated user" role
    When I go to "eform/submit/brp-initiatives-feedback_en"
    Then I fill in the following:
      | My feedback                  | <feedback>          |
      | Language of my feedback      | <feedback_language> |
      | I am giving my feedback as   | <usertype>          |
      | Organisation name            | <org>               |
      | Transparency register number | <trans_nr>          |
      | Organisation size            | <comp_size>         |
      | Country of origin            | <country>           |
      | Scope                        | <scope>             |
    And I press "Submit"
    Then I should see "Complete these fields and try again."
    Then I <feedback_error> see "My feedback field is required." in the "#edit-field-brp-fb-body" element
    Then I <feedback_language_error> see "Language of my feedback field is required." in the "#edit-field-brp-fb-language" element
    Then I <usertype_error> see "I am giving my feedback as field is required."
    Then I <org_error> see "Organisation name field is required."
    Then I <trans_nr_error> see "Transparency register number is invalid."
    Then I <comp_size_error> see "Organisation size field is required."
    Then I <country_error> see "Country of origin field is required."
    Then I <scope_error> see "Scope field is required."
    Then I should see "I agree with the personal data protection provisions field is required."
    Then I check "I agree with the personal data protection provisions"
    And I press "Submit"
    Then I should not see "I accept"

    Examples:
      | usertype         | usertype_error | feedback                | feedback_error | feedback_language | feedback_language_error | country | country_error | org    | org_error  | trans_nr | trans_nr_error | comp_size | comp_size_error | scope | scope_error |
      | _none            | should         |                         | should         | EN                | should not              | _none   | should        |        | should not |          | should not     | _none     | should not      | _none | should not  |
      | _none            | should         | Text feedback           | should not     | FR                | should not              | BRG     | should not    |        | should not |          | should not     | _none     | should not      | _none | should not  |
      | EU_CITIZEN       | should not     | Text feedback           | should not     | _none             | should                  | BRG     | should not    |        | should not |          | should not     | _none     | should not      | _none | should not  |
      | COMPANY          | should not     | Text feedback conpany 1 | should not     | IT                | should not              | BRG     | should not    | Foobar | should not | x12321   | should         | MICRO     | should not      | _none | should not  |
      | COMPANY          | should not     | Text feedback conpany 2 | should not     | PT                | should not              | BRG     | should not    |        | should     |          | should not     | _none     | should          | _none | should not  |
      | COMPANY          | should not     | Text feedback conpany 3 | should not     | _none             | should                  | _none   | should        |        | should     |          | should not     | _none     | should          | _none | should not  |
      | PUBLIC_AUTHORITY | should not     | Text feedback           | should not     | _none             | should                  | _none   | should        |        | should     |          | should not     | _none     | should          | _none | should      |

  @javascript
  Scenario: Users should receive a notification on navigating away from a filled in form
    Given I go to "eform/submit/brp-initiatives-feedback_en"
    And I fill in "My feedback" with "My feedback title"
    And I click "Logout"
    # As we can not yet implement:
    # Then I should receive a javascript alert
    # because it is not yet supported, we can simply check if we can change the input after clicking a link.
    # if we are able, it means that a popup blocked us from navigating away.
    And I fill in "My feedback" with "My feedback title"
