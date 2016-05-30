/**
 * @file
 * JS file for accessibility tabs.
 */

(function ($) {
  // Fix for accessibility issue, when user reach the close tab,
  // (using the keyboard tab), it should then move to first language selection.
  Drupal.behaviors.facets_in_filters = {
    attach: function (context) {
      // Normal inputs.
      $('.facet-trigger').on('click', function(event){
        $(this).find('input').each(function(i, e) {
          currentvalue = $(e).attr('value');
          if (currentvalue.indexOf("trigger") == -1) {
            $(e).attr('value', $(e).attr('value') + '&trigger=true');
          }
        });
      });
      // For select lists.
      $('.facet-trigger select').on('change', function(event){
        currentvalue = $(this).attr('name');
        if (currentvalue.indexOf("trigger") == -1) {
          $(this).attr('name', $(this).attr('name') + '_trigger');
        }
      });
    }
  }
})(jQuery);
