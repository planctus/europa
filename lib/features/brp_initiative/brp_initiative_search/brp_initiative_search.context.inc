<?php

/**
 * @file
 * brp_initiative_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function brp_initiative_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'brp_init_filter_search_api';
  $context->description = '';
  $context->tag = 'BRP';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'brp_initiatives_search_api:page' => 'brp_initiatives_search_api:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-dd4d32d33352da2ebe216f4094ed3a18' => array(
          'module' => 'views',
          'delta' => 'dd4d32d33352da2ebe216f4094ed3a18',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('BRP');
  $export['brp_init_filter_search_api'] = $context;

  return $export;
}
