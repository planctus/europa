<?php

/**
 * @file
 * Default implementation of the splash page content.
 *
 * Available variables:
 * - $close_button: unformatted close button.
 * - $languages_list: the language list.
 * - $languages_list_array: unformated array of languages.
 * - $languages_blacklist: unformated array of blacklisted language codes.
 *
 * @see template_preprocess()
 * @see template_preprocess_splash()
 * @see template_process()
 */
?>
<nav class="splash-page__container">
  <h2><span class="icon icon--language"></span> <?php print $header_text; ?></h2>

  <?php print $languages_list; ?>
  <?php print $close_button; ?>
</nav>
