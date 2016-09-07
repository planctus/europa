<?php

/**
 * @file
 * dt_integration_announcement_consumer.features.inc
 */

/**
 * Implements hook_default_integration_consumer().
 */
function dt_integration_announcement_consumer_default_integration_consumer() {
  $items = [];

  $items['announcement'] = entity_import('integration_consumer', '{
    "entity_bundle" : "announcement",
    "backend" : "dt_couchdb",
    "resource" : "news",
    "mapping" : [],
    "settings" : { "plugin" : { "mapping" : {
          "title" : "title_field",
          "description" : "field_core_description",
          "introduction" : "field_core_introduction",
          "background_information" : "field_announcement_info",
          "body" : "body",
          "news_type" : "field_announcement_type",
          "location" : "field_announcement_location",
          "sources" : "field_core_links",
          "department" : "field_core_department",
          "person" : "field_core_persons",
          "publish_date" : "field_core_date_published",
          "update_date" : "changed"
        }
      }
    },
    "name" : "Announcement",
    "machine_name" : "announcement",
    "plugin" : "node_consumer",
    "enabled" : "1",
    "description" : null,
    "rdf_mapping" : []
  }');

  return $items;
}

/**
 * Implements hook_default_integration_backend().
 */
function dt_integration_announcement_consumer_default_integration_backend() {
  $items = [];

  $items['dt_couchdb'] = entity_import('integration_backend', '{
    "formatter" : "json_formatter",
    "authentication" : "no_authentication",
    "name" : "DT CouchDB",
    "machine_name" : "dt_couchdb",
    "plugin" : "couchdb_backend",
    "enabled" : "1",
    "settings" : {
      "plugin" : {
        "resource_schemas" : [ "departments", "news" ],
        "backend" : {
          "base_url" : "https:\\/\\/webgate.acceptance.ec.europa.eu\\/fpfis\\/ilayer\\/beta",
          "id_endpoint" : "\\/uuid"
        },
        "resource_schema" : {
          "departments" : {
            "endpoint" : "\\/docs\\/types\\/departments",
            "all_docs_endpoint" : "\\/docs\\/types\\/departments\\/producers\\/infosite",
            "changes_endpoint" : "\\/changes\\/types\\/departments\\/producers\\/infosite"
          },
          "news" : {
            "endpoint" : "\\/docs\\/types\\/news",
            "all_docs_endpoint" : "\\/docs\\/types\\/news\\/producers\\/prd",
            "changes_endpoint" : "\\/changes\\/types\\/news\\/producers\\/prd"
          }
        }
      },
      "components" : { "authentication_handler" : { "username" : "", "password" : "", "loginpath" : "\\/login" } }
    },
    "description" : null,
    "rdf_mapping" : []
  }');

  return $items;
}
