<?php

/**
 * @file
 * Contains the basic markup for the latest block.
 */
?>
<div class="section__group">
  <?php if ($heading): ?>
    <h2 id="<?php echo $heading_id; ?>"><?php echo $heading; ?></h2>
  <?php endif; ?>
  <?php if ($news_items || $featued_item): ?>
    <div class="sidebar-field-group__main">
      <?php if ($featued_item): ?>
        <?php echo $featued_item; ?>
      <?php endif; ?>
      <?php echo $news_items; ?>
    </div>
  <?php endif; ?>
  <?php if ($social_links): ?>
    <div class="sidebar-field-group__sidebar">
      <?php echo $social_links; ?>
    </div>
  <?php endif; ?>
</div>
