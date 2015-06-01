(function ($) {
  Drupal.behaviors.inpage_navigation = {
    fixWidth: function($e, $parent) {
      // Adjust width dinamcally to parent.
      var blockWidth = 'auto';
      blockWidth = $parent.width() + 'px';
      $e.css({
        'width' : blockWidth
      });
    },

    currentTitle: function($navBar, $navBarCurrent) {
      // Clear title for In page nav navbar title if nothing selected.
      var currentItem = $("li.active > a", $navBar);
      if (currentItem.length == 0) {
        $navBarCurrent.text(Drupal.settings.inpage_navigation.node_title);
      } else {
        $navBarCurrent.text(currentItem.text());
      }
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
            $inPageBlock
              .removeClass("affix affix-top affix-bottom is-fixed is-bottom");

            // Affix.
            Drupal.behaviors.inpage_navigation.fixWidth($inPageBlock, $inPageBlockParent);
            $inPageBlock.affix({
              offset: {
                top: function () {
                  return(Math.floor($inPageBlock.parent().offset().top - 15));
                },
                bottom: function () {
                  return($('footer.footer').outerHeight() + $('footer.footer-top').outerHeight() + 20);
                }
              }
            });

            $inPageBlock.on('affix.bs.affix', function() {
              $inPageBlock.addClass('is-fixed');
            });

            $inPageBlock.on('affixed.bs.affix', function() {
              $inPageBlock.addClass('is-fixed');
              $inPageBlock.removeClass('is-bottom');
            });

            $inPageBlock.on('affixed-top.bs.affix', function() {
                $inPageBlock.addClass('is-fixed');
            });

            $inPageBlock.on('affixed-bottom.bs.affix', function() {
                $inPageBlock.addClass('is-bottom');
            });
          },

          setup: function() {
            var $navBar = $('<div class="inpage-nav inpage-nav__navbar-wrapper"><nav class="navbar navbar-default navbar-fixed-top inpage-nav__navbar"><div class="container inpage-nav__container"><div class="navbar-header inpage-nav__header"  data-toggle="collapse" data-target="#inpage-navigation-list" aria-expanded="false" aria-controls="navbar"><button type="button" class="navbar-toggle collapsed inpage-nav__toggle"><span class="sr-only">' + Drupal.t("Toggle navigation") + '</span><span class="inpage-nav__icon-arrow icon icon--arrow-down"></span></button><span class="navbar-brand inpage-nav__help">' +  Drupal.t('On this page') + '</span><div class="inpage-nav__current-wrapper"><span class="navbar-brand inpage-nav__current">' +  title + '</span></div></div><div class="navbar-collapse collapse inpage-nav__list" id="inpage-navigation-list"><span class="inpage-nav__title" >' +  title + '</span>' + $inPage.html() + '</div></div></nav>');
            var $navBarHeader = $('.inpage-nav__header', $navBar);
            var $navBarList = $('#inpage-navigation-list', $navBar);
            var $navBarCurrent = $('.inpage-nav__current', $navBar);
            var $navBarTitle = $('.inpage-nav__title', $navBar);
            var $navBarHelp = $('.inpage-nav__help', $navBar);

            // Page smooth scrolling on anchor click from sidebar.
            $('a[href^="#"]', $inPage).click(function(e) {
              e.preventDefault();
              var sectionOffset = $(this.hash).offset().top;
              $('html, body').velocity("scroll", {easing:'ease', duration: 400, offset: sectionOffset});
            });

            // Page smooth scrolling on anchor click from navbar.
            $('li a[href^="#"]', $navBar).click(function(e) {
              e.preventDefault();
              var sectionOffset = $(this.hash).offset().top - 50;
              $('html, body').velocity("scroll", {easing:'ease', duration: 400, offset: sectionOffset});
              $navBarList.collapse('hide');
            });

            // Hide if clicked outside.
            $('.inpage-nav__navbar', $navBar).click(function(e) {
              $navBarList.collapse('hide');
            });

            $('body').append($navBar);
            // Page navigation scroll spy.
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
              // Set title to current;
              Drupal.behaviors.inpage_navigation.currentTitle($navBar, $navBarCurrent);
            });


            $(window).scroll(function(e) {
              $window = $(this);
              // Set title to current;
              Drupal.behaviors.inpage_navigation.currentTitle($navBar, $navBarCurrent);

              // Show navbar if scroll is under the block.
              var docViewTop = $window.scrollTop();
              var docViewBottom = docViewTop + $window.height();
              var inPageBottom = inPageBlockTop + inPageBlockHeight - 35;
              if (inPageBottom <= docViewTop) {
                $navBar.addClass('is-active');
              } else {
                $navBar.removeClass('is-active');
              }
            });
          },

          // mobile
          unmatch : function() {
            // Swicth off affix.
            $(window).off('.affix');
            $inPageBlock
              .removeClass("affix affix-top affix-bottom is-fixed is-bottom")
              .removeData("bs.affix");
          }
        });
      });
    }
  }
})(jQuery);
