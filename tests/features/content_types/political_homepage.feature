@api @political @dt_homepage
Feature: Political Homepage different layout

  Scenario: Political Homepage has different layout and shows translated strings
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "Homepage":
      | title                   | Political hp           |
      | field_core_introduction | Political introduction |
      | status                  | 1                      |
      | language                | en                     |
      | og_group_ref            | Global editorial team  |
    And I translate the string "Highlight" to "French" with "Highlight fr"
    Then I should see "Highlight" in the ".field--field-core-introduction .field__label" element
    Then I should see "Political introduction" in the ".field--field-core-introduction .field__items p" element
    # Translation of fields and label.
    And I go to add "fr" translation
    And I fill in "title_field[fr][0][value]" with "Political hp FR"
    And I fill in "field_core_introduction[fr][0][value]" with "Political introduction FR"
    And I fill in "Moderation state" with "published"
    And I press "Save"
    Then I should see "Highlight fr" in the ".field--field-core-introduction .field__label" element
    Then I should see "Political introduction FR" in the ".field--field-core-introduction .field__items p" element
