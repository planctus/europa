@api @shared @nexteuropa_file
Feature: File content type
  In order to fill in the website
  As an editor
  I should be able to upload localized files
  As an anonymous user
  I should be able to download localized files

  @javascript
  Scenario: Files can be uploaded and downloaded
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "file" content:
      | title  | File Title |
      | status | 1          |
    And I click "New draft" in the "tabs" region
    And I select the radio button "Upload the file."
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "test_en.pdf" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I switch out of all frames
    And I click "Editorial settings"
    And I select "Global editorial team" from "Your groups" chosen.js select box
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see "File Title" in the ".region-content .file" element
    Then I should see "English" in the ".region-content .file" element
    Then I should see the link "Download"
    Then I get the file "test_en.pdf" after clicking "Download"

  @javascript @information
  Scenario: When a file is not translated, and displayed on a translated node, it should display it's native language
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "file" content:
      | title    | My File Title |
      | status   | 1             |
      | language | en            |
    And I click "New draft" in the "tabs" region
    And I select the radio button "Upload the file."
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "test_en.pdf" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I switch out of all frames
    And I click "Editorial settings"
    And I select "Global editorial team" from "Your groups" chosen.js select box
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"

    And I translate the string "English" to "Dutch" with "Engels"
    And I am viewing a "Department" content:
      | title                       | Department    |
      | status                      | 1             |
      | field_department_organigram | My File Title |
      | language                    | nl            |
    Then I should see "Engels" in the ".region-content .file" element

  @javascript @dt_publication @nexteuropa_formatters @nexteuropa_file @dt_page
  Scenario: Files can be translated
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "file" content:
      | title    | My File Title |
      | status   | 1             |
      | language | en            |
      | nid      | 99999         |
      | is_new   | 1             |
    And I click "New draft" in the "tabs" region
    And I select the radio button "Upload the file."
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "test_en.pdf" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I switch out of all frames
    And I click "Editorial settings"
    And I select "Global editorial team" from "Your groups" chosen.js select box
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see "My File Title" in the ".region-content .file" element
    Then I should see "English" in the ".region-content .file" element
    Then I should see the link "Download"
    Then I get the file "test_en.pdf" after clicking "Download"
    And I create the following translations for "file" content with title "My File Title":
      | language | title               | status |
      | nl       | Mijn bestands titel | 1      |
    And I change the language to "Dutch"
    And I click "New draft" in the "tabs" region
    And I select the radio button "Upload the file."
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "test_nl.pdf" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I switch out of all frames
    And I click "Editorial settings"
    And I select "Global editorial team" from "Your groups" chosen.js select box
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    Then I should see "Mijn bestands titel" in the ".region-content .file" element
    Then I should see "Nederlands" in the ".region-content .file" element
    And I translate the string "Download" to "Dutch" with "Downloaden"
    And I reload the page
    Then I should see the link "Downloaden"
    Then I get the file "test_nl.pdf" after clicking "Download"
    # Check if translation is visible on full view mode.
    When I click "Available languages (1)"
    And I wait for a second
    Then I should see "English version" in the ".file__translations .file__title" element
    And I get the file "test_en.pdf" after clicking "Downloaden" in the ".file__translations" element
    # Check for translations when embedding into a publication.
    When I am viewing a "Publication":
      | title                           | Publication title |
      | language                        | en                |
      | status                          | 1                 |
      | field_core_files                | My File Title     |
      | field_core_date_updated:value   | 1400980800        |
      | field_core_date_updated:value2  | 1400980800        |
      | field_core_date_published:value | 1400980800        |
      | field_core_date_published:value | 1400980800        |
    When I click "Available languages (1)"
    And I wait for a second
    Then I should see "Nederlands version" in the ".file__translations .file__title" element
    And I get the file "test_nl.pdf" after clicking "Download" in the ".file__translations" element
    # Check for embedding into a body field.
    And I am viewing a "Page" content:
      | title       | File teaser view mode test                   |
      | body:value  | [node:99999:view-mode:teaser]{My File Title} |
      | body:format | full_html                                    |
      | status      | 1                                            |
      | language    | en                                           |
    Then I should see an ".node.node-file.node-teaser" element
    When I click "Available languages (1)"
    And I wait for a second
    Then I should see a ".field--field-core-file a.btn.file__btn.btn-default" element
    And I should see a ".field--field-core-file ul.file__translations-list a.btn.file__btn.btn--condensed.is-internal" element
    And I should see "Nederlands version" in the ".file__translations .file__title" element
    And I get the file "test_nl.pdf" after clicking "Download" in the ".file__translations" element

  @dt_page
  Scenario: I can add external links to a file
    Given "File" content:
      | title      | status | field_core_legacy_link  |
      | File title | 1      | Link - http://google.be |
    And I am viewing a "Page":
      | title            | Page external file |
      | status           | 1                  |
      | field_core_files | File title         |
    Then I should see "File title" in the ".file" element
    Then I should see "English" in the ".file" element
    Then I should see the link "Download" linking to "http://google.be"

  @javascript
  Scenario: ZIP Files can be uploaded and downloaded by anonymous
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "file" content:
      | title  | File Title |
      | status | 1          |
      | nid    | 99999      |
      | is_new | 1          |
    And I click "New draft" in the "tabs" region
    And I select the radio button "Upload the file."
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
      # <-- Media frame
    And I attach the file "test_en.zip" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
      # Media frame -->
    And I switch out of all frames
    And I click "Editorial settings"
    And I select "Global editorial team" from "Your groups" chosen.js select box
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    And I click "Logout"
    And I am on "node/99999"
    Then I should see the link "Download"
    Then I get the file "test_en.zip" after clicking "Download"

  @javascript @information
  Scenario: TMX Files can be uploaded and downloaded by anonymous
    Given I am logged in as a user with the "administrator" role
    And I am viewing a "file" content:
      | title  | File Title |
      | status | 1          |
      | nid    | 99999      |
      | is_new | 1          |
    And I click "New draft" in the "tabs" region
    And I select the radio button "Upload the file."
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "test.tmx" to "files[upload]"
    And I press "Next"
    And I press "Next"
    And I press "Save"
    # Media frame -->
    And I switch out of all frames
    And I click "Editorial settings"
    And I select "Global editorial team" from "Your groups" chosen.js select box
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"
    And I click "Logout"
    And I am on "node/99999"
    Then I should see the link "Download"
    Then I get the file "test.tmx" after clicking "Download"

  @dt_publication
  Scenario: File is displayed with the file--link modifier
    Given "file_origins" terms:
      | name             |
      | File origin term |
    Given I am logged in as a user with the "administrator" role
    # In order to see the page  (full view mode) of a file with external link, it needs administrator role.
    And I am viewing a "File":
      | title                  | File title              |
      | status                 | 1                       |
      | field_core_legacy_link | Link - http://google.be |
      | field_file_link_upload | link                    |
      | field_file_location    | File origin term        |
    Then I should see "File title" in the ".file.file--link" element
    Then I should see the link "File title" linking to "http://google.be"
    Given I am viewing a "Publication":
      | title                           | Pub w/ external file-link |
      | status                          | 1                         |
      | field_core_files                | File title                |
      | field_core_date_updated:value   | 1400980800                |
      | field_core_date_updated:value2  | 1400980800                |
      | field_core_date_published:value | 1400980800                |
      | field_core_date_published:value | 1400980800                |
    Then I should see "File title" in the ".file.file--link" element
    Then I should see the link "File title" linking to "http://google.be"
