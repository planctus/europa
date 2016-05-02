<?php
/**
 * @file
 * dt_event.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function dt_event_default_cer() {
  $items = array();
  $items['node:event:field_event_parent_events*node:event:field_event_children_events'] = entity_import('cer', '{
    "identifier" : "node:event:field_event_parent_events*node:event:field_event_children_events",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:event:field_event_parent_events" } ] },
    "cer_right" : { "und" : [ { "path" : "node:event:field_event_children_events" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function dt_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
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
 * Implements hook_views_api().
 */
function dt_event_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dt_event_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Create content of type Event.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function dt_event_default_search_api_index() {
  $items = array();
  $items['event_index'] = entity_import('search_api_index', '{
    "name" : "Event index",
    "machine_name" : "event_index",
    "description" : null,
    "server" : "information_sapi_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "event" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "field_core_departments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_core_description" : { "type" : "text" },
        "field_core_introduction:value" : { "type" : "text" },
        "field_core_location:country" : { "type" : "string" },
        "field_core_topics" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_event_date:value" : { "type" : "string" },
        "field_event_date:value2" : { "type" : "string" },
        "field_event_is_live_streaming" : { "type" : "boolean" },
        "field_event_is_online" : { "type" : "boolean" },
        "field_event_status_description:value" : { "type" : "text" },
        "field_event_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_what_happened:value" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function dt_event_default_search_api_server() {
  $items = array();
  $items['information_sapi_server'] = entity_import('search_api_server', '{
    "name" : "information_sapi_server",
    "machine_name" : "information_sapi_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "4",
      "partial_matches" : 0,
      "indexes" : { "event_index" : {
          "field_core_topics" : {
            "table" : "search_api_db_event_index_field_core_topics",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_core_departments" : {
            "table" : "search_api_db_event_index_field_core_departments",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_event_is_live_streaming" : {
            "table" : "search_api_db_event_index",
            "column" : "field_event_is_live_streaming",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_event_is_online" : {
            "table" : "search_api_db_event_index",
            "column" : "field_event_is_online",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_event_type" : {
            "table" : "search_api_db_event_index",
            "column" : "field_event_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_event_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_event_date:value" : {
            "table" : "search_api_db_event_index",
            "column" : "field_event_date_value",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_core_location:country" : {
            "table" : "search_api_db_event_index",
            "column" : "field_core_location_country",
            "type" : "string",
            "boost" : "1.0"
          },
          "title_field" : {
            "table" : "search_api_db_event_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_core_introduction:value" : {
            "table" : "search_api_db_event_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_event_what_happened:value" : {
            "table" : "search_api_db_event_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_event_date:value2" : {
            "table" : "search_api_db_event_index",
            "column" : "field_event_date_value2",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_core_description" : {
            "table" : "search_api_db_event_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_event_status_description:value" : {
            "table" : "search_api_db_event_index_text",
            "type" : "text",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
