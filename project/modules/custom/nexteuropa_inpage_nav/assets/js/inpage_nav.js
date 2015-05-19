(function ($) {
  Drupal.behaviors.inpage_navigation = {
    attach: function (context) {
      $('.inpage-nav').once('page-navigation', function () {
        var $inPage = $(this);
        var $inPageList = $('.inpage-nav__list', $inPage);
        console.log($inPage);
        var title = Drupal.settings.inpage_navigation.node_title;

        // Clone block for navbar use on mobiles.
        var $inPageNavBar = $inPage.clone();
        $inPageNavBar.addClass('is-navbar');

        var $navBar = $('.inpage-nav__navbar', $inPageNavBar);
        var $navBarHeader = $('.inpage-nav__header', $navBar);
        var $navBarList = $('.inpage-nav__list', $navBar);
        var $navBarCurrent = $('.inpage-nav__current', $navBar);
        var $navBarTitle = $('.inpage-nav__title', $navBar);
        var $navBarHelp = $('.inpage-nav__help', $navBar);

        $navBar.addClass('navbar navbar-default navbar-fixed-top');
        $navBarHeader.addClass('navbar-header');
        $navBarList.addClass('navbar-collapse collapse');
        $('.nav', $navBarList).addClass('navbar-nav navbar-stacked');

        // Page navigation scroll spy
        $('body').scrollspy({
            target: '.inpage-nav'
        });

        $('body').append($inPageNavBar);

        $navBar.on('show.bs.collapse', function() {
          $inPageNavBar.addClass('is-collapsing');
        });

        $navBar.on('shown.bs.collapse', function() {
          $inPageNavBar.addClass('is-collapsed');
          $inPageNavBar.removeClass('is-collapsing');
        });

        $navBar.on('hide.bs.collapse', function() {
          $inPageNavBar.removeClass('is-collapsed');
        });

        $inPageNavBar.on("activate.bs.scrollspy", function(e) {
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
