Feature: Display some specific languages in lower case
  To keep in line with the languages capitalization requirements
  As an administrator user
  I want to see some languages in lower case on the languages page

  @api
  Scenario Outline: Some lowercase languages on languages pages
    Given I am logged in as a user with the "administrator" role
    And am on "admin/config/regional/language"
    Then the language <language> should be <case>
    And the language <language> should have weight <weight>

    Examples:
      | language | case    | weight  |
      | "bg"     | "lower" | "-20"   |
      | "cs"     | "lower" | "-19"   |
      | "da"     | "lower" | "-18"   |
      | "de"     | "upper" | "-17"   |
      | "et"     | "lower" | "-16"   |
      | "el"     | "lower" | "-15"   |
      | "en"     | "upper" | "-14"   |
      | "es"     | "lower" | "-13"   |
      | "fr"     | "lower" | "-12"   |
      | "ga"     | "upper" | "-11"   |
      | "hr"     | "lower" | "-10"   |
      | "it"     | "upper" | "-9"    |
      | "lv"     | "lower" | "-8"    |
      | "lt"     | "lower" | "-7"    |
      | "hu"     | "lower" | "-6"    |
      | "mt"     | "upper" | "-5"    |
      | "nl"     | "upper" | "-4"    |
      | "pl"     | "lower" | "-3"    |
      | "pt-pt"  | "lower" | "-2"    |
      | "ro"     | "lower" | "-1"    |
      | "sk"     | "lower" | "0"     |
      | "sl"     | "lower" | "1"     |
      | "fi"     | "lower" | "2"     |
      | "sv"     | "lower" | "3"     |
