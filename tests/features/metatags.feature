Feature: As an anonymous user
  I want to be able to see additional information in the metatags

  @api
  Scenario Outline: Anonymous users can see the date published value in the date metatag on article's
    Given I am an anonymous user
    When I am viewing a "Announcement" content:
      | title                     | <title>          |
      | field_core_date_published | <date-published> |
      | status                    | 1                |
    Then I should see "<expected-string>"
    Then the metatag attribute "date" should have the value "<expected-meta>"
    Then I should not see "access denied"

    Examples:
      | title             | date-published      | expected-string | expected-meta |
      | Test announcement | 1992-01-26 17:45:00 | 26 January 1992 | 26/01/1992    |
