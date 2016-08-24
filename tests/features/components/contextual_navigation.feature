@api
Feature: Contextual navigation
  In order to see related content
  As an editor
  I should be able to add related content on content types
  As an anonymous user
  I should be able to see contextual links on content

  Background:
    Given "Person" content:
      | title                             | field_person_first_name | field_person_last_name | field_person_role | status |
      | Commissioner John Weekley         | John                    | Weekley                | Commissioner      | 1      |
      | Commissioner Jennifer Vazquez     | Jennifer                | Vazquez                | Commissioner      | 1      |
      | President Charlie Trusty          | Charlie                 | Trusty                 | President         | 1      |
      | President Janet Llanos            | Janet                   | Llanos                 | President         | 1      |
      | Vice-president Christine Gonzalez | Christine               | Gonzalez               | Vice-president    | 1      |

  @information
  Scenario: Dynamic label for related persons with different roles
    Given I am viewing a "Policy" content:
      | title              | Policy                                                                                                                |
      | field_core_persons | Vice-president Christine Gonzalez, Commissioner John Weekley, Commissioner Jennifer Vazquez, President Charlie Trusty |
      | status             | 1                                                                                                                     |
    Then I should see "Commissioner" in the ".context-nav .context-nav__label" element
    Then I should see "Vice-president Christine Gonzalez" in the ".context-nav .context-nav__items" element
    Then I should not see "Commissioner John Weekley" in the ".context-nav .context-nav__items" element
    Then I should see "John Weekley" in the ".context-nav .context-nav__items" element
    Then I should not see "Commissioner Jennifer Vazquez" in the ".context-nav .context-nav__items" element
    Then I should see "Jennifer Vazquez" in the ".context-nav .context-nav__items" element
    Then I should see "President Charlie Trusty" in the ".context-nav .context-nav__items" element

  @information
  Scenario: Dynamic label for related persons with equal roles (non commissioner)
    Given I am viewing a "Policy" content:
      | title              | Policy                                           |
      | field_core_persons | President Janet Llanos, President Charlie Trusty |
      | status             | 1                                                |
    Then I should see "President" in the ".context-nav .context-nav__label" element
    Then I should not see "President Janet Llanos" in the ".context-nav .context-nav__items" element
    Then I should not see "President Charlie Trusty" in the ".context-nav .context-nav__items" element
    Then I should see "Charlie Trusty" in the ".context-nav .context-nav__items" element
    Then I should see "Janet Llanos" in the ".context-nav .context-nav__items" element

  @information
  Scenario: Dynamic label for related persons with equal roles
    Given I am viewing a "Policy" content:
      | title              | Policy                                                   |
      | field_core_persons | Commissioner John Weekley, Commissioner Jennifer Vazquez |
      | status             | 1                                                        |
    Then I should see "Commissioner" in the ".context-nav .context-nav__label" element
    Then I should not see "Commissioner John Weekley" in the ".context-nav .context-nav__items" element
    Then I should not see "Commissioner Jennifer Vazquez" in the ".context-nav .context-nav__items" element
    Then I should see "John Weekley" in the ".context-nav .context-nav__items" element
    Then I should see "Jennifer Vazquez" in the ".context-nav .context-nav__items" element
