(function ($) {
	
  /**
   * Returns true if list is bigger than wrapper.
   */
  function listIsWider(){
    var $wrapper = $('.lang-select-page'),
      $list = $('.lang-select-page__list'),
      $icon = $('.lang-select-page__icon');

    if ($list.length && $list.is(':visible') && $wrapper.length) {
      // 40px of buffer in wrapper which is compensated due to font icon changing size.
      return ($list.outerWidth() + $icon.outerWidth() > $wrapper.outerWidth() - 40);
    }
  }

  Drupal.behaviors.languageSwitcherPage = {
    attach: function(context) {
      var pageLanguageSelector = $('.lang-select-page');
      pageLanguageSelector.selectify({
        listSelector: 'ul.lang-select-page__list',
        item: 'lang-select-page__option',
        other: '.lang-select-page__other',
        selected: '.is-selected'
      });

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
              if(listIsWider()){
                pageLanguageSelector.trigger('hide.list');
                pageLanguageSelector.trigger('show.dropdown');
              }
            });
          },
          setup: function() {
            if(listIsWider()){
              pageLanguageSelector.trigger('hide.list');
              pageLanguageSelector.trigger('show.dropdown');
            }
          }
        }, true);
      }
    }
  };
})(jQuery);