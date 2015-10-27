'use strict';

(function ($) {
  $.fn.selectify = function (options) {
    this.each(function () {
      var settings = $.extend({
        listWrapper: $(this),
        listSelector: 'element__list',
        item: 'element__option',
        other: 'element__other',
        unavailable: 'element__unavailable',
        selected: 'is-selected'
      }, options);
      var attachDropDown = function () {
        var listClass = settings.listSelector,
            $list = $('ul.' + listClass);

        $list.each(function () {
          var $select = $('<select />').addClass(listClass);

          $list.find('li.' + settings.item).each(function () {
            var currentClass = $(this).attr('class');

            switch (currentClass) {

              case String(settings.item + ' ' + settings.unavailable):
                break;

              case String(settings.item + ' ' + settings.selected):
                var $option = $('<option />');
                $option.html($(this).html()).attr('selected', true);
                $select.append($option);
                break;

              case String(settings.item + ' ' + settings.other):
                var $option = $('<option />');
                $option.attr('value', $(this).find('a').attr('href')).html($(this).html());
                $select.append($option);
                break;
            }
          });

          if (!$list.parent().find('select').length) {
            $list.parent().append($select);
            settings.listWrapper.find('select').hide();
            $select.on({
              change: function () {
                window.location.href = $("a[href='" + String($(this).val()) + "']").first().attr('href');
              }
            });
          }
        });
      };
      var hideDropDown = function () {
        settings.listWrapper.find('select' + '.' + settings.listSelector).hide();
      };
      var hideList = function () {
        var $list = settings.listWrapper.find('ul.' + settings.listSelector);
        $list.children('.lang-select-page__other').hide();
        $list.children('.is-selected').hide();
      };
      var showDropDown = function () {
        settings.listWrapper.find('select' + '.' + settings.listSelector).show();
      };
      var showList = function () {
        var $list = settings.listWrapper.find('ul.' + settings.listSelector);
        $list.children('.lang-select-page__other').show();
        $list.children('.is-selected').show();
      };

      settings.listWrapper.on('hide.dropdown', hideDropDown);
      settings.listWrapper.on('hide.list', hideList);
      settings.listWrapper.on('show.dropdown', showDropDown);
      settings.listWrapper.on('show.list', showList);
      attachDropDown();
    });
  };

})(jQuery);
