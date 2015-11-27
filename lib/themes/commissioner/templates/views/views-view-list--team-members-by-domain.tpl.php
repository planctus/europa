<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * Variables:
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 *
 * @ingroup views_templates
 */

?>
<?php
  $formatted_title = drupal_html_id(strip_tags($title));
?>

<?php print $wrapper_prefix; ?>
  <div id="members-toggle">
    <?php if (!empty($title)) : ?>
      <div class="members-grouping">
        <a href="#<?php print $formatted_title; ?>" class="collapsed" data-toggle="collapse">
          <h3>
            <?php print $title; ?>
          </h3>
        </a>
      </div>
    <?php endif; ?>
    <div id="<?php print $formatted_title; ?>" class="members-listing-wrapper collapse">
      <ul class="members-listing">
        <?php foreach ($rows as $id => $row): ?>
          <li class="<?php print strtolower($classes_array[$id]); ?>"><?php print $row; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
<?php print $wrapper_suffix; ?>
