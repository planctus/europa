@api @brp
Feature: As an anonymous user
  I want to be able to see all corporate bodies in the filter.
  Background:
    Given I am logged in as a user with the "administrator" role
    Then I go to "import/nal_corporate_bodies_importer_en"
    And I fill in "URL" with "http://publications.europa.eu/mdr/resource/authority/corporate-body/xml/corporatebodies.xml"
    And I press the "Import" button
    Then I wait for the batch job to finish

  @javascript
  Scenario: The visitor should see the corporate body in the search.
    Given I go to "/initiatives"
    Then I should have the following options for "Department":
      | Directorate-General for Agriculture and Rural Development                                 |
      | Directorate-General for Climate Action                                                    |
      | Directorate-General for Communication                                                     |
      | Directorate-General for Communications Networks, Content and Technology                   |
      | Directorate-General for Competition                                                       |
      | Directorate-General for Economic and Financial Affairs                                    |
      | Directorate-General for Education and Culture                                             |
      | Directorate-General for Employment, Social Affairs and Inclusion                          |
      | Directorate-General for Energy                                                            |
      | Directorate-General for European Civil Protection and Humanitarian Aid Operations (ECHO)  |
      | Directorate-General for Financial Stability, Financial Services and Capital Markets Union |
      | Directorate-General for Health and Food Safety                                            |
      | Directorate-General for Human Resources and Security                                      |
      | Directorate-General for Informatics                                                       |
      | Directorate-General for Internal Market, Industry, Entrepreneurship and SMEs              |
      | Directorate-General for International Cooperation and Development                         |
      | Directorate-General for Interpretation                                                    |
      | Directorate-General for Justice and Consumers                                             |
      | Directorate-General for Maritime Affairs and Fisheries                                    |
      | Directorate-General for Migration and Home Affairs                                        |
      | Directorate-General for Mobility and Transport                                            |
      | Directorate-General for Neighbourhood and Enlargement Negotiations                        |
      | Directorate-General for Regional and Urban Policy                                         |
      | Directorate-General for Research and Innovation                                           |
      | Directorate-General for Taxation and Customs Union                                        |
      | Directorate-General for the Budget                                                        |
      | Directorate-General for the Environment                                                   |
      | Directorate-General for Trade                                                             |
      | Directorate-General for Translation                                                       |
      | Euratom Supply Agency                                                                     |
      | European Anti-Fraud Office                                                                |
      | European External Action Service                                                          |
      | European Personnel Selection Office                                                       |
      | European Political Strategy Centre                                                        |
      | Eurostat                                                                                  |
      | Internal Audit Service                                                                    |
      | Joint Research Centre                                                                     |
      | Legal Service                                                                             |
      | Office for the Administration and Payment of Individual Entitlements                      |
      | Publications Office                                                                       |
      | Secretariat-General                                                                       |
      | Service for Foreign Policy Instruments                                                    |
