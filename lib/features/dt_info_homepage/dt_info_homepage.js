/**
 * @file
 * JS file for dt_info_homepage feature.
 */

(function ($) {
  Drupal.behaviors.info_homepage = {
    attach: function (context) {
      $('.field--field-info-homepage-topic-link .btn', context).click(function () {
        PiwikDTT.sendTrack(0,'trackEvent','button', 'clicked', 'topics a-z');
      });
    }
  };
})(jQuery);
