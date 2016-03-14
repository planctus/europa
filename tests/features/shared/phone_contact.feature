@api

Feature: Contact phone should be converted to HTML links.
When I log into the website
As an editor
I should be able to create contact content

  Scenario Outline:
    Given "contact" content:
      | title   | field_contact_phone_number | status |
      | <title> | <phones> <label>           | 1      |

    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "<title>"
    Then I should see the link "<phones>"
    Then I should see text matching "<label>"

    Examples:
      | phones              | title            | label                    |
      | +32 2 295 38 44     | Be Contact label | (European Commission BE) |
      | +32 2 295 38 44     | Be Contact       |                          |
      | +31 70 313 53 00    | NL Contact label | (European Commission NL) |
      | +31 70 313 53 00    | NL Contact       |                          |
      | +44 1224 649483     | UK Contact label | (European Commission UK) |
      | +44 1224 649483     | UK Contact       |                          |
      | +353 74 956 0862    | IE Contact label | (European Commission IE) |
      | +353 74 956 0862    | IE Contact       |                          |
      | +46 72 2229356      | SE Contact label | (European Commission SE) |
      | +46 72 2229356      | SE Contact       |                          |
      | +43 4363 58 50 2100 | AU Contact label | (European Commission AU) |
      | +43 4363 58 50 2100 | AU Contact       |                          |
      | +33 3 23 26 34 60   | FR Contact label | (European Commission FR) |
      | +33 3 23 26 34 60   | FR Contact       |                          |
      | +40 259 427 398     | RO Contact label | (European Commission RO) |
      | +40 259 427 398     | RO Contact       |                          |
      | +49 8331 850730     | DE Contact label | (European Commission DE) |
      | +49 8331 850730     | DE Contact       |                          |
      | +34 925 28 62 69    | SP Contact label | (European Commission SP) |
      | +34 925 28 62 69    | SP Contact       |                          |

  Scenario Outline:
    Given I am logged in as a user with the "editor" role
    When I go to "node/add/contact"
    Then I fill in the following:
      | Name         | <title>          |
      | Phone number | <phones> <label> |

    Then I press "Save"
    Then I should see "<err>"

    Examples:
      | phones             | title                              | label                            | err                                                                          |
      | +32                | Just Country Prefix                |                                  | Phone number is missing or with wrong format (+cc r xxx xx xx (description)) |
      | 2 295 38 44        | Missing Prefix                     |                                  | Country code missing or in wrong format, ex:+32                              |
      |                    | Just phone label, no phone number  | (Phone - European Commission BE) | Country code missing or in wrong format, ex:+32                              |
      | +31 70 (313) 53 00 | Phone number with the Wrong format |                                  | Phone number is missing or with wrong format (+cc r xxx xx xx (description)) |
      | 31 7053 00         | No + at the begging                |                                  | Country code missing or in wrong format, ex:+32                              |
      | +31 7053 00        | Miss ()                            | Phone - European Commission BE   | Phone number is missing or with wrong format (+cc r xxx xx xx (description)) |
      | +31 7053 00        | Miss close (                       | (Phone - European Commission BE  | Phone number is missing or with wrong format (+cc r xxx xx xx (description)) |
