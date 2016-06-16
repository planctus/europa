<?php
/**
 * @file
 * Contains the markup for the message block.
 */
?>
<?php if (!empty($message_title)) : ?>
  <div class="messages<?php print $message_classes . (!empty($message_type) ? ' ' . $message_type : ''); ?>">
    <h3><?php if (!empty($message_type)) : ?><span class="sr-only"><?php print $message_type; ?> message: </span><?php endif; ?><?php print $message_title; ?></h3>
    <?php if (!empty($message_body)) : ?>
      <p><?php print $message_body; ?></p>
    <?php endif; ?>
  </div>
<?php endif; ?>
