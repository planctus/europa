<?php

/**
 * @file
 * Contains the markup for the feedback list items.
 */
?>
<?php if ($link): ?>
  <div class="listing__item listing__item--fullwidth">
    <a href="<?php print $link; ?>" class="listing__item-link">
      <div class="meta">
        <span class="meta__item"><?php print $created_date; ?></span>
        <?php if ($user_type): ?>
          <span class="meta__item"><?php print $user_type; ?></span>
        <?php endif; ?>
      </div>

      <?php if ($title): ?>
        <h3 class="listing__title"><?php print $title; ?></h3>
      <?php endif; ?>
      <?php if ($feedback): ?>
        <p<?php if ($feedback_language): print ' lang="' . $feedback_language . '"'; ?>
       <?php endif; ?>>
          <?php print $feedback; ?>
        </p>
      <?php endif; ?>
    </a>
  </div>
<?php endif; ?>
