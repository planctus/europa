(function ($) {
  Drupal.behaviors.europaComponents_filters = {
    attach: function (context, settings) {
      var $filters      = $('.filters'),
          refineText    = Drupal.t('Refine'),
          hideText      = Drupal.t('Hide'),
          clearAll      = Drupal.t('Clear all'),
          $resultsCount = $('.filters__result-count'),
          $exposedData  = $('.exposed_filter_data');

      // On page load and ajax calls.

      // Adding things.
      if ($resultsCount.is(':visible') && !$('.filters__btn-collapse').length) {
        $resultsCount
          .append(
            '<div class="btn-group">' +
              '<button class="btn btn-default filters__btn-reset--small hidden-sm hidden-md hidden-lg">' + clearAll +
              '</button>' +
              '<button class="btn btn-primary hidden-sm hidden-md hidden-lg filters__btn-collapse" type="button"' +
              ' data-toggle="collapse" data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
              ' aria-expanded="false" aria-controls="collapseFilters">' +
                refineText +
              '</button>' +
            '</div>'
          );
      }

      // Removing things.
      // Desktop first case.
      $filters.find('.filters__btn-submit').hide();
      // First there are results, then there are no results.
      if ($exposedData.length &&
        $exposedData.find('.content').html().trim() === "") {
        $exposedData.hide();
      }

      // Listeners.
      // Small button emulating the original reset button.
      $(".filters__btn-reset--small").on("click", function(){
        $(".filters__btn-reset").trigger("click");
      });

      // Runs only once.
      $filters.once('filters', function() {
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register('screen and (max-width: 768px)', {
            // mobile
            match : function() {
              var $sidebarFirst = $(".region-sidebar-first");

              // Adding things.
              $('.filters__btn-submit', $filters).removeClass('ctools-auto-submit-click').show();
              $('.filters__btn-collapse').show();
              $filters.wrapInner("<div class='filters__wrapper'></div>");
              $filters.addClass('collapse');

              // Listeners.
              // Clicking on the submit should collapse the filters.
              $('.filters__btn-submit').click(function () {
                $filters.removeClass('in');
                $filters.children('.close').remove();
              });

            },
            // desktop
            unmatch : function() {
              var $sidebarFirst = $(".region-sidebar-first"),
                $filtersWrapper = $(".filters__wrapper");

              $('.filters__btn-submit', $filters).addClass('ctools-auto-submit-click')

              // Removing things.
              $filters.removeClass('collapse in');
              $filters.find('.filters__btn-submit').hide();
              $filters.children('.close').remove();
              if ($filtersWrapper.length) {
                $filtersWrapper.children().unwrap("<div class='filters__wrapper'></div>");
              }
            }
          });
        }

        $filters.on('show.bs.collapse', function(){
          $(this).prepend('<a class="close filters__close" data-toggle="collapse" ' +
          ' data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
          ' aria-expanded="true" aria-controls="collapseFilters">' + hideText + '</a>');
          $('.filters__btn-collapse').hide();
          $('.filters__btn-reset--small').hide();
          $filters.find('.filters__btn-submit').show();
        });

        $filters.on('hide.bs.collapse', function(){
          $(this).children('.close').remove();
          $('.filters__btn-collapse').show();
          $('.filters__btn-reset--small').show();
        });
      }); // end of .once()
    }
  };
})(jQuery);
