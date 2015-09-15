(function ($) {
  /**
   * Transformer class manipulating the list
   * @param selector css selector, NOT jQuery one
   * @constructor
   */
  function Transformer(selector){
    this.selector = selector;

    this.hideList = function(){
      $(this.selector).find('ul.lang-select-page__list').hide();
    };
    this.showList = function(){
      $(this.selector).find('ul.lang-select-page__list').show();
    };
    this.hideSelect = function(){
      $(this.selector).find("select").hide();
    };
    this.showSelect = function(){
      $(this.selector).find("select").show();
    };
    this.toggle = function(){
      if($(this.selector).find("select").is(":visible")){
        this.hideSelect();
        this.showList();
      } else if($(this.selector).find('ul.lang-select-page__list').is(":visible")){
        this.hideList();
        this.showSelect();
      }
    };
    this.attachSelect = function(){
      var selector = this.selector,
        $list  = $(selector).find('ul.lang-select-page__list'),
        listClass = $list.attr('class');

      $list.each(function() {
        var $select = $('<select />').addClass(listClass);

        $(this).find('a').each(function() {
          var $option = $('<option />');
          $option.attr('value', $(this).attr('href')).html($(this).html());
          $select.append($option);
        });

        if (!$list.parent().find('select').length) {
          $list.parent().append($select);
          $(selector).find("select").hide();
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
      // 40px of buffer in wrapper which is compensated due to font icon changing size
      return ($list.outerWidth() + $icon.outerWidth() > $wrapper.outerWidth() - 40);
    }
  }

  Drupal.behaviors.languageSwitcherPage = {
    attach: function(context) {
      if (typeof enquire !== 'undefined') {
        var resizeListener = function() {
          $(window).on('resize', function(){
            if (listIsWider()) {
              switcher.hideList();
              switcher.showSelect();
            } else {
              switcher.hideSelect();
              switcher.showList();
            }
          });
        };
        enquire.register(Drupal.europa.breakpoints.small, {
          // desktop
          match : function() {
            resizeListener();
          },
          // mobile
          unmatch : function() {
            resizeListener();
          },
          setup: function() {
            switcher = new Transformer('.lang-select-page--transparent');
            switcher.attachSelect();
            listIsWider() && switcher.toggle();
            resizeListener();
          }
        });
      }
    }
  };
})(jQuery);