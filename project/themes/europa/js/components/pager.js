(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function(context) {
      var options = '';
      $('ul.pager').once('pager', function(){
        $('li.select', this).once('pagerselect', function(){
          var $link = $('a', this);
          if($link.length > 0) {
            var value = $link.attr('href');
            var title = $link.html();
            var selected = '';
          } else {
            var value = '';
            var title = Drupal.t('Page') + ' ' + $(this).html();
            var selected = 'selected="selected"';
          }
          options += '<option value="' + value + '"' + selected + '>' + title + '</option>';
          $(this).remove();
        });
        if(options != '') {
          var select = $('<span class="pager-dropdown-wrapper"><select class="pager-dropdown">' + options + '</select></span>');
          select.children().data('activation', 'activated').on({
            keydown: function(event) {
              if(event.which === 13){
                if($(this).data('activation') === 'paused'){
                  $(this).data('activation', 'activated');
                  $(this).trigger('change');
                }
              } else {
                $(this).data('activation', 'paused');
              }
            },
            click: function(event) {
              if($(this).data('activation') === 'paused'){
                $(this).data('activation', 'activated');
                $(this).trigger('change');
              }
            },
            change: function(event) {
              if($(this).data('activation') === 'activated'){
                selectNav(event);
              }
            }
          });
          $('li.pager-current-combo .pager-current-combo-current', this).after(select);
          $('li.pager-current-combo .pager-current-combo-current').hide();
        }
      });
    }
  }
})(jQuery);
