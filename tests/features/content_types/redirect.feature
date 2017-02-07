@api @information @dt_core @dt_announcement @dt_page
Feature: Redirect path
  As an anonymous user
  I should be redirected to the same content if the content url path changes.

  Scenario: Old alias should redirect to new one.
    Given I am logged in as a user with the "site manager" role
    And I am viewing an "announcement" content:
      | title                       | Test redirect         |
      | status                      | 1                     |
      | language                    | en                    |
      | field_core_type_content     | default               |
      | field_core_description      | A test description.   |
      | field_announcement_type     | news_article          |
      | field_core_date_published   | 1456790400            |
      | field_core_introduction     | A test introduction   |
      | body                        | A test body           |
      | field_announcement_location | Brussels              |
      | og_group_ref                | Global editorial team |

    # View current announcement page.
    And I go to "news/test-redirect"
    Then I should see "Test redirect" in the "h1" element

    # Create a new draft and update the title field.
    Then I follow "New draft" in the "tabs"
    And fill in "edit-title-field-en-0-value" with "Test redirect new alias"

    # Generate new url alias based on title and publish this version.
    And I check the box "Generate automatic URL alias"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    Then I should see "Test redirect new alias" in the "h1" element

    # Go to new content and add the redirect.
    Then I follow "New draft" in the "tabs"
    And I click "Add URL redirect to this node"

    # Create the redirect.
    And I fill in "edit-source" with "news/test-redirect"
    And I press the "Save" button
    And I select "published" from "Moderation state"
    And I press the "Save" button

    # Test if the redirect works.
    And I go to "news/test-redirect"
    Then I should not see "Page not found" in the "h1" element
    Then I should see "Test redirect new alias" in the "h1" element

    #Automatic redirect for announcement.
  Scenario: A Announcement redirect alias should not be done automatically.
    Given I am logged in as a user with the "site manager" role
    And I am viewing an "announcement" content:
      | title                       | Automatic redirect    |
      | status                      | 1                     |
      | language                    | en                    |
      | field_core_type_content     | default               |
      | field_core_description      | A test descriptio     |
      | field_announcement_type     | news_article          |
      | field_core_date_published   | 1456790400            |
      | field_core_introduction     | A test introduction   |
      | body                        | A test body           |
      | field_announcement_location | Brussels              |
      | og_group_ref                | Global editorial team |

    # View current announcement page.
    And I go to "news/automatic-redirect"
    Then I should see "Automatic redirect" in the "h1" element
    Then I follow "New draft" in the "tabs"
    And fill in "edit-title-field-en-0-value" with "New automatic redirect"
    And I check the box "Generate automatic URL alias"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    And I go to "news/automatic-redirect"
    Then I should not see "New automatic redirect" in the "h1" element

  #Automatic redirect for page child and parent configuration.
  Scenario: Automatic URL is generated for "Page" after update
    Given "Page" content:
      | title             | field_core_description | field_core_introduction | field_core_parents | path[pathauto] | status |
      | First page title  | Content description    | Intro                   |                    | 1              | 1      |
      | Second page title | Content description    | Intro                   | First page title   | 1              | 1      |
    And I am logged in as a user with the "site manager" role
    And I go to "first-page-title/second-page-title"
    Then I should see "Second page title" in the "title" element

    Then I follow "New draft" in the "tabs"
    And fill in "edit-title-field-en-0-value" with "New Second page title "
    And I check the box "Generate automatic URL alias"
    And I select "published" from "Moderation state"
    And I press the "Save" button
    And I go to "first-page-title/new-second-page-title"
    Then I should see "Second page title" in the "title" element
