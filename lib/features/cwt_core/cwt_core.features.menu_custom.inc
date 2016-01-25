<?php
/**
 * @file
 * cwt_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function cwt_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-dt-menu-social-media.
  $menus['menu-dt-menu-social-media'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'title' => 'Footer - Social Media',
    'description' => 'List of social networks links for the European Commission',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-dt-service-links.
  $menus['menu-dt-service-links'] = array(
    'menu_name' => 'menu-dt-service-links',
    'title' => 'Service links',
    'description' => 'Help | Cookies and privacy notes | Legal statement',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer - Social Media');
  t('Help | Cookies and privacy notes | Legal statement');
  t('List of social networks links for the European Commission');
  t('Service links');

  return $menus;
}
