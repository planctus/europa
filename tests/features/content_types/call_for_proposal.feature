@api @information
Feature: Call for proposal content type

  Scenario: "Open call" single stage and basic fields
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                   |
      | field_core_description           | CFP description             |
      | field_core_introduction          | CFP introduction            |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                  |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                  |
      | status                           | 1                           |
      | language                         | en                          |
      | field_cfp_publication            | CFP link - http://google.be |
      # Wed, 02 Jan 2030 00:00:00 GMT
      | field_core_deadlines             | 1893542400                  |
    Then I should see "This call is currently open." in the ".messages" element
    Then I should see "If you want to participate in the call, you must submit your application before the deadline:" in the ".messages" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Single-stage" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadline" in the ".field--field-core-deadlines .field__label" element
    Then I should not see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element

  Scenario: "Open call" two stage
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                   |
      | field_core_description           | CFP description             |
      | field_core_introduction          | CFP introduction            |
      | field_cfp_deadline_model         | Two-stage                   |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                  |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                  |
      | status                           | 1                           |
      | language                         | en                          |
      | field_cfp_publication            | CFP link - http://google.be |
      # Wed, 02 Jan 2030 00:00:00 GMT, Wed, 09 Jan 2030 00:00:00 GMT
      | field_core_deadlines             | 1893542400, 1894147200      |
    Then I should see "This call is currently open." in the ".messages" element
    Then I should see "If you want to participate in the call, you must submit your application before the deadline:" in the ".messages" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Two-stage" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element

  Scenario: "Open call" Multiple cut-off
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                          |
      | field_core_description           | CFP description                    |
      | field_core_introduction          | CFP introduction                   |
      | field_cfp_deadline_model         | Multiple cut-off                   |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                         |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                         |
      | status                           | 1                                  |
      | language                         | en                                 |
      | field_cfp_publication            | CFP link - http://google.be        |
      # Wed, 02 Jan 2030 00:00:00 GMT, Wed, 09 Jan 2030 00:00:00 GMT, Sat, 26 Jan 2030 00:00:00 GMT
      | field_core_deadlines             | 1893542400, 1894147200, 1895616000 |
    Then I should see "This call is currently open." in the ".messages" element
    Then I should see "If you want to participate in the call, you must submit your application before the deadline:" in the ".messages" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see "26 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Multiple cut-off" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "26 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element

  Scenario: "Open call" Multiple cut-off with expired date
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                          |
      | field_core_description           | CFP description                    |
      | field_core_introduction          | CFP introduction                   |
      | field_cfp_deadline_model         | Multiple cut-off                   |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                         |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                         |
      | status                           | 1                                  |
      | language                         | en                                 |
      | field_cfp_publication            | CFP link - http://google.be        |
      # Tue, 26 Jan 2016 00:00:00 GMT, Wed, 02 Jan 2030 00:00:00 GMT, Wed, 09 Jan 2030 00:00:00 GMT
      | field_core_deadlines             | 1453766400, 1893542400, 1894147200 |
    Then I should see "This call is currently open." in the ".messages" element
    Then I should see "If you want to participate in the call, you must submit your application before the deadline:" in the ".messages" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should not see "26 January 2016, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Multiple cut-off" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "26 January 2016, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__item--expired" element

  Scenario: "Open call" Multiple cut-off with expired date in random order
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                          |
      | field_core_description           | CFP description                    |
      | field_core_introduction          | CFP introduction                   |
      | field_cfp_deadline_model         | Multiple cut-off                   |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                         |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                         |
      | status                           | 1                                  |
      | language                         | en                                 |
      | field_cfp_publication            | CFP link - http://google.be        |
      # Wed, 02 Jan 2030 00:00:00 GMT, Wed, 09 Jan 2030 00:00:00 GMT, Tue, 26 Jan 2016 00:00:00 GMT
      | field_core_deadlines             | 1893542400, 1894147200, 1453766400 |
    Then I should see "This call is currently open." in the ".messages" element
    Then I should see "If you want to participate in the call, you must submit your application before the deadline:" in the ".messages" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should not see "26 January 2016, 1:00 (Europe/Brussels)" in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Multiple cut-off" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "9 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
    Then I should see "26 January 2016, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__item--expired" element


  Scenario: "Closed call" single stage
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                   |
      | field_core_description           | CFP description             |
      | field_core_introduction          | CFP introduction            |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                  |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                  |
      | status                           | 1                           |
      | language                         | en                          |
      | field_cfp_publication            | CFP link - http://google.be |
      # Sat, 02 Jan 2016 00:00:00 GMT
      | field_core_deadlines             | 1451692800                  |
    Then I should see "This call is closed." in the ".messages" element
    Then I should see "This call was closed on 2 January 2016, 1:00 (Europe/Brussels)." in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Single-stage" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadline" in the ".field--field-core-deadlines .field__label" element
    Then I should not see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2016, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items .field__item--expired" element

  Scenario: "Upcoming call" single stage
    Given I am viewing a "call_for_proposal":
      | title                            | CFP title                   |
      | field_core_description           | CFP description             |
      | field_core_introduction          | CFP introduction            |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value  | 1893456000                  |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_published:value2 | 1893456000                  |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_opening:value    | 1893456000                  |
      # Tue, 01 Jan 2030 00:00:00 GMT
      | field_core_date_opening:value2   | 1893456000                  |
      | status                           | 1                           |
      | language                         | en                          |
      | field_cfp_publication            | CFP link - http://google.be |
      # Sat, 02 Jan 2016 00:00:00 GMT
      | field_core_deadlines             | 1893542400                  |
    Then I should see "This call is upcoming." in the ".messages" element
    Then I should see "The call will be opened on 1 January 2030." in the ".messages" element
    Then I should see the heading "CFP title"
    Then I should see the heading "Details"
    Then I should see "CFP introduction"
    Then the metatag attribute "description" should have the value "CFP description"
    Then I should see the link "CFP link" linking to "http://google.be"
    Then I should see "Publication date" in the ".field--dt-call-for-proposal-published .field__label" element
    Then I should see "1 January 2030 in" in the ".field--dt-call-for-proposal-published .field__items" element
    Then I should see "Deadline model" in the ".field--field-cfp-deadline-model .field__label" element
    Then I should see "Single-stage" in the ".field--field-cfp-deadline-model .field__items" element
    Then I should see "Deadline" in the ".field--field-core-deadlines .field__label" element
    Then I should not see "Deadlines" in the ".field--field-core-deadlines .field__label" element
    Then I should see "2 January 2030, 1:00 (Europe/Brussels)" in the ".field--field-core-deadlines .field__items" element
