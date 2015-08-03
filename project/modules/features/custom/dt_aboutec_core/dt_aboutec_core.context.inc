<?php
/**
 * @file
 * dt_aboutec_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_aboutec_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about_ec_landing_page';
  $context->description = '';
  $context->tag = 'About EC';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about-ec*' => 'about-ec*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-aboutec_demosprint8-roles' => array(
          'module' => 'views',
          'delta' => 'aboutec_demosprint8-roles',
          'region' => 'content_bottom',
          'weight' => '-35',
        ),
        'views-3df542eedad952b4a75369418d3a0a8a' => array(
          'module' => 'views',
          'delta' => '3df542eedad952b4a75369418d3a0a8a',
          'region' => 'content_bottom',
          'weight' => '-34',
        ),
        'views-aboutec_demosprint8-president' => array(
          'module' => 'views',
          'delta' => 'aboutec_demosprint8-president',
          'region' => 'content_bottom',
          'weight' => '-33',
        ),
        'views-88d7d03b881913d88070cef8834a637b' => array(
          'module' => 'views',
          'delta' => '88d7d03b881913d88070cef8834a637b',
          'region' => 'content_bottom',
          'weight' => '-32',
        ),
        'views-a02ea4d5e73199b65f9335187b8d33da' => array(
          'module' => 'views',
          'delta' => 'a02ea4d5e73199b65f9335187b8d33da',
          'region' => 'content_bottom',
          'weight' => '-31',
        ),
        'views-ee48900b715db75603ece4a005720540' => array(
          'module' => 'views',
          'delta' => 'ee48900b715db75603ece4a005720540',
          'region' => 'content_bottom',
          'weight' => '-30',
        ),
        'views-aboutec_demosprint8-staff' => array(
          'module' => 'views',
          'delta' => 'aboutec_demosprint8-staff',
          'region' => 'content_bottom',
          'weight' => '-29',
        ),
        'nexteuropa_inpage_nav-inline_navigation' => array(
          'module' => 'nexteuropa_inpage_nav',
          'delta' => 'inline_navigation',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('About EC');
  $export['about_ec_landing_page'] = $context;

  return $export;
}
