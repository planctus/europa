@api
Feature: I want to be see each content type in their defined URL path pattern

  @information @dt_announcement @dt_department @dt_info_homepage @dt_law @dt_page @dt_policy @dt_policy_area @dt_class @dt_tender @dt_topic
  Scenario Outline: Correct URL path pattern is generated for each content type
    Given "<content_type>" content:
      | title   | path[pathauto] | status |
      | <title> | 1              | 1      |
    And I go to "<url_pattern_prefix><url_title>"
    Then I should see "<title>" in the "title" element

    Examples:
      | content_type     | title                           | url_title                       | url_pattern_prefix |
      | Announcement     | Announcement test title         | announcement-test-title         | news/     |
      | Department       | Department test title           | department-test-title           | departments/       |
      | Homepage         | Information Homepage test title | information-homepage-test-title |                    |
      | Law              | Law test title                  | law-test-title                  | law/               |
      | Page             | Page test title                 | page-test-title                 |                    |
      | Policy           | Policy test title               | policy-test-title               | policies/          |
      | Policy area      | Policy area test title          | policy-area-test-title          | strategy/          |
      | Temporary class  | Class test title                | class-test-title                |                    |
      | Call for tenders | Tender test title               | tender-test-title               | tender/            |
      | Topic            | Topic test title                | topic-test-title                | topics/            |

  @information @dt_publication
  Scenario: Correct URL path for Publication content
    Given "Publication" content:
      | title                  | status | field_core_date_updated:value | field_core_date_updated:value2 | field_core_date_published:value | field_core_date_published:value2 |
      | Publication test title | 1      | 1969952000                    | 1969952000                     | 1400980800                      | 1400980800                       |
    And I go to "publications/publication-test-title"
    Then I should see "Publication test title" in the "title" element

  @information @dt_event
  Scenario: Correct URL path for Event content
    Given "Event" content:
      | title            | status | field_event_date:value | field_event_date:value2 | field_event_date:timezone | field_core_location             |
      | Event test title | 1      | 1969952000             | 1969952000              | Europe/Budapest           | country: BE - locality: Brussel |
    And I go to "events/event-test-title"
    Then I should see "Event test title" in the "title" element

  @political @dt_priority @dt_pri_policy_area
  Scenario Outline: Correct URL path pattern is generated for each content type of political
    Given "<content_type>" content:
      | title   | path[pathauto] | status |
      | <title> | 1              | 1      |
    And I go to "<url_pattern_prefix><url_title>"
    Then I should see "<title>" in the "title" element

    Examples:
      | content_type         | title                           | url_title                       | url_pattern_prefix |
      | Priority             | Priority test title             | priority-test-title             |                    |
      | Priority policy area | Priority policy area test title | priority-policy-area-test-title |                    |

# @cwt is missing, has to be covered once we can run tests.
