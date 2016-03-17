<?php
/**
 * @file
 * Contains the basic markup for the latest block.
 */
?>
<div class="section__group">
  <?php if ($heading): ?>
    <h2 id="<?php echo drupal_clean_css_identifier($heading); ?>"><?php echo $heading; ?></h2>
  <?php endif; ?>
  <?php if ($news_items): ?>
    <div class="sidebar-field-group__main">
      <?php echo $news_items; ?>
    </div>
  <?php endif; ?>
  <?php if ($social_links): ?>
    <div class="sidebar-field-group__sidebar">
      <?php echo $social_links; ?>
    </div>
  <?php endif; ?>
</div>
