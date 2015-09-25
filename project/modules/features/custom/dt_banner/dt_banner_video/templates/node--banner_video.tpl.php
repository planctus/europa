<?php
/**
 * @file
 * This is the rendering of our banner_quote content type.
 *
 * Available variables:
 * - $content: this contains all of the elements available from the Drupal ui.
 */

?>
<div class="<?php print $classes; ?> banner_video row" <?php print $attributes; ?>>
  <div class="col-md-6">
    <div class="banner_video__video">
      <?php print render($content['field_banner_video_file']); ?>
    </div>
    <div class="banner_video__caption">
      <?php print render($content['field_banner_caption']); ?>
    </div>
  </div>
  <div class="col-md-6">
    <div class="banner_video__paragraph">
      <?php print render($content['field_core_description']); ?>
    </div>
  </div>
</div>
