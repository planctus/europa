@api @information @dt_consultation
Feature: Consultation content type
  In order to get the latest transformation of the consultation content type
  As an anonymous user
  I should see the information of the page in a specific way

  Background:
    Given "Topic" content:
      | title        | language | status |
      | RelatedTopic | en       | 1      |
    Given "Department" content:
      | title             | language | status |
      | RelatedDepartment | en       | 1      |
    Given "Policy area" content:
      | title      | language | status |
      | PolicyArea | en       | 1      |
    Given "Contact" content:
      | title            | field_contact_phone_number               | field_contact_mobile_number              | status | language |
      | Be Contact label | +32 2 295 38 44 (European Commission BE) | +32 2 295 38 44 (European Commission BE) | 1      | en       |
    Given "Publication" content:
      | title                  | status | language | field_core_date_updated:value | field_core_date_updated:value2 | field_core_date_published:value | field_core_date_published:value2 |
      | Publication test title | 1      | en       | 1969952000                    | 1969952000                     | 1400980800                      | 1400980800                       |
    Given "File" content:
      | title      | status | field_core_legacy_link  | language |
      | File title | 1      | Link - http://google.be | en       |
    Given "Page" content:
      | title      | status | language | field_core_description | field_core_latest_visibility |
      | Page title | 1      | en       | Sample description     | Disable                      |


  Scenario: Consultation fields are seen in correct places
    Given I am viewing an "Consultation" content:
      | title                            | A new Consultation          |
      | status                           | 1                           |
      | language                         | en                          |
      | field_core_description           | A consultation description. |
      # Tue, 01 Jan 2017 00:00:00 GMT
      | field_core_date_opening:value    | 1483228800                  |
      # Tue, 01 Feb 2017 00:00:00 GMT
      | field_core_date_closing:value    | 1485907200                  |
      | field_core_departments           | RelatedDepartment           |
      | field_core_topics                | RelatedTopic                |
      | field_core_policy_areas          | PolicyArea                  |
      | field_core_contact               | Be Contact label            |
      | field_consultation_target_groups | Consultation target group.  |
      | field_consultation_objective     | Consultation objective.     |
      | field_consultation_how_to_submit | Consultation how to.        |
      | field_consultation_questionnaire | Consultation questionnaire. |
      | field_core_publications          | Publication test title      |
      | field_core_files                 | File title                  |
      | field_core_pages                 | Page title                  |
      | field_consultation_contributions | Consultation contributions. |
      | field_consultation_results       | Consultation results.       |

    Then I should see the heading "A new Consultation" in the "main_content" region

    Then I should see "Page contents" in the ".section.inpage-nav__wrapper" element
    And I should see the link "Details"
    And I should see the link "Target group"
    And I should see the link "Objective of the consultation"
    And I should see the link "How to submit your contribution"
    And I should see the link "View the questionnaire"
    And I should see the link "Reference documents"
    And I should see the link "Contact"
    And I should see the link "View the contributions"
    And I should see the link "Results of the consultation and next steps"
    And I should see the link "Legal notices"

    Then I should see the heading "Details" in the "main_content" region
    And I should see "1 January 2017 - 1 February 2017" in the "main_content" region
    And I should see "PolicyArea" in the "main_content" region
    And I should see "RelatedDepartment" in the "main_content" region

    Then I should see the heading "Target group" in the "main_content" region
    And I should see the heading "Objective of the consultation" in the "main_content" region
    And I should see the heading "How to submit your contribution" in the "main_content" region
    And I should see the heading "View the questionnaire" in the "main_content" region
    And I should see the heading "Reference documents" in the "main_content" region
    And I should see the heading "Contact" in the "main_content" region
    And I should see the heading "View the contributions" in the "main_content" region
    And I should see the heading "Results of the consultation and next steps" in the "main_content" region
    And I should see the heading "Legal notices" in the "main_content" region
