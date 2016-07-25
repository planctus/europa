@api @information
Feature: In order to guarantee that content can be managed only by the appropriate users
  As a product owner
  I want to have the editorial workflow control access

  Background:
    Given users:
      | name           | mail                      | status | roles       |
      | Mike_First     | MikeFirst@example.com     | 1      |             |
      | Agatha_First   | AgathaFirst@example.com   | 1      | contributor |
      | Vanessa_First  | VanessaFirst@example.com  | 1      | contributor |
      | Rocky_First    | RockyFirst@example.com    | 1      | contributor |
      | Mike_Second    | MikeSecond@example.com    | 1      |             |
      | Agatha_Second  | AgathaSecond@example.com  | 1      | contributor |
      | Vanessa_Second | VanessaSecond@example.com | 1      | contributor |
      | Rocky_Second   | RockySecond@example.com   | 1      | contributor |
      | Mike_Both      | MikeBoth@example.com      | 1      |             |
      | Agatha_Both    | AgathaBoth@example.com    | 1      | contributor |
      | Vanessa_Both   | VanessaBoth@example.com   | 1      | contributor |
      | Rocky_Both     | RockyBoth@example.com     | 1      | contributor |

    Given I am viewing an "editorial_team" content:
      | title                        | First team               |
      | status                       | 1                        |
      | language                     | en                       |
      | og_roles_permissions[und]    | 0                        |
      | field_editorial_types[und][] | announcement, basic-page |
    And I add "Mike_First" to the group as "member"
    And I add "Agatha_First" to the group as "author"
    And I add "Vanessa_First" to the group as "validator"
    And I add "Rocky_First" to the group as "reviewer"
    And I add "Mike_Both" to the group as "member"
    And I add "Agatha_Both" to the group as "author"
    And I add "Vanessa_Both" to the group as "validator"
    And I add "Rocky_Both" to the group as "reviewer"

    Given I am viewing an "editorial_team" content:
      | title                        | Second team              |
      | status                       | 1                        |
      | language                     | en                       |
      | og_roles_permissions[und]    | 0                        |
      | field_editorial_types[und][] | announcement, department |
    And I add "Mike_Second" to the group as "member"
    And I add "Agatha_Second" to the group as "author"
    And I add "Vanessa_Second" to the group as "validator"
    And I add "Rocky_Second" to the group as "reviewer"
    And I add "Mike_Both" to the group as "member"
    And I add "Agatha_Both" to the group as "author"
    And I add "Vanessa_Both" to the group as "validator"
    And I add "Rocky_Both" to the group as "reviewer"

    Given "announcement" content with revisions:
      | title                  | status | workbench_moderation_state_new | og_group_ref | author        |
      | Draft1                 | 0      | draft                          | First team   | Agatha_First  |
      | Draft2                 | 0      | draft                          | Second team  | Agatha_Second |
      | Content_in_Validation1 | 0      | request_validation             | First team   | Agatha_First  |
      | Content_in_Validation2 | 0      | request_validation             | Second team  | Agatha_Second |
      | Content_in_Review1     | 0      | needs_review                   | First team   | Agatha_First  |
      | Content_in_Review2     | 0      | needs_review                   | Second team  | Agatha_Second |
      | Validated1             | 0      | validated                      | First team   | Agatha_First  |
      | Validated2             | 0      | validated                      | Second team  | Agatha_Second |
      | Published1             | 1      | published                      | First team   | Agatha_First  |
      | Published2             | 1      | published                      | Second team  | Agatha_Second |
      | Archived1              | 0      | archived                       | First team   | Agatha_First  |
      | Archived2              | 0      | archived                       | Second team  | Agatha_Second |
      | Expired1               | 0      | expired                        | First team   | Agatha_First  |
      | Expired2               | 0      | expired                        | Second team  | Agatha_Second |

  @wip
  Scenario Outline: users are allowed to edit only content types for their group
    Given I am logged in as "<user>"
    And I go to "node/add/<type>"
    Then I should get a <response> HTTP response
    Examples:
      | user          | type         | response |
      | Agatha_First  | announcement | 200      |
      | Agatha_First  | department   | 403      |
      | Agatha_First  | basic-page   | 200      |
      | Agatha_Second | announcement | 200      |
      | Agatha_Second | department   | 200      |
      | Agatha_Second | basic-page   | 403      |
      | Agatha_Both   | announcement | 200      |
      | Agatha_Both   | department   | 200      |
      | Agatha_Both   | basic-page   | 200      |

  Scenario Outline: "My Drafts" section permissions
    Given I am logged in as "<user>"
    When I go to "admin/workbench/drafts-page"
    Then I <see_draft_group_1> see "Draft1"
    And I <see_draft_group_2> see "Draft2"

    Examples:
      | user           | see_draft_group_1 | see_draft_group_2 |
      | Mike_First     | should not        | should not        |
      | Agatha_First   | should            | should not        |
      | Vanessa_First  | should not        | should not        |
      | Rocky_First    | should not        | should not        |
      | Mike_Second    | should not        | should not        |
      | Agatha_Second  | should not        | should            |
      | Vanessa_Second | should not        | should not        |
      | Rocky_Second   | should not        | should not        |
      | Mike_Both      | should not        | should not        |
      | Agatha_Both    | should not        | should not        |
      | Vanessa_Both   | should not        | should not        |
      | Rocky_Both     | should not        | should not        |

  Scenario Outline: "Validation pending" section permissions
    Given I am logged in as "<user>"
    When I go to "admin/workbench/content-in-validation"
    Then I <see_content_in_validation_group_1> see "Content_in_Validation1"
    And I <see_content_in_validation_group_2> see "Content_in_Validation2"

    Examples:
      | user           | see_content_in_validation_group_1 | see_content_in_validation_group_2 |
      | Mike_First     | should not                        | should not                        |
      | Agatha_First   | should                            | should not                        |
      | Vanessa_First  | should                            | should not                        |
      | Rocky_First    | should not                        | should not                        |
      | Mike_Second    | should not                        | should not                        |
      | Agatha_Second  | should not                        | should                            |
      | Vanessa_Second | should not                        | should                            |
      | Rocky_Second   | should not                        | should not                        |
      | Mike_Both      | should not                        | should not                        |
      | Agatha_Both    | should not                        | should not                        |
      | Vanessa_Both   | should                            | should                            |
      | Rocky_Both     | should not                        | should not                        |

  Scenario Outline: "Content In Review" section permissions
    Given I am logged in as "<user>"
    When I go to "admin/workbench/content-in-review"
    Then I <see_content_in_review_group_1> see "Content_in_Review1"
    And I <see_content_in_review_group_2> see "Content_in_Review2"

    Examples:
      | user           | see_content_in_review_group_1 | see_content_in_review_group_2 |
      | Mike_First     | should not                    | should not                    |
      | Agatha_First   | should                        | should not                    |
      | Vanessa_First  | should                        | should not                    |
      | Rocky_First    | should                        | should not                    |
      | Mike_Second    | should not                    | should not                    |
      | Agatha_Second  | should not                    | should                        |
      | Vanessa_Second | should not                    | should                        |
      | Rocky_Second   | should not                    | should                        |
      | Mike_Both      | should not                    | should not                    |
      | Agatha_Both    | should not                    | should not                    |
      | Vanessa_Both   | should                        | should                        |
      | Rocky_Both     | should                        | should                        |

  Scenario Outline: "Other content" section permissions
    Given I am logged in as "<user>"
    When I go to "admin/workbench/other-content"
    Then I <see_validation_content_group_1> see "Validated1"
    And I <see_validation_content_group_2> see "Validated2"
    And I <see_published_content_group_1> see "Published1"
    And I <see_published_content_group_2> see "Published2"
    And I <see_archived_content_group_1> see "Archived1"
    And I <see_archived_content_group_2> see "Archived2"
    And I <see_expired_content_group_1> see "Expired1"
    And I <see_expired_content_group_2> see "Expired2"

    # This page should be accessible only by authors and validators.
    Examples:
      | user           | see_validation_content_group_1 | see_validation_content_group_2 | see_published_content_group_1 | see_published_content_group_2 | see_archived_content_group_1 | see_archived_content_group_2 | see_expired_content_group_1 | see_expired_content_group_2 |
      | Mike_First     | should not                     | should not                     | should not                    | should not                    | should not                   | should not                   | should not                  | should not                  |
      | Vanessa_First  | should                         | should not                     | should                        | should                        | should                       | should not                   | should                      | should not                  |
      | Rocky_First    | should not                     | should not                     | should not                    | should not                    | should not                   | should not                   | should not                  | should not                  |
      | Mike_Second    | should not                     | should not                     | should not                    | should not                    | should not                   | should not                   | should not                  | should not                  |
      | Vanessa_Second | should not                     | should                         | should                        | should                        | should not                   | should                       | should not                  | should                      |
      | Rocky_Second   | should not                     | should not                     | should not                    | should not                    | should not                   | should not                   | should not                  | should not                  |
      | Mike_Both      | should not                     | should not                     | should not                    | should not                    | should not                   | should not                   | should not                  | should not                  |
      | Vanessa_Both   | should                         | should                         | should                        | should                        | should                       | should                       | should                      | should                      |
      | Rocky_Both     | should not                     | should not                     | should not                    | should not                    | should not                   | should not                   | should not                  | should not                  |

  Scenario Outline: "Workbench main screen" permissions
    Given I am logged in as "<user>"
    When I go to "admin/workbench"
    Then I <can_create_content> see "Create Content"
    And I <can_access_my_drafts> see "My Drafts"
    And I <can_access_content_in_review> see "Content in Review"
    And I <can_access_content_in_validation> see "Validation Pending"
    And I <can_access_other_content> see "My Other Content"

    Examples:
      | user          | can_create_content | can_access_my_drafts | can_access_content_in_review | can_access_content_in_validation | can_access_other_content |
      | Agatha_First  | should             | should               | should                       | should                           | should                    |
      | Rocky_First   | should not         | should not           | should                       | should                           | should not                |
      | Vanessa_First | should not         | should not           | should                       | should                           | should                    |
      | Mike_First    | should not         | should not           | should not                   | should not                       | should not                |
