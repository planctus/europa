@api @information
Feature: Users can use and see the gallery
  In order to show images
  I want a gallery to be presented on pages

  Scenario Outline: All the required Image styles are configured
    Given I am logged in as a user with the "administrator" role
    And I go to "admin/config/media/image-styles_en"
    Then I should see the link "Gallery Grid - <cols>" linking to "/admin/config/media/image-styles/edit/gallery_grid_<cols>_en"
    Then I should see the link "Gallery Grid - <cols> - Retina" linking to "/admin/config/media/image-styles/edit/gallery_grid_2x_<cols>_en"

    Examples:
      | cols  |
      | 2     |
      | 3     |
      | 4     |
      | 5     |
      | 6     |
      | 7     |
      | 8     |
      | 12    |
      | phone |

