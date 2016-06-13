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
<div class="page-header-wrapper page-header--specialtitle">
  <?php if (!empty($line_1)): ?>
    <div class="meta meta--header">
      <div class="meta__item meta__item--type"><?php print render($line_1); ?></div>
    </div>
  <?php endif; ?>
  <?php if (!empty($line_2)): ?>
    <h1><?php print render($line_2); ?></h1>
  <?php endif; ?>
  <?php if (!empty($line_3)): ?>
    <p><?php print render($line_3); ?></p>
  <?php endif; ?>
</div>
