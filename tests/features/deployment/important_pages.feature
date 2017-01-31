@api @javascript @deploymenttest
Feature: Tests post/pre deployment pages
  This feature tests a few important things known to be broken on production after deployment.
  These scenarios should never involve authentication.

  Scenario Outline: Pages are live
    Given I am on "<url>"
    Then I should see "<text>"

    Examples:
      | url                                 | text                                                        |
      | https://ec.europa.eu/info/          | ελληνικά                                                    |
      | https://ec.europa.eu/info/topics_en | Topics (36)                                                 |
      | https://ec.europa.eu/info/strategy  | Learn how EU strategy seeks to promote peace and well-being |
      | https://ec.europa.eu/info/contact   | Questions about the European Union                          |
