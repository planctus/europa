<?php

/**
 * @file
 * Contains the markup for when user anonymously access feedback form.
 */
?>
<?php if ($title_text): ?>
  <h2><?php print $title_text; ?></h2>
<?php endif; ?>
<?php if ($account_text): ?>
  <p><strong><?php print $account_text; ?></strong><?php if ($register_text): ?><br/><?php print $register_text; ?><?php
 endif; ?></p>
<?php endif; ?>
<div class="btn-group">
  <?php print $button_login; ?>
  <?php print $button_register; ?>
</div>
