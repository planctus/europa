<?php
/**
 * @file
 * cwt_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cwt_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-dt-menu-social-media_facebook:https://www.facebook.com/EuropeanCommission
  $menu_links['menu-dt-menu-social-media_facebook:https://www.facebook.com/EuropeanCommission'] = array(
    'menu_name' => 'menu-dt-menu-social-media',
    'link_path' => 'https://www.facebook.com/EuropeanCommission',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'identifier' => 'menu-dt-menu-social-media_facebook:https://www.facebook.com/EuropeanCommission',
      'alter' => TRUE,
      'attributes' => array(
        'data-display-title' => 1,
        'class' => array(
          0 => 'icon',
          1 => 'icon--facebook',
          2 => 'footer__icon--facebook',
          3 => 'footer__icon--social',
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
      'alter' => TRUE,
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
      'alter' => TRUE,
      'attributes' => array(
        'data-display-title' => 1,
        'class' => array(
          0 => 'icon',
          1 => 'icon--twitter',
          2 => 'footer__icon--twitter',
          3 => 'footer__icon--social',
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
  // Exported menu link: menu-dt-service-links_contact:<front>
  $menu_links['menu-dt-service-links_contact:<front>'] = array(
    'menu_name' => 'menu-dt-service-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-service-links_contact:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-service-links_cookies:<front>
  $menu_links['menu-dt-service-links_cookies:<front>'] = array(
    'menu_name' => 'menu-dt-service-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Cookies',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-service-links_cookies:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-dt-service-links_legal-notice:<front>
  $menu_links['menu-dt-service-links_legal-notice:<front>'] = array(
    'menu_name' => 'menu-dt-service-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Legal notice',
    'options' => array(
      'attributes' => array(
        'data-display-title' => 1,
        'data-remove-class' => 0,
      ),
      'identifier' => 'menu-dt-service-links_legal-notice:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Cookies');
  t('Facebook');
  t('Legal notice');
  t('Other social media');
  t('Twitter');


  return $menu_links;
}