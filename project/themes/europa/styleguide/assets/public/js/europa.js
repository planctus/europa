(function ($) {
  Drupal.europa = Drupal.europa || {};
  Drupal.europa.breakpoints = Drupal.europa.breakpoints || {};

  // TODO:
  // Populate the breakpoints with those comming from Breakpoints module.
  // @see breakpoints js module for potential solution.
  Drupal.europa.breakpoints.medium = 'screen and (min-width: 480px)';


  Drupal.behaviors.europa_tabs = {
    attach: function (context) {
      $('.nav-tabs--with-content').once('nav-tabs', function(){
        $this = $(this);
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register('screen and (max-width: 479px)', {
            // setup
            setup : function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
            },
            // mobile
            match : function() {
              $this.siblings('.tab-content').children().removeClass('tab-pane');
            },
            // desktop
            unmatch: function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
            },
          });
        }
      });
    }
  };
})(jQuery);
