<?php

/**
 * @file
 * Contains the markup for the feedback block.
 */
?>
<div class="paragraph">
  <div class="file">
    <span class="icon icon--file file__icon"></span>

    <div class="file__metadata">
      <?php if ($file_title): ?>
        <span class="file__title"><?php print $file_title; ?></span>
      <?php endif; ?>
      <div class="file__info">
        <?php if ($file_lang): ?>
          <span class="file__content-language"><?php print $file_lang; ?></span>
        <?php endif; ?>
        <?php if ($attachment_type): ?>
          <?php print $attachment_type; ?>
        <?php endif; ?>
        <?php if ($file_size): ?>
          <?php print $file_size; ?>
        <?php endif; ?>
        <?php if ($file_type): ?>
          <?php print $file_type; ?>
        <?php endif; ?>
        <?php if ($file_pages): ?>
          <?php print $file_pages; ?>
        <?php endif; ?>
      </div>
    </div>
    <a class="btn btn-default file__btn" href="<?php print $attachments; ?>">
      <?php echo $button_title; ?>
      <span class="sr-only"><?php print $file_type; ?> - <?php print $file_size; ?></span>
    </a>
  </div>
</div>
