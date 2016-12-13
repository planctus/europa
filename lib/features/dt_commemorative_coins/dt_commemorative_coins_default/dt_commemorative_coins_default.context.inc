<?php
/**
 * @file
 * dt_commemorative_coins_default.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_commemorative_coins_default_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'commemorative_coins';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'commemorative_coins:page' => 'commemorative_coins:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-commemorative_coins-page' => array(
          'module' => 'views',
          'delta' => '-exp-commemorative_coins-page',
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
  $export['commemorative_coins'] = $context;

  return $export;
}
