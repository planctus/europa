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
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'header_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Digital Transformation');
  $export['dt_core_non_homepage_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dt_core_sitewide';
  $context->description = '';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'dt_core-dt_header_site_tab_switcher' => array(
          'module' => 'dt_core',
          'delta' => 'dt_header_site_tab_switcher',
          'region' => 'header_top',
          'weight' => '-10',
        ),
        'language_selector_site-language_selector_site' => array(
          'module' => 'language_selector_site',
          'delta' => 'language_selector_site',
          'region' => 'header',
          'weight' => '-10',
        ),
        'nexteuropa_europa_search-nexteuropa_europa_search_form' => array(
          'module' => 'nexteuropa_europa_search',
          'delta' => 'nexteuropa_europa_search_form',
          'region' => 'header',
          'weight' => '-9',
        ),
        'nexteuropa_feedback-nexteuropa_feedback' => array(
          'module' => 'nexteuropa_feedback',
          'delta' => 'nexteuropa_feedback',
          'region' => 'footer_top',
          'weight' => '-42',
        ),
        'dt_core-dt_footer_site_tab_switcher' => array(
          'module' => 'dt_core',
          'delta' => 'dt_footer_site_tab_switcher',
          'region' => 'footer_top',
          'weight' => '-41',
        ),
        'menu-menu-dt-menu-social-media' => array(
          'module' => 'menu',
          'delta' => 'menu-dt-menu-social-media',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'menu-menu-dt-service-links' => array(
          'module' => 'menu',
          'delta' => 'menu-dt-service-links',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'dt_core-dt_block_copyright' => array(
          'module' => 'dt_core',
          'delta' => 'dt_block_copyright',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'dt_core-dt_block_footer_site_switcher' => array(
          'module' => 'dt_core',
          'delta' => 'dt_block_footer_site_switcher',
          'region' => 'footer_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

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
