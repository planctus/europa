<?php
/**
 * @file
 * cwt_translation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cwt_translation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tmgmt_purge_finished';
  $strongarm->value = '86400';
  $export['tmgmt_purge_finished'] = $strongarm;

  return $export;
}
