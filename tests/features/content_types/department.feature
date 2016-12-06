@api @information @political @dt_department
Feature: Department related tests

  Scenario: The visitor should see the main task in the search.
    Given I go to "/departments"
    Then I should have the following options for "Main task":
      | Policy-making and implementation   |
      | Managing programmes                |
      | Publications, archives, statistics |
      | Support to the public              |
      | Support to EU institutions         |
    And I translate the term "Policy-making and implementation" to "French" with "Élaboration et mise en œuvre des politiques"
    And I translate the term "Managing programmes" to "French" with "Gestion des programmes"
    And I translate the term "Publications, archives, statistics" to "French" with "Publications, statistiques, archives"
    And I translate the term "Support to the public" to "French" with "Soutien au public"
    And I translate the term "Support to EU institutions" to "French" with "Soutien aux institutions"
    When I go to "/departments_fr"
    Then I should have the following options for "Main task":
      | Élaboration et mise en œuvre des politiques |
      | Gestion des programmes                      |
      | Publications, statistiques, archives        |
      | Soutien au public                           |
      | Soutien aux institutions                    |
