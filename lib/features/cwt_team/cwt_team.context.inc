<?php
/**
 * @file
 * cwt_team.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cwt_team_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cabinet';
  $context->description = '';
  $context->tag = 'CWT';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'team' => 'team',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'node_taxonomy_uuid' => array(
      'values' => array(
        '6995fb8a-82db-4610-8b65-3cfc9f4cb580' => '6995fb8a-82db-4610-8b65-3cfc9f4cb580',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-team_cabinet_contact-block' => array(
          'module' => 'views',
          'delta' => 'team_cabinet_contact-block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-team_cabinet_members-block_2' => array(
          'module' => 'views',
          'delta' => 'team_cabinet_members-block_2',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'team-cabinet',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['cabinet'] = $context;

  return $export;
}
