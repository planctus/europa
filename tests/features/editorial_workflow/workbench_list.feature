@api @information
Feature: In order to guarantee that content can be managed only by the appropriate users
  As a product owner
  I want to have the editorial workflow control access

  Background:
    Given users:
      | name         | mail                    | status | roles       |
      | Mike_First   | MikeFirst@example.com   | 1      |             |
      | Agatha_First | AgathaFirst@example.com | 1      | contributor |

    Given "Announcement" content:
      | title              | status | workbench_moderation_state_new | author       |
      | Draft announcement | 0      | needs_review                   | Agatha_First |

  Scenario: users can find and manage content in Workbench lists
    Given I am logged in as a user with the "administrator" role
    When I go to "admin/content"
    And I follow "Draft announcement"
    And I follow "Edit draft"
    Then show last response
