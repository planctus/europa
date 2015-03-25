<?php
/**
 * @file
 * nexteuropa_core.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function nexteuropa_core_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'simple_text';
  $bean_type->label = 'Simple text';
  $bean_type->options = '';
  $bean_type->description = 'Placeholder for plain text and paragraphs';
  $export['simple_text'] = $bean_type;

  return $export;
}
