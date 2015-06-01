(function ($) {
  Drupal.behaviors.europaComponents_filters = {
    attach: function (context, settings) {
      // Saving .filters in variable as a generic element, so that
      // The script works for all filter blocks on current page
      var $filters      = $('.filters'),
          hideText      = Drupal.t('Hide'),
          refineText    = Drupal.t('Refine'),
          clearAll      = Drupal.t('Clear all');

      // ONCE
      $filters.once('filters', function(){
        // Including filter button.
        if ($('.filters__result-count').is(':visible') && $('.filters__btn-collapse').length == 0) {
          Drupal.addFiltersButtonCollapse();
        }

        if ($(".region-sidebar-first").length > 0) {
          $(".region-sidebar-first").removeClass("well");
        }

        $(".filters__btn-reset--small").on("click", function(){
          $(".filters__btn-reset").trigger("click");
        });

        // Adding a wrapper to take the padding which is problematic for the bs.collapse.
        $filters.wrapInner("<div class='filters__wrapper'></div>");

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

        // Responsive behavior.
        //Drupal.filtersAdapt();
      });


      ////////////////////////////////////////////////////////////////////////////////////////////
      ///// ALL THE TIME /////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////

      // Filters responsive behavior.
      Drupal.filtersAdapt();

      // Including refine filter button.
      if ($('.filters__result-count').is(':visible') && $('.filters__btn-collapse').length == 0) {
        Drupal.addFiltersButtonCollapse();
      }

      // Including reset button.
      if ($('.filters__result-count').is(':visible') &&
          $('.exposed_filter_data').length > 0 &&
          $('.filters__btn-reset--small').length == 0) {
        Drupal.addFiltersButtonReset();
      }

      // Scenario when firstly there are results, but not results on second go.
      if ($('.exposed_filter_data').length > 0 &&
          $('.exposed_filter_data').find('.content').html().trim() === "") {
        $('.exposed_filter_data').hide();
      }

      if ($(".filters__btn-reset--small").length > 0) {
        $(".filters__btn-reset--small").on("click", function(){
          $(".filters__btn-reset").trigger("click");
        });
      }

    } /// end attached scope.
  };

  Drupal.filtersAdapt = function() {
    var $filters = $('.filters');
    if (typeof enquire !== 'undefined') {
      enquire.register('screen and (min-width: 768px)', {
        match : function() {
          $('.filters__btn-submit', $filters).addClass('ctools-use-ajax ctools-auto-submit-click js-hide');
          $filters.find('form').addClass('ctools-auto-submit-full-form ctools-auto-submit-processed');
          $filters.removeAttr('style').removeClass('collapse in');
          $filters.children('.close').remove();
          // When desktop, wrapper is not needed as the .well is back in the sidebar.
          if (!$(".region-sidebar-first").hasClass('well')) {
            $(".region-sidebar-first").addClass('well');
          }
          if ($(".filters__wrapper").length > 0) {
            $(".filters__wrapper").children().unwrap("<div class='filters__wrapper'></div>");
          }
        },
        // mobile
        unmatch : function() {
          $('.filters__btn-submit', $filters).removeClass('ctools-use-ajax ctools-auto-submit-click js-hide');
          $filters.find('form').removeClass('ctools-auto-submit-full-form ctools-auto-submit-processed');
          $filters.addClass('collapse');
          $('.filters__btn-collapse').show();
          if ($(".region-sidebar-first").length > 0 &&
              $(".region-sidebar-first").hasClass('well') &&
              $filters.children('.filters__wrapper').length == 0) {
            $(".region-sidebar-first").removeClass("well");
            $filters.wrapInner("<div class='filters__wrapper'></div>");
          }
          // Clicking on the submit should collapse the filters.
          $('.filters__btn-submit').click(function () {
            $('.filters__btn-collapse').trigger("click");
          });
        }
      });
    }
  };

  Drupal.addFiltersButtonCollapse = function() {
    var refineText    = Drupal.t('Refine');
    var $resultsCount = $('.filters__result-count');

    $resultsCount.append('<button class="btn btn-primary hidden-sm hidden-md hidden-lg filters__btn-collapse" type="button"' +
      ' data-toggle="collapse" data-target="#' + Drupal.settings.europa.exposedBlockId + '"' +
      ' aria-expanded="false" aria-controls="collapseFilters">' +
      refineText +
      '</button>'
    );
  };

  Drupal.addFiltersButtonReset = function() {
    var clearAll      = Drupal.t('Clear all');
    var $resultsCount = $('.filters__result-count');

    $resultsCount.append("<button class='btn btn-default filters__btn-reset--small hidden-sm hidden-md hidden-lg'>" + clearAll +
      '</button>'
    );
  };

})(jQuery);
