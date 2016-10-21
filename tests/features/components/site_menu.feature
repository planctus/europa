@api @information
Feature: Site menu

  Scenario: Site menu should follow interface language
    Given "Temporary class" content:
      | title           | status | language | is_new | nid   |
      | Class 1 English | 1      | en       | 1      | 13337 |
    And I create the following translations for "class" content with title "Class 1 English":
      | title          | status | language |
      | Class 1 Dutch  | 1      | nl       |
      | Class 1 French | 1      | fr       |

    And I am logged in as a user with the "Administrator" role
    And I am on "/block/information-site-menu/edit"
    And I fill in the following:
      | field_site_menu_classes[und][0][target_id] | Class 1 English (13337) |
      | field_site_menu_links[en][0][title]        | Link title EN           |
      | field_site_menu_links[en][0][url]          | http://google.com       |
      | field_site_menu_topic_link[en][0][title]   | Topics link EN          |
      | field_site_menu_topic_link[en][0][url]     | /topics                 |
    And I press "Save"

    And I am on "/block/information-site-menu/edit/add/en/nl_nl"
    And I fill in the following:
      | field_site_menu_links[nl][0][title]      | Link title NL    |
      | field_site_menu_links[nl][0][url]        | http://google.nl |
      | field_site_menu_topic_link[nl][0][title] | Topics link NL   |
      | field_site_menu_topic_link[nl][0][url]   | /topics          |
    And I press "Save"

    And I am on "/block/information-site-menu/edit/add/en/fr_fr"
    And I fill in the following:
      | field_site_menu_links[fr][0][title]      | Link title FR    |
      | field_site_menu_links[fr][0][url]        | http://google.fr |
      | field_site_menu_topic_link[fr][0][title] | Topics link FR   |
      | field_site_menu_topic_link[fr][0][url]   | /topics          |
    And I press "Save"

    And I am viewing a "Page" content:
      | title    | Content title Lipsum - English |
      | status   | 1                              |
      | language | en                             |
    And I create the following translations for "basic_page" content with title "Content title Lipsum - English":
      | title                        | status | language |
      | Content title Lipsum - Dutch | 1      | nl       |

    Then I should see the link "Class 1 English"
    Then I should see the link "Link title EN"
    Then I should see the link "Topics link EN"

    And I change the language to "Dutch"
    Then I should see the link "Class 1 Dutch"
    Then I should see the link "Link title NL"
    Then I should see the link "Topics link NL"

    And I change the language to "French"
    Then I should see the link "Class 1 French"
    Then I should see the link "Link title FR"
    Then I should see the link "Topics link FR"
