@api @brp @brpMock
Feature: Tests initiatives and feedback using the brp webservice mock
  In order to test the webservice behaviour on the site
  We need to be able to use the mock

  Background:
    Given I am logged in as a user with the "administrator" role
    And I go to "/admin/structure/taxonomy/nal_resource_types/add"
    And I fill in the following:
      | Name           | ResourceType              |
      | Authority code | RES_TYP                   |
      | Description    | Resource type description |
    And I press "Save"

    Then I go to "admin/structure/taxonomy/nal_countries/add"
    Then I fill in the following:
      | name                      | Bulgarian |
      | field_iso3[und][0][value] | BRG       |
    Then I press "Save"

  Scenario: Initiatives can be loaded using the mock
    Given I am on "/initiatives"
    Then I should see the link "ARMEN TEST ON ACCEPTANCE"
    And I click "Next" in the "pager"
    Then I should see the link "Clean air and water quality improvement"

  Scenario: "Clean air and water quality improvement" should contain feedback
    Given I am on "/initiatives"
    And I click "Next" in the "pager"
    And I follow "Clean air and water quality improvement"
    Then I should see "Recent feedback"
    Then I should see "This feedback was removed because it broke the rules."

  Scenario: Inpage navigation should not show "Recent feedback" if no feedback is available
    Given I am on "/initiatives"
    And I follow "ARMEN TEST ON ACCEPTANCE"
    Then I should not see "Recent feedback"

  Scenario: Inpage navigation should show "Recent feedback" if feedback is available
    Given I am on "/initiatives"
    And I click "Next" in the "pager"
    And I follow "Clean air and water quality improvement"
    Then I should see the following in the repeated ".inpage_nav__list-item" element within the context of the ".inpage-nav__list" element:
      | text                  |
      | About this initiative |
      | Give your feedback    |
      | Recent feedback       |

  Scenario: I should be able to view and report feedback
    Given I am on "/initiatives"
    And I click "Next" in the "pager"
    And I follow "Clean air and water quality improvement"
    And I follow "Polska Izba Książki (POL)"
    Then I should see "Feedback from:"
    Then I should see "Report an issue with this feedback"

  Scenario: I should not be able to view reported feedback
    Given I am on "/initiatives"
    And I click "Next" in the "pager"
    And I follow "Clean air and water quality improvement"
    And I follow "Hugh PRIOR (COD)"
    Then I should see "We removed this feedback because it violated the feedback rules. Any feedback item users report to us as inappropriate will be examined and removed if necessary. Please take a look at the feedback rules to learn more about the content guidelines for this website."

  Scenario: I can submit feedback
    Given I am logged in as a user with the "authenticated user" role
    And I go to "/user"
    And I click "Edit" in the "tabs"
    Then I fill in the following:
      | First name | John |
      | Last name  | Doe  |
    Then I press "Save"
    And I am on "/initiatives"
    And I follow "ARMEN TEST ON ACCEPTANCE"
    And I follow "Give feedback"
    Then I fill in the following:
      | My feedback                | Feedback   |
      | Language of my feedback    | EN         |
      | I am giving my feedback as | EU_CITIZEN |
      | Country of origin          | BRG        |
    And I check the box "I agree with the personal data protection provisions"
    And I press "Submit"
    Then I should see "Thank you for your feedback. Your contribution informs us about your views on EU laws in the making."
    Then I should see "Feedback received on:"
    Then I should see "ARMEN TEST ON ACCEPTANCE" in the "h1 span" element
