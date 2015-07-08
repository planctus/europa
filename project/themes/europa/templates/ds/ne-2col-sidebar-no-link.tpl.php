<?php
/**
 * @file
 * Display Suite NE Bootstrap Two Columns Stacked.
 */

  // Add sidebar classes so that we can apply the correct width in css.
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <?php if (!empty($second)): ?>
  <<?php print $main_wrapper; ?> class="listing__column-main listing__column-main--sidebar-next column-main <?php print $main_classes; ?>">
    <a href="<?php print $node_url; ?>" class="listing__item-link">
      <?php print $main; ?>
    </a>
  </<?php print $main_wrapper; ?>>

  <<?php print $second_wrapper; ?> class="listing__column-second listing__column-second--no-link column-second <?php print $second_classes; ?>">
    <?php print $second; ?>
  </<?php print $second_wrapper; ?>>

  <?php else: ?>
    <<?php print $main_wrapper; ?> class="listing__column-main column-main <?php print $main_classes; ?>">
      <a href="<?php print $node_url; ?>" class="listing__item-link">
        <?php print $main; ?>
      </a>
    </<?php print $main_wrapper; ?>>
  <?php endif; ?>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
