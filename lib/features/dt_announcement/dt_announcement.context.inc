<?php
/**
 * @file
 * dt_announcement.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_announcement_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'announcements';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'announcements:page_1' => 'announcements:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-853486dff58ad0ea58da907af7babd9c' => array(
          'module' => 'views',
          'delta' => '853486dff58ad0ea58da907af7babd9c',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-b719acfefcf2fde5d5b6d51df090a12f' => array(
          'module' => 'views',
          'delta' => 'b719acfefcf2fde5d5b6d51df090a12f',
          'region' => 'content_top',
          'weight' => '-9',
        ),
        'views--exp-announcements-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-announcements-page_1',
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
  $export['announcements'] = $context;

  return $export;
}
