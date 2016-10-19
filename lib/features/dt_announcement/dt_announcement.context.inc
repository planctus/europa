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
        'dt_list_view_content-views_related_links' => array(
          'delta' => 'views_related_links',
          'module' => 'dt_list_view_content',
          'region' => 'sidebar_first',
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
