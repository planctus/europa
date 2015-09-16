(function ($) {
  /**
   * Transformer class manipulating the list
   * @param selector css selector, NOT jQuery one
   * @constructor
   */
  function Transformer(selector){
    this.selector = selector;
    this.listSelector = 'ul.lang-select-page__list';
    this.otherLanguages = '.lang-select-page__other';
    this.selected = '.is-selected';

    this.hideList = function(){
      $(this.selector).find(this.listSelector).find(this.otherLanguages).hide();
      $(this.selector).find(this.listSelector).find(this.selected).hide();
    };
    this.showList = function(){
      $(this.selector).find(this.listSelector).find(this.otherLanguages).show();
      $(this.selector).find(this.listSelector).find(this.selected).show();
    };
    this.hideSelect = function(){
      $(this.selector).find('select').hide();
    };
    this.showSelect = function(){
      $(this.selector).find('select').show();
    };
    this.attachSelect = function(){
      var selector = this.selector,
        $list  = $(selector).find(this.listSelector),
        listClass = $list.attr('class');

      $list.each(function() {
        var $select = $('<select />').addClass(listClass);

        $(this).find('li').each(function() {
          var currentClass = $(this).attr('class');
          switch (currentClass) {
            case 'lang-select-page__option is-selected':
              var $option = $('<option />');
              $option.html($(this).html()).attr('selected', true);;
              $select.append($option);
              break;

            case 'lang-select-page__option lang-select-page__other':
              var $option = $('<option />');
              $option.attr('value', $(this).find('a').attr('href')).html($(this).html());
              $select.append($option);
              break;
          }
        });

        if (!$list.parent().find('select').length) {
          $list.parent().append($select);
          $(selector).find('select').hide();
          $select.on({
            change: function(event) {
              var optionHref = $(this).val(),
                $item = $list.find('li'),
                $location = $item.children('a[href="' + optionHref + '"]');

              window.location.href = $location.attr('href');
            }
          });
        }
      });
    };
    this.detachSelect = function(){
      $(this.selector).find('select').remove();
    };
  }

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
      switcher = new Transformer('.lang-select-page');
      switcher.attachSelect();
      if (typeof enquire !== 'undefined') {
        enquire.register(Drupal.europa.breakpoints.small, {
          // desktop
          match : function() {
            switcher.showList();
            switcher.hideSelect();
          },
          // mobile
          unmatch : function() {
            $(window).on('resize', function(){
              if(listIsWider()){
                switcher.hideList();
                switcher.showSelect();
              }
            });
          },
          setup: function() {
            if(listIsWider()){
              switcher.hideList();
              switcher.showSelect();
            }
          }
        }, true);
      }
    }
  };
})(jQuery);