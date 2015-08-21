<?php
/**
 * @file
 * View template to display a news carousel.
 *
 * @ingroup views_templates
 */
?>
<div class="listing__wrapper<?php print $listing_columns . $listing_wrapper_modifier; ?>">
  <div class="listing<?php print $ds_view_mode . $listing_modifier; ?>">
    <?php foreach ($columns as $column): ?>
      <div class="column">
      <?php foreach ($column as $id => $row): ?>
        <div class="listing__item">
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
