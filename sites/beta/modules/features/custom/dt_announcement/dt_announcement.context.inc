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
  $context->name = 'announcement';
  $context->description = '';
  $context->tag = 'Beta';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'announcement' => 'announcement',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-announcements-block' => array(
          'module' => 'views',
          'delta' => 'announcements-block',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Beta');
  $export['announcement'] = $context;

  return $export;
}
