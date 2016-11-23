@api @brp @brp_initiative @dt_nal_services @brp_feedback_form
Feature: As a product owner
  I want aliases for Initiatives to follow a defined pattern.

  Background:
    Given "nal_resource_types" terms:
      | name         | description                   |
      | ResourceType | The resource type description |

  Scenario Outline: The visitor should access initiatives on specific URL alias.
    Given "Initiative" content:
      | title            | status | field_brp_inve_reference | field_brp_inve_isc | field_core_description | path[pathauto] | field_brp_inve_resource_type | field_brp_inve_id |
      | Initiative title | 1      | Ares(2222)999999         | ISC/2016/12345     | Initiative description | 1              | ResourceType                 | 1                 |
    Then I go to "<original_alias>"
    And I should see "Initiative title" in the "h1" element
    Then I go to "<isc_alias>"
    And the current URL should be "<original_alias>"
    And I should see "Initiative title" in the "h1" element

    Examples:
      | original_alias                  | isc_alias                     |
      | initiatives/ares-2222-999999_en | initiatives/isc-2016-12345    |
      | initiatives/ares-2222-999999_en | initiatives/isc-2016-12345_en |
      | initiatives/ares-2222-999999_pt | initiatives/isc-2016-12345_pt |

  Scenario: "View this initiative" link should link to the initative page
    Given I am logged in as a user with the "Authenticated user" role
    And "Initiative" content:
      | title            | status | field_brp_inve_reference | field_brp_inve_isc | path[pathauto] | field_brp_inve_resource_type | field_brp_inve_id | field_brp_inve_fb_end_date |
      | Initiative title | 1      | Ares(2222)999999         | ISC/2016/12345     | 1              | ResourceType                 | 1                 | 1970665600                 |
    And I go to "initiatives/ares-2222-999999_en"
    And I click "Give feedback"
    Then I should see the link "View this initiative" linking to "/initiatives/ares-2222-999999_en"
    And I go to "initiatives/ares-2222-999999_fr"
    And I click "Give feedback"
    Then I should see the link "View this initiative" linking to "/initiatives/ares-2222-999999_fr"
