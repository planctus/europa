<?php
/**
 * @file
 * cwt_blogs.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cwt_blogs_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_post';
  $context->description = '';
  $context->tag = 'CWT';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'commisioner_blog_post' => 'commisioner_blog_post',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'subscriptions_ui-0' => array(
          'module' => 'subscriptions_ui',
          'delta' => '0',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['blog_post'] = $context;

  return $export;
}
