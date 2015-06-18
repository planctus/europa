(function ($) {
  Drupal.behaviors.europaComponents_filters = {

    attach: function (context, settings) {
      var $filters        = $('.filters'),
          $filtersSubmit  = $('.filters__btn-submit', $filters),
          filtersFormId   = $filters.find('form').attr('id');
          refineText      = Drupal.t('Refine'),
          hideText        = Drupal.t('Hide'),
          clearAll        = Drupal.t('Clear all'),
          $resultsCount   = $('.filters__result-count'),
          $itemsNumber    = $('.filters__items-number');

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
              '<button class="btn btn-default filters__btn-reset--small">' + clearAll +
              '</button>' +
              '<button class="btn btn-primary filters__btn-collapse" type="button"' +
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
      // Add throbber next to content type and items count text
      $filters.once('filters', function() {
        throbber = '<div class="ajax-progress ajax-progress-throbber"><i class="icon icon--spinner is-spinning"></i></div>';
        $(document)
          .ajaxStart(function(e) {
            if (typeof e.currentTarget.activeElement.form != 'undefined' && e.currentTarget.activeElement.form.id === filtersFormId) {
              $itemsNumber
                .prepend(throbber);
            }
          });

        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register('screen and (min-width: 992px)', {
            // desktop
            match : function() {
              var $sidebarFirst = $(".region-sidebar-first"),
                $filtersWrapper = $(".filters__wrapper");

              $filtersSubmit.addClass('ctools-auto-submit-click');

              // Opening filters when changing to desktop
              $filters
                .removeClass('collapse')
                .addClass('collapse in')
                .attr('aria-expanded', true)
                .removeAttr('style');

              // Hiding filter buttons
              //hideMainFilterButtons();

              $filters.children('.close').remove();
              if ($filtersWrapper.length) {
                $filtersWrapper.children().unwrap("<div class='filters__wrapper'></div>");
              }
            },
            // mobile
            unmatch : function() {
              var $sidebarFirst = $(".region-sidebar-first");

              // Showing buttons on viewport switch
              //showFilterButtons();

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
              //hideMainFilterButtons();
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
