/**
 * @file
<<<<<<< HEAD:lib/features/dt_site_menu/dt_site_menu.js
 */
=======
 * Contains javascript alterations for the site menu.
 */

>>>>>>> 0f44a62ded9bbab15711fb9e523c328b4ef48475:project/modules/features/custom/dt_site_menu/dt_site_menu.js
(function ($) {
  Drupal.behaviors.site_menu = {
    attach: function(context) {
      var $siteMenu = $('#block-bean-information-site-menu .site-menu');
      var $topBar = $('.region-header');

      $siteMenu.once('site_menu', function() {
        var $menuButton = $('<section class="site-menu__toggle"><button class="btn btn-menu">' + Drupal.t('Menu') + '</button></section>');
        $topBar.append($menuButton);
        $siteMenu.collapse('hide').removeAttr('style');
        $menuButton.click(function() {
          $siteMenu.collapse('toggle');
          $('button', this).toggleClass('is-collapsed');
          PiwikDTT.sendTrack(1,'trackEvent','Menu', 'Open');
        });
      });
    }
  }
})(jQuery);
