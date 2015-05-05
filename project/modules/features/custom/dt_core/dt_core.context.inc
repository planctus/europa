<?php
/**
 * @file
 * dt_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dt_sitewide';
  $context->description = 'global context';
  $context->tag = 'site wide';
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
        'dt_core-dt_block_copyright' => array(
          'module' => 'dt_core',
          'delta' => 'dt_block_copyright',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('global context');
  t('site wide');
  $export['dt_sitewide'] = $context;

  return $export;
}
