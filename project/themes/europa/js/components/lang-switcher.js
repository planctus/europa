(function ($) {

  var pageSwitcher = {
    listClass: '.lang-select-page__list',
    itemClass: '.lang-select-page__option',
    iconClass: '.lang-select-page__icon',
    unavClass: '.lang-select-page__unavailable',
    listWidth: function() {
      return $(pageSwitcher.listClass).outerWidth();
    },
    iconWidth: function() {
      return $(pageSwitcher.iconClass).outerWidth();
    },
    unavailableWidth: function() {
      return $(pageSwitcher.unavClass).outerWidth();
    },
    itemsWidth: function() {
      var overallWidth = 0;
      $(pageSwitcher.listClass).children(pageSwitcher.itemClass).each(function() {
        if ($(this).is(':visible')) {
          var itemSize = $(this).outerWidth();
          overallWidth += itemSize;
        }
      });
      return overallWidth;
    },
    itemsOverflow: function() {
      var availableSpace = pageSwitcher.listWidth() - pageSwitcher.iconWidth() - pageSwitcher.unavailableWidth();
      return pageSwitcher.itemsWidth() > availableSpace - 20;
    },
    hideLast: function() {
      var lastVisible = $('.lang-select-page__option').last(':visible');
      lastVisible.hide();
      return lastVisible;
    },
    shrink: function() {
      var numberItems = $(pageSwitcher.itemClass).length;
      while (numberItems > 0) {
        if (pageSwitcher.itemsOverflow()) {
          pageSwitcher.hideLast();
          numberItems--;
        }
      }
    },
    showLast: function() {
      // contrary to hideLast()
    },
    expand: function() {
      // contrary to shrink()
    }
  };

  Drupal.behaviors.languageSwitcherPage = {
    attach: function(context) {
      var pageLanguageSelector = $('.lang-select-page');
      pageLanguageSelector.selectify({
        listSelector: 'lang-select-page__list',
        item: 'lang-select-page__option',
        other: 'lang-select-page__other',
        unavailable: 'lang-select-page__unavailable',
        selected: 'is-selected'
      });

      pageSwitcher.shrink();

      if (typeof enquire !== 'undefined') {
        enquire.register(Drupal.europa.breakpoints.small, {
          // desktop
          match : function() {
            pageLanguageSelector.trigger('show.list');
            pageLanguageSelector.trigger('hide.dropdown');
          },
          // mobile
          unmatch : function() {
            $(window).on('resize', function(){
              if(pageSwitcher.itemsOverflow()){
                pageLanguageSelector.trigger('hide.list');
                pageLanguageSelector.trigger('show.dropdown');
              }
            });
          },
          setup: function() {
            if(pageSwitcher.itemsOverflow()){
              pageLanguageSelector.trigger('hide.list');
              pageLanguageSelector.trigger('show.dropdown');
            }
          }
        }, true);
      }
    }
  };
})(jQuery);