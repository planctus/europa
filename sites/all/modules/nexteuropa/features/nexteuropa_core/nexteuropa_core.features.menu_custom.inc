<?php
/**
 * @file
 * nexteuropa_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nexteuropa_core_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-european-commission-links.
  $menus['menu-european-commission-links'] = array(
    'menu_name' => 'menu-european-commission-links',
    'title' => t('View the European Commission on :'),
    'description' => 'Lists static links for EC social networks.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Lists static links for EC social networks.');
  t('View the European Commission on :');


  return $menus;
}
