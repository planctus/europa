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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'college';
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
        '8f7d3b66-ffbf-4f70-963d-7da7b8508d4c' => '8f7d3b66-ffbf-4f70-963d-7da7b8508d4c',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-team_image-block' => array(
          'module' => 'views',
          'delta' => 'team_image-block',
          'region' => 'content',
          'weight' => '-11',
        ),
        'views-team_navigation-block' => array(
          'module' => 'views',
          'delta' => 'team_navigation-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'cwt_highlights-cwt_highlights' => array(
          'module' => 'cwt_highlights',
          'delta' => 'cwt_highlights',
          'region' => 'content',
          'weight' => '-9',
        ),
        'cwt_core-college_members' => array(
          'module' => 'cwt_core',
          'delta' => 'college_members',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-team_agenda-block_1' => array(
          'module' => 'views',
          'delta' => 'team_agenda-block_1',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'team-college',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['college'] = $context;

  return $export;
}
