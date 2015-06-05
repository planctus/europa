(function ($) {
  Drupal.behaviors.europaComponents_filters = {

    attach: function (context, settings) {
      var $filters       = $('.filters'),
          $filtersSubmit = $('.filters__btn-submit', $filters);
          refineText     = Drupal.t('Refine'),
          hideText       = Drupal.t('Hide'),
          clearAll       = Drupal.t('Clear all'),
          $resultsCount  = $('.filters__result-count');

      // Function for hiding Submit and Reset buttons
      var hideMainFilterButtons = function() {
        $('.filters__btn-submit, .filters__btn-reset',$filters).hide();
      }

      var hideFilterButtons = function() {
        $('.filters__btn-collapse, .filters__btn-reset--small').hide();
      }

      var showFilterButtons = function() {
        $('.filters__btn-collapse, .filters__btn-reset--small').show();
      }

      // Adding buttons for the filters
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

      // Listeners.
      // Small button emulating the original reset button.
      $(".filters__btn-reset--small").on("click", function(){
        $(".filters__btn-reset").trigger("click");
      });

      // Runs only once.
      $filters.once('filters', function() {
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register('screen and (min-width: 768px)', {
            // desktop
            match : function() {
              var $sidebarFirst = $(".region-sidebar-first"),
                $filtersWrapper = $(".filters__wrapper");

              $filtersSubmit.addClass('ctools-auto-submit-click');

              // Opening filters when changing to desktop
              $filters
                .removeClass('collapse')
                .addClass('collapse in')
                .attr('aria-expanded', true);

              // Hiding filter buttons
              hideMainFilterButtons();

              $filters.children('.close').remove();
              if ($filtersWrapper.length) {
                $filtersWrapper.children().unwrap("<div class='filters__wrapper'></div>");
              }
            },
            // mobile
            unmatch : function() {
              var $sidebarFirst = $(".region-sidebar-first");

              // Showing buttons on viewport switch
              showFilterButtons();

              $filters.wrapInner("<div class='filters__wrapper'></div>");
              $filters
                .removeClass('collapse in')
                .addClass('collapse')
                .attr('aria-expanded', false);

              $filtersSubmit.removeClass('ctools-auto-submit-click');
            },

            setup: function() {
              $filters.addClass('collapse');
              // Hiding filter buttons
              hideMainFilterButtons();
              $filtersSubmit.removeClass('ctools-auto-submit-click').show();
              $filters.wrapInner("<div class='filters__wrapper'></div>");

              $filtersSubmit.click(function () {
                if (!$filtersSubmit.hasClass('ctools-auto-submit-click')) {
                  $filters.collapse('hide');
                }
              });

              $filters.on('show.bs.collapse', function(){
                $(this).prepend('<a class="close filters__close" data-toggle="collapse" ' +
                ' data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
                ' aria-expanded="true" aria-controls="collapseFilters">' + hideText + '</a>');
                hideFilterButtons();
                $filters.find('.filters__btn-submit').show();
              });

              $filters.on('hide.bs.collapse', function(){
                $(this).children('.close').remove();
                showFilterButtons();
              });
            },
          });
        }
      }); // end of .once()
    }
  };
})(jQuery);
