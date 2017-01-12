@api @shared @dt_editorial
Feature: Draft viewer role
  In order to validate visual representation of content before it's published
  As a registered user
  I need to have a draft viewer role to see drafts in the system

  Scenario Outline: Users part of of DG COMM A5 unit should receive the role automatically
    Given users:
      | name   | mail   | status   | roles   | field_creator   |
      | <user> | <mail> | <status> | <roles> | <field_creator> |
    And I am logged in as "<user>"
    And I am logged in as a user with the "administer users,administer permissions" permission
    And I go to "admin/people"
    And I click "edit" in the "<user>" row
    Then the checkbox "Draft viewer" <is_expected> be checked

    Examples:
      | user              | is_expected | mail                   | status | roles         | field_creator              |
      | harinro_test      | should not  | harinro@mail.mail      | 1      | administrator | eu.europa.ec/DIGIT.A.3.003 |
      | asselva_test      | should      | asselva@mail.mail      | 1      | administrator | eu.europa.ec/COMM.A.5.002  |
      | site_manager_test | should not  | site_manager@mail.mail | 1      | administrator |                            |

  @dt_page
  Scenario: The user should see the option "View draft" when a node has a draft version.
    Given users:
      | name              | mail                      | status | roles        |
      | Draft viewer user | draft_user_test1@test.com | 1      | Draft viewer |

    And I am logged in as a user with the "administrator" role
    Given I am viewing a "Basic page" content:
      | title  | Lorem ipsum basic page |
      | status | 1                      |
    And I follow "New draft" in the "tabs" region
    And I fill in "Moderation state" with "draft"
    Then I press the "Save" button

    And I am logged in as "Draft viewer user"
    Then I go to "lorem-ipsum-basic-page"
    Then I should see the link "View draft" in the "tabs" region

  @dt_announcement
  Scenario: Should see the draft/published version of a related node.
    Given users:
      | name              | mail                      | status | roles        |
      | Draft viewer user | draft_user_test1@test.com | 1      | Draft viewer |

    Given "Announcement" content:
      | title    | status | language | field_core_type_content | field_core_description | field_announcement_type | field_core_date_published | field_core_introduction | body        | field_announcement_location |
      | Ann. one | 1      | en       | default                 | A test description.    | press_release           | 1456790400                | A test introduction     | A test body | Brussels                    |
      | Ann. two | 1      | en       | default                 | A test description.    | press_release           | 1456790400                | A test introduction     | A test body | Brussels                    |

    Given I am logged in as "Draft viewer user"
    And I am viewing an "Announcement" content:
      | title                       | Announcement lipsum |
      | status                      | 1                   |
      | language                    | en                  |
      | field_core_type_content     | default             |
      | field_core_description      | A test description. |
      | field_announcement_type     | press_release       |
      | field_core_date_published   | 1456790400          |
      | field_core_introduction     | A test introduction |
      | body                        | A test body         |
      | field_announcement_location | Brussels            |
      | field_core_announcement     | Ann. one, Ann. two  |
    Then I should see the link "Ann. one" linking to "/news/ann-one_en"
    Then I should see the link "Ann. two" linking to "/news/ann-two_en"

    Given I am logged in as a user with the "administrator" role
    Then I am at "/news/ann-one_en"
    Then I follow "New draft" in the "tabs" region
    Then I fill in "title_field[en][0][value]" with "Ann. one draft"
    Then I uncheck "Generate automatic URL alias"
    Then I press the "Save" button

    Given I am logged in as "Draft viewer user"
    And I am at "/news/announcement-lipsum_en"
    Then I should see the link "Ann. one" linking to "/news/ann-one_en"

    Given I am logged in as a user with the "administrator" role
    And I am at "/news/announcement-lipsum_en"
    Then I follow "New draft" in the "tabs" region
    Then I fill in "title_field[en][0][value]" with "Announcement lipsum draft"
    Then I uncheck "Generate automatic URL alias"
    Then I press the "Save" button

    Given I am logged in as "Draft viewer user"
    And I am at "/news/announcement-lipsum_en"
    Then I should see the link "Ann. one" linking to "/news/ann-one_en"
    Then I follow "View draft" in the "tabs" region
    Then I follow "Ann. one"
    Then I should see "Ann. one draft"
