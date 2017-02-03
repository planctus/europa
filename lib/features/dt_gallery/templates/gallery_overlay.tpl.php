<?php

/**
 * @file
 * The template file for media gallery overlay.
 */
?>
<?php if ($media): ?>
  <div class="gallery-overlay">
    <div class="gallery-overlay__main">
    <?php if ($previous): ?>
      <span class="gallery-overlay__media-previous"><?php print $previous; ?></span>
    <?php endif; ?>
      <div class="gallery-overlay__media gallery-overlay__media--<?php print $type; ?>">
        <?php print $media; ?>
      </div>
    <?php if ($next): ?>
      <span class="gallery-overlay__media-next"><?php print $next; ?></span>
    <?php endif; ?>
    </div>
    <div class="gallery-overlay__sidebar">
      <div class="gallery-overlay__close"><?php print $close; ?></div>
      <div class="gallery-overlay__meta">
        <span class="gallery-overlay__count"><?php print $count; ?></span>
        <span class="gallery-overlay__download"><?php print $download; ?></span>
        <span class="gallery-overlay__share"><script type="application/json">
          {
            "service": "sbkm",
            "popup": true,
            "sharing": true,
            "selection": true,
            "to": [
              "more",
              "twitter",
              "facebook",
              "googleplus",
              "linkedin",
              "e-mail"
            ],
            "stats": true,
            "css": {
              "list": "wtShareList"
            }
          }
        </script></span>
      </div>
      <?php if ($description): ?>
        <div class="gallery-overlay__description">
          <?php print $description; ?>
        </div>
      <?php endif; ?>
      <?php if ($copyright): ?>
        <div class="gallery-overlay__copyright">
          <?php print $copyright; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
