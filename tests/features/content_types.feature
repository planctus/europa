Feature: Content type configuration
  In order to fill in the website
  As an editor
  I should be able to access certain configuration pages

  @api
  Scenario: Editors can set the priority page id
    Given I am logged in as a user with the "editor" role
    When I go to "admin/config/system/dt-priority-settings"
    Then I should get a "200" HTTP response
    And I should see the link "Priority page settings"

  @api
  Scenario Outline: Editors can access certain admin pages
    Given I am logged in as a user with the "editor" role
    When I go to "<path>"
    Then the "h1" element should not contain "Add content"

    Examples:
    | path                                     |
    | node/add/announcement                    |
    | node/add/banner-quote                    |
    | node/add/banner-video                    |
    | node/add/contact                         |
    | node/add/department                      |
    | node/add/featured-item                   |
    | node/add/file                            |
    | node/add/basic-page                      |
    | node/add/person                          |
    | node/add/policy                          |
    | node/add/policy-area                     |
    | node/add/policy-implementation           |
    | node/add/policy-input                    |
    | node/add/priority                        |
    | node/add/priority-policy-area            |
    | node/add/publication                     |
    | node/add/topic                           |
