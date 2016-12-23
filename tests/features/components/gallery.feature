@api @information @dt_gallery
Feature: Users can use and see the gallery
  In order to show images
  I want a gallery to be presented on pages

  Scenario Outline: All the required Image styles are configured
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/config/media/image-styles_en"
    Then I should see the link "Gallery <type> - <name>" linking to "/admin/config/media/image-styles/edit/gallery_<machine_name>_<name>_en"
    Then I should see the link "Gallery <type> - <name> - Retina" linking to "/admin/config/media/image-styles/edit/gallery_<machine_name>_2x_<name>_en"

    Examples:
      | name   | type | machine_name |
      | 2      | Grid | grid         |
      | 3      | Grid | grid         |
      | 4      | Grid | grid         |
      | 5      | Grid | grid         |
      | 6      | Grid | grid         |
      | 7      | Grid | grid         |
      | 8      | Grid | grid         |
      | 12     | Grid | grid         |
      | phone  | Grid | grid         |
      | mobile | Full | full         |
      | narrow | Full | full         |
      | medium | Full | full         |
      | normal | Full | full         |
      | wide   | Full | full         |

  Scenario: "/gallery" is a protected alias
    Given "Page" content:
      | title   | status |
      | Gallery | 1      |
    When I go to "/gallery-0_en"
    Then I should see the heading "Gallery"
    When I go to "/gallery"
    Then I should see the heading "Access denied"

  @javascript @dt_event
  Scenario: The "[alias]/gallery" path is accessible when there is a gallery for the node.
    Given "Event" content:
      | title      | language | nid     | is_new | status | path[pathauto] | field_event_date:value | field_event_date:value2 | field_event_date:timezone |
      | Test Event | en       | 1234567 | 1      | 1      | 1              | 1893456000             | 1893456000              | Europe/Budapest           |
    When I go to "/node/1234567/gallery_en"
    Then I should see the heading "Page not found"
    When I am logged in as a user with the "editor,site manager" role
    And I go to "/node/1234567_en"
    Then I should see the heading "Test Event"
    And I follow "New draft" in the "tabs"
    And I click "After the event"
    And I click "Browse" in the "gallery_upload"
    And I switch to the frame "mediaBrowser"
     # <-- Media frame
    And I attach the file "test_1.png" to "files[upload]"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I switch out of all frames
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    When I go to "/node/1234567/gallery_en"
    Then I should not see the heading "Page not found"
    When I go to "/events/test-event/gallery_en"
    Then I should not see the heading "Page not found"

  @javascript @dt_event
  Scenario: Gallery items are browseable.
    Given "Event" content:
      | title      | language | nid     | is_new | status | path[pathauto] | field_event_date:value | field_event_date:value2 | field_event_date:timezone |
      | Test Event | en       | 1234567 | 1      | 1      | 1              | 1291161600             | 1291161600              | Europe/Budapest           |
    When I am logged in as a user with the "editor,site manager" role
    # Upload 1st image.
    And I go to "/node/1234567/edit_en"
    And I click "After the event"
    And I click "Browse" in the "gallery_upload"
    And I switch to the frame "mediaBrowser"
    And I attach the file "test_1.png" to "files[upload]"
    And I press "Next"
    And I fill in the following:
      | Alt Text   | ALT 1     |
      | Title Text | TITLE 1   |
      | Caption    | CAPTION 1 |
    And I press "Save"
    And I switch out of all frames
    And I press "Save"
    # Upload 2nd image.
    And I go to "/node/1234567/edit_en"
    And I click "After the event"
    And I click "Browse" in the "gallery_upload"
    And I switch to the frame "mediaBrowser"
    And I attach the file "test_2.png" to "files[upload]"
    And I press "Next"
    And I fill in the following:
      | Alt Text   | ALT 2     |
      | Title Text | TITLE 2   |
      | Caption    | CAPTION 2 |
    And I press "Save"
    And I switch out of all frames
    And I press "Save"
    # Upload 3rd image.
    And I go to "/node/1234567/edit_en"
    And I click "After the event"
    And I click "Browse" in the "gallery_upload"
    And I switch to the frame "mediaBrowser"
    And I attach the file "test_3.png" to "files[upload]"
    And I press "Next"
    And I fill in the following:
      | Alt Text   | ALT 3     |
      | Title Text | TITLE 3   |
      | Caption    | CAPTION 3 |
    And I press "Save"
    And I switch out of all frames
    And I press "Save"
    # Upload 4th image.
    And I go to "/node/1234567/edit_en"
    And I click "After the event"
    And I click "Browse" in the "gallery_upload"
    And I switch to the frame "mediaBrowser"
    And I attach the file "test_4.png" to "files[upload]"
    And I press "Next"
    And I fill in the following:
      | Alt Text   | ALT 4     |
      | Title Text | TITLE 4   |
      | Caption    | CAPTION 4 |
    And I press "Save"
    # Publish finally.
    And I switch out of all frames
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    When I click the element with CSS selector ".mediagallery__item_container a:first-child"
    # Gallery overlay.
    Then I should see "1 of 4" in the ".gallery-overlay__count" element
    And I should see "CAPTION 1" in the ".gallery-overlay__description" element
    And I should see an "img[title='TITLE 1']" element
    And I should not see the link "Previous" in the "gallery_overlay"
    And I should see the link "Next" in the "gallery_overlay"
    And I should see the link "Download photo" in the "gallery_overlay"
    And I should see the link "Close" linking to "/node/1234567_en"
    Then I follow "Next"
    And I should see the link "Next" in the "gallery_overlay"
    And I should see the link "Previous" in the "gallery_overlay"
    Then I follow "Next"
    Then I follow "Next"
    Then I should see "4 of 4" in the ".gallery-overlay__count" element
    And I should see "CAPTION 4" in the ".gallery-overlay__description" element
    And I should see an "img[title='TITLE 4']" element
    And I should see the link "Previous" in the "gallery_overlay"
    And I should not see the link "Next" in the "gallery_overlay"
    And I should see the link "Download photo" in the "gallery_overlay"
    And I should see the link "Close" linking to "/node/1234567_en"
