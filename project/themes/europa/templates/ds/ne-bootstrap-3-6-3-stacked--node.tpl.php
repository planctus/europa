<?php
/**
 * @file
 * Display Suite NE Bootstrap Three Columns Stacked.
 */

  // Add sidebar classes so that we can apply the correct width in css.
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <!-- Page Header -->
  <div class="page-header">
    <div class="container-fluid">
      <<?php print $left_header_wrapper; ?> class="col-sm-9 <?php print $left_header_classes; ?>">
        <?php print $left_header; ?>
      </<?php print $left_header_wrapper; ?>>

      <?php if(!empty($right_header)): ?>
        <<?php print $right_header_wrapper; ?> class="col-sm-3 <?php print $right_header_classes; ?>">
          <?php print $right_header; ?>
        </<?php print $right_header_wrapper; ?>>
      <?php endif; ?>
    </div>
  </div>
  <div class="container-fluid">
    <div class="row">
      <?php if (!empty($messages)): ?>
        <?php print $messages; ?>
      <?php endif; ?>

      <a id="main-content" tabindex="-1"></a>
      <<?php print $left_wrapper; ?> class="col-sm-3 <?php print $left_classes; ?>">
        <?php print $left; ?>
      </<?php print $left_wrapper; ?>>
      <section class="col-sm-6 <?php print $central_classes; ?>">
        <?php print $central; ?>
      </section>
      <<?php print $right_wrapper; ?> class="col-sm-3 <?php print $right_classes; ?>">
        <?php print $right; ?>
      </<?php print $right_wrapper; ?>>
    </div>
  </div>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>