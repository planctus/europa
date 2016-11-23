<?php

/**
 * @file
 * brp_initiative_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function brp_initiative_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function brp_initiative_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function brp_initiative_search_default_search_api_index() {
  $items = array();
  $items['brp_initiatives_index'] = entity_import('search_api_index', '{
    "name" : "brp initiatives index",
    "machine_name" : "brp_initiatives_index",
    "description" : null,
    "server" : "brp_search_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "brp_initiative" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_brp_inve_committee" : { "type" : "text" },
        "field_brp_inve_expert_group" : { "type" : "text" },
        "field_brp_inve_fb_count" : { "type" : "integer" },
        "field_brp_inve_fb_end_date" : { "type" : "date" },
        "field_brp_inve_fb_start_date" : { "type" : "date" },
        "field_brp_inve_id" : { "type" : "integer" },
        "field_brp_inve_initiative_status" : { "type" : "string" },
        "field_brp_inve_leading_service" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_brp_inve_modified_date" : { "type" : "date" },
        "field_brp_inve_publication_date" : { "type" : "date" },
        "field_brp_inve_reference" : { "type" : "text" },
        "field_brp_inve_resource_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_brp_inve_unit" : { "type" : "text" },
        "field_core_description" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Contains",
                "type" : "fulltext",
                "fields" : [
                  "title",
                  "title_field",
                  "field_core_description",
                  "field_brp_inve_reference"
                ],
                "description" : "A Fulltext aggregation of the following fields: Title, Name, Description, Reference."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_brp_inve_unit" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_brp_inve_unit" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "field_brp_inve_unit" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_brp_inve_unit" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_brp_inve_unit" : true },
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
function brp_initiative_search_default_search_api_server() {
  $items = array();
  $items['brp_search_server'] = entity_import('search_api_server', '{
    "name" : "brp search server",
    "machine_name" : "brp_search_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "2",
      "partial_matches" : 1,
      "indexes" : { "brp_initiatives_index" : {
          "type" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_brp_initiatives_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "title_field" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_brp_inve_unit" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_brp_inve_reference" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_brp_inve_fb_count" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_fb_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_brp_inve_fb_end_date" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_fb_end_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_brp_inve_fb_start_date" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_fb_start_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_brp_inve_id" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_id",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_brp_inve_initiative_status" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_initiative_status",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_brp_inve_leading_service" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_leading_service",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_brp_inve_modified_date" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_modified_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_brp_inve_publication_date" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_publication_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_brp_inve_resource_type" : {
            "table" : "search_api_db_brp_initiatives_index",
            "column" : "field_brp_inve_resource_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_core_description" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_brp_inve_committee" : {
            "table" : "search_api_db_brp_initiatives_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_brp_inve_expert_group" : {
            "table" : "search_api_db_brp_initiatives_index_text",
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
