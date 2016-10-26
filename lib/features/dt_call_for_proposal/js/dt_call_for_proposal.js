/**
 * @file
 * JS file for dt call for proposal feature.
 */

(function ($) {
  Drupal.behaviors.checktime = {
    attach: function (context) {
        $('.node-call_for_proposal-form').submit(function () {
            var closing = $('#field-core-date-closing-values tbody tr');

            closing.each(function () {
                var $this = $(this);
                $('input', $this).first().css('background', 'blue');
                var date = $('input', $this).first().val();
                var time = $('input', $this).last().val();

              if (date.trim()) {
                if (!time.trim()) {
                    $('input', $this).last().val('23:59');
                }
              }
            });
        });
    }
  }
})(jQuery);
