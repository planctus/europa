<?php
/**
 * @file
 * dt_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dt_core_non_homepage_pages';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-information-site-menu' => array(
          'module' => 'bean',
          'delta' => 'information-site-menu',
          'region' => 'header_bottom',
          'weight' => '-10',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'header_bottom',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Transformation');
  $export['dt_core_non_homepage_pages'] = $context;

  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Transformation');
  $export['dt_core_sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'in_page_navigation';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:21:{s:4:"node";s:4:"node";s:13:"taxonomy_term";i:0;s:7:"comment";i:0;s:4:"bean";i:0;s:8:"flagging";i:0;s:16:"i18n_translation";i:0;s:18:"og_membership_type";i:0;s:13:"og_membership";i:0;s:4:"file";i:0;s:19:"taxonomy_vocabulary";i:0;s:9:"tmgmt_job";i:0;s:14:"tmgmt_job_item";i:0;s:13:"tmgmt_message";i:0;s:16:"tmgmt_translator";i:0;s:12:"tmgmt_remote";i:0;s:16:"tmgmt_local_task";i:0;s:21:"tmgmt_local_task_item";i:0;s:4:"user";i:0;s:15:"wysiwyg_profile";i:0;s:31:"workbench_moderation_transition";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_core_in_page_navigation',
        'field_value' => '1',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nexteuropa_inpage_nav-inline_navigation' => array(
          'module' => 'nexteuropa_inpage_nav',
          'delta' => 'inline_navigation',
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
  $export['in_page_navigation'] = $context;

  return $export;
}
