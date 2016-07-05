@api @shared
Feature: Display content language in meta tag
  To keep in line with the languages capitalization requirements
  As a user
  I want to see the content language in the meta tags

  Scenario Outline: Content language in meta tag
    Given I am viewing an "basic-page" content:
      | title       | <title>         |
      | description | <description>   |
      | language    | <language_code> |
    Then I should see "<title>" in the "title" element
    Then the language metatag should have the value "<language>"

    Examples:
      | title     | description | language | language_code |
      | nid en    | Node Engl   | en       | en            |
      | nid fr    | Node fren   | fr       | fr            |
      | nid pt-pt | Node PT     | pt       | pt-pt         |
