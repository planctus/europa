/**
 * @file
 */

(function ($) {
  $(function() {
    var $topbar = $('.profile_topbar__expander');
    if ($topbar.length) {
      var show_text = Drupal.t('Show contact details'),
          hide_text = Drupal.t('Hide contact details'),
          clicked = false,
          $button = $('<button class="btn btn-collapse" type="button" data-toggle="collapse" data-target="#profiletopbar" aria-expanded="false" aria-controls="profiletopbar">'
            + '<span class="toggling-text">' + show_text + '</span>'
            + '<i class="icon icon--blue-dark icon--down"></i></button>');

      $('.profile_topbar__column').append($button);

      $($button).on('click', function (event) {
        var $arrow = $('.icon', $(event.target)),
            fillMe = $('.toggling-text', $(event.target)),
            toggler_text = fillMe.text() == hide_text ? show_text : hide_text;
        if (!clicked) {
          $arrow.removeClass('icon--down').addClass('icon--up');
          clicked = true;
        }
        fillMe.text(toggler_text);
      });
    }
  });
})(jQuery);
