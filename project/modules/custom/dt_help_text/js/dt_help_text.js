(function ($) {
  Drupal.behaviors.dt_help_text = {
    attach: function(context) {
      $(".help-text-hidden").before('<a href="#">' + Drupal.t(' more ') + '</a>').hide();
      $(".help-text-hidden").prev("a").bind('click', function($e){
        $(this).hide().next('.help-text-hidden').show();
        return false;
      });
    }
  }
})(jQuery);
