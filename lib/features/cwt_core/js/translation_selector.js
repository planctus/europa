/**
 * @file
 * Taken directly from old CWT.
 */
(function ($) {
  Drupal.behaviors.translation_selector = {
    attach: function(context) {
      var selectNav = function(event) {
        var href = $(event.target).val();
        if (href !== window.location.href) {
          window.location.href = href;
        }
      };

      var options = '';
      $('.translation-list').once('translation_selector', function(){
        $('li a', this).once('translation_link', function() {
          var $link = $(this);
          var selected = $link.hasClass('active') ? ' selected="selected"' : '';
          options += '<option value="' + $link.attr('href') + '"' + selected + '>' + $link.html() + '</option>'
        });
        var select = $('<div class="form-select-wrapper"><select class="translation_select form-control form-select">' + options + '</select></div>');
        $(this).replaceWith(select);
        select.children().data('activation', 'activated').on({
          keydown: function(event) {
            if (event.which === 13) {
              if ($(this).data('activation') === 'paused') {
                $(this).data('activation', 'activated');
                $(this).trigger('change');
              }
            }
            else {
              $(this).data('activation', 'paused');
            }
          },
          click: function(event) {
            if ($(this).data('activation') === 'paused') {
              $(this).data('activation', 'activated');
              $(this).trigger('change');
            }
          },
          change: function(event) {
            if ($(this).data('activation') === 'activated') {
              selectNav(event);
            }
          }
        });
      });
    }
  }
})(jQuery);