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
        | title        | <title>           |
        | language     | <source_language> |
        | body         | <body>            |
        | field_core_description | <description>     |
        | field_core_introduction | <introduction>    |
        | status       | 1                 |

    Then I should see "<title>"
    And I edit the node
    And I fill "Introduction" with "5000" characters of dummy text
    And I fill "Description" with "5000" characters of dummy text
    And I press the "Save" button
    Then I should see "Description cannot be longer than "
    # Then I should see "Introduction cannot be longer than "
    And I go to add a "<target_language>" translation from "<source_language>"
    And I fill "Introduction" with "5000" characters of dummy text
    And I fill "Description" with "5000" characters of dummy text
    And I press the "Save" button
    Then I should not see "Description cannot be longer than "
    # Then I should not see "Introduction cannot be longer than "
    # Then print current page

    Examples:
      | title        | source_language | body             | description  | introduction | target_language |
      | EN Test page | en       | PLACEHOLDER BODY | PLACEHOLDER DESCRIPTION | PLACEHOLDER INTRO       | fr      |
      | FR Test page | fr       | PLACEHOLDER BODY | PLACEHOLDER DESCRIPTION | PLACEHOLDER INTRO       | en      |
