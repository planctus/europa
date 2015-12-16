Feature: User authentication
  In order to protect the integrity of the website
  As a product owner
  I want to make sure only authenticated users can access the site administration

Scenario: Anonymous user can see the user login page
  Given I am not logged in
  When I go to "user"
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
  | admin/structure/feature-set |

@api
Scenario: Editors should not be able to see the flush cache link
  Given I am logged in as a user with the "editor" role
  When I go to "node/add_en"
  Then I should not see the link "Flush all caches"

@api
Scenario Outline: Editors can access certain admin pages
  Given I am logged in as a user with the "editor" role
  When I go to "<path>"
  Then I should get a "200" HTTP response

  Examples:
  | path                                     |
  | admin/config                             |

@api
Scenario Outline: Administrators can access certain administration pages
  Given I am logged in as a user with the "administrator" role
  When I go to "<path>"
  Then I should get a "200" HTTP response

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
