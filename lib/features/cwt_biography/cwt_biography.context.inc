<?php
/**
 * @file
 * cwt_biography.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cwt_biography_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'announcements';
  $context->description = '';
  $context->tag = 'CWT';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'biography_news:list' => 'biography_news:list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-biography_news-list' => array(
          'module' => 'views',
          'delta' => '-exp-biography_news-list',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['announcements'] = $context;

  return $export;
}
