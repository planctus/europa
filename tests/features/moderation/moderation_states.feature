@api @shared
Feature: Moderation states
  In order to be able to configure moderation workflows
  I want to see all the moderation states
  At the moderation states page

  Scenario Outline: See all moderation states
    Given I am logged in as a user with the "administrator" role
    And I visit "admin/config/workbench/moderation"
    Then I should see "<system_name>"
    Then the "states[<system_name>][label]" field should contain "<state>"
    Then the "states[<system_name>][description]" field should contain "<description>"

    Examples:
      | state              | system_name        | description                      |
      | Draft              | draft              | Work in progress                 |
      | Expired            | expired            | Not visible to site visitors     |
      | Archived           | archived           | Content is not published anymore |
      | Published          | published          | Make this version live           |
      | Needs Review       | needs_review       | Ready for moderation             |
      | Request Validation | request_validation | Requesting validation            |
      | Validated          | validated          | Approved by administrator        |
