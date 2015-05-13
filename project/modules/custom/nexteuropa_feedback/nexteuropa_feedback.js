(function ($) {
  Drupal.behaviors.nexteuropa_feedback = {
    attach: function(context) {
      var $feedbackForm = $('#nexteuropa-feedback-form');
      var $feedbackFormWrapper = $('.feedback-form__wrapper');

      $feedbackForm.once('feedback', function() {
        var $submitButton = $('.form-submit', this),
            $accordionWrapper = $('#feedback-form__accordion');

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

            // Scroll window so that the form sticks to the footer
            $feedbackForm.velocity("scroll", {easing:'ease', duration: 400});
          });

        // Set feedbck type based on accordion state.
        $accordionWrapper.on('shown.bs.collapse', function () {
          $('input[name="feedback_type"]').val($('.in' , this).attr('id'));
        });

        // Hide submit button when no accordion elements are open
        $accordionWrapper.on('hidden.bs.collapse', function() {
          if ($('.accordion-body', this).children(':visible').length == 0) {
            $submitButton.hide();
          }
        });

        // Toggle class on feedback open
        $('.feedback-form__trigger').click(function() {
          $feedbackFormWrapper.toggleClass('is-open');
          $feedbackForm.velocity("scroll", {easing:'ease', duration: 350});
        });
      });

      // Remove is-open class when button for loading new form is clicked
      $('.feedback__message a').click(function(){
        $feedbackFormWrapper.removeClass('is-open');
      });

      var currentType = $('input[name="feedback_type"]').val();
      var $feedbackActiveCollapsed = $('#feedback-form__content, #'+currentType+'');

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
