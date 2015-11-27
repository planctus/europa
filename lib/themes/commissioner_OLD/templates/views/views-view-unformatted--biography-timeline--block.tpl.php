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
<?php 
	$i = 0;
?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
  	<span class="timeline-icon"></span>
  	<div class="views-row-inner">
	    <?php 
	    	print $row;
	    	$i++;
	    ?>
	  </div>
  </div>
<?php endforeach; ?>

<?php if ($i > 5) : ?>
	<button type="button" class="btn btn-show-more"><span><?php print t('Show timeline'); ?></span></button>
<?php endif; ?>
