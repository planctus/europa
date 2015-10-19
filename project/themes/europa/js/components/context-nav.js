(function ($) {
  Drupal.behaviors.contextual_nav = {
    attach: function(context) {
      // Define our dropdown button.
      var dropDown = '<span class="context-nav__more-button">' + Drupal.t('More') + '<span class="caret"></span></span>';

      // Loop all our contextual navigation items.
      $.each($('.context-nav__items'), function() {

        // Cache our variables.
        var $item = $(this),
            contextNavItems = $item.children(),
            contextNavItemCount = contextNavItems.length;

        // If there are more then 5 we create our dropdown.
        if (contextNavItemCount > 5) {
          // Wrap the other elements.
          contextNavItems.slice(2).wrapAll('<div class="context-nav__expander"><div class="context-nav__hidden"></div></div>');
          // Add the button.
          $item.children('.context-nav__expander').prepend(dropDown);
        }

      });

      // Add the button onclick event.
      $('.context-nav__expander').on('click', '.context-nav__more-button', function() {
        var $button = $(this);
        // Remove the wrappers, returning the html to return to the default
        // state.
        $button.parent('.context-nav__expander').children('.context-nav__hidden').unwrap().children().unwrap();
        // Remove the button.
        $button.remove();
      });

    }
  }
})(jQuery);
