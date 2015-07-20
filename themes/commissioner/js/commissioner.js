(function ($) {

  var tablet    = '480px',
      lgTablet = '768px',
      desktop   = '960px';

  Drupal.behaviors.modal_dialogs = {
    attach: function(context) {
      // Fixes Bootstrap z-index issue
      // @see https://github.com/twbs/bootstrap/issues/3217
      $('.modal').appendTo($("body"));
    }
  }

  Drupal.behaviors.commissioner_contact_form = {
    attach: function(context, settings) {
      var iframeClass = '#iframe-contact-form';
      $(iframeClass).once('contact-form', function(){
        $('.contact-details').append('<button class="btn btn-default btn-default--contact" ' +
                                     'type="button" data-toggle="modal" data-target="' +
                                      iframeClass + '">' +
                                        Drupal.t('Contact') + ' ' + Drupal.settings.cwtBiography.biographyName +
                                      '</button>');
      });
    }
  }

  Drupal.behaviors.commissioner_timeline = {
    attach: function(context) {
      $('.view-biography-timeline').once('timeline', function(){
        var timelineItemsCount = $('.view-biography-timeline > .view-content .views-row').length;
        var $timelineView = $(this);

        $('.view-biography-timeline > .view-content .views-row').each(function(i){
          if (i > 4) {
            $(this).addClass('hidden');
          }
        });

        $('.btn-show-more', this).click(function(e) {
          e.preventDefault();
          $(this).hide();
          $('.view-biography-timeline .views-row.hidden').fadeIn().removeClass('hidden');

          // Refreshing scrollspy to recalculate the offset
          $('body').scrollspy('refresh');
        });
      });
    }
  }

  Drupal.behaviors.commissioner_page_navigation = {
    attach: function(context) {
      var $pageNavBlock =  $('#block-cwt-core-page-contents');
      var pageNavBlockHeight = $pageNavBlock.height();
      //var footerHeight = $('.region-footer-wrapper').outerHeight();
      $pageNavBlock.once('page-navigation', function(){

        // Page navigation scroll spy
        $('body').scrollspy({
          target: '#block-cwt-core-page-contents'
        });


        // Manually adding affix top and offset for fixed page navigation position
        $(window).scroll(function() {
          var safeHeight = pageNavBlockHeight + $('#footer').outerHeight() + 50;
          var navOffset = $pageNavBlock.parent().offset().top,
              scrollTopValue = $(window).scrollTop();
          var atBottom = (scrollTopValue + safeHeight) > $('body').height();
          if(!atBottom) {
            if (navOffset < scrollTopValue && !($pageNavBlock.hasClass('affix'))) {
              $pageNavBlock.addClass('affix').removeClass('affix-top').removeClass('affix-bottom');
            }
            else if (navOffset > scrollTopValue && !($pageNavBlock.hasClass('affix-top'))) {
              $pageNavBlock.removeClass('affix').addClass('affix-top');
            }
          } else {
            $pageNavBlock.removeClass('affix').addClass('affix-bottom');
          }

        });


        // Page smooth scrolling on anchor click
        $('a[href^="#"]', this).click(function(e) {
          e.preventDefault();

          sectionOffset = $(this.hash).offset().top;

          if ($(this).parent().is(':first-child')) {
            sectionOffset = sectionOffset - 20;
          }

          $('html, body').velocity("scroll", {easing:'ease', duration: 400, offset: sectionOffset});
        });
      });
    }
  }

  Drupal.behaviors.commissioner_branding = {
    attach: function(context) {
      var $regionBranding = $('.region-branding');

      $regionBranding.once('branding', function(){
        var buttonSearch = '<span class="btn btn-mobile btn-mobile-search hidden-md hidden-lg" data-target="#block-nexteuropa-europa-search-nexteuropa-europa-search-form"></span>',
            buttonLanguage = '<span class="btn btn-mobile btn-mobile-language hidden-md hidden-lg" data-target="#block-cwt-core-translation-selector"></span>';
            $buttonContainer = $('.navbar-wrapper .container'),
            $animationContainer = $('.page-wrapper');

        // Hide blocks in branding region and append buttons
        $regionBranding.children().hide();
        $buttonContainer.append(buttonSearch + buttonLanguage);

        // Checking if block related to the button exists
        $buttonContainer.children('.btn').each(function() {
          if ($($(this).data('target')).length == 0) {
            $(this).hide();
          }
        });

        if (typeof enquire !== 'undefined') {
          enquire.register("screen and (min-width: 960px)", {
            match : function() {
              $regionBranding.children().show();
              $('h2.block-title', $regionBranding).hide();
              $buttonContainer.children().removeClass('active');
              $animationContainer.css('top', 0);
            },
            unmatch : function() {
              $regionBranding.children().hide();
              $('h2.block-title', $regionBranding).show();
            }
          }, true);
        }

        $buttonContainer.children('.btn').click(function() {
          if ($(this).hasClass('active')) {
            $(this).removeClass('active');

            // Scroll up
            $animationContainer.velocity('stop').velocity({top: 0, duration: 400}, {complete: function(elements) {
              $regionBranding.children().hide();
            }});
          } else {
            $(this).addClass('active');
            $(this).siblings().removeClass('active');
            $regionBranding.children().hide();

            // Get data-target of blocks from region-branding
            var $buttonTarget = $($(this).data('target'));
            $buttonTarget.show();

            // Scroll Down
            $animationContainer.velocity('stop').velocity({top: $regionBranding.outerHeight(), duration: 400});
          }
        });
      });
    }
  }

  Drupal.behaviors.commissioner_breadcrumbs = {
    attach: function(context) {
      $('#block-easy-breadcrumb-easy-breadcrumb').once('breadcrumbs', function(){

        // Putting breadcrumbs selectors in variables
        var marginOffset = 30,
            $breadcrumbWrapper = $('#block-easy-breadcrumb-easy-breadcrumb'),
            $breadcrumb = $breadcrumbWrapper.children('.breadcrumb'),

            // Check the width of breadcrumb blocks
            breadcrumbWidth = $breadcrumb.width() + marginOffset;

        // Width of all elements of second breadcrumb combined
        var breadcrumbWidthCombined = marginOffset;
        $breadcrumb.find('a').each(function(){
          breadcrumbWidthCombined += $(this).width();
        });

        var regionHeaderWidth = $('.region-header').width();

        function breadcrumbElementChecker() {
          // Compare region-header with breadcrumb block combined width
          if (breadcrumbWidthCombined >= regionHeaderWidth) {
            // Check the width of the last hidden element (elements cannot be hidden with display:none otherwise it is not possible to calculate it's width!!!)
            var lastElementWidth = $breadcrumb.find('a.element-hidden').last().width();

            if ((breadcrumbWidth + lastElementWidth) < regionHeaderWidth) {
              $breadcrumb.find('a.element-hidden').last().removeClass('element-hidden').addClass('breadcrumb-item-first')
              .parent().next().children().removeClass('breadcrumb-item-first');
            }

          // When region-header width is bigger than breadcrumb block than show the first breadcrumb block again
          } else {
            $breadcrumb.find('a:not(.element-hidden)').first().removeClass('breadcrumb-item-first');
            $breadcrumb.find('a.element-hidden').removeClass('element-hidden');
          }
        }

        function breadcrumbEachChecker() {
          $breadcrumb.find('a:not(.element-hidden)').each(function() {
            // Check if the breadcrumb block is bigger than region-header
            if (breadcrumbWidth >= regionHeaderWidth && $breadcrumb.find('a:not(.element-hidden)').length > 1) {
              $breadcrumb.find('a:not(.element-hidden)').first('element-hidden').removeClass('breadcrumb-item-first').addClass('element-hidden')
              .parent().next().children().addClass('breadcrumb-item-first');
            }
            breadcrumbWidth = $breadcrumb.width();
          });
        }

        breadcrumbEachChecker();

        // Check breadcrumbs elements on window resize
        $(window).resize(function() {
          regionHeaderWidth = $('.region-header').width();
          breadcrumbElementChecker();
          breadcrumbEachChecker();
        });
      });
    }
  }

  Drupal.behaviors.commissioner_contact = {
    attach: function(context) {
      $('#block-views-contact-block').once('biography-contact', function(){
        // Translate button strings
        var buttonStringShow = Drupal.t('Show contact details'),
            buttonStringHide = Drupal.t('Hide contact details');

        // Create button html
        var buttonHTML = '<button class="btn btn-contact-toggle collapsed" type="button" data-toggle="collapse" data-target="#block-views-contact-block"><span>'
                            +buttonStringShow+
                          '</span></button>';

        // Grab social media block id
        var $socialmediaBlock = $('#block-views-biography-social-networks-block');

        // Conditionally generate button html
        if($socialmediaBlock.length) {
          $socialmediaBlock.before(buttonHTML);
        } else {
          $('.region-content-top').append(buttonHTML);
        }

        var $buttonTextSelector = $('.btn-contact-toggle span');

        // Checking button width
        function buttonWidth() {
          var buttonHideWidth = $buttonTextSelector.parent().width(),
              buttonShowWidth = $buttonTextSelector.text(buttonStringShow).parent().width(),
              buttonBiggestWidth = Math.max(buttonShowWidth,buttonHideWidth);

          return buttonBiggestWidth;
        }

        if (typeof enquire !== 'undefined') {
          enquire.register("screen and (min-width: 480px)", {
            setup : function() {
                $buttonTextSelector.parent().css('width', '100%');
            },
            match : function() {
              $buttonTextSelector.parent().css('width', 'auto').queue(function() {
                buttonWidth();
                $(this).css('width', buttonWidth() + 'px').dequeue();
              });
            },
            unmatch : function() {
              $buttonTextSelector.parent().css('width', '100%');
            }
          });
        }

        // Change button string on show button click
        $(this).on('show.bs.collapse', function(){
          $buttonTextSelector.text(buttonStringHide);
        });

        // Change button string on hide button click
        $(this).on('hide.bs.collapse', function(){
          $buttonTextSelector.text(buttonStringShow);
        });
      });
    }
  }

  Drupal.behaviors.commissioner_pager = {
    attach: function(context) {
      var options = '';
      $('ul.pager').once('pager', function(){
        $('li.select', this).once('pagerselect', function(){
          var $link = $('a', this);
          if($link.length > 0) {
            var value = $link.attr('href');
            var title = $link.html();
            var selected = '';
          } else {
            var value = '';
            var title = Drupal.t('Page') + ' ' + $(this).html();
            var selected = 'selected="selected"';
          }
          options += '<option value="' + value + '"' + selected + '>' + title + '</option>';
          $(this).remove();
        });
        if(options != '') {
          var select = $('<span class="pager-dropdown-wrapper"><select class="pager-dropdown">' + options + '</select></span>');
          select.children().data('activation', 'activated').on({
            keydown: function(event) {
              if(event.which === 13){
                if($(this).data('activation') === 'paused'){
                  $(this).data('activation', 'activated');
                  $(this).trigger('change');
                }
              } else {
                $(this).data('activation', 'paused');
              }
            },
            click: function(event) {
              if($(this).data('activation') === 'paused'){
                $(this).data('activation', 'activated');
                $(this).trigger('change');
              }
            },
            change: function(event) {
              if($(this).data('activation') === 'activated'){
                selectNav(event);
              }
            }
          });
          $('li.pager-current-combo .pager-current-combo-current', this).after(select);
          $('li.pager-current-combo .pager-current-combo-current').hide();
        }
      });
    }
  }

  Drupal.behaviors.commissioner_comments = {
    attach: function(context) {
      $('#comments').once('comments', function(){
        $('#comment-form-wrapper', this).on('show.bs.collapse', function(){
          $(this).siblings('.btn-add-comment').hide();
        });
      });
    }
  }

  Drupal.behaviors.commissioner_feedback = {
    attach: function(context) {
      $('#cwt-feedback-form').once('feedback', function() {
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
          $('#footer').velocity("scroll", {easing:'ease', duration: 400});
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
          $('.region-footer-top-wrapper').toggleClass('region-open');
          $('#footer').velocity("scroll", {easing:'ease', duration: 350});
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

  Drupal.behaviors.translation_selector = {
    attach: function(context) {
      var options = '';
      $('.translation-list').once('translation_selector', function(){
        $('li a', this).once('translation_link', function() {
          var $link = $(this);
          var selected = $link.hasClass('active') ? ' selected="selected"' : '';
          options += '<option value="' + $link.attr('href') + '"' + selected + '>' + $link.html() + '</option>'
        });
        var select = $('<div class="form-select-wrapper"><select class="translation_select form-control form-select">' + options + '</select></div>');
        $(this).replaceWith(select);
        select.children().data('activation', 'activated').on({
          keydown: function(event) {
            if(event.which === 13){
              if($(this).data('activation') === 'paused'){
                $(this).data('activation', 'activated');
                $(this).trigger('change');
              }
            } else {
              $(this).data('activation', 'paused');
            }
          },
          click: function(event) {
            if($(this).data('activation') === 'paused'){
              $(this).data('activation', 'activated');
              $(this).trigger('change');
            }
          },
          change: function(event) {
            if($(this).data('activation') === 'activated'){
              selectNav(event);
            }
          }
        });
      });
    }
  }

  Drupal.behaviors.iframe_height_calculate = {
    attach: function(context) {
      $('.iframe').once('iframe', function(){
        // selecting the iframe element
        var currentIFrame = this;

        // selecting the iframe jQuery object
        var $currentIFrameElement = $(this);

        // Function that calculates height of an iframe content and set height
        // to iframe element
        function iFrameResize(iframe, iframeObject) {
          var iFrameHeight = iframe.contentWindow.document.body.offsetHeight +
                            'px';
          iframeObject.height(iFrameHeight);
        }

        // Changing iframe element height on iframe load
        $(this).load(function() {
          iFrameResize(currentIFrame, $currentIFrameElement);
        });

        // Changing iframe element height on window resize
        $(window).resize(function() {
          iFrameResize(currentIFrame, $currentIFrameElement);
        });
      });
    }
  }

  Drupal.behaviors.commissioner_filters = {
    attach: function(context) {
      // Saving .block-filters in variable as a generic element, so that
      // The script works for all filter blocks on current page
      var $blockFilters = $('.block-filters'),
          hideText      = Drupal.t('Hide'),
            refineText  = Drupal.t('Refine');

      // Hide filter button on ajax call
      if ($blockFilters.is(':visible')) {
        $('.filter-button', context).hide();
      }

      if ('.filter-button'.length > 0) {
        $('.view-header .result-count', context).after('<div class="filter-button">' +
                                      '<button class="btn btn-primary hidden-md hidden-lg" type="button" data-toggle="collapse" data-target="#block-views-exp-agenda-list" aria-expanded="false" aria-controls="collapseFilters">' +
                                        refineText +
                                      '</button>' +
                                    '</div>');
      }

      $blockFilters.once('filters', function(){
        $(this).addClass('collapse');
        $('.form-submit', this).removeClass('ctools-auto-submit-click');

        $blockFilters.on('show.bs.collapse', function(){
          $(this).prepend('<a class="close" data-toggle="collapse" data-target="#block-views-exp-agenda-list">'+hideText+'</a>');
          $('.filter-button').hide();
        });

        $blockFilters.on('hide.bs.collapse', function(){
          $(this).children('.close').remove();
          $('.filter-button').show();
        });

        if (typeof enquire !== 'undefined') {
          enquire.register('screen and (min-width: 960px)', {
            match : function() {
              $('.form-submit', $blockFilters).addClass('ctools-auto-submit-click js-hide');
              $blockFilters.removeAttr('style').removeClass('collapse in');
              $blockFilters.children('.close').remove();
            },
            unmatch : function() {
              $('.form-submit', $blockFilters).removeClass('ctools-auto-submit-click js-hide');
              $blockFilters.addClass('collapse');
              $('.filter-button').show();
            }
          });
        }
      });
    }
  }

  function selectNav(event) {
    var href = $(event.target).val();
    if(href !== window.location.href) {
      window.location.href = href;
    }
  }


  // @see https://www.drupal.org/node/1232416#comment-8499615
  Drupal.ajax.prototype.original_error = Drupal.ajax.prototype.error;
  Drupal.ajax.prototype.error = function (response, uri) {
    if(response.readyState == 0){
      alert('Your internet connection was lost.');
    }
    //Add more conditionals for the other readyStates if you want...I think 4 is the "terminated abnormally" that everyone is complaining about
    //comment the next line out if you want to ignore Drupal's default ajax error method altogether
    //this.original_error(response, uri);
  }

})(jQuery);
