@api @information @political @dt_announcement @dt_department @dt_person @dt_priority
Feature: As a visitor
  I want to see relevant articles from PRD
  So that I am informed

  Background:
    Given "Department" content:
      | title                               | field_core_abbreviation | language | status | nid    | is_new |
      | Test Energy                         | DG ENER TEST            | en       | 1      | 100000 | 1      |
      | Eurostat - European statistics      | DG ESTAT                | en       | 1      | 100001 | 1      |
      | European Anti-Fraud Office          | OLAF                    | en       | 1      | 100002 | 1      |
      | European Personnel Selection Office | EPSO                    | en       | 1      | 100003 | 1      |

    Given "Person" content:
      | title                 | field_person_first_name | field_person_last_name | field_person_role | status | nid    | is_new |
      | Commissioner John Doe | John                    | Doe                    | Commissioner      | 1      | 200000 | 1      |

    Given "Priority" content:
      | title         | language | status | nid    | is_new | field_core_latest_visibility |
      | Test Priority | en       | 1      | 300000 | 1      | Enable                       |

    Given I am logged in as a user with the "site manager, editor" roles
    And I am viewing an "News PRD Importer" importer:
      | title                           | PRD Types Import Test                                        |
      | feeds[FeedsHTTPFetcher][source] | /sites/all/modules/dev_modules/prd_rss/announcement_type.rss |
      | language                        | en                                                           |
    When I follow "Import" in the "tabs"
    And I press "Import"
    And I wait for the batch job to finish

    Given I am viewing an "News PRD Importer" importer:
      | title                           | PRD Department Import Test                            |
      | feeds[FeedsHTTPFetcher][source] | /sites/all/modules/dev_modules/prd_rss/department.rss |
      | field_core_departments          | Test Energy                                           |
      | language                        | en                                                    |
    When I follow "Import" in the "tabs"
    And I press "Import"
    And I wait for the batch job to finish

    Given I am viewing an "News PRD Importer" importer:
      | title                           | PRD Person Import Test                            |
      | feeds[FeedsHTTPFetcher][source] | /sites/all/modules/dev_modules/prd_rss/person.rss |
      | field_core_persons              | Commissioner John Doe                             |
      | language                        | en                                                |
    When I follow "Import" in the "tabs"
    And I press "Import"
    And I wait for the batch job to finish

    Given I am viewing an "News PRD Importer" importer:
      | title                           | PRD Priority Import Test                            |
      | feeds[FeedsHTTPFetcher][source] | /sites/all/modules/dev_modules/prd_rss/priority.rss |
      | field_core_priorities           | Test Priority                                       |
      | language                        | en                                                  |
    When I follow "Import" in the "tabs"
    And I press "Import"
    And I wait for the batch job to finish

  @javascript
  Scenario: Announcement types, Departments, Priorities and Persons are correctly mapped
    
    Given I go to "admin/content"
    And I follow "Press release IP"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"

    Given I go to "admin/content"
    And I follow "Press release STAT"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"
    And I go to "node/100001"
    Then I should see "Press release STAT"

    Given I go to "admin/content"
    And I follow "Press release OLAF"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"
    And I go to "node/100002"
    Then I should see "Press release OLAF"

    Given I go to "admin/content"
    And I follow "Press release EPSO"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"
    And I go to "node/100003"
    Then I should see "Press release EPSO"

    Given I go to "admin/content"
    And I follow "Press release AC"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"

    Given I go to "admin/content"
    And I follow "Factsheet"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "memo"

    Given I go to "admin/content"
    And I follow "Daily news"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "mex"

    Given I go to "admin/content"
    And I follow "Speech"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "speech"

    Given I go to "admin/content"
    And I follow "Commissioners' weekly activities"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "cldr"

    Given I go to "admin/content"
    And I follow "Upcoming events"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "agenda"

    Given I go to "admin/content"
    And I follow "Statement"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "statement"

    Given I go to "admin/content"
    And I follow "Weekly meeting"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "wm"

    Given I go to "admin/content"
    And I follow "Press release of Department"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"
    And I go to "node/100000"
    Then I should see "Press release of Department"
    And I go to "node/100002"
    Then I should see "Press release of Department"

    Given I go to "admin/content"
    And I follow "Press release of Priority"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"
    And I go to "node/300000"
    Then I should see "Press release of Priority"

    Given I go to "admin/content"
    And I follow "Press release of Person"
    And I follow "New draft" in the "tabs"
    Then the select "#edit-field-announcement-type .form-select" should be set to "press_release"
    And I click "Related content"
    Then the "edit-field-core-persons-und-0-target-id" field should contain "Commissioner John Doe (Person) (200000)"
