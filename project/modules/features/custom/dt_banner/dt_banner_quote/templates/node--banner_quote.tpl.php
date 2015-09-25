<?php
/**
 * @file
 * This is the rendering of our banner_quote content type.
 *
 * Available variables:
 * - $content: this contains all of the elements available from the Drupal ui.
 */

?>
<div class="<?php print $classes; ?> banner_quote" <?php print $attributes; ?>>
  <div class="banner_quote__quote">
    <blockquote class="blockquote blockquote--small">
      <?php print render($content['field_core_description']); ?>
    </blockquote>
  </div>
  <div class="banner_quote__author">
    <?php print render($content['field_banner_author']); ?>
  </div>
</div>
