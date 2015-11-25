<?php
/**
 * @file
 * Define the display of a custom view mode.
 */
?>

<div class="listing__item--2blocks__top">
  <?php print render($content['field_biography_portrait']); ?>
  <?php print render($content['field_biography_tagline']); ?>
  <?php print $title_prefix; ?>
    <?php print $title; ?>
  <?php print $title_suffix; ?>
  <?php print render($content['field_biography_email']); ?>
  <?php print render($content['field_biography_phone']) ?>
  <?php print render($content['field_social_networks']); ?>
</div>
<div class="listing__item--2blocks__bottom">
  <?php print render($content['body']); ?>
</div>
