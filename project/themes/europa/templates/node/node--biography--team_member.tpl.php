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
  <div class="listing--cabinet-top-wrapper">
    <div class="listing--cabinet__picture field">
      <?php print render($content['field_biography_portrait']); ?>
    </div>

  <?php if (isset($content['field_biography_tagline'])): ?>
    <span class="label label--upper field">
      <?php print render($content['field_biography_tagline'][0]['#markup']); ?>
    </span>
  <?php endif; ?>

    <h4 class="listing--cabinet__name field">
      <?php print l($firstname . ' ' . $lastname, 'node/' . $node->nid); ?>
    </h4>

  <?php if (isset($content['field_biography_email'])): ?>
    <div class="listing--cabinet__email field">
      <span class="label label--aligned">
        <?php print render($content['field_biography_email']['#title']); ?>
      </span>
      <?php print render($content['field_biography_email'][0]['#markup']); ?>
    </div>
  <?php endif; ?>

  <?php if (isset($phone)): ?>
    <div class="listing--cabinet__phone field">
      <span class="label label--aligned">
        <?php print render($content['field_biography_phone']['#title']); ?>
      </span>
        <a href="tel:<?php print $phone; ?>"><?php print $phone; ?></a>
    </div>
  <?php endif; ?>

  <?php if (isset($social)): ?>
    <div class="listing--cabinet__social field">
      <span class="label label--aligned--top">
        <?php print render($content['field_social_networks']['#title']); ?>
      </span>
      <div class="listing--cabinet__social_icons">
      <?php
        foreach ($social as $i) {
          print render($content['field_social_networks'][$i]['#markup']);
        }
      ?>
      </div>
    </div>
  <?php endif; ?>

  </div> <!-- .team-member-top-wrapper END -->

  <div class="field listing--cabinet-bottom-wrapper">
    <span class="label label--aligned--top">
      <?php print render($content['body']['#title']); ?>
    </span>
    <div class="listing--cabinet__body">
      <?php print render($content['body'][0]['#markup']); ?>
    </div>
  </div> <!-- .team-member-bottom-wrapper END -->
</div>