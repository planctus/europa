'use strict';

(function ($) {
  $.fn.selectify = function (options) {
    this.each(function () {
      var settings = $.extend({
        listWrapper: $(this),
        listSelector: 'ul',
        item: 'li',
        other: '.item__other'
      }, options);
      var attachDropDown = function () {
        var listClass = settings.listSelector,
          $list = $(listClass);

        $list.each(function () {
          var $select = $('<select />').addClass(listClass);

          $list.find(settings.item).each(function () {
            var $option = $('<option />');
            $option.attr('value', $(this).find('a').attr('href')).html($(this).html());
            $select.append($option);
          });

          if (!$list.parent().find('select').length) {
            $list.parent().append($select);
            settings.listWrapper.find('select').hide();
            $select.on({
              change: function () {
                var optionHref = $(this).val(),
                  $item = $list.find(settings.item),
                  $location = $item.children('a[href="' + optionHref + '"]');

                window.location.href = $location.attr('href');
              }
            });
          }
        });
      };
      var hideDropDown = function () {
        settings.listWrapper.find('select').hide();
      };
      var hideList = function () {
        settings.listWrapper.find(settings.listSelector).hide();
      };
      var showDropDown = function () {
        settings.listWrapper.find('select').show();
      };
      var showList = function () {
        settings.listWrapper.find(settings.listSelector).show();
      };

      settings.listWrapper.on('hide.dropdown', hideDropDown);
      settings.listWrapper.on('hide.list', hideList);
      settings.listWrapper.on('show.dropdown', showDropDown);
      settings.listWrapper.on('show.list', showList);
      attachDropDown();
    });
  };

})(jQuery);
