@api @information @political @dt_contact
Feature: Contact related tests

  Scenario: The visitor should see the contact.
    Given I am viewing an "Contact" content:
      | title                         | Contact example |
      | body                          | Some role       |
      | status                        | 1               |
      | field_contact_location_office | BERL 04/347     |
      | field_contact_phone_number    | +49 2299999999  |
    Given I go to "/content/contact-example_en"
    Then I should see "Location" in the ".field--field-contact-location-office .field__label" element
    Then I should not see "Location," in the ".field--field-contact-location-office .field__label" element
    Then I should not see "Location " in the ".field--field-contact-location-office .field__label" element
