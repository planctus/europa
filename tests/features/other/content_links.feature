@api
Feature: Content linking
  In order to provide helpfull links
  As an editor
  I want to be able to link to anything in wysiwyg fields

  @cwt
  Scenario: Links on images using a wysiwyg field should work
    Given I am logged in as a user with the "administrator" role
    When I go to "node/add/aggregated-news"
    And I fill in "edit-title" with "News title"
    And I select "European Commission" from "Editorial sections"
    And I insert dummy image token into the "edit-body-und-0-value" field
    And I press "Save"
    Then I should see an "a.inline-media-image-link" element
    Then I should see an "a.inline-media-image-link img" element
    Then I should not see an "a.inline-media-image-link a" element
