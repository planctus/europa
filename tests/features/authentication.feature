Feature: User authentication
  In order to protect the integrity of the website
  As a product owner
  I want to make sure only authenticated users can access the site administration

Scenario: Anonymous user can see the user login page
  Given I am not logged in
  When I visit "user"
  Then I should see the text "Log in"
  And I should see the text "Request new password"
  And I should see the text "Username"
  And I should see the text "Password"
  But I should not see the text "Log out"
  And I should not see the text "My account"

Scenario Outline: Anonymous user cannot access site administration
  Given I am not logged in
  When I go to "<path>"
  Then I should get an access denied error

  Examples:
  | path                        |
  | admin/config                |
  | admin/dashboard             |
  | admin/structure             |
  | admin/structure/feature-set |
  | node/add/article            |

@api
Scenario Outline: Editors cannot access certain pages intended for administrators
  Given I am logged in as a user with the "editor" role
  When I go to "<path>"
  Then I should get an access denied error

  Examples:
  | path                        |
  | node/add/article            |
  | node/add/page               |
  | admin/config                |
  | admin/dashboard             |
  | admin/structure             |
  | admin/structure/feature-set |

@api
Scenario Outline: Editors can access certain admin pages
  Given I am logged in as a user with the "editor" role
  Then I go to "<path>"

  Examples:
  | path                                     |
  | admin/config/system/dt-priority-settings |
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
  | node/add/policy-keyfile                  |
  | node/add/priority                        |
  | node/add/priority-policy-area            |
  | node/add/publication                     |
  | node/add/class                           |
  | node/add/class-link-group                |
  | node/add/topic                           |
  | node/add/toplink                         |

@api
Scenario Outline: Administrators can access certain administration pages
  Given I am logged in as a user with the "administrator" role
  Then I visit "<path>"

  Examples:
  | path                        |
  | admin/config                |
  | admin/dashboard             |
  | admin/structure             |
  | admin/structure/feature-set |
  | node/add/article            |
  | node/add/page               |

@api
Scenario Outline: Administrators should not be able to access technical pages intended for developers
  Given I am logged in as a user with the "administrator" role
  When I go to "<path>"
  Then I should get an access denied error

  Examples:
  | path                     |
  | admin/structure/features |
