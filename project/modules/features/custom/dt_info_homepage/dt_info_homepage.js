(function ($) {
    Drupal.behaviors.info_homepage = {
        attach: function (context) {
            $('.btn-ctn', context).click(function () {
                PiwikDTT.sendTrack(0,'trackEvent','button', 'clicked', 'topics a-z');
            });
        }
    };
})(jQuery);