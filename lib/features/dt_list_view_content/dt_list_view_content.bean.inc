<?php

/**
 * @file
 * dt_list_view_content.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function dt_list_view_content_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'list_view_content';
  $bean_type->label = 'List view content';
  $bean_type->options = '';
  $bean_type->description = 'This bean holds the information which is used to update the display of list views.';
  $export['list_view_content'] = $bean_type;

  return $export;
}
