/**
 * @file
 * Javascript helper for [break] solution.
 */

jQuery(function ($) {
  // Find only the description fields which contain '[break]' text.
  $('.description:contains("[break]")').each(function(index, value) {

    // Split the string in 2.
    var helpParts = $(value).text().split('[break]'),
        moreButton = Drupal.t('more information'),
        lessButton = Drupal.t('less information'),
        newMarkup = '';

    // If we were able to split, and have 2 parts, we apply some extra html. This should actually always be the case.
    // Here we also parse the markup to html.
    if (helpParts.length == 2) {
      newMarkup= marked(helpParts[0]);
      newMarkup += '<a href="" class="expand">' + moreButton + '</a><span class="help-text-hidden" style="display: none;">' + marked(helpParts[1]) + '</span>';
      $(value).html(newMarkup);
    }

    $(value).on('click', 'a.expand', function(event) {
      event.preventDefault();
      var $element = $(this);
      if (($element).hasClass('open')) {
        $element.removeClass('open').html(moreButton);
      }
      else {
        $element.addClass('open').html(lessButton);
      }
      // Toggle the content.
      $element.next('.help-text-hidden').toggle();
    });
  });

  // In case we don't have a break, we should still replace the markup type content.
  $('.description:not(:contains("[break]"))').each(function(index, value) {
    $(value).html(
      marked($(value).html())
    );
  });
});
