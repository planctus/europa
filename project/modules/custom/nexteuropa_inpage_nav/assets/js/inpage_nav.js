(function ($) {
    Drupal.behaviors.inpage_navigation = {
        attach: function (context) {

            var $pageNavBlock = $('.inpage-nav');
            var pageNavBlockHeight = $pageNavBlock.height();
            var pageNavBlockTitle = $pageNavBlock.parent().siblings("h3.block-title");
            var pageNavInfo = $(".navigation-place");
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
                pageNavInfo.text(nodeTitle);
            }

            $(".inpage-nav").on("activate.bs.scrollspy", function(){
                var currentItem = $(".nav li.active > a").text();
                if (currentItem) {
                    pageNavInfo.text(currentItem);
                }
            });

            enquire.register("screen and (min-width: 768px)", {
                setup : function() {
                    $pageNavBlock.addClass("navbar-toggle collapsed")
                        .attr({
                            "data-toggle":"collapse",
                            "data-target":".inpage-nav__list",
                            "aria-expanded":"false",
                            "aria-controls":"navbar"
                        });
                    pageNavBlockTitle.hide();
                },

                // desktop
                match : function() {
                    $pageNavBlock.removeClass("navbar-toggle collapsed");
                    $pageNavBlock.children("nav").removeClass("navbar-default--blue navbar-fixed-top");
                    $pageNavBlock.attr({
                        "data-toggle":"",
                        "data-target":"",
                        "aria-expanded":"",
                        "aria-controls":""
                    });
                    pageNavBlockTitle.show();
                    pageNavInfo.hide();
                },

                // mobile
                unmatch : function() {
                    Drupal.resizeButton();
                    $pageNavBlock.addClass("navbar-toggle collapsed")
                        .attr({
                            "data-toggle":"collapse",
                            "data-target":".inpage-nav__list",
                            "aria-expanded":"false",
                            "aria-controls":"navbar"
                        });
                    $pageNavBlock.children("nav").addClass("navbar-default--blue navbar-fixed-top");
                    pageNavBlockTitle.hide();
                    pageNavInfo.show();
                }
            });

            // the button has to be full height
            Drupal.resizeButton();

            // changing the color of the bar depending on the stete
            $(".navbar-toggle").on("click",function(){
                var $this = $(this);
                if(Drupal.navListCollapsed()){
                    $this.parent().find(".navbar-header").css({
                        "background":"#ececec",
                        "color":"#575757"
                    });
                    $this.parent().find(".navigation-place").text("On this page");
                    $this.find(".arrow-down").hide();
                    $this.find(".close-text").show();
                } else {
                    $this.parent().find(".navbar-header").css({
                        "background":"#004494",
                        "color":"#fff"
                    });
                    $this.parent().find(".navigation-place").text(nodeTitle);
                    $this.find(".arrow-down").show();
                    $this.find(".close-text").hide();
                }
            });
        }
    }

    Drupal.resizeButton = function() {
        var button, selectHeight, btnObj;
        button = $(".inpage-nav").find("button");
        btnObj = $(button);
        selectHeight = btnObj.parent(".navbar-header").outerHeight();
        btnObj.outerHeight(selectHeight);
        btnObj.css({
            "min-width":selectHeight
        });
    }

    // TRUE when open
    Drupal.navListCollapsed = function() {
        var list = $('.inpage-nav__list');
        var listCollapsed = list.hasClass('collapse in');
        return !listCollapsed;
    }
})(jQuery);
