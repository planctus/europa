<?php

/**
 * @file
 * Contains the markup for the feedback fields.
 */
?>
<?php if ($value): ?>
  <div class="context-nav">
    <?php if ($label): ?>
      <span class="context-nav__label">
        <strong><?php print $label; ?></strong>
      </span>
    <?php endif; ?>
    <div class="context-nav__items">
      <span class="context-nav__item"><?php print $value; ?></span>
    </div>
  </div>
<?php endif; ?>
