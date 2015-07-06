(function ($) {
  Drupal.behaviors.site_menu = {
    attach: function(context) {
      var $siteMenu = $('#block-bean-information-site-menu .site-menu');
      var $topBar = $('.region-header');

      $siteMenu.once('site_menu', function() {
        var $menuButton = $('<section class="site-menu__toggle col-xs-3"><button class="btn btn-menu">' + Drupal.t('Menu') + '</button></section>');
        $topBar.append($menuButton);
        $siteMenu.addClass('collapse');
        $menuButton.click(function() {
          $siteMenu.collapse('toggle');
          $('button', this).toggleClass('is-collapsed');
        });
      });
    }
  }
})(jQuery);
