<?php

/**
 * @file
 * The template file for media gallery item.
 */
?>
<?php if ($image): ?>
  <div class="mediagallery__item col-sm-<?php print $size; ?> col-md-<?php print $size; ?>">
    <div class="mediagallery__item_container">
      <?php print $image; ?>

      <?php if ($caption): ?>
        <span class="mediagallery__caption"><?php print $caption; ?></span>
      <?php endif; ?>
      <?php if ($type): ?>
        <span class="icon <?php print $type; ?>"></span>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>