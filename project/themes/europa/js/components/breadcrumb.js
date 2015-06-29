(function ($) {
  Drupal.behaviors.europa_breadcrumb = {
    attach: function (context) {
      $('#breadcrumb').once('breadcrumb', function(){

        // Add collapsible class for js mobile behavior.
        var $breadcrumbWrapper = $(this);
        $breadcrumbWrapper.addClass('breadcrumb--collapsible');

        $breadcrumbWrapper.append('<span class="breadcrumb__btn-separator">...</span>');
        var $breadcrumbButton = $breadcrumbWrapper.find('.breadcrumb__btn-separator');

        function showBreadcrumbs($selector) {
          console.log('works');
          $selector.hide();

          var $breadcrumbWrapper = $('#breadcrumb');
          $breadcrumbWrapper.addClass('is-open');
        }

        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register(Drupal.europa.breakpoints.medium, {
            // desktop
            match : function() {
              $breadcrumbWrapper.removeClass('is-open');
              $breadcrumbButton.hide();
            },
            // mobile
            unmatch : function() {
              $breadcrumbButton.show();
            },

            setup: function() {
              $breadcrumbButton.click(function(){
                // Adding $(this) as a selector for the showBreadcrumbs function.
                showBreadcrumbs($(this));
              });
            },
          });
        }
      });
    }
  }
})(jQuery);
