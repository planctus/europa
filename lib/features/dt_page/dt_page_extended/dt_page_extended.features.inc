<?php

/**
 * @file
 * dt_page_extended.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function dt_page_extended_default_cer() {
  $items = array();
  $items['node:basic_page:field_core_children*node:basic_page:field_core_parents'] = entity_import('cer', '{
    "identifier" : "node:basic_page:field_core_children*node:basic_page:field_core_parents",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:basic_page:field_core_children" } ] },
    "cer_right" : { "und" : [ { "path" : "node:basic_page:field_core_parents" } ] },
    "entity_type" : "cer",
    "rdf_mapping" : [],
    "entity_translation_handler_id" : "cer-eid-12970-0",
    "translations" : {"original":null,"data":[]}
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_page_extended_ctools_plugin_api($module = NULL, $api = NULL) {
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
