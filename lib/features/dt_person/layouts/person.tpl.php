<?php

/**
 * @file
 * Display suite layout for the person content type full view mode.
 */
$header_back = isset($header_back) ? ' page-header--image' : '';
?>

<div class="page-header<?php print $header_back ?>">
  <nav class="page-navigation" role="navigation">
    <div class="container-fluid">
      <?php print render($header_bottom); ?>
    </div>
  </nav>
  <div class="container-fluid page-header__hero-title">
    <div class="row padding-reset">
      <div class="col-lg-9 <?php print $left_header_classes; ?>">
        <?php print $left_header; ?>
      </div>
    </div>
  </div>
</div>

<div class="profile_topbar section">

  <div class="container section__group">
    <div class="row">
      <?php if ($biography_image): ?>
        <div class="col-md-2 profile_topbar__picture">
          <?php print $biography_image; ?>
        </div>
      <?php endif; ?>

      <?php if ($biography_column): ?>
        <div class="col-md-10 profile_topbar__column">
          <?php print $biography_column; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

  <?php if ($top): ?>
    <div id="profiletopbar" class="profile_topbar__expander section__group collapse">
      <div class="container">
        <?php print $top; ?>
      </div>
    </div>
  <?php endif; ?>
</div>


<div class="page-content section">
  <div class="container-fluid">
    <?php if (!empty($local_tabs) || !empty($messages)) : ?>
      <div class="row section__group">
        <section class="col-md-12 <?php print $top_classes; ?>">
          <?php if (!empty($local_tabs)) : ?>
            <?php print $local_tabs; ?>
          <?php endif; ?>
          <?php if (!empty($messages)) : ?>
            <?php print $messages; ?>
          <?php endif; ?>
        </section>
      </div>
    <?php endif; ?>
    <div class="row section__group">
      <a id="main-content" tabindex="-1"></a>
      <div class="col-md-3">
        <?php print $left; ?>
      </div>
      <section class="col-md-9">
        <?php print $central; ?>
      </section>
    </div>
  </div>
</div>

<?php if (!empty($drupal_render_children)) : ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
