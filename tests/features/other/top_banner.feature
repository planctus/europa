@api @shared
Feature: Yellow construction works banner
  In order to feel good that the Beta project is released
  As a normal user
  I don't want to see a yellow banner on top of the site

  Scenario: Anonymous user doesn't see constructions message
    Given I am not logged in
    When I go to "/index_en"
    Then I should not see the text "This is a test site for a new design and navigation for the Commission website."
