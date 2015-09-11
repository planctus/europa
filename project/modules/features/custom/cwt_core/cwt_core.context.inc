<?php
/**
 * @file
 * cwt_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cwt_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cwt_core_sitewide';
  $context->description = '';
  $context->tag = 'CWT';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cwt_core-cwt_header_site_tab_switcher' => array(
          'module' => 'cwt_core',
          'delta' => 'cwt_header_site_tab_switcher',
          'region' => 'header_top',
          'weight' => '-10',
        ),
        'language_selector_site-language_selector_site' => array(
          'module' => 'language_selector_site',
          'delta' => 'language_selector_site',
          'region' => 'header',
          'weight' => '-10',
        ),
        'nexteuropa_europa_search-nexteuropa_europa_search_form' => array(
          'module' => 'nexteuropa_europa_search',
          'delta' => 'nexteuropa_europa_search_form',
          'region' => 'header',
          'weight' => '-9',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'header_bottom',
          'weight' => '-9',
        ),
        'nexteuropa_feedback-nexteuropa_feedback' => array(
          'module' => 'nexteuropa_feedback',
          'delta' => 'nexteuropa_feedback',
          'region' => 'footer_top',
          'weight' => '-42',
        ),
        'cwt_core-cwt_footer_site_tab_switcher' => array(
          'module' => 'cwt_core',
          'delta' => 'cwt_footer_site_tab_switcher',
          'region' => 'footer_top',
          'weight' => '-41',
        ),
        'menu-menu-dt-menu-social-media' => array(
          'module' => 'menu',
          'delta' => 'menu-dt-menu-social-media',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'menu-menu-dt-service-links' => array(
          'module' => 'menu',
          'delta' => 'menu-dt-service-links',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'cwt_core-cwt_block_copyright' => array(
          'module' => 'cwt_core',
          'delta' => 'cwt_block_copyright',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['cwt_core_sitewide'] = $context;

  return $export;
}
