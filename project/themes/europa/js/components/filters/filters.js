(function ($) {
  Drupal.behaviors.europaComponents_filters = {
    attach: function (context, settings) {
      // Saving .block-filters in variable as a generic element, so that
      // The script works for all filter blocks on current page
      var $filters      = $('.filters'),
          hideText      = Drupal.t('Hide'),
          refineText    = Drupal.t('Refine');

      // Hide filter button on ajax call
      if ($filters.is(':visible')) {
        $('.filters__btn-collapse', context).hide();
      }

      $filters.once('filters', function(){
        // Add filters button if the result count element is available and
        // the filters button is not yet available
        if ('.filters__btn-collapse'.length > 0) {
          $('.filters__result-count').append('<button class="btn btn-primary hidden-sm hidden-md hidden-lg filters__btn-collapse" type="button"' +
            ' data-toggle="collapse" data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
            ' aria-expanded="false" aria-controls="collapseFilters">' +
              refineText +
            '</button>'
          );
        }

        $(this).addClass('collapse');
        $('.form-submit', this).removeClass('ctools-auto-submit-click');

        $filters.on('show.bs.collapse', function(){
          $(this).prepend('<a class="close filters__close" data-toggle="collapse" ' +
            ' data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
            ' aria-expanded="true" aria-controls="collapseFilters">' + hideText + '</a>');
          $('.filters__btn-collapse').hide();
        });

        $filters.on('hide.bs.collapse', function(){
          $(this).children('.close').remove();
          $('.filters__btn-collapse').show();
        });

        if (typeof enquire !== 'undefined') {
          enquire.register('screen and (min-width: 768px)', {
            match : function() {
              $('.form-submit', $filters).addClass('ctools-auto-submit-click js-hide');
              $filters.removeAttr('style').removeClass('collapse in');
              $filters.children('.close').remove();
            },
            unmatch : function() {
              $('.form-submit', $filters).removeClass('ctools-auto-submit-click js-hide');
              $filters.addClass('collapse');
              $('.filters__btn-collapse').show();
            }
          });
        }
      });
    }
  }
})(jQuery);
