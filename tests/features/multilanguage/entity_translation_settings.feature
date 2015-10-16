@api

Feature: "Language neutral" option should not be availabe when creating content
  In order to have a clear defintion about the lanuage of a node
  As a contirbutor
  I should not be able to choose "Language neutral" as a Language for the node

  Scenario Outline: On the entity translation configuration page settings should be correct
    Given I am logged in as a user with the "administrator" role
    And I visit "admin/config/regional/entity_translation"
    Then the checkboxes "<Hide language neutral>" should be checked
    And the selects "<Default language select>" should be set to "<Default language>"

      Examples:
        | Hide language neutral | Default language select | Default language |
        |#edit-node input[id$='exclude-language-none']:not(#edit-entity-translation-settings-node-page-exclude-language-none) | #edit-node select[id$='default-language']:not(#edit-entity-translation-settings-node-page-default-language) | xx-et-default |
        # page is excluded since it is not subject to this setting.
