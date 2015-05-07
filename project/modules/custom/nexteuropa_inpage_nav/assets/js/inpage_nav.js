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
            target: '.inpage-nav',
            offset: 400
        });

        $navBar.on('shown.bs.collapse', function() {
          $inPage.addClass('is-collapsed');
        });
        $navBar.on('hide.bs.collapse', function() {
          $inPage.removeClass('is-collapsed');
        });

        $inPage.on("activate.bs.scrollspy", function(e){
          console.log("tt");
          var currentItem = $("li.active > a", $navBar);
          if (currentItem.length > 0) {
            $navBarCurrent.text(currentItem.text());
          } else {
            $navBarCurrent.text(title);
          }
        });

        enquire.register("screen and (min-width: 768px)", {
          setup : function() {

          },

          // desktop
          match : function() {

          },

          // mobile
          unmatch : function() {

          }
        });
      });
    }
  }
})(jQuery);
