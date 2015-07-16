(function ($) {
  Drupal.behaviors.europa_pager = {
    attach: function(context) {
      var options = '';
      $('ul.pager').once('pager', function(){
        $('li.select', this).once('pagerselect', function(){
          var $link = $('a', this);
          if($link.length > 0) {
            var value = $link.attr('href');
            var title = Drupal.t('Page') + ' ' + $link.html();
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
          var select = $('<select class="combo__dropdown">' + options + '</select>');
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
          $('.combo__container', this).before(select);
          //$('li.pager-current-combo .pager-current-combo-current').hide();
        }
      });
    }
  };

  function selectNav(event) {
    var href = $(event.target).val();
    if(href !== window.location.href) {
      window.location.href = href;
    }
  }
})(jQuery);
