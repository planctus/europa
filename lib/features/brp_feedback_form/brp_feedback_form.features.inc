<?php

/**
 * @file
 * brp_feedback_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function brp_feedback_form_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function brp_feedback_form_default_entityform_type() {
  $items = array();
  $items['brp_initiatives_feedback'] = entity_import('entityform_type', '{
    "type" : "brp_initiatives_feedback",
    "label" : "BRP Initiatives feedback",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "\\u003Cnone\\u003E",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : 0,
        "2" : "2",
        "4" : 0,
        "3" : 0,
        "5" : 0,
        "6" : 0,
        "7" : 0,
        "8" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "full_html" },
      "brp_client" : { "connection" : "brp" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['brp_initiatives_feedback_report'] = entity_import('entityform_type', '{
    "type" : "brp_initiatives_feedback_report",
    "label" : "BRP Initiatives feedback report",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "\\u003Cnone\\u003E",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "\\u003Ch2 style=\\u0022font-family: Arial, sans-serif;\\u0022\\u003EThank you for submitting your report.\\u003C\\/h2\\u003E\\r\\n",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "2" : 0,
        "4" : 0,
        "3" : 0,
        "5" : 0,
        "6" : 0,
        "7" : 0,
        "8" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "plain_text" },
      "brp_client" : { "connection" : "brp" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}
