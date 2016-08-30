<?php

/**
 * @file
 * Contains the markup for the feedback block.
 */
?>
<div class="paragraph">
  <div class="file">
    <span class="file__icon icon icon--file"></span>

    <div class="file__metadata">
      <?php if ($file_title): ?>
        <span class="file__title">
        <?php echo $file_title; ?>
      </span>
      <?php endif; ?>
      <div class="file__info">
        <?php if ($file_lang): ?>
          <span class="file__contentlanguage"><?php echo $file_lang; ?></span>
        <?php endif; ?>
        <?php if ($attachment_type): ?>
          <?php echo $attachment_type; ?>
        <?php endif; ?>
        <?php if ($file_size): ?>
          <?php echo $file_size; ?>
        <?php endif; ?>
        <?php if ($file_type): ?>
          <?php echo $file_type; ?>
        <?php endif; ?>
        <?php if ($file_pages): ?>
          <?php echo $file_pages; ?>
        <?php endif; ?>
      </div>
    </div>
    <a class="file__btn btn btn-default" href="<?php echo $attachments; ?>">
      <?php echo $button_title; ?>
      <span class="sr-only"><?php echo $file_type; ?>
        - <?php echo $file_size; ?></span>
    </a>
  </div>
</div>
