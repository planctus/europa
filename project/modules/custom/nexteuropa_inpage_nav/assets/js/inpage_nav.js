(function ($) {
  Drupal.behaviors.inpage_navigation = {
    attach: function (context) {
      $('.inpage-nav').once('page-navigation', function () {
        var $inPage = $(this);
        var $navBar = $('.navbar', $inPage);
        var $navBarCurrent = $('.inpage-nav__current', $inPage);
        var $navBarTitle = $('.inpage-nav__title', $inPage);
        var $navBarHelp = $('.inpage-nav__help', $inPage);
        var title = Drupal.settings.inpage_navigation.node_title;

        // Page navigation scroll spy
        $('body').scrollspy({
            target: '.inpage-nav'
        });

        $navBar.on('show.bs.collapse', function() {
          $inPage.addClass('is-collapsing');
        });

        $navBar.on('shown.bs.collapse', function() {
          $inPage.addClass('is-collapsed');
          $inPage.removeClass('is-collapsing');
        });

        $navBar.on('hide.bs.collapse', function() {
          $inPage.removeClass('is-collapsed');
        });

        $inPage.on("activate.bs.scrollspy", function(e) {
          // Set current heading as title for In page nav navbar title.
          $navBarCurrent.text($("li.active > a", $navBar).text());
        });

        $(window).scroll(function(e) {
          // Clear title for In page nav navbar title if nothing selected.
          var currentItem = $("li.active > a", $navBar);
          if (currentItem.length == 0) {
            $navBarCurrent.text(title);
          }
        });

        enquire.register("screen and (max-width: 768px)", {
          // mobile
          match : function() {
            $('body').addClass('is-inpage-nav-navbar');
          },
          // desktop
          unmatch : function() {
            $('body').removeClass('is-inpage-nav-navbar');
          }
        });
      });
    }
  }
})(jQuery);
