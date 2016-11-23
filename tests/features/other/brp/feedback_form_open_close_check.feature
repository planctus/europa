@api @brp @brp_feedback_form @dt_nal_services @brp_initiative
Feature: Chech the BRP feedback form state, if it is open/close.
When I go to the BRP website, as an anonymous user I should see different feedback state.

  Background:
    Given "nal_resource_types" terms:
      | name         | description                   |
      | ResourceType | The resource type description |

  Scenario Outline: Creating a Initiative content and check the Feedback state
    Given I am viewing a "Initiative" content:
      | title                        | <title>                        |
      | field_brp_inve_reference     | <title>                        |
      | field_brp_inve_fb_start_date | <field_brp_inve_fb_start_date> |
      | field_brp_inve_fb_end_date   | <field_brp_inve_fb_end_date>   |
      | status                       | <status>                       |
      | field_brp_inve_resource_type | ResourceType                   |
      | field_brp_inve_id            | 1                              |
    Then I should see text matching "<should_see_at_initiative_page>"
    Then I should not see text matching "<should_not_see_at_initiative_page>"
    Then I should see the link "<link_text>" linking to "<link_url>"
    Then I visit "<link_url>"
    Then I should see text matching "<should_see_on_feedback_page>"
    Then I should not see text matching "<should_not_see_on_feedback_page>"

    Examples:
      | title                               | field_brp_inve_fb_start_date | field_brp_inve_fb_end_date | status | should_see_at_initiative_page | should_not_see_at_initiative_page | link_text     | link_url                                                   | should_see_on_feedback_page | should_not_see_on_feedback_page |
      | Open initiative content for Behat   | 1462060800                   | 1577750400                 | 1      | Feedback status: Open         | Feedback status: Close            | Give feedback | /initiatives/open-initiative-content-behat/feedback/add_en | Log in                      | Feedback received on            |
      | Closed initiative content for Behat | 1430438400                   | 1430438401                 | 1      | Feedback status: Close        | Feedback status: Open             | All feedback  | /initiatives/closed-initiative-content-behat/feedback_en   | Feedback received on        | Log in                          |


