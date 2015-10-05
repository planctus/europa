(function ($) {
  Drupal.behaviors.contextual_nav = {
    attach: function(context) {
      // Define our dropdown.
      var dropdown = '<span class="context-nav__more-button">More <span class="caret"></span></span>';

      // Loop al our contextual navigation items.
      $.each($('.context-nav__items'), function() {

        // Get the amount of children.
        context_nav_items = $(this).children();
        context_nav_item_count = context_nav_items.length;

        // If there are more then 5 we create our dropdown.
        if (context_nav_item_count > 4) {
          // Wrap the other elements.
          context_nav_items.slice(4).wrapAll('<div class="context-nav__expander"><div class="context-nav__hidden"></div></div>');
          // Add the button.
          $(this).children('.context-nav__expander').prepend(dropdown);
        }

      });

      // Add the button onclick event.
      $('.context-nav__expander').on('click', '.context-nav__more-button', function() {
        // Remove the wrappers, returning the html to return to the default
        // state.
        $(this).parent('.context-nav__expander').children('.context-nav__hidden').unwrap().children().unwrap();
        // Remove the button.
        $(this).remove();
      });

    }
  }
})(jQuery);
