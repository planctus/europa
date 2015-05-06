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
      <div class="row padding-reset">
        <<?php print $left_header_wrapper; ?> class="col-lg-9 <?php print $left_header_classes; ?>">
          <?php print $left_header; ?>
        </<?php print $left_header_wrapper; ?>>

        <?php if(!empty($right_header)): ?>
          <<?php print $right_header_wrapper; ?> class="col-lg-3 <?php print $right_header_classes; ?>">
            <?php print $right_header; ?>
          </<?php print $right_header_wrapper; ?>>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <div class="container-fluid">
    <div class="row">
      <section class="col-lg-12 <?php print $top_classes; ?>">
        <?php print $top; ?>

        <?php if (!empty($messages)): ?>
          <?php print $messages; ?>
        <?php endif; ?>
      </section>

      <a id="main-content" tabindex="-1"></a>
      <section class="col-lg-9 <?php print $central_classes; ?>">
        <?php print $central; ?>
      </section>
    </div>
  </div>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
