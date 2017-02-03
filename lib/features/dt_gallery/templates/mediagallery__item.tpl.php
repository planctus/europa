<?php

/**
 * @file
 * The template file for media gallery item.
 *
 * @todo: The links are disable as the full implementation is not yet complete.
 *  Normally we would revert the commit but as this is a big one that would not
 *  be without concequenses.
 */
?>
<?php if ($image): ?>
  <div class="mediagallery__item col-sm-<?php print $size; ?> col-md-<?php print $size; ?><?php print $hasicon; ?>">
    <div class="mediagallery__item_container">
      <!--<a href="<?php print $gallery_link; ?>">-->
      <?php print $image; ?>
      <?php if ($caption): ?>
        <span class="mediagallery__caption"><?php print $caption; ?></span>
      <?php endif; ?>
      <?php if ($type): ?>
        <span class="mediagallery__icon">
          <span class="icon <?php print $type; ?>"></span>
        </span>
      <?php endif; ?>
      <!--</a>-->
    </div>
  </div>
<?php endif; ?>
