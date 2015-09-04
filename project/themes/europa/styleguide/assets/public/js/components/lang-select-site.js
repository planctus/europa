(function ($) {
    Drupal.behaviors.europa_pager = {
      attach: function(context) {
        $('.lang-select-site').on('click', 'a.lang-select-site__link', function(event){

          // We only want to load it once.
          if ($('#lang-select-site-overlay .splash-page__btn-close').length == 0) {

            $.get($(this).attr('href'), function( splashscreen ) {
              // Store our object.
              var $jQueryObject = $($.parseHTML(splashscreen));
              // Output the part we want to our overlay.
              $('#lang-select-site-overlay').html($jQueryObject.find('.page-content'))
            });
          }

          // Show overlay.
          $('.overlay').css({'display': 'block'});

          // Hide frame on click.
          $("#lang-select-site-overlay").on('click', '.splash-page__btn-close', function(event){
            $('.overlay').css({'display': 'none'});
            // Prevent the actual close a href to trigger. This should only work
            // if javascript is disabled.
            event.preventDefault();
          });

          // Prevent the default click, if javascript is disabled this link
          // will keep on working.
          event.preventDefault();
        });
      }
    };
})(jQuery);
