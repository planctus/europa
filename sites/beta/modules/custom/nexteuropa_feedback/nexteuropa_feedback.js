(function ($) {
    Drupal.behaviors.nexteuropa_feedback = {
        attach: function(context) {
            $('#nexteuropa-feedback-form').once('feedback', function() {
                var $submitButton = $('.form-submit', this),
                    $accordionWrapper = $('#feedback-accordion');

                $submitButton.hide();
                $('.accordion-body', this).removeClass('in');
                $('.accordion-toggle', this).addClass('collapsed');

                // Accordion behavior
                $accordionWrapper.on('show.bs.collapse', function () {
                    // Clean up other blocks
                    $('.in' , this).collapse('hide');

                    // Show submit button when opening accordion element and the button is already hidden
                    if ($submitButton.is(':hidden')) {
                        $submitButton.show();
                    }
                    $('.feedback-component').velocity("scroll", {easing:'ease', duration: 400});
                });
                // Set feedbck type based on accordion state.
                $accordionWrapper.on('shown.bs.collapse', function () {
                    $('input[name="feedback_type"]').val($('.in' , this).attr('id'));
                });
                // Hide submit button when no accordion elements are open
                $accordionWrapper.on('hidden.bs.collapse', function() {
                    if ($('.accordion-body', this).children(':visible').length == 1) {
                        $submitButton.hide();
                    }
                });

                // Toggle class on feedback open
                $('#feedback-trigger').click(function() {
                    $('.feedback-component__wrapper').toggleClass('region-open');
                    $('.feedback-component').velocity("scroll", {easing:'ease', duration: 350});
                });

            });
            var currentType = $('input[name="feedback_type"]').val();
            var $feedbackActiveCollapsed = $('#feedback-form-content, #'+currentType+'');

            // Initializing collapse plugin so that it works on browsers without css3 transitions
            $feedbackActiveCollapsed.collapse({toggle: false});

            // Checking if value of the hidden field is 'feedback'
            if(currentType !== 'feedback') {

                // Hiding error message from the feedback from
                $('.feedback-processed .messages').hide();

                // Showing active tab after ajax call with empty field
                $feedbackActiveCollapsed.collapse('toggle');
                $('#' + currentType).siblings('.accordion-heading').children().removeClass('collapsed');
            }
        }
    }
})(jQuery);
