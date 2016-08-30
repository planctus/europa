<?php

/**
 * @file
 * Contains the markup for the feedback main list.
 */
?>
<?php if ($title): ?>
  <h2 id="<?php print drupal_clean_css_identifier($title); ?>"><?php print $title; ?></h2>
<?php endif; ?>
<?php if ($nr_results): ?>
  <h4><?php print $nr_results; ?></h4>
<?php endif; ?>
<?php if ($feedback_list): ?>
  <div class="section__group">
    <div class="listing__wrapper">
      <div class="listing">
        <?php print $feedback_list; ?>
      </div>
    </div>
  </div>
<?php endif; ?>
<?php if ($button): ?>
  <?php print $button; ?>
<?php endif; ?>
