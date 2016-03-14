@api
Feature: Splash Screen features
  In order navigate on the site in my language of preference
  As a citizen of the European Union
  I want to be able to choose my language at my first site connection

# Regression test for a bug that broke the Portuguese (pt-pt) link.
# See https://webgate.ec.europa.eu/CITnet/jira/browse/NEXTEUROPA-8033
Scenario: Test language with a custom prefix
  Given I am logged in as a user with the 'administrator' role
  And the "pt-pt" language is available
  When I go to "admin/config/regional/language/edit/pt-pt"
  And I fill in "edit-prefix" with "pt"
  And I press the "Save language" button
  When I go to "/"
  Then I should see the link "português"
  When I click "português"
  Then the url should match "(.*)_pt"
