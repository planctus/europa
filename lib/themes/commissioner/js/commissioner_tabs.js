/**
 * @file
 * Reverts behavior of europa_tabs for a special case.
 */

(function ($) {
  Drupal.behaviors.commissioner_tabs = {
    attach: function (context) {
      $('.nav-tabs--with-content').once('nav-tabs', function() {
        $this = $(this);
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register('screen and (max-width: 479px)', {
            // Setup.
            setup : function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
            },
            // Mobile.
            match : function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
              $this.show();
            },
            // Desktop.
            unmatch: function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
            }
          });
        }
      });
    }
  };
})(jQuery);
