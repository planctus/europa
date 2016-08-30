<?php

/**
 * @file
 * Contains the markup for the feedback fields.
 */
?>
<?php if ($main_title): ?>
<div class="field field--title">
  <div class="field__items">
    <h1><?php print $main_title; ?><?php if ($subtitle): ?><span><?php print $subtitle; ?></span><?php
   endif; ?></h1>
  </div>
</div>
<?php endif; ?>
