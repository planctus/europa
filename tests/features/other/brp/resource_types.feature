@api @brp @dt_nal_services @brp_initiative @dt_page
Feature: As a product owner
  I want the resource type descriptions displayed with links.

  Scenario: The links in resource type description support tokens.
    Given "Page" content:
      | title           | status | path[pathauto] |
      | Test page title | 1      | 1              |
    Given "nal_resource_types" terms:
      | name         | description                                     |
      | NalResourceType | test-page-title_[dt_tokens:dt_content_language] |
    Given "Initiative" content:
      | title            | status | field_brp_inve_reference | field_brp_inve_isc | field_core_description | path[pathauto] | field_brp_inve_resource_type | field_brp_inve_id |
      | Initiative title | 1      | Ares(2222)999999         | ISC/2016/12345     | Initiative description | 1              | NalResourceType                 | 1                 |
    Then I go to "initiatives/ares-2222-999999_en"
    Then I should see "test-page-title_en"
