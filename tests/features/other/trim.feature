@api
Feature: Trimming settings are correct
  As a site owner
  I want to be sure no trimming is applied where it is not needed
  @information @wip
  Scenario Outline: Field is not trimmed when displayed
    Given I am logged in as a user with the administrator role
    # @wip is there because administrator on clean install can't access this page.
    And I am on "admin/structure/types/manage/<content_type>/display/<display_mode>"
    Then the selects "#edit-fields-<field_name>-type" should not be set to "smart_trim_format"
    And the selects "#edit-fields-<field_name>-type" should not be set to "text_trimmed"

    Examples:
      | field_name | content_type | display_mode     |
      | body       | event        | event_collection |
