<?php

/**
 * @file
 * Contains the markup for the attachments items.
 */
?>
<li class="file__translations-item">
  <div class="file file--document file--bare">
    <span class="file__icon icon icon--file"></span>
    <div class="file__metadata">
      <span class="file__title"><?php print $file_lang; ?> version</span>
      <div class="file__info">
        <span class="file__size"><?php print $file_size; ?></span> - <?php print $file_type; ?>
      </div>
    </div>
    <a href="<?php print $attachments; ?>" class="file__btn btn is-internal">
      Download<span class="sr-only"><?php print $file_type; ?> - <?php print $file_size; ?></span>
    </a>
  </div>
</li>
