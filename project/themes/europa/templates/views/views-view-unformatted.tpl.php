<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php if ($active_filters): ?>
  <div class="view-header">
    <?php print $active_filters; ?>
  </div>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_array[$id] . ' ' . $additional_classes_array; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
