<?php
/**
 * @file
 * dt_policy.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_policy_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'policies';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'policy_overview:page' => 'policy_overview:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-policy_overview-page' => array(
          'module' => 'views',
          'delta' => '-exp-policy_overview-page',
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
  $export['policies'] = $context;

  return $export;
}
