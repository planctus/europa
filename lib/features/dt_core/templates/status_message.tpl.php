<?php
/**
 * @file
 * Contains the markup for the message block.
 */
?>
<div class="messages<?php echo $message_classes; ?>">
  <?php if($message_title): ?>
    <h3><?php echo $message_title; ?></h3>
  <?php endif; ?>
  <?php if($message_body): ?>
    <ul>
      <li><?php echo $message_body; ?></li>
    </ul>
  <?php endif; ?>
</div>
