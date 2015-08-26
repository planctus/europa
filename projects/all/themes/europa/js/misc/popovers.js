(function ($) {
  Drupal.behaviors.europaPopovers = {
    attach: function (context, settings) {
      $('.lang-select-site__link').on('click', function(e){
        e.preventDefault();
      });
    }
  };
})(jQuery);
