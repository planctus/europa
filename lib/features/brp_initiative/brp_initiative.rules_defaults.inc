<?php

/**
 * @file
 * brp_initiative.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function brp_initiative_default_rules_configuration() {
  $items = array();
  $items['rules_brp_initiative_comp_check_update'] = entity_import('rules_config', '{ "rules_brp_initiative_comp_check_update" : {
      "LABEL" : "BRP Initiative | Comp. | Check \\u0026 Update",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "BRP Initiative" ],
      "REQUIRES" : [ "brp_initiative" ],
      "USES VARIABLES" : {
        "initaitve" : { "label" : "Initiative node", "type" : "node" },
        "remote_initiative" : { "label" : "Remote initiative", "type" : "remote_initiative" }
      },
      "IF" : [
        { "brp_initiative_check_initiative_state" : {
            "initiative" : [ "initaitve" ],
            "remote_initiative" : [ "remote-initiative" ]
          }
        }
      ],
      "DO" : [
        { "brp_initiative_create_update" : {
            "user" : [ "site:current-user" ],
            "remote_initiative" : [ "remote_initiative" ]
          }
        }
      ]
    }
  }');
  $items['rules_brp_initiative_comp_create'] = entity_import('rules_config', '{ "rules_brp_initiative_comp_create" : {
      "LABEL" : "BRP Initiative | Comp. | Create",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "BRP Initiative" ],
      "REQUIRES" : [ "brp_ws_client", "brp_initiative" ],
      "USES VARIABLES" : { "initiative_id" : { "label" : "BRP Initiative ID", "type" : "integer" } },
      "DO" : [
        { "brp_ws_client_get_initiative_by_id" : {
            "USING" : { "connection_name" : "brp", "initiative_id" : [ "initiative-id" ] },
            "PROVIDE" : { "remote_initiative" : { "remote_initiative" : "Remote initiative object." } }
          }
        },
        { "brp_initiative_create_update" : {
            "user" : [ "site:current-user" ],
            "remote_initiative" : [ "remote_initiative" ]
          }
        }
      ]
    }
  }');
  $items['rules_brp_initiative_create'] = entity_import('rules_config', '{ "rules_brp_initiative_create" : {
      "LABEL" : "BRP Initiative | Create",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "BRP Initiative" ],
      "REQUIRES" : [ "brp_ws_client", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "brp_ws_client_get_all_initiatives" : {
            "USING" : { "connection_name" : "brp" },
            "PROVIDE" : { "initiatives_id_list" : { "initiatives_id_list" : "Initiatives IDs list." } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : "admin" },
            "PROVIDE" : { "variable_added" : { "initiative_owner_username" : "Initiative owner username" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "name",
              "value" : [ "initiative-owner-username" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "user_object" : "User object" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "initiatives-id-list" ] },
            "ITEM" : { "initiative" : "Initiative" },
            "DO" : [
              { "component_rules_brp_initiative_comp_create" : { "initiative_id" : [ "initiative" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_brp_initiative_update'] = entity_import('rules_config', '{ "rules_brp_initiative_update" : {
      "LABEL" : "BRP Initiative | Update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "BRP Initiative" ],
      "REQUIRES" : [ "rules", "brp_ws_client" ],
      "ON" : { "node_view--brp_initiative" : { "bundle" : "brp_initiative" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "view-mode" ],
            "op" : "IN",
            "value" : { "value" : { "full" : "full", "teaser" : "teaser" } }
          }
        }
      ],
      "DO" : [
        { "brp_ws_client_get_initiative_by_id" : {
            "USING" : {
              "connection_name" : "brp",
              "initiative_id" : [ "node:field-brp-inve-id" ]
            },
            "PROVIDE" : { "remote_initiative" : { "brp_remote_initiative" : "Remote initiative object." } }
          }
        },
        { "component_rules_brp_initiative_comp_check_update" : {
            "initaitve" : [ "node" ],
            "remote_initiative" : [ "brp-remote-initiative" ]
          }
        }
      ]
    }
  }');
  return $items;
}
