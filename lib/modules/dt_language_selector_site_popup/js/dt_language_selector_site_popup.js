/**
 * @file
 * JS file for accessibility tabs.
 */

(function ($) {
// Fix for accessibility issue, when user reach the close tab,
// (using the keyboard tab), it should then move to first language selection.
Drupal.behaviors.splash_accessibility = {
    attach: function (context) {
        var $firstLanguage = (".splash-page__btn-language:first");
        $('.splash-page--overlay').keydown(function(e){
            if($('.splash-page__btn-close').is(":focus") && (e.which || e.keyCode) == 9){
                e.preventDefault();
                $($firstLanguage).focus();
            }
        });
    }
}
})(jQuery);
