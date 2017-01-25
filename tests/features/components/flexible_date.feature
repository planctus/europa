@api @shared
Feature: Ability to add a field with a date and a granularity

  Scenario: Check sorting of flexible date.
    And I visit "test-view"
    Then the ".views-row-1 .views-field-field-test-flexible-date .field-content" element should contain "31 December 2016"
    Then I should see "31 December 2016" in the ".views-row-1 .views-field-field-test-flexible-date .field-content" element
    Then I should see "December 2016" in the ".views-row-2 .views-field-field-test-flexible-date .field-content" element
    Then I should see "2016" in the ".views-row-3 .views-field-field-test-flexible-date .field-content" element
    Then I should see "02 January 2017" in the ".views-row-4 .views-field-field-test-flexible-date .field-content" element
    Then I should see "January 2017" in the ".views-row-5 .views-field-field-test-flexible-date .field-content" element
    Then I should see "2017" in the ".views-row-6 .views-field-field-test-flexible-date .field-content" element
    And I visit "test-view-desc"
    Then I should see "02 January 2017" in the ".views-row-1 .views-field-field-test-flexible-date .field-content" element
    Then I should see "January 2017" in the ".views-row-2 .views-field-field-test-flexible-date .field-content" element
    Then I should see "2017" in the ".views-row-3 .views-field-field-test-flexible-date .field-content" element
    Then I should see "31 December 2016" in the ".views-row-4 .views-field-field-test-flexible-date .field-content" element
    Then I should see "December 2016" in the ".views-row-5 .views-field-field-test-flexible-date .field-content" element
    Then I should see "2016" in the ".views-row-6 .views-field-field-test-flexible-date .field-content" element

  Scenario: The granular date field widget should be functional.
    Given I am logged in as a user with the "administrator" role
    When I go to "node/add/dt-test-content-type_en"
    Then I should see "Date" in the ".field-type-dt-flexible-date .fieldset-wrapper .form-type-textfield label" element
    And I should see "Display Granularity" in the ".field-type-dt-flexible-date .fieldset-wrapper .form-type-select label" element
    And I should see "test flexible date" in the ".fieldset-legend" element
