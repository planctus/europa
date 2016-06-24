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

  $modifier = isset($variables['modifier']) ? $variables['modifier'] : "";

  // Array of sites in the correct order.
  $sites = [
    [
      'label' => t("Commission and its priorities"),
      'url' => variable_get('site_switcher_political_url', 'http://ec.europa.eu/') . 'index_' . $language->prefix . '.htm',
      'active' => ' is-selected',
    ],
    [
      'label' => t("Policies, information and services"),
      'url' => variable_get('site_switcher_info_url', 'https://ec.europa.eu/info/') . 'index_' . $language->prefix . (isset($parameters['2nd-language']) ? '?2nd-language=' . $parameters['2nd-language'] : ''),
      'active' => '',
    ],
  ];

  $output = "<div class='site-switcher $modifier'>";
  $output .= "<ul class='site-switcher__list'>";
  foreach ($sites as $site) {
    $output .= '<li class="site-switcher__option' . $site['active'] . '"><a href="' . $site['url'] . '">' . $site['label'] . '</a></li>';
  }
  $output .= "</ul>";
  $output .= "</div>";

  return $output;
}
