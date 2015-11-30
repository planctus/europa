<?php

/**
 * @file
 * Basic template file.
 */

?>

<?php if (isset($exposed_filters)): ?>
  <div class="filters__active-facets">
    <?php foreach ($exposed_filters as $filter => $value): ?>
      <?php if ($value): ?>
        <div class="facet-tag filters__facet-tag">
          <span class="facet-tag__label filters__active-facet-label"><?php print $filter; ?></span>
          <?php if (is_array($value)): ?>
            <span class="facet-tag__value filters__active-facet-value"><?php print implode(', ', $value); ?></span>
          <?php else: ?>
          <span class="facet-tag__value filters__active-facet-value"><?php print $value; ?></span>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
