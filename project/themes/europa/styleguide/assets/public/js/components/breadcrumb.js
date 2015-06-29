(function ($) {
  Drupal.behaviors.europa_breadcrumb = {
    attach: function (context) {
      $('#breadcrumb').once('breadcrumb', function(){

        // Add collapsible class for js mobile behavior.
        $breadcrumbWrapper = $(this);
        $breadcrumbWrapper.addClass('breadcrumb--collapsible');

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
            },
            // mobile
            unmatch : function() {
              $breadcrumbWrapper.find('.breadcrumb__btn-separator').show();
            },

            setup: function() {
              $breadcrumbWrapper.append('<span class="breadcrumb__btn-separator">...</span>');

              $breadcrumbWrapper.find('.breadcrumb__btn-separator').click(function(){
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
