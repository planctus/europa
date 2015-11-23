/**
 * @file
 * Contains javascript alterations for the site menu.
 */

(function ($) {
  Drupal.behaviors.site_menu = {
    attach: function(context) {
      var $siteMenu = $('#block-bean-information-site-menu .site-menu');
      var $topBar = $('.region-header');
      var $linkMenuSection = $('.site-menu__section a');
      $siteMenu.once('site_menu', function() {
        var $menuButton = $('<section class="site-menu__toggle"><button class="btn btn-menu">' + Drupal.t('Menu') + '</button></section>');
        $topBar.append($menuButton);
        $siteMenu.collapse('hide').removeAttr('style');
        $menuButton.click(function() {
          $siteMenu.collapse('toggle');
          $('button', this).toggleClass('is-collapsed');
          // Track menu open close events, once per page load.
          if ($('button', this).hasClass('is-collapsed')) {
            PiwikDTT.sendTrack(1,'trackEvent', 'Menu', 'Opened');
          }
          else {
            PiwikDTT.sendTrack(1,'trackEvent', 'Menu', 'Closed');
          }
        });
      });
      // Track clicks inside of site-menu section.
      $($linkMenuSection).click(function() {
        var data = $(this).text();
        PiwikDTT.sendTrack(0,'trackEvent', 'Menu', 'link', data);
      });
    }
  }
})(jQuery);
