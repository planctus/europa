<?php

/**
 * @file
 * Contains the markup for the feedback block.
 */
?>
<?php if ($title): ?>
<h2 id="<?php echo drupal_clean_css_identifier($title); ?>"><?php echo $title; ?>
<?php endif; ?>
  <div class="field-group">
    <?php if ($status_label): ?>
      <?php echo $status_label; ?>
    <?php endif; ?>
  </div>
  <h3><?php echo $intro; ?></h3>
  <?php if ($message): ?>
    <p><?php echo $message; ?></p>
  <?php endif; ?>
  <?php if ($button): ?>
    <?php echo $button; ?>
  <?php endif; ?>
