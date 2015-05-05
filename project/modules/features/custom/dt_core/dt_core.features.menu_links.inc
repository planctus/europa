<?php
/**
 * @file
 * dt_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dt_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-dt-menu-social-media_facebook:https://www.facebook.com/EuropeanCommission
  $menu_links['menu-dt-menu-social-media_facebook:https://www.facebook.com/EuropeanCommission'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'link_path' => 'https://www.facebook.com/EuropeanCommission',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'identifier' => 'menu-dt-menu-social-media_facebook:https://www.facebook.com/EuropeanCommission',
      'attributes' => array(
        'data-display-title' => 1,
        'class' => array(
          0 => 'icon--social--facebook',
        ),
        'data-remove-class' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-menu-social-media_other-social-media:http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm
  $menu_links['menu-dt-menu-social-media_other-social-media:http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'link_path' => 'http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm',
    'router_path' => '',
    'link_title' => 'Other social media',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-menu-social-media_other-social-media:http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-menu-social-media_twitter:https://twitter.com/eu_commission
  $menu_links['menu-dt-menu-social-media_twitter:https://twitter.com/eu_commission'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'link_path' => 'https://twitter.com/eu_commission',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'identifier' => 'menu-dt-menu-social-media_twitter:https://twitter.com/eu_commission',
      'attributes' => array(
        'data-display-title' => 1,
        'class' => array(
          0 => 'icon--social--twitter',
        ),
        'data-remove-class' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-service-links_cookies-and-privacy-notice:http://ec.europa.eu/
  $menu_links['menu-dt-service-links_cookies-and-privacy-notice:http://ec.europa.eu/'] = array(
    'menu_name' => 'menu-dt-service-links',
    'link_path' => 'http://ec.europa.eu/',
    'router_path' => '',
    'link_title' => 'Cookies and privacy notice',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-service-links_cookies-and-privacy-notice:http://ec.europa.eu/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-service-links_help:http://ec.europa.eu/
  $menu_links['menu-dt-service-links_help:http://ec.europa.eu/'] = array(
    'menu_name' => 'menu-dt-service-links',
    'link_path' => 'http://ec.europa.eu/',
    'router_path' => '',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-service-links_help:http://ec.europa.eu/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-service-links_legal-statement:http://ec.europa.eu/
  $menu_links['menu-dt-service-links_legal-statement:http://ec.europa.eu/'] = array(
    'menu_name' => 'menu-dt-service-links',
    'link_path' => 'http://ec.europa.eu/',
    'router_path' => '',
    'link_title' => 'Legal statement',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-service-links_legal-statement:http://ec.europa.eu/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Cookies and privacy notice');
  t('Facebook');
  t('Help');
  t('Legal statement');
  t('Other social media');
  t('Twitter');


  return $menu_links;
}
