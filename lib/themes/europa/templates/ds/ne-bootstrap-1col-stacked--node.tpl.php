<?php

/**
 * @file
 * Display Suite NE Bootstrap One Column Stacked.
 */
?>

<<?php print $layout_wrapper . $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <!-- Page Header -->
  <div class="page-header<?php print isset($header_back) ? ' page-header--image' : ''; ?>">
    <nav class="page-navigation" role="navigation">
      <div class="container-fluid">
        <?php print render($header_bottom); ?>
      </div>
    </nav>
    <?php if (!empty($left_header)) : ?>
      <div class="container-fluid page-header__hero-title">
        <div class="row padding-reset">
          <<?php print $left_header_wrapper; ?> class="col-lg-9 <?php print $left_header_classes; ?>">
            <?php print $left_header; ?>
          </<?php print $left_header_wrapper; ?>>
          <?php if (!empty($right_header)) : ?>
            <<?php print $right_header_wrapper; ?> class="col-lg-3 <?php print $right_header_classes; ?>">
              <?php print $right_header; ?>
            </<?php print $right_header_wrapper; ?>>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>

  <?php if (isset($utility) && !empty($utility)): ?>
    <div class="utility">
      <div class="container-fluid">
        <?php print render($utility); ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="page-content">
    <div class="container-fluid">
      <div class="row<?php print isset($ceiling) ? ' ' . $ceiling : ''; ?>">
        <?php if (!empty($top) || !empty($local_tabs) || !empty($messages)) : ?>
          <div class="row">
            <section class="section section--content-top col-md-12 <?php print $top_classes; ?>">
              <?php print $top; ?>
              <?php if (!empty($local_tabs)) : ?>
                <?php print $local_tabs; ?>
              <?php endif; ?>
              <?php if (!empty($messages)) : ?>
                <?php print $messages; ?>
              <?php endif; ?>
            </section>
          </div>
        <?php endif; ?>
        <a id="main-content" tabindex="-1"></a>
        <section class="section col-md-12 <?php print $central_classes; ?>">
          <?php print $central; ?>
        </section>
      </div>
    </div>
  </div>
</<?php print $layout_wrapper; ?>>

<?php if (!empty($drupal_render_children)) : ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
