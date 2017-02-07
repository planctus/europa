<?php
/**
 * @file
 * dt_pri_policy_area.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function dt_pri_policy_area_default_cer() {
  $items = array();
  $items['node:priority_policy_area:field_core_child_policies*node:basic_page:field_core_parents'] = entity_import('cer', '{
    "identifier" : "node:priority_policy_area:field_core_child_policies*node:basic_page:field_core_parents",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:priority_policy_area:field_core_child_policies" } ] },
    "cer_right" : { "und" : [ { "path" : "node:basic_page:field_core_parents" } ] },
    "entity_type" : "cer",
    "rdf_mapping" : [],
    "entity_translation_handler_id" : "cer-eid-816-0",
    "translations" : {"original":null,"data":[]}
  }');
  $items['node:priority_policy_area:field_core_child_policies*node:policy:field_core_parent'] = entity_import('cer', '{
    "identifier" : "node:priority_policy_area:field_core_child_policies*node:policy:field_core_parent",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:priority_policy_area:field_core_child_policies" } ] },
    "cer_right" : { "und" : [ { "path" : "node:policy:field_core_parent" } ] },
    "entity_type" : "cer",
    "rdf_mapping" : [],
    "entity_translation_handler_id" : "cer-eid-817-0",
    "translations" : {"original":null,"data":[]}
  }');
  $items['node:priority_policy_area:field_core_child_policies*node:priority_policy_area:field_core_parent'] = entity_import('cer', '{
    "identifier" : "node:priority_policy_area:field_core_child_policies*node:priority_policy_area:field_core_parent",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:priority_policy_area:field_core_child_policies" } ] },
    "cer_right" : { "und" : [ { "path" : "node:priority_policy_area:field_core_parent" } ] },
    "entity_type" : "cer",
    "rdf_mapping" : [],
    "entity_translation_handler_id" : "cer-eid-818-0",
    "translations" : {"original":null,"data":[]}
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_pri_policy_area_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dt_pri_policy_area_node_info() {
  $items = array(
    'priority_policy_area' => array(
      'name' => t('Priority policy area'),
      'base' => 'node_content',
      'description' => t('Priority policy area content type for Digital Transformation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
