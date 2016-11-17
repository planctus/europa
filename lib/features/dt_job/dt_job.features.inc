<?php

/**
 * @file
 * dt_job.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function dt_job_default_cer() {
  $items = array();
  $items['node:person:field_core_jobs*node:job:field_core_persons'] = entity_import('cer', '{
    "identifier" : "node:person:field_core_jobs*node:job:field_core_persons",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:person:field_core_jobs" } ] },
    "cer_right" : { "und" : [ { "path" : "node:job:field_core_persons" } ] },
    "entity_type" : "cer",
    "rdf_mapping" : [],
    "entity_translation_handler_id" : "cer-eid-8227-0",
    "translations" : {"original":null,"data":[]}
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_job_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_job_node_info() {
  $items = array(
    'job' => array(
      'name' => t('Job'),
      'base' => 'node_content',
      'description' => t('Create content of type Job.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
