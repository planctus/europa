(function ($) {
  Drupal.behaviors.europaComponents_filters = {
    attach: function (context, settings) {
      // Saving .block-filters in variable as a generic element, so that
      // The script works for all filter blocks on current page
      var $filters      = $('.filters'),
          hideText      = Drupal.t('Hide'),
          refineText    = Drupal.t('Refine'),
          clearAll      = Drupal.t('Clear all');

      // Hide filter button on ajax call
      if ($filters.is(':visible')) {
        $('.filters__btn-collapse', context).hide();
      }

      if ($(".region-sidebar-first").length > 0) {
        $(".region-sidebar-first").removeClass("well");
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
          $('.filters__result-count').append("<button class='btn btn-default filters__btn-reset--small hidden-sm hidden-md hidden-lg'>" + clearAll +
            '</button>'
          );

          $(".filters__btn-reset--small").on("click", function(){
             $(".filters__btn-reset").trigger("click");
          });
        }

        $(this).addClass('collapse');
        $('.filters__btn-submit', $filters).removeClass('ctools-use-ajax ctools-auto-submit-click js-hide');
        $filters.find('form').removeClass('ctools-auto-submit-full-form ctools-auto-submit-processed');

        $filters.on('show.bs.collapse', function(){
          $(this).prepend('<a class="close filters__close" data-toggle="collapse" ' +
            ' data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
            ' aria-expanded="true" aria-controls="collapseFilters">' + hideText + '</a>');
          $('.filters__btn-collapse').hide();
          $('.filters__btn-reset--small').hide();
        });

        $filters.on('hide.bs.collapse', function(){
          $(this).children('.close').remove();
          $('.filters__btn-collapse').show();
          $('.filters__btn-reset--small').show();
        });

        if (typeof enquire !== 'undefined') {
            enquire.register('screen and (min-width: 768px)', {
            match : function() {
              $('.filters__btn-submit', $filters).addClass('ctools-use-ajax ctools-auto-submit-click js-hide');
              //$('.form-submit', $filters).addClass('ctools-use-ajax ctools-auto-submit-click js-hide');
              $filters.find('form').addClass('ctools-auto-submit-full-form ctools-auto-submit-processed');
              $filters.removeAttr('style').removeClass('collapse in');
              $filters.children('.close').remove();
              $(".region-sidebar-first").addClass("well");
            },
            unmatch : function() {
              $('.filters__btn-submit', $filters).removeClass('ctools-use-ajax ctools-auto-submit-click js-hide');
              // $('.form-submit', $filters).removeClass('ctools-use-ajax ctools-auto-submit-click js-hide');
              $filters.find('form').removeClass('ctools-auto-submit-full-form ctools-auto-submit-processed');
              $filters.addClass('collapse');
              $('.filters__btn-collapse').show();
              if ($(".region-sidebar-first").length > 0) {
                $(".region-sidebar-first").removeClass("well");
              }              
            }
          });
        }
      });
    }
  }
})(jQuery);
