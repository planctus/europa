bar!

<?php if ($heading): ?>
  <h2 id="<?php echo drupal_clean_css_identifier($heading); ?>"><?php echo $heading; ?></h2>
<?php endif; ?>
