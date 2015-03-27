(function ($) {
    Drupal.behaviors.inpage_navigation = {
        attach: function (context) {
            var $pageNavBlock = $('.inpage-nav');
            var pageNavBlockHeight = $pageNavBlock.height();
            $pageNavBlock.once('page-navigation', function () {

                // Page navigation scroll spy
                $('body').scrollspy({
                    target: '.inpage-nav'
                });

                // Manually adding affix top and offset for fixed page navigation position
                $(window).scroll(function () {
                    var safeHeight = pageNavBlockHeight + $('#footer').outerHeight() + 50;
                    var navOffset = $pageNavBlock.parent().offset().top,
                        scrollTopValue = $(window).scrollTop();
                    var atBottom = (scrollTopValue + safeHeight) > $('body').height();
                    if (!atBottom) {
                        if (navOffset < scrollTopValue && !($pageNavBlock.hasClass('affix'))) {
                            $pageNavBlock.addClass('affix').removeClass('affix-top').removeClass('affix-bottom');
                        }
                        else if (navOffset > scrollTopValue && !($pageNavBlock.hasClass('affix-top'))) {
                            $pageNavBlock.removeClass('affix').addClass('affix-top');
                        }
                    } else {
                        $pageNavBlock.removeClass('affix').addClass('affix-bottom');
                    }

                });

                // Page smooth scrolling on anchor click
                $('a[href^="#"]', this).click(function (e) {
                    e.preventDefault();

                    sectionOffset = $(this.hash).offset().top;

                    if ($(this).parent().is(':first-child')) {
                        sectionOffset = sectionOffset - 20;
                    }

                    $('html, body').velocity("scroll", {easing: 'ease', duration: 400, offset: sectionOffset});
                });
            });

            // Page title vs section title
            if (typeof Drupal.settings.inpage_navigation.node_title != 'undefined') {
                var nodeTitle = Drupal.settings.inpage_navigation.node_title;
                $(".navigation-place").text(nodeTitle);
            }

            $(".inpage-nav").on("activate.bs.scrollspy", function(){
                var currentItem = $(".nav li.active > a").text();
                if (currentItem) {
                    $(".navigation-place").text(currentItem);
                }
            });

            enquire.register("screen and (min-width: 768px)", {
                setup : function() {
                    $pageNavBlock.addClass("navbar-toggle collapsed")
                        .attr({
                            "data-toggle":"collapse",
                            "data-target":".inpage-nav--list",
                            "aria-expanded":"false",
                            "aria-controls":"navbar"
                        });
                    $pageNavBlock.prev("h2").hide();
                },

                // desktop
                match : function() {
                    $pageNavBlock.removeClass("navbar-toggle collapsed");
                    $pageNavBlock.children("nav").removeClass("navbar-default navbar-fixed-top");
                    $pageNavBlock.attr({
                        "data-toggle":"",
                        "data-target":"",
                        "aria-expanded":"",
                        "aria-controls":""
                    });
                    $pageNavBlock.prev("h2").show();
                    $(".navigation-place").hide();
                },

                // mobile
                unmatch : function() {
                    $pageNavBlock.addClass("navbar-toggle collapsed")
                        .attr({
                            "data-toggle":"collapse",
                            "data-target":".inpage-nav--list",
                            "aria-expanded":"false",
                            "aria-controls":"navbar"
                        });
                    $pageNavBlock.children("nav").addClass("navbar-default navbar-fixed-top");
                    $pageNavBlock.prev("h2").hide();
                    $(".navigation-place").show();
                }
            });
        }
    }

})(jQuery);