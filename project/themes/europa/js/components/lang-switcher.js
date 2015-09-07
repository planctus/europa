(function ($) {
  $(document).ready(function(){
    var selector = '.lang-select-page--dropdown',
        $list  = $(selector).find('ul'),
        listClass = $list.attr('class');

    $list.each(function() {
      var $select = $('<select />').addClass(listClass).addClass('form-control');

      $(this).find('a').each(function() {
        var $option = $('<option />');
        $option.attr('value', $(this).attr('href')).html($(this).html());
        $select.append($option);
      });

      if (!$list.parent().find('select').length) {
        $list.parent().append($select);
        $select.on({
          change: function(event) {
            var optionHref = $(this).val(),
                $item = $list.find('li'),
                $location = $item.children('a[href="' + optionHref + '"]');

            // $location.click(); // ajax-friendly
            window.location.href = $location.attr('href');
          }
        });
      }
    });
    $list.hide();
  });
})(jQuery);