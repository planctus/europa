@api @information @dt_commemorative_coins @dt_page
Feature: Commemorative coins content type
  In order to fill in an commemorative coin
  As an editor
  I should be able to upload content
  As an anonymous
  I should be able to see the uploaded content and lists

  Background:
    Given "Page" content:
      | title       | language | status |
      | RelatedPage | en       | 1      |
    And I am logged in as a user with the "administrator" role
    And I go to "admin/structure/taxonomy/nal_countries/add"
    And I fill in the following:
      | name | Belgium |
    And I press "Save"

  @javascript
  Scenario: Fields are visible on a listing page without link to the content
    Given I am logged in as a user with the "administrator" role
    And I am viewing an "commemorative_coins" content:
      | title                  | Commemorative Coin 1     |
      | status                 | 1                        |
      | language               | en                       |
      | field_cc_subject       | First commemorative coin |
      | field_core_description | A test description.      |
      | field_nal_country      | Belgium                  |
      | field_cc_date          | 1456790400               |
      | field_cc_volume        | 500000                   |
      | field_cc_issue_page    | RelatedPage              |
      | field_core_link        | Test - http://google.be  |
    Then I click "New draft" in the "tabs" region
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "coin.jpg" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I go to "/commemorative-coins"
    And I should see an "img" element
    And I should see "First commemorative coin"
    And I should see "A test description."
    And I should see "Belgium"
    And I should see "March 2016"
    And I should see "RelatedPage"
    And I should see "500,000 coins"
    And I should see the link "Test"
