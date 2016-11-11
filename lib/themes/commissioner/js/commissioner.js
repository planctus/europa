/**
 * @file
 * Behaviors related to the commissioner theme.
 */

(function ($) {
  Drupal.behaviors.europa_collapse = {
    attach: function (context) {
      var show_text = Drupal.t('Show contact details'),
          hide_text = Drupal.t('Hide contact details');

      Drupal.europa.collapsing(show_text, hide_text);
    }
  };
})(jQuery);
