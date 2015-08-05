<?php
/**
 * @file
 * If no modifier is send by theme(), then assume it's a header one.
 */
$modifier = reset($variables['modifier']);
?>
<span class="site-switcher <?php echo $modifier; ?>">
  <ul class="site-switcher__list">
    <li class="site-switcher__option"><a href="#">Political priorities</a></li>
    <li class="site-switcher__option site-switcher__option--selected"><a href="#">Information and services</a></li>
  </ul>
</span>
