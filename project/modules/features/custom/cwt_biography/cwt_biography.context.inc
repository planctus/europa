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
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['announcements'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'biography';
  $context->description = '';
  $context->tag = 'CWT';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'biography' => 'biography',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-biography_portrait-block' => array(
          'module' => 'views',
          'delta' => 'biography_portrait-block',
          'region' => 'content_top',
          'weight' => '-38',
        ),
        'views-biography_related_terms-block' => array(
          'module' => 'views',
          'delta' => 'biography_related_terms-block',
          'region' => 'content_top',
          'weight' => '-37',
        ),
        'views-biography_social_networks-block' => array(
          'module' => 'views',
          'delta' => 'biography_social_networks-block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-contact-block' => array(
          'module' => 'views',
          'delta' => 'contact-block',
          'region' => 'content_top_2',
          'weight' => '-10',
        ),
        'cwt_biography-biography_contact_form' => array(
          'module' => 'cwt_biography',
          'delta' => 'biography_contact_form',
          'region' => 'content_top_2',
          'weight' => '-9',
        ),
        'views-biography_team-block_1' => array(
          'module' => 'views',
          'delta' => 'biography_team-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-biography_news-block' => array(
          'module' => 'views',
          'delta' => 'biography_news-block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-activities-block' => array(
          'module' => 'views',
          'delta' => 'activities-block',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-blog_commisioner_bio-block' => array(
          'module' => 'views',
          'delta' => 'blog_commisioner_bio-block',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-biography_timeline-block' => array(
          'module' => 'views',
          'delta' => 'biography_timeline-block',
          'region' => 'content',
          'weight' => '-5',
        ),
        'cwt_core-page_contents' => array(
          'module' => 'cwt_core',
          'delta' => 'page_contents',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CWT');
  $export['biography'] = $context;

  return $export;
}
