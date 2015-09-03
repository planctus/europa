(function ($) {
  $(document).ready(function(){
    var selector = '.lang-select-page--dropdown',
        $list  = $(selector).find('ul'),
        listClass = $list.attr('class');

    $list.each(function() {
      var $select = $('<select />');
      $select.addClass(listClass);

      $(this).find('a').each(function() {
        var $option = $('<option />');
        $option.attr('value', $(this).attr('href')).html($(this).html());
        $select.append($option);
      });

      if (!$list.parent().find('select').length) {
        $list.parent().append($select);
      }
    });
    $list.hide();
  });
})(jQuery);