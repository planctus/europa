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
          'weight' => '-46',
        ),
        'facetapi-Qn4mHjrUCYMjogtPOBqspX1w14DbE5Os' => array(
          'module' => 'facetapi',
          'delta' => 'Qn4mHjrUCYMjogtPOBqspX1w14DbE5Os',
          'region' => 'sidebar_first',
          'weight' => '-46',
        ),
        'facetapi-rAR3k0ulQeOtL3qTKcxTfMxkkn7aanqi' => array(
          'module' => 'facetapi',
          'delta' => 'rAR3k0ulQeOtL3qTKcxTfMxkkn7aanqi',
          'region' => 'sidebar_first',
          'weight' => '-45',
        ),
        'facetapi-P0IUOvzCOBK8UMo1aInwhPKPHbgV95zQ' => array(
          'module' => 'facetapi',
          'delta' => 'P0IUOvzCOBK8UMo1aInwhPKPHbgV95zQ',
          'region' => 'sidebar_first',
          'weight' => '-44',
        ),
        'facetapi-NU2xbmEcLsoyUVsgfc6rzIFvtFmLKdM3' => array(
          'module' => 'facetapi',
          'delta' => 'NU2xbmEcLsoyUVsgfc6rzIFvtFmLKdM3',
          'region' => 'sidebar_first',
          'weight' => '-43',
        ),
        'facetapi-aJ17bUpq12382gZfAervvqkoOFSYzqfL' => array(
          'module' => 'facetapi',
          'delta' => 'aJ17bUpq12382gZfAervvqkoOFSYzqfL',
          'region' => 'sidebar_first',
          'weight' => '-42',
        ),
        'facetapi-rgiJ88oTRjckzess7OJ1SqpDVn3WawgK' => array(
          'module' => 'facetapi',
          'delta' => 'rgiJ88oTRjckzess7OJ1SqpDVn3WawgK',
          'region' => 'sidebar_first',
          'weight' => '-46',
        ),
        'mefibs-bbb7e22b2175b33ce74448fffc9bd2aa' => array(
          'module' => 'mefibs',
          'delta' => 'bbb7e22b2175b33ce74448fffc9bd2aa',
          'region' => 'sidebar_first',
          'weight' => '-10',
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
