<?php

/**
 * @file
 * Template of the DGT supported XML format.
 */
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <meta name="JobID" content="<?php echo filter_xss($tjid); ?>" />
     <meta name="languageSource" content="<?php echo filter_xss($source_language); ?>" />
    <title>Job ID <?php echo filter_xss($tjid); ?></title>
  </head>
  <body>
    <div id="languageTarget" class="meta"><?php echo filter_xss($target_language); ?></div>
    <?php foreach ($items as $item_key => $item): ?>
      <div class="asset" id="<?php echo filter_xss($item_key); ?>">
        <?php foreach ($item as $field_key => $field): ?>
          <?php
            $key = drupal_substr($field_key, 1);
            $key = base64_decode(str_pad(strtr($key, '-_', '+/'), drupal_strlen($key) % 4, '=', STR_PAD_RIGHT));
          ?>
        <div class="atom" id="<?php echo filter_xss($field_key); ?>" label="<?php echo filter_xss($field['#label']); ?>" context="[<?php echo filter_xss($key); ?>]"><?php echo filter_xss($field['#text']); ?></div>
        <?php endforeach; ?>
      </div>
    <?php endforeach; ?>
  </body>
</html>
