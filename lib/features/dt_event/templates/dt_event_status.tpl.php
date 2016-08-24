<?php

/**
 * @file
 * Contains the markup for the status message.
 */
?>
<div class="<?php print $message_classes; ?>">

  <?php if ($message_title): ?>
    <strong><?php print ($message_type ? '<span class="sr-only">' . $message_type . ': </span>' : '') . $message_title; ?></strong>
  <?php else: ?>
    <?php print ($message_type ? '<span class="sr-only">' . $message_type . ': </span>' : ''); ?>
  <?php endif; ?>

  <?php if ($message_body): ?>
    <?php print $message_body; ?>
  <?php endif; ?>

</div>
