(function ($) {
  $(document).ready(function(){
    var $list  = $('.lang-select-page__list');

    $list.each(function() {
      var $select = $('<select />');

      $(this).find('a').each(function() {
        var $option = $('<option />');
        $option.attr('value', $(this).attr('href')).html($(this).html());
        $select.append($option);
      });

      $list.replaceWith($select);
    });
  });
})(jQuery);