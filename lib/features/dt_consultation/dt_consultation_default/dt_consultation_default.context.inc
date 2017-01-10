<?php
/**
 * @file
 * dt_consultation_default.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_consultation_default_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'consultations';
  $context->description = 'Consultations search page filter';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'consultations' => 'consultations',
        'consultations:page' => 'consultations:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-consultations-page' => array(
          'module' => 'views',
          'delta' => '-exp-consultations-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Consultations search page filter');
  t('Digital Transformation');
  $export['consultations'] = $context;

  return $export;
}
