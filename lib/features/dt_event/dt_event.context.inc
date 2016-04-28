<?php
/**
 * @file
 * dt_event.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_event_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dt_events_filter';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'events:page' => 'events:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-events-page' => array(
          'module' => 'views',
          'delta' => '-exp-events-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-NU2xbmEcLsoyUVsgfc6rzIFvtFmLKdM3' => array(
          'module' => 'facetapi',
          'delta' => 'NU2xbmEcLsoyUVsgfc6rzIFvtFmLKdM3',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-1GGNUWh94nGnKsOVyMP1hhMQIInvMjvo' => array(
          'module' => 'facetapi',
          'delta' => '1GGNUWh94nGnKsOVyMP1hhMQIInvMjvo',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Transformation');
  $export['dt_events_filter'] = $context;

  return $export;
}
