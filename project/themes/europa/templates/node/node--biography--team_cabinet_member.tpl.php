<?php
/**
 * @file
 * Define the display of a custom view mode.
 */

  // Those are required fields.
  $firstname = render($content['field_biography_first_name'][0]['#markup']);
  $lastname =  render($content['field_biography_last_name'][0]['#markup']);

  // Social networks, find the values to be able to print them.
  if (isset($content['field_social_networks'])) {
    $keys = array_keys($content['field_social_networks']);
    $social = array_filter($keys, function($n) { return is_int($n); });
  }

  // Phone field, we format it as a link.
  if (isset($content['field_biography_phone'])) {
    $phone = render($content['field_biography_phone'][0]['#markup']);
  }
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