(function ($) {
    Drupal.behaviors.europa_pager = {
      attach: function(context) {
        var $overlay = $('#lang-select-site-overlay'),
            overlay = '.overlay',
            closeBtn = '.splash-page__btn-close';

        $('.lang-select-site').on('click', 'a.lang-select-site__link', function(event){

          // We only want to load it once.
          if (!$overlay.find(closeBtn).length) {

            $.get($(this).attr('href'), function(splashscreen) {
              // Store our object.
              var $jQueryObject = $($.parseHTML(splashscreen));
              // Output the part we want to our overlay.
              $overlay.html($jQueryObject.find('.page-content'))
            });
          }

          // Show overlay.
          $(overlay).show();

          // Hide frame on click.
          $overlay.on('click', closeBtn, function(event){
            $(overlay).hide();
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
