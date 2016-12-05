<?php
/**
 * @file
 * dt_person_press_contacts_list.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dt_person_press_contacts_list_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'press_contacts_list';
  $context->description = 'The page listing all the press contacts';
  $context->tag = 'Digital Transformation';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'press_contacts:page' => 'press_contacts:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-press_contacts-page' => array(
          'module' => 'views',
          'delta' => '-exp-press_contacts-page',
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
  t('The page listing all the press contacts');
  $export['press_contacts_list'] = $context;

  return $export;
}
