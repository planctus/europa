<?php
/**
 * @file
 * dt_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dt_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-dt-menu-social-media.
  $menus['menu-dt-menu-social-media'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'title' => 'View the European Commission on :',
    'description' => 'List of social networks links for the European Commission',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-dt-service-links.
  $menus['menu-dt-service-links'] = array(
    'menu_name' => 'menu-dt-service-links',
    'title' => 'Service links',
    'description' => 'Help | Cookies and privacy notes | Legal statement',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Help | Cookies and privacy notes | Legal statement');
  t('List of social networks links for the European Commission');
  t('Service links');
  t('View the European Commission on :');


  return $menus;
}
