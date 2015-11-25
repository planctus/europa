jQuery(function ($) {
  // Find only the description fields which contain '[break]' text.
  $('.description:contains("[break]")').each(function(index, value){
    // [break] text replacement.
    var replace_text = $(value).text().replace('[break]', '<a href="#">' + Drupal.t('more') + '</a><span class="help-text-hidden">') + '</span>';
    // Replace the description field html with the new value.
    $(value).html(replace_text);
    // Find, hide, and bind a click listener on 'a' tag.
    $(value)
      .find('.help-text-hidden')
      .hide()
      .prev('a')
      .bind('click', function(){
        // Hide the 'a' tag, and show the hidden text.
        $(this).hide().next('.help-text-hidden').show();
        return false;
      });
  });
});
