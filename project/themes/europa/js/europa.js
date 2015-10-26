(function ($) {
  Drupal.europa = Drupal.europa || {};
  Drupal.europa.breakpoints = Drupal.europa.breakpoints || {};

  // TODO:
  // Populate the breakpoints with those comming from Breakpoints module.
  // @see breakpoints js module for potential solution.
  Drupal.europa.breakpoints.medium = 'screen and (min-width: 480px)';
  Drupal.europa.breakpoints.small = 'screen and (min-width: 768px)';

  Drupal.behaviors.europa_tabs = {
    attach: function (context) {
      $('.nav-tabs--with-content').once('nav-tabs', function() {
        $this = $(this);
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register('screen and (max-width: 479px)', {
            // setup
            setup : function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
            },
            // mobile
            match : function() {
              $this.siblings('.tab-content').children().removeClass('tab-pane');
            },
            // desktop
            unmatch: function() {
              $this.siblings('.tab-content').children().addClass('tab-pane');
            },
          });
        }
      });
    }
  };

  Drupal.behaviors.equal_blocks = {
    attach: function (context) {
      $('.equal-height').once('equal-height-blocks', function() {
        $equal_height_block = $(this);
        if (typeof enquire !== 'undefined') {
          // Runs on device width change.
          enquire.register(Drupal.europa.breakpoints.small, {
            // desktop
            match : function() {
              Drupal.behaviors.equal_blocks.fixBlockHeights($equal_height_block, false);
            },
            // mobile
            unmatch : function() {
              Drupal.behaviors.equal_blocks.fixBlockHeights($equal_height_block, true);
            },
          });
        }
      });
    },

    fixBlockHeights: function ($block, stop) {
      $block.each(function () {
        $wrapper = $(this);
        var $blocks = [];

        // Columns and rows.
        if ($wrapper.hasClass('listing__wrapper--two-columns') || $wrapper.hasClass('listing__wrapper--row-two')) {
          var selector = '.listing__item-link > :first-child';
          // Two column listing blocks.
          if ($wrapper.hasClass('listing__wrapper--two-columns')) {
            $first_column = $wrapper.find('.listing:first-child .listing__item');
            $last_column = $wrapper.find('.listing:last-child .listing__item');
          }
          // Row with two items.
          else if ($wrapper.hasClass('listing__wrapper--row-two')) {
            $first_column = $wrapper.find('.listing .listing__item:nth-child(odd)');
            $last_column = $wrapper.find('.listing .listing__item:nth-child(even)');
          }

          // First column always contains more items if not equal.
          $first_column.each(function(index, item) {
            // Only applicable if there's an item in the other column at index.
            if (!$last_column.eq(index)) {
              return;
            }
            var $row = $(item).find(selector).add($last_column.eq(index).find(selector));
            $blocks.push($row);
          });
        }
        // Simple listing blocks.
        else {
          $blocks.push($wrapper.find('.listing__item-link > :first-child'));
        }

        var i, max;
        for (i = 0, max = $blocks.length; i < max; i++) {
          var $block = $blocks[i].equalHeight();
          // if(stop) {
          //   $block.stop();
          // }
        }
      });
    }
  };

  var trackElements = [];
  var errorEventSent = 'Piwik, trackEvent was not fired up.';
/**
 * Acts like a wrapper for Piwik push method.
 *
 * @fires _paq.push
 *
 * @param {triggerValue}
 *   How many times should the call be triggered by page load.
 *   Accepts 0,1 (0 for always and 1 just for one time).
 *
 * @param {action}, {category}, {value}, {data}
 * @see https://developer.piwik.org/guides/tracking-javascript-guide
 */
  PiwikDTT = {
    sendTrack: function(triggerValue, action, category, value, data) {
      if (typeof action === "undefined" || action === null || action === '') {
        action = "trackEvent";
      }
      // Trigger only once.
      if (triggerValue == 1) {
        var innerElements = (triggerValue + action + category + value + data);
        if ($.inArray(innerElements, trackElements) === -1){
          trackElements.push(innerElements);
          if (typeof _paq != 'undefined'){
            _paq.push([action, category, value, data]);
          } else {
            console.log(errorEventSent);
          }
        }
      }
      // Always trigger.
      if (triggerValue == 0){
        if (typeof _paq != 'undefined'){
          _paq.push([action, category, value, data]);
        } else {
          console.log(errorEventSent);
        }
      }
    }
  }
})(jQuery);
