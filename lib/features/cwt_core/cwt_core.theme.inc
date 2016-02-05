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
  global $language;
  $parameters = drupal_get_query_parameters();

  $info_url = variable_get('site_switcher_info_url', 'https://beta.ec.europa.eu/') . 'index_' . $language->prefix . (isset($parameters['2nd-language']) ? '?2nd-language=' . $parameters['2nd-language'] : '');
  $political_url = variable_get('site_switcher_political_url', 'http://ec.europa.eu/') . 'index_' . $language->prefix . '.htm';

  $modifier = isset($variables['modifier']) ? $variables['modifier'] : "";

  $output = "<div class='site-switcher $modifier'>";
  $output .= "<ul class='site-switcher__list'>";
  $output .= "<li class='site-switcher__option is-selected'><a href='$political_url'>" . t("Commission and its priorities") . "</a></li>";
  $output .= "<li class='site-switcher__option'><a href='$info_url'>" . t("Policies, information and services") . "</a></li>";
  $output .= "</ul>";
  $output .= "</div>";

  return $output;
}
