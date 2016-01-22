/**
 * @file
 * Javascript helper for [break] solution.
 */

jQuery(function ($) {
  // Find only the description fields which contain '[break]' text.
  $('.description:contains("[break]")').each(function(index, value) {

    // Split the string in 2.
    var help_parts = $(value).text().split('[break]'),
        more_button = Drupal.t('more information'),
        less_button = Drupal.t('less information'),
        new_markup = '';

    // If we were able to split, and have 2 parts, we apply some extra html. This should actually always be the case.
    // Here we also parse the markup to html.
    if (help_parts.length == 2) {
      new_markup = marked(help_parts[0]);
      new_markup += '<a href="" class="expand">' + more_button + '</a><span class="help-text-hidden" style="display: none;">' + marked(help_parts[1]) + '</span>';
      $(value).html(new_markup);
    }

    $(value).on('click', 'a.expand', function(event){
      event.preventDefault();
      if ($(this).hasClass('open')) {
        $(this).removeClass('open').html(more_button);
      }
      else {
        $(this).addClass('open').html(less_button);
      }
      // Toggle the content.
      $(this).next('.help-text-hidden').toggle();
    });
  });

  // In case we dont have a break, we should stil replace the markup type content.
  $('.description:not(:contains("[break]"))').each(function(index, value) {
    $(value).html(
      marked($(value).html())
    );
  });
});
