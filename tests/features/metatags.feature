@api
Feature: As an anonymous user
  I want to be able to see additional information in the metatags

  @information @political
  Scenario Outline: Anonymous users can see the date published value in the date metatag on article's
    Given I am an anonymous user
    When I am viewing a "Announcement" content:
      | title                     | <title>          |
      | field_core_date_published | <date-published> |
      | status                    | 1                |
    Then I should see "<expected-string>"
    Then the metatag attribute "date" should have the value "<expected-meta>"

    Examples:
      | title             | date-published      | expected-string | expected-meta |
      | Test announcement | 696384000 | 26 January 1992 | 26/01/1992    |

  @api @brp
  Scenario: Users should see the meta description on Initiative content.
    Given I am viewing a "Initiative" content:
      | title                  | Initiative Title            |
      | field_core_description | Initiative meta description |
      | status                 | 1                           |
    Then the metatag attribute "description" should have the value "Initiative meta description"
