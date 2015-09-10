<?php
/**
 * @file
 * cwt_core.block.inc
 */

/**
 * Implements hook_block_info().
 */
function cwt_core_block_info() {
  $blocks['cwt_block_copyright'] = array(
    'info' => t('Copyright paragraph'),
  );

  $blocks['cwt_header_site_tab_switcher'] = array(
    'info' => t('Header site tab switcher'),
  );

  $blocks['cwt_footer_site_tab_switcher'] = array(
    'info' => t('Footer site tab switcher'),
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function cwt_core_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'cwt_block_copyright':
    case 'cwt_header_site_tab_switcher':
    case 'cwt_footer_site_tab_switcher':
      $block['content'] = cwt_core_get_blocks_content($delta);
      break;
  }
  return $block;
}

/**
 * A module-defined block content function.
 */
function cwt_core_get_blocks_content($delta) {
  $result = array();
  switch ($delta) {
    case 'cwt_block_copyright':
      $result = array(
        '#markup' => "<div class='footer__disclaimer'><span>" . t('© European Commission 2015') . "</span></div>",
      );
      break;

    case 'cwt_header_site_tab_switcher':
      $result = array(
        '#markup' => theme('site_switcher_tabs', array('modifier' => 'site-switcher--header')),
      );
      break;

    case 'cwt_footer_site_tab_switcher':
      $result = array(
        '#markup' => theme('site_switcher_tabs', array('modifier' => 'site-switcher--footer')),
      );
      break;
  }
  return $result;
}

/**
 * Implements hook_theme().
 */
function cwt_core_theme($existing, $type, $theme, $path) {
  return array(
    'site_switcher_tabs' => array(
      'file' => 'cwt_core.theme.inc',
      'variables' => array(
        'modifier' => NULL,
      ),
    ),
  );
}
