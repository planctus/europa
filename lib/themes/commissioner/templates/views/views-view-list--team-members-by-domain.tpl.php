<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */

?>
<?php
  $formattedTitle = drupal_html_id(strip_tags($title));
?>

<?php print $wrapper_prefix; ?>
  <div class="expandable__group">
    <?php if (!empty($title)) : ?>
      <a href="#<?php print $formattedTitle; ?>" class="collapsed expandable__toggle" data-toggle="collapse">
        <h3>
          <?php print $title; ?>
        </h3>
      </a>
    <?php endif; ?>
    <div id="<?php print $formattedTitle; ?>" class="expandable__content collapse">
      <div class="listing listing--person listing--column-left listing--nostripe">
        <?php foreach ($rows as $id => $row): ?>
          <div class="listing__item <?php print strtolower($classes_array[$id]); ?>"><?php print $row; ?></div>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
<?php print $wrapper_suffix; ?>
