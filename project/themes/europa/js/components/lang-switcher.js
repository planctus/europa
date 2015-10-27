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
        overallWidth += $(this).outerWidth();
      });
      return overallWidth;
    },
    itemsOverflow: function() {
      var availableSpace = pageSwitcher.listWidth() - pageSwitcher.iconWidth() - pageSwitcher.unavailableWidth();
      return pageSwitcher.itemsWidth() > availableSpace - 20;
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

      var overflowToggle = function () {
        if (pageSwitcher.itemsOverflow()) {
          pageLanguageSelector.trigger('hide.list');
          pageLanguageSelector.trigger('show.dropdown');
        } else {
          pageLanguageSelector.trigger('show.list');
          pageLanguageSelector.trigger('hide.dropdown');
        }
      };

      if (typeof enquire !== 'undefined') {
        enquire.register(Drupal.europa.breakpoints.small, {
          setup: function() {
            overflowToggle();
          }
        }, true);
      }
    }
  };
})(jQuery);