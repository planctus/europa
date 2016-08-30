<?php

/**
 * @file
 * Contains the markup for the feedback text.
 */
?>
<?php if ($feedback): ?>
  <?php if ($feedback_language): ?>
    <p lang="<?php print $feedback_language; ?>"><?php print $feedback; ?></p>
  <?php else: ?>
    <p><?php print $feedback; ?></p>
  <?php endif; ?>
<?php endif; ?>

<?php if ($rejected): ?>
  <div class="messages warning">
    <h3>Removed</h3>
    <ul>
      <li><?php print $rejected; ?></li>
    </ul>
  </div>
<?php endif; ?>

<section class="section col-md-12 ">
  <?php if ($report_link): ?>
    <div class="row section">
      <?php print $report_link; ?>
    </div>
  <?php endif; ?>
  <?php if ($button_back): ?>
    <div class="row">
      <?php print $button_back; ?>
    </div>
  <?php endif; ?>
</section>

<?php if ($legal_disclaimer): ?>
  <p><?php print $legal_disclaimer; ?></p>
<?php endif; ?>
