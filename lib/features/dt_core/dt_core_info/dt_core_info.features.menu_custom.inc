<?php
/**
 * @file
 * dt_core_info.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dt_core_info_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-dt-menu-social-media.
  $menus['menu-dt-menu-social-media'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'title' => 'Footer - Social Media',
    'description' => 'List of social networks links for the European Commission',
    'language' => 'und',
    'i18n_mode' => 5,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Footer - Social Media');
  t('List of social networks links for the European Commission');

  return $menus;
}
