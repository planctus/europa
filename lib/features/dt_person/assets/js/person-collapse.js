/**
 * @file
 */

(function ($) {
    $(document).ready(function () {
        var $topbar = $('.profile_topbar__expander'),
            show_text = Drupal.t('Show contact details'),
            hide_text = Drupal.t('Hide contact details'),
            up = 'icon--up',
            down = 'icon--down',
            $button = $('<button class="btn btn-collapse" data-target="#profiletopbar" data-toggle="collapse">'
                + '<span class="toggling-text">' + show_text + '</span>'
                + '<span class="icon icon--blue-dark icon--down"></span>'
                + '</button>');
        if ($topbar.length) {
             $($button).on('click', function () {
                var $arrow = $('.icon', $(this)),
                    add = $arrow.hasClass(down) ? up : down,
                    rem = $arrow.hasClass(down) ? down : up,
                    fillMe = $('.toggling-text', $(this)),
                    toggler = fillMe.text() == hide_text ? show_text : hide_text;
                fillMe.text(toggler);
                $arrow.addClass(add).removeClass(rem);
            });
            $('.profile_topbar__column').append($button);
        }
    });
})(jQuery);
