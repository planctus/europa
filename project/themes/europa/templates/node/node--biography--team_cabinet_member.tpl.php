<?php
/**
 * @file
 * Define the display of a custom view mode.
 */
?>

<div class="listing--cabinet">
  <div class="listing--cabinet__top-wrapper">
    <?php print render($content['field_biography_portrait']); ?>
    <?php print render($content['field_biography_tagline']); ?>
    <!-- We should use title module in order to use formatters here -->
    <h4 class="listing--cabinet__name field">
      <?php print l($title, 'node/' . $node->nid); ?>
    </h4>
    <?php print render($content['field_biography_email']); ?>
    <?php print render($content['field_biography_phone']) ?>
    <?php print render($content['field_social_networks']); ?>
  </div>

  <div class="field listing--cabinet__bottom-wrapper">
    <?php print render($content['body']); ?>
  </div>
</div>