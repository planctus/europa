<?php

/**
 * @file
 * Display Suite NE Bootstrap One Column Section Item.
 */
?>

<div class="listing listing--navigation">
  <a href="<?php print $node_url; ?>" class="listing__item-link">
    <h2 class="listing__section-title"><?php print $title; ?></h2>
    <?php if ($description && !$children): ?>
      <p class="listing__description"><?php print $description; ?></p>
    <?php endif; ?>
  </a>
  <?php if ($children): ?>
    <?php print $children; ?>
  <?php endif; ?>
  <?php if (($children || $description) && $links): ?>
    <hr class="listing__separator">
  <?php endif; ?>
  <?php if ($links): ?>
    <?php print $links; ?>
  <?php endif; ?>
</div>
