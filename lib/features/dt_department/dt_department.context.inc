<?php
/**
 * @file
 * dt_department.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_department_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'departments_landing_page';
  $context->description = '';
  $context->tag = 'About EC';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'department:page' => 'department:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-department-page' => array(
          'module' => 'views',
          'delta' => '-exp-department-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('About EC');
  $export['departments_landing_page'] = $context;

  return $export;
}
