(function ($) {
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

              $location.click(); // ajax-friendly
            }
          });
        }
      });
    };
    this.detachSelect = function(){
      $(this.selector).find('select').remove();
    };
  }

  Drupal.behaviors.languageSwitcherPage = {
    attach: function(context) {
      if (typeof enquire !== 'undefined') {
        enquire.register(Drupal.europa.breakpoints.medium, {
          // desktop
          match : function() {
            switcher.hideSelect();
            switcher.showList();
            $(window).resize(function() {

            });
          },
          // mobile
          unmatch : function() {
            switcher.hideList();
            switcher.showSelect();
            $(window).off('resize');
          },
          setup: function() {
            switcher = new Transformer('.lang-select-page--transparent');
            switcher.attachSelect();
          }
        });
      }
    }
  };
})(jQuery);