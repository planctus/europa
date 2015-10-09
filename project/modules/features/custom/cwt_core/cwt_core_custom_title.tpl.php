<?php

/**
 * @file
 * Template file for Custom page title blocks.
 *
 * Available variables:
 * - $line_1: the (sanitized) title of the highlight.
 * - $line_2: a render array representing the highlight image.
 * - $line_3: optional render array representing the subheader.
 *
 * @see template_preprocess_cwt_core_custom_title()
 *
 * @ingroup themeable
 */
?>
<div class="page-header-wrapper">
<?php if (!empty($line_1)): ?>
  <span class="header-line-1"><?php print render($line_1); ?></span>
<?php endif; ?>
  <h1 class="page-header">
  <?php if (!empty($line_2)): ?>
    <span class="header-line-2"><?php print render($line_2); ?></span>
  <?php endif; ?>
  <?php if (!empty($line_3)): ?>
    <span class="header-line-3"><?php print render($line_3); ?></span>
  <?php endif; ?>
  </h1>
</div>
