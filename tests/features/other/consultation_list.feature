@api @information @dt_consultation
Feature: Consultation content type
  In order to get the latest transformation of the consultation content type
  As an anonymous user
  I should see the information of the page in a specific way

  Background:
    Given "Policy area" content:
      | title      | language | status |
      | PolicyArea | en       | 1      |
    Given "Consultation" content:
      | title               | status | field_core_date_opening:value | field_core_date_closing:value | field_core_policy_areas | field_core_description |
      | "Open Consultation" | 1      | 1452086424                    | 1578316824                    | PolicyArea              | Consultation text open |
    Given "Consultation" content:
      | title                | status | field_core_date_opening:value | field_core_date_closing:value | field_core_policy_areas | field_core_description   |
      | "Close Consultation" | 1      | 1480604808                    | 1481034166                    | PolicyArea              | Consultation text closed |

  Scenario: Consultation search page should offer user a way search and view
    Consultations.
    Given I am logged in as a user with the "administrator" role
    And I go to "consultations"
    # Consultation Content in main content section.
    Then I should see "Consultation status: Open" in the "#block-system-main .field--consultation-status-label .label--highlight" element
    And I should see "Consultation status: Closed" in the "#block-system-main .field--consultation-status-label .label--status" element
    And I should see "Consultation period" in the "#block-system-main .field--consultation-period" element
    And I should see "Policy area" in the "#block-system-main .field--field-core-policy-areas" element
   # Views counter top.
    And I should see an ".filters__result-count .filters__items-number" element
    And the element ".filters__result-count .filters__items-number" should contain text
    And I should see "Consultations (2)" in the ".filters__result-count .filters__items-number" element
   # Exposed options.
    And I should see "Contains" in the ".page-content .views-exposed-form" element
    And I should see "Consultation status" in the ".page-content .views-exposed-form" element
    And I should see "Consultation end date" in the ".page-content .views-exposed-form" element
    And I should see "Consultation start date" in the ".page-content .views-exposed-form" element
    And I should see "Policy area" in the ".page-content .views-exposed-form" element
   # Searching for open/closed consultations
    Then I select "closed" from "Consultation status"
    And I press "Refine results"
    And I should not see "Consultation status: Open"
   # Faceted information.
    And I should see "Closed" in the "#block-system-main .filters__active-facet-value" element
    Then I select "open" from "Consultation status"
    And I press "Refine results"
    And I should not see "Consultation status: Closed"
   # Faceted information.
    And I should see "Open" in the "#block-system-main .filters__active-facet-value" element
   # Editing open Consultation end date to past date should update the Consultation status to past.
    Then I follow "Open Consultation"
    And I follow "New draft" in the "tabs"
    And I fill in "field_core_date_opening[und][0][value][date]" with "01/12/2016"
    And I fill in "field_core_date_closing[und][0][value][date]" with "04/12/2016"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    # View the change in the listing page, both Consultations are now closed.
    Then I go to "consultations"
    And I should not see "Consultation status: Open"
