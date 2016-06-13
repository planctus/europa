/**
 * @file
 * Behaviors related to the commissioner theme.
 */

(function ($) {
  Drupal.behaviors.europa_collapse = {
    attach: function(context) {
      showText = Drupal.t('Show contact details');
      hideText = Drupal.t('Hide contact details');

      Drupal.europa.collapsing(showText, hideText);
    }
  };

})(jQuery);
