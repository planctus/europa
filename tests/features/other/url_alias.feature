@api @information @political @dt_shared_functions
Feature: Url aliases have specific configurations and patterns.

  Scenario: When updating the parent page, the child url alias should be updated between "law" and "page"
    Given I am logged in as a user with the "administrator" role
    And "Page" content:
      | title    | status | language |
      | Sub page | 1      | en       |
    And "Law" content:
      | title         | status | language |
      | Law title     | 1      | en       |
      | New law title | 1      | en       |
    When I am viewing a "Page" content:
      | title              | Page title |
      | field_core_parents | Law title  |
      | status             | 1          |
      | language           | en         |
    Then the canonical link should contain the value "/law/law-title/page-title_en"
    When I follow "New draft" in the "tabs" region
    And I fill in the reference "edit-field-core-parents-und-0-target-id" with "New law title"
    And I fill in "Moderation state" with "published"
    # First time we enter checkbox is checked.
    And I check the box "Generate automatic URL alias"
    When I press "Save"
    Then I should see "Created new alias law/new-law-title/page-title"
    And I should see "replacing law/law-title/page-title"
    And the canonical link should contain the value "/law/new-law-title/page-title_en"
    When I follow "New draft" in the "tabs" region
    And I fill in the reference "edit-field-core-parents-und-0-target-id" with "Sub page"
    And I fill in "Moderation state" with "published"
    # Second time, this is automatically unchecked.
    Then the "Generate automatic URL alias" checkbox should not be checked
    When I press "Save"
    Then I should not see "Created new alias sub-page/page-title"
    And I should not see "replacing law/new-law-title/page-title"
    And the canonical link should contain the value "/law/new-law-title/page-title_en"
    When I follow "New draft" in the "tabs" region
    And I fill in "Moderation state" with "published"
    # Third time, we manually check the checkbox.
    And I check the box "Generate automatic URL alias"
    When I press "Save"
    Then I should see "Created new alias sub-page/page-title"
    And I should see "replacing law/new-law-title/page-title"
    And the canonical link should contain the value "/sub-page/page-title_en"

  @api @information @political @dt_shared_functions
  Scenario: When a page has a long title the url alias should be limited to 250 characters
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "Page" content:
      | title              | Lorem ipsum dolor sit amet consectetur adipiscing elit Donec commodo gravida nibh non varius mi dictum in Sed sed nulla condimentum fermentum neque ut auctor risus nulla condimentum fermentum neque ut auctor risus|
      | status             | 1          |
      | language           | en         |
    Then I go to "lorem-ipsum-dolor-sit-amet-consectetur-adipiscing-elit-donec-commodo-gravida-nibh-non-varius-mi-dictum-sed-sed-nulla-condimentum-fermentum-neque-ut-auctor-risus-nulla-condimentum-fermentum-neque-ut-auctor-risus"
    Then I should see "Lorem ipsum dolor sit amet consectetur adipiscing elit Donec commodo gravida nibh non varius mi dictum in Sed sed nulla condimentum fermentum neque ut auctor risus nulla condimentum fermentum neque ut auctor risus" in the "title" element
