@api @information @dt_page @dt_publication
Feature: Publication List shows on page bottom with filters that have or not default values.
  As an anonymous user
  I should be able to filter publications.

  Background:
    Given "Tags" terms:
      | name  |
      | Color |
    Given "tags" terms:
      | name  | parent |
      | Red   | Color  |
      | Green | Color  |
      | Blue  | Color  |
    Given "publication_types" terms:
      | name       |
      | Other type |
      | Pub type   |
    Given "eurovoc" terms:
      | name    |
      | Topic 1 |
      | Topic 2 |
    Given "Publication" content:
      | title    | field_core_date_updated:value | field_core_date_updated:value2 | field_core_date_published:value | field_core_date_published:value | field_core_description | field_publication_collection | field_publication_type | status | field_core_tags | field_eurovoc_taxonomy |
      | Pub 2014 | 1400980800                    | 1400980800                     | 1400980800                      | 1400980800                      | Content description    | 0                            | Pub type               | 1      | Color, Red      | Topic 1                |
      | Pub 2016 | 1483099200                    | 1483099200                     | 1483099200                      | 1483099200                      | Content description    | 0                            | Other type             | 1      | Color, Green    | Topic 2                |

  Scenario: One page without Publication List
    Given I am viewing a "Page" content:
      | title    | Page w/o Pub List |
      | language | en                |
      | status   | 1                 |
    Then I should see "Page w/o Pub List"
    Then I should not see "Publications" in the ".page-content" element

  Scenario: One page with Publication List and all filters exposed
    Given I am viewing a "Page" content:
      | title                         | Page w/ Pub List |
      | field_publications_visibility | 1                |
      | field_publications_topic_on   | 1                |
      | field_publications_country_on | 1                |
      | field_publications_year_on    | 1                |
      | field_publications_type_on    | 1                |
      | field_publications_tag_on     | 1                |
      | language                      | en               |
      | status                        | 1                |
    Then I should see "Page w/ Pub List"
    Then I should see "Publications" in the ".page-content" element
    Then I should see "Topic" in the ".page-content .views-exposed-form" element
    Then I should see "Country" in the ".page-content .views-exposed-form" element
    Then I should see "Year" in the ".page-content .views-exposed-form" element
    Then I should see "Publication type" in the ".page-content .views-exposed-form" element
    Then I should see "Tag" in the ".page-content .views-exposed-form" element
    Then I should see "- All countries -" in the "#edit-field-core-nal-countries-tid-selective" element
    Then I should see "- All years -" in the "#edit-field-core-date-published-value-value-year" element
    Then I should see "- All publication types -" in the "#edit-field-publication-type-tid-i18n" element
    Then I should see "- All tags -" in the "#edit-field-core-tags-tid-i18n" element

  Scenario: One page with Publication List and one filter exposed
    Given I am viewing a "Page" content:
      | title                         | Page w/ Pub List |
      | field_publications_visibility | 1                |
      | field_publications_topic_on   | 0                |
      | field_publications_country_on | 1                |
      | field_publications_year_on    | 0                |
      | field_publications_type_on    | 0                |
      | field_publications_tag_on     | 0                |
      | language                      | en               |
      | status                        | 1                |
    Then I should see "Country" in the ".page-content .views-exposed-form" element
    Then I should not see "Topic" in the ".page-content .views-exposed-form" element
    Then I should not see "Year" in the ".page-content .views-exposed-form" element
    Then I should not see "Publication type" in the ".page-content .views-exposed-form" element
    Then I should not see "Tag" in the ".page-content .views-exposed-form" element

  Scenario: One page with Publication List, one filter exposed with default value
    Given I am viewing a "Page" content:
      | title                         | Page w/ Pub List |
      | field_publications_visibility | 1                |
      | field_publications_country_on | 0                |
      | field_publications_year_on    | 1                |
      | field_publications_year       | 1451649600       |
      | field_publications_type_on    | 0                |
      | field_publications_tag_on     | 0                |
      | language                      | en               |
      | status                        | 1                |
    Then I should see "Year" in the ".page-content .views-exposed-form" element
    Then the selects ".page-content .views-exposed-form .date-year" should be set to "2016"
    Then I should see "Pub 2016" in the ".page-content .view-content" element
    Then I should not see "Pub 2014" in the ".page-content .view-content" element

  Scenario: One page with Publication List, filter not exposed but with default value
    Given I am viewing a "Page" content:
      | title                         | Page w/ Pub List |
      | field_publications_visibility | 1                |
      | field_publications_topic_on   | 0                |
      | field_publications_country_on | 0                |
      | field_publications_year_on    | 0                |
      | field_publications_year       | 1388577600       |
      | field_publications_type_on    | 0                |
      | field_publications_tag_on     | 0                |
      | language                      | en               |
      | status                        | 1                |
    Then I should not see an ".page-content .views-exposed-form" element
    Then I should see "Pub 2014" in the ".page-content .view-content" element
    Then I should not see "Pub 2016" in the ".page-content .view-content" element

  Scenario: Publication filters should be selective
    Given I am viewing a "Page" content:
      | title                         | Page w/ Pub List |
      | field_publications_visibility | 1                |
      | field_publications_topic_on   | 1                |
      | field_publications_country_on | 1                |
      | field_publications_year_on    | 1                |
      | field_publications_type_on    | 1                |
      | field_publications_tag_on     | 1                |
      | language                      | en               |
      | status                        | 1                |
      | field_publications_tag        | Color            |
    Then the "#edit-field-publication-type-tid-i18n" element should not contain "Color"
    And I should see "Color" in the ".facet-tag__value.filters__active-facet-value" element
    When I select "Red" from "Tags"
    And I press "Refine results"
    Then I should see "Red" in the ".facet-tag__value.filters__active-facet-value" element
    And the "#edit-field-core-tags-tid-i18n" element should not contain "Color"
    When I select "- Any -" from "Tags"
    And I press "Refine results"
    Then the "#edit-field-core-tags-tid-i18n" element should not contain "Color"
    And I should see "Color" in the ".facet-tag__value.filters__active-facet-value" element
    Then the "#edit-field-core-tags-tid-i18n" element should contain "Blue"
    And the "#edit-field-core-tags-tid-i18n" element should contain "Green"
    And the "#edit-field-eurovoc-taxonomy-target-id-selective" element should contain "Topic 1"
    And the "#edit-field-eurovoc-taxonomy-target-id-selective" element should contain "Topic 2"
    And the "#edit-field-publication-type-tid-i18n" element should contain "Pub type"
    And the "#edit-field-publication-type-tid-i18n" element should contain "Other type"
