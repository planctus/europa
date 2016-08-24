<?php

/**
 * @file
 * Contains the markup for the date-block component.
 */
?>
<div class="date-block<?php print $modifier_classes; ?>">
  <?php if ($show_days_name && !empty($date_days_name)) : ?>
    <span class="date-block__day-text"><?php print $date_days_name; ?></span>
  <?php endif; ?>
  <span class="date-block__day"><?php print $date_days; ?></span>
  <span class="date-block__month"><?php print $date_months; ?></span>
  <?php if ($show_years && !empty($date_years)) : ?>
    <span class="date-block__year"><?php print $date_years; ?></span>
  <?php endif; ?>
</div>
