/**
 * @file
 * Javascript helper for [break] solution.
 */

jQuery(function ($) {
  // Find only the description fields which contain '[break]' text.
  $('.description:contains("[break]")').each(function(index, value) {

    // Split the string in 2.
    var help_parts = $(value).text().split('[break]'),
        newmarkup = '';

    // If we were able to split, and have 2 parts, we apply some extra html. This should actually always be the case.
    // Here we also parse the markup to html.
    if (help_parts.length == 2) {
      newmarkup = marked(help_parts[0]);
      newmarkup += '<a href="#" class="expand">' + Drupal.t('more') + '</a><span class="help-text-hidden">' + marked(help_parts[1]) + '</span>';
      $(value).html(newmarkup);
    }

    // Find, hide, and bind a click listener on 'a' tag.
    $(value)
      .find('.help-text-hidden')
      .hide();

    $(this).on('a.expand', 'click', function(event){
      event.preventDefault();
      $(this).next('.help-text-hidden').fadeIn('fast');
    });
  });

  // In case we dont have a break, we should stil replace the markup type content.
  $('.description:not(:contains("[break]"))').each(function(index, value) {
    $(value).html(
      marked($(value).html())
    );
  });
});
