@api @shared
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
    # Media frame -->
    And I switch out of all frames
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
    And I click "Browse"
    And I switch to the frame "mediaBrowser"
    # <-- Media frame
    And I attach the file "test_en.pdf" to "files[upload]"
    And I press "Next"
    And I press "Next"
    # Media frame -->
    And I switch out of all frames
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


  @javascript
  Scenario: Files can be translated
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
    # Media frame -->
    And I switch out of all frames
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
    # Media frame -->
    And I switch out of all frames
    And I click "Publishing options"
    And I select "Published" from "Moderation state"
    And I press "Save"

    Then I should see "Mijn bestands titel" in the ".region-content .file" element
    Then I should see "Nederlands" in the ".region-content .file" element
    And I translate the string "Download" to "Dutch" with "Downloaden"
    And I reload the page
    Then I should see the link "Downloaden"
    Then I get the file "test_nl.pdf" after clicking "Download"
