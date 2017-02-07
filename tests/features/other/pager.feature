@api @information @dt_core @dt_announcement
Feature: Display pager region and show/hide pager elements

  Scenario: Pager doesn't have first, ellipsis and last links, but shows
  previous and next links depending on the current page.
    Given I have 30 "announcement" content:
      | title               | status |
      | Announcement number | 1      |
    And I go to "news"
    Then I should see an ".pager__item--current" element
    Then I should not see an ".pager__item--previous" element
    Then I should not see an ".pager__item--first" element
    Then I should not see an ".pager__item--ellipsis" element
    Then I should not see an ".pager__item--last" element
    Then I click "2" in the "pager" region
    Then I should see an ".pager__item--previous" element
    Then I should see an ".pager__item--next" element
    Then I click "3" in the "pager" region
    Then I should not see an ".pager__item--next" element

  Scenario: Pager shows first, last, previous and next links depending on the current page.
    Also shows ellipsis indicator depending on the current page.
    Given I have 110 "announcement" content:
      | title               | status |
      | Announcement number | 1      |
    And I go to "news"
    Then I should not see an ".pager__item--previous" element
    Then I should not see an ".pager__item--first" element
    Then I should see 1 ".pager__item--ellipsis" elements
    Then I should see an ".pager__item--last" element
    Then I should see an ".pager__item--next" element
    Then I should see an ".pager__item--current" element

    Then I click "5" in the "pager" region
    Then I should see an ".pager__item--previous" element
    Then I should not see an ".pager__item--first" element
    Then I should see 1 ".pager__item--ellipsis" elements
    Then I should see an ".pager__item--last" element
    Then I should see an ".pager__item--next" element

    Then I click "6" in the "pager" region
    Then I should see an ".pager__item--previous" element
    Then I should see an ".pager__item--first" element
    Then I should see 2 ".pager__item--ellipsis" elements
    Then I should see an ".pager__item--last" element
    Then I should see an ".pager__item--next" element

    Then I click "7" in the "pager" region
    Then I should see an ".pager__item--previous" element
    Then I should see an ".pager__item--first" element
    Then I should see 1 ".pager__item--ellipsis" elements
    Then I should not see an ".pager__item--last" element
    Then I should see an ".pager__item--next" element

    Then I click "11" in the "pager" region
    Then I should see an ".pager__item--previous" element
    Then I should see an ".pager__item--first" element
    Then I should see 1 ".pager__item--ellipsis" elements
    Then I should not see an ".pager__item--last" element
    Then I should not see an ".pager__item--next" element
