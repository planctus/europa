(function ($) {
  Drupal.behaviors.inpage_navigation = {
    attach: function (context) {
      $('.inpage-nav').once('page-navigation', function () {
        var $inPage = $(this);
        var inPageHeight = $inPage.height();
        var $inPageList = $('.inpage-nav__list', $inPage);
        var title = Drupal.settings.inpage_navigation.node_title;
        // Page navigation scroll spy
        $('body').scrollspy({
            target: '.inpage-nav'
        });

        enquire.register("screen and (max-width: 1200px)", {
          // mobile
          match : function() {
            if ($('.inpage-nav__navbar-wrapper').length == 0) {
              var $navBar = $('<div class="inpage-nav inpage-nav__navbar-wrapper"><nav class="navbar navbar-default navbar-fixed-top inpage-nav__navbar"><div class="container inpage-nav__container"><div class="navbar-header inpage-nav__header"  data-toggle="collapse" data-target="#inpage-navigation-list" aria-expanded="false" aria-controls="navbar"><button type="button" class="navbar-toggle collapsed inpage-nav__toggle"><span class="sr-only">' + Drupal.t("Toggle navigation") + '</span><span class="inpage-nav__collapse-icon"></span><span class="inpage-nav__close-text">' + Drupal.t("Close") + '</span></button><span class="navbar-brand inpage-nav__help">' +  Drupal.t('On this page') + '</span><span class="navbar-brand inpage-nav__current">' +  title + '</span></div><div class="navbar-collapse collapse inpage-nav__list" id="inpage-navigation-list"><span class="inpage-nav__title" >' +  title + '</span>' + $inPageList.html() + '</div></div></nav>');
              var $navBarHeader = $('.inpage-nav__header', $navBar);
              var $navBarList = $('.inpage-nav__list', $navBar);
              var $navBarCurrent = $('.inpage-nav__current', $navBar);
              var $navBarTitle = $('.inpage-nav__title', $navBar);
              var $navBarHelp = $('.inpage-nav__help', $navBar);

              $('body').append($navBar);
              // Page navigation scroll spy
              $('body').scrollspy({
                  target: '.inpage-nav'
              });

              $navBar.on('show.bs.collapse', function() {
                $navBar.addClass('is-collapsing');
              });

              $navBar.on('shown.bs.collapse', function() {
                $navBar.addClass('is-collapsed');
                $navBar.removeClass('is-collapsing');
              });

              $navBar.on('hide.bs.collapse', function() {
                $navBar.removeClass('is-collapsed');
              });

              $navBar.on("activate.bs.scrollspy", function(e) {
                // Set current heading as title for In page nav navbar title.
                $navBarCurrent.text($("li.active > a", $navBar).text());
              });

              $(window).scroll(function(e) {
                $window = $(this);
                // Clear title for In page nav navbar title if nothing selected.
                var currentItem = $("li.active > a", $navBar);
                if (currentItem.length == 0) {
                  $navBarCurrent.text(title);
                }

                // Show navbar if scroll is under the block.
                var docViewTop = $window.scrollTop();
                var docViewBottom = docViewTop + $window.height();
                var inPageBottom = $inPage.offset().top + inPageHeight;
                if (inPageBottom <= docViewTop) {
                  $navBar.addClass('is-active');
                } else {
                  $navBar.removeClass('is-active');
                }
              });
            }
          },
          // desktop
          unmatch : function() {

          }
        });
      });
    }
  }
})(jQuery);
