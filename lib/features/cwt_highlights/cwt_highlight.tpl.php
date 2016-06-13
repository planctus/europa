<?php

/**
 * @file
 * Template file for a Highlight for the Commissioner's site.
 *
 * Available variables:
 * - $title: the (sanitized) title of the highlight.
 * - $image: a render array representing the highlight image.
 * - $subheader: optional render array representing the subheader.
 * - $abstract: optional (sanitized) abstract text.
 * - $additional_links: optional render array containing a list of links.
 *
 * @see template_preprocess_cwt_highlight()
 *
 * @ingroup themeable
 */
?>
<div class="highlights-list-item<?php print $item_classes; ?>">
  <h3 class="highlights-list-title"><?php print $title; ?></h3>
  <div class="highlights-list-image">
    <?php print render($image); ?>
  </div>
  <div class="highlights-list-text-wrapper">
    <?php if (!empty($subheader)): ?>
      <h4><?php print render($subheader); ?></h4>
    <?php endif; ?>
    <?php if (!empty($abstract)): ?>
      <div class="highlights-list-abstract"><?php print $abstract; ?></div>
    <?php endif; ?>
    <?php if (!empty($additional_links)): ?>
      <?php print render($additional_links); ?>
    <?php endif; ?>
  </div>
</div>
