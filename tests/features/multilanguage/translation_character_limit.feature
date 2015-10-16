@api

Feature: Ignore character limit when translating Content
  In order to create appropriate translation for all languages
  As an editor
  I want to have the character limit removed from the descritpion and introduction fields

  Scenario Outline: Character limit not enforced while translating
    Given I am logged in as a user with the "administrator" role
    And the following languages are available:
      | languages |
      | en        |
      | fr        |
    When I am viewing a "basic_page" content:
        | title                   | <title>           |
        | language                | <source_language> |
        | body                    | <body>            |
        | field_core_description  | <description>     |
        | field_core_introduction | <introduction>    |
        | status                  | 1                 |

    Then I should see "<title>"
    And I edit the node
    And I see that the "edit-field-core-description-<source_language>-0-value" field has "maxlength" attribute
    And I go to add a "<target_language>" translation from "<source_language>"
    And I see that the "edit-field-core-description-<target_language>-0-value" field has no "maxlength" attribute

    Examples:
      | title        | source_language | body             | description             | introduction            | target_language |
      | EN Test page | en              | PLACEHOLDER BODY | PLACEHOLDER DESCRIPTION | PLACEHOLDER INTRO       | fr              |
      | FR Test page | fr              | PLACEHOLDER BODY | PLACEHOLDER DESCRIPTION | PLACEHOLDER INTRO       | en              |
