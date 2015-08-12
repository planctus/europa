<?php
/**
 * @file
 * Site switcher tab - political and info sites options.
 */

/**
 * Returns HTML for the element.
 *
 * @param mixed $variables
 *   An associative array containing:
 *   - modifier: The modifier applied to the element.
 *
 * @return string
 *   The markup itself.
 */
function theme_site_switcher_tabs($variables) {
  $modifier = isset($variables['modifier']) ? $variables['modifier'] : "";

  $output = "<span class='site-switcher $modifier'>";
  $output .= "<ul class='site-switcher__list'>";
  $output .= "<li class='site-switcher__option'><a href='http://ec.europa.eu/'>" . t("Political priorities") . "</a></li>";
  $output .= "<li class='site-switcher__option is-selected'><a href='https://beta.ec.europa.eu/'>" . t("Information and services") . "</a></li>";
  $output .= "</ul>";
  $output .= "</span>";

  return $output;
}
