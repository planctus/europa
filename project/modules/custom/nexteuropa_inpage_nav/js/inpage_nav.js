(function ($) {
  Drupal.behaviors.inpage_navigation = {
    fixWidth: function($e, $parent) {
      // Adjust width dinamcally.
      var blockWidth = 'auto';
      if ($e.hasClass('is-affixed')) {
        blockWidth = $parent.width() + 'px';
      }
      $e.css({
        'width' : blockWidth
      });
    },

    attach: function (context) {
      $('.inpage-nav').once('page-navigation', function () {
        var $inPageActive = false;
        var $inPage = $(this);
        var $inPageBlock = $inPage.parents('.inpage-nav__wrapper');
        var $inPageBlockParent = $inPageBlock.parent();
        var inPageBlockHeight = $inPageBlock.height();
        var inPageBlockTop = $inPageBlock.offset().top;
        var inPageBlockParentTop = $inPageBlockParent.offset().top;
        var $inPageList = $('.inpage-nav__list', $inPage);
        var title = Drupal.settings.inpage_navigation.node_title;
        // Page navigation scroll spy
        $('body').scrollspy({
            target: '.inpage-nav'
        });

        $(window).resize(function(e) {
          Drupal.behaviors.inpage_navigation.fixWidth($inPageBlock, $inPageBlockParent);
        });

        enquire.register("screen and (min-width: 1200px)", {
          // desktop
          match : function() {
            $inPageActive = true;
            // Page smooth scrolling on anchor click
            $('a[href^="#"]', this).click(function(e) {
              e.preventDefault();

              sectionOffset = $(this.hash).offset().top;

              if ($(this).parent().is(':first-child')) {
                sectionOffset = sectionOffset - 20;
              }

              $('html, body').velocity("scroll", {easing:'ease', duration: 400, offset: sectionOffset});
            });
          },

          setup: function() {
            var $navBar = $('<div class="inpage-nav inpage-nav__navbar-wrapper"><nav class="navbar navbar-default navbar-fixed-top inpage-nav__navbar"><div class="container inpage-nav__container"><div class="navbar-header inpage-nav__header"  data-toggle="collapse" data-target="#inpage-navigation-list" aria-expanded="false" aria-controls="navbar"><button type="button" class="navbar-toggle collapsed inpage-nav__toggle"><span class="sr-only">' + Drupal.t("Toggle navigation") + '</span><span class="inpage-nav__icon-arrow icon icon--arrow-down"></span></button><span class="navbar-brand inpage-nav__help">' +  Drupal.t('On this page') + '</span><div class="inpage-nav__current-wrapper"><span class="navbar-brand inpage-nav__current">' +  title + '</span></div></div><div class="navbar-collapse collapse inpage-nav__list" id="inpage-navigation-list"><span class="inpage-nav__title" >' +  title + '</span>' + $inPage.html() + '</div></div></nav>');
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
              var inPageBottom = inPageBlockTop + inPageBlockHeight;
              if (inPageBottom <= docViewTop) {
                $navBar.addClass('is-active');
              } else {
                $navBar.removeClass('is-active');
              }

              // Sidebar Inpage Nav.
              if ($inPageActive) {
                var safeHeight = inPageBlockHeight + $('#footer').outerHeight() + $('#footer-top').outerHeight() + 50;
                var navOffset = $inPageBlock.parent().offset().top,
                  scrollTopValue = $(window).scrollTop();
                var atBottom = (scrollTopValue + safeHeight) > $('body').height();
                if(!atBottom) {
                  if (navOffset < scrollTopValue && !($inPageBlock.hasClass('affix'))) {
                    $inPageBlock.addClass('affix is-affixed').removeClass('affix-top').removeClass('affix-bottom');
                  }
                  else if (navOffset > scrollTopValue && !($inPageBlock.hasClass('affix-top'))) {
                    $inPageBlock.removeClass('affix is-affixed').addClass('affix-top');
                  }
                } else {
                  $inPageBlock.removeClass('affix is-affixed').addClass('affix-bottom');
                }
                Drupal.behaviors.inpage_navigation.fixWidth($inPageBlock, $inPageBlockParent);
              }
            });
          },

          // mobile
          unmatch : function() {
            $inPageActive = false;
            $inPageBlock.removeClass('affix is-affixed affix-top affix-bottom');
          }
        });
      });
    }
  }
})(jQuery);
