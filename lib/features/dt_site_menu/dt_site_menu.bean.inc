<?php
/**
 * @file
 * dt_site_menu.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function dt_site_menu_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'site_menu';
  $bean_type->label = 'Site menu';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['site_menu'] = $bean_type;

  return $export;
}
