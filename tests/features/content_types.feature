@api
Feature: Content type configuration
  In order to fill in the website
  As an editor
  I should be able to access certain configuration pages

  @shared
  Scenario: Description meta tag
    Given "Page" content:
      | title         | field_core_description | field_core_introduction |
      | Content title | Content description    | Intro                   |
    And I am logged in as a user with the "editor" role
    And I go to "admin/content"
    And I follow "Content title"
    Then I should see "Content title" in the "title" element
    Then the metatag attribute "description" should have the value "Content description"

  @political @information
  Scenario: Editors can set the priority page id
    Given I am logged in as a user with the "editor" role
    When I go to "admin/config/system/dt-priority-settings"
    Then I should get a "200" HTTP response
    And I should see the link "Priority page settings"

  Scenario Outline: Editors can access certain admin pages
    Given I am logged in as a user with the "editor" role
    When I go to "<path>"
    Then the "h1" element should not contain "Add content"

    Examples:
      | path                           |
      | node/add/announcement          |
      | node/add/banner-quote          |
      | node/add/banner-video          |
      | node/add/contact               |
      | node/add/department            |
      | node/add/featured-item         |
      | node/add/file                  |
      | node/add/basic-page            |
      | node/add/person                |
      | node/add/policy                |
      | node/add/policy-area           |
      | node/add/policy-implementation |
      | node/add/policy-input          |
      | node/add/priority              |
      | node/add/priority-policy-area  |
      | node/add/publication           |
      | node/add/topic                 |
