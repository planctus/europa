@api

Feature: Only consultations should be visible.
When I log into the website
As an editor
I should be able to create consulation content

  Scenario: Adding a consultation
    Given "consultation" content:
      | title             | field_core_description |
      | Consulation title | Content description    |

    Given "policy" content:
      | title                    | field_core_introduction | field_policy_input |
      | Policy with consultation | Introduction            | Consulation title  |


    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Policy with consultation"
    Then I should see text matching "Consultation"


  Scenario: Description meta tag
    Given "impact_assessment" content:
      | title                   |
      | Impact Assessment title |

    Given "policy" content:
      | title                  | field_core_introduction | field_policy_input |
      | Policy with assessment | Introduction            | Impact Assessment title  |


    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Policy with assessment"
    Then I should not see "Impact Assessment"